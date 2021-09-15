import bytecode.ClassFile;
import bytecode.Generator;
import cli.Args;
import com.beust.jcommander.JCommander;
import compiler.ArgoLexer;
import compiler.ArgoParser;
import io.ArgoWriter;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;

import java.io.IOException;

public final class ArgoC {

	public static final String CLI_NAME = "ArgoCompiler";
	public static final String CLI_EXE_NAME = "argoc";
	public static final String CLI_VERSION = "0.0.1";

	private final Args args;
	private final JCommander cli;

	public ArgoC() {
		this.args = new Args();
		this.cli = JCommander
				.newBuilder()
				.programName(CLI_EXE_NAME)
				.addObject(this.args)
				.build();
	}

	public static void main(String... argv) {
		// Create argoc instance
		final ArgoC argoc = new ArgoC();
		// If empty display the usage
		if(argv.length != 0) {
			// Parse
			argoc.cli.parse(argv);
			// Run
			argoc.run();
		}else {
			argoc.cli.usage();
		}
	}

	public void run() {
		if(args.isHelp()) {
			cli.usage();
		}else if(args.isVersion()) {
			version();
		}else if(args.getFiles().size() != 0) {
			try {
				compile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	public void version() {
		System.out.printf("%s(%s) v%s\n", CLI_NAME, CLI_EXE_NAME, CLI_VERSION);
	}

	public void compile() throws IOException {
		// Take just the first one (for now)
		final String filename = args.getFiles().get(0);
		// Create chars stream
		CharStream stream = CharStreams.fromFileName(filename);
		// Feed lexer
		ArgoLexer lexer = new ArgoLexer(stream);
		// Create intermediate representation
		CommonTokenStream tokens = new CommonTokenStream(lexer);
		// Feed the parser
		ArgoParser parser = new ArgoParser(tokens);
		// Get hierarchy (Program context)
		ArgoParser.ProgContext tree = parser.prog();
		// Create visitor to generate bytecode
		Generator visitor = new Generator();
		// Visit
		final ClassFile classFile = visitor.visit(tree);
		// Eventually display output
		if(args.isDebug()) System.out.println(classFile);
		// Write on disk
		ArgoWriter.write(classFile, args.getNamedOutput(filename));
	}

}
