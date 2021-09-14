import antlr4.ArgoBaseVisitor;
import antlr4.ArgoLexer;
import antlr4.ArgoParser;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;

import java.io.IOException;
import java.io.InputStream;
import java.util.Objects;

public class Main {
	public static void main(String[] args) throws IOException {
		// Load file from res
		InputStream input = Objects.requireNonNull(Main.class.getResourceAsStream("sum.argo"));
		// Create chars stream
		CharStream stream = CharStreams.fromStream(input);
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
