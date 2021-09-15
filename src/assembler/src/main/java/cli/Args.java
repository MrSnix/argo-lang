package cli;

import bytecode.ClassFile;
import com.beust.jcommander.Parameter;

import java.io.File;
import java.nio.file.Paths;
import java.util.List;

public class Args {
    @Parameter(description = "[<file>]")
    private List<String> files;
    @Parameter(names = {"-o <file>", "--output <file>"}, description = "Place the output into <file>")
    private String output;
    @Parameter(names = {"-d", "--debug"}, description = "Display byte-code representation on output")
    private boolean debug;
    @Parameter(names = "--help", description = "Display this help and exit", help = true)
    private boolean help;
    @Parameter(names = "--version", description = "Displays version information and exit")
    private boolean version;

    public String getNamedOutput(String filename) {
        return Paths.get(getOutput(), getBasename(filename).concat("." + ClassFile.EXT)).toString();
    }

    public String getBasename(String filename) {
        final String name = new File(filename).getName();
        return name.substring(0, name.lastIndexOf('.'));
    }

    public String getOutput() {
        return output != null ? output : Paths.get(".").toAbsolutePath().normalize().toString();
    }

    public List<String> getFiles() {
        return files;
    }

    public boolean isDebug() {
        return debug;
    }

    public boolean isHelp() {
        return help;
    }

    public boolean isVersion() {
        return version;
    }
}
