package bytecode;

import java.util.HashMap;

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

	@Override
	public String toString() {
		return "ClassFile{" +
				"majorVersion=" + majorVersion +
				", minorVersion=" + minorVersion +
				", routinesTable=" + routinesTable +
				'}';
	}
}
