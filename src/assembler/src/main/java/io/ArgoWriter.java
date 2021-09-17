package io;

import at.favre.lib.bytes.Bytes;
import bytecode.ClassFile;
import bytecode.Routine;

import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

public final class ArgoWriter {

	public static final byte[] SIGNATURE = { 0x41, 0x52, 0x47, 0x4f, 0x3c, 0x33, 0x4b, 0x53 };

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
		for (byte i : SIGNATURE) { fos.write(i); }
	}

	private void version(FileOutputStream fos) throws IOException {
		fos.write(asLittleEndian(classFile.getMajorVersion(), 2));
		fos.write(asLittleEndian(classFile.getMinorVersion(), 2));
	}

	private void routine(FileOutputStream fos, Routine routine) throws IOException {
		// Write id
		fos.write(asLittleEndian(routine.getId(), 2));
		// Write name size
		fos.write(asLittleEndian(routine.getName().length(), 1));
		// Write actual name
		fos.write(routine.getName().getBytes(StandardCharsets.UTF_8));
		// Write instruction size
		fos.write(asLittleEndian(routine.getData().size()));
		// Write instructions
		for (Integer data : routine.getData()) { fos.write(asLittleEndian(data)); }
	}

	private void table(FileOutputStream fos) throws IOException {
		// Write routine table size
		fos.write(asLittleEndian(classFile.getRoutinesTable().size(), 2));
		// Write each routine
		for (Routine rtn : classFile.getRoutines()) {
			routine(fos, rtn);
		}
	}

	private byte[] asLittleEndian(int raw, int bytes){
		return Bytes.from(raw).resize(bytes).reverse().array();
	}

	private byte[] asLittleEndian(int raw){
		return Bytes.from(raw).reverse().array();
	}

}
