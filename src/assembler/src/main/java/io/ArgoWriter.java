package io;

import at.favre.lib.bytes.Bytes;
import bytecode.ClassFile;
import bytecode.Routine;

import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

public final class ArgoWriter {

	public static final int[] SIGNATURE = { 0x41, 0x52, 0x47, 0x4f, 0x3c, 0x33, 0x4b, 0x53 };

	private final ClassFile classFile;

	public ArgoWriter(ClassFile classFile) {
		this.classFile = classFile;
	}

	public void write(String filename) throws IOException {

		try (FileOutputStream fos = new FileOutputStream(filename)) {
			// Write signature
			signature(fos);
			// Write version
			version(fos);
			// Write routine table
			table(fos);
		}

	}

	private void signature(FileOutputStream fos) throws IOException {
		for (int i : SIGNATURE) { fos.write(i); }
	}

	private void version(FileOutputStream fos) throws IOException {
		fos.write(Bytes.from(classFile.getMajorVersion()).resize(2).array());
		fos.write(Bytes.from(classFile.getMinorVersion()).resize(2).array());
	}

	private void routine(FileOutputStream fos, Routine routine) throws IOException {
		// Write id
		fos.write(Bytes.from(routine.getId()).resize(2).array());
		// Write name size
		fos.write(routine.getName().getBytes(StandardCharsets.UTF_8).length);
		// Write actual name
		fos.write(routine.getName().getBytes(StandardCharsets.UTF_8));
		// Write instruction size
		fos.write(routine.getData().size());
		// Write instructions
		for (Integer data : routine.getData()) { fos.write(data); }
	}

	private void table(FileOutputStream fos) throws IOException {
		// Write routine table size
		fos.write(Bytes.from(classFile.getRoutinesTable().size()).resize(2).array());
		// Write each routine
		for (Routine rtn : classFile.getRoutinesTable().values()) {
			routine(fos, rtn);
		}
	}


}
