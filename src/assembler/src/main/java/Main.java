import antlr4.ArgoBaseVisitor;
import antlr4.ArgoLexer;
import antlr4.ArgoParser;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;

public class Main {
	public static void main(String[] args) {
		// Create stream input
		CharStream stream = CharStreams.fromString("# The following .arg equals to this code:\n" +
				"# \n" +
				"# function sum(int a, int b) {\n" +
				"#   return a + b;\n" +
				"# }\n" +
				"# function main() {\n" +
				"#   return sum(5, 4);\n" +
				"# }\n" +
				"#\n" +
				"\n" +
				":sum {\n" +
				"    ADD\n" +
				"    RET\n" +
				"}\n" +
				"\n" +
				":main {\n" +
				"    PSH, 5 \n" +
				"    PSH, 4 \n" +
				"    CLL, sum \n" +
				"    HLT\n" +
				"}\n");
		// Feed lexer
		ArgoLexer lexer = new ArgoLexer(stream);
		// Create intermediate representation
		CommonTokenStream tokens = new CommonTokenStream(lexer);
		// Feed the parser
		ArgoParser parser = new ArgoParser(tokens);
		// Get hierarchy (Program context)
		ArgoParser.ProgContext tree = parser.prog();
		// Create visitor to generate bytecode
		ArgoBaseVisitor<Void> visitor = new ArgoBaseVisitor<>();
		// Visit
		visitor.visit(tree);
	}
}
