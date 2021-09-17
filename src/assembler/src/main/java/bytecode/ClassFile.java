package bytecode;

import java.util.HashMap;
import java.util.TreeSet;

public final class ClassFile {

	public static final String EXT = "argoc";

	private final int majorVersion;
	private final int minorVersion;
	private final HashMap<String, Routine> routinesTable;

	public ClassFile(int majorVersion, int minorVersion) {
		this.majorVersion = majorVersion;
		this.minorVersion = minorVersion;
		this.routinesTable = new HashMap<>();
	}

	public int getMajorVersion() {
		return majorVersion;
	}

	public int getMinorVersion() {
		return minorVersion;
	}

	public HashMap<String, Routine> getRoutinesTable() {
		return routinesTable;
	}

	public TreeSet<Routine> getRoutines() {
		return new TreeSet<>(routinesTable.values());
	}

	@Override
	public String toString() {
		return "ClassFile{" +
				"majorVersion=" + majorVersion +
				", minorVersion=" + minorVersion +
				", routinesTable=" + routinesTable +
				'}';
	}
}
