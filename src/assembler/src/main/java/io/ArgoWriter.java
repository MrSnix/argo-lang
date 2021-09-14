package io;

import bytecode.ClassFile;
import bytecode.Routine;

import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

public final class ArgoWriter {

	public static final int[] SIGNATURE = { 0x41, 0x52, 0x47, 0x4f, 0x3c, 0x33, 0x4b, 0x53 };

	public static void write(ClassFile classFile, String filename) throws IOException {

		try (FileOutputStream fos = new FileOutputStream(filename)) {
			// Write signature
			for (int i : SIGNATURE) { fos.write(i); }
			// Write version
			fos.write(classFile.getMajorVersion());
			fos.write(classFile.getMinorVersion());
			// Write routine table size
			fos.write(classFile.getRoutinesTable().size());
			// Write each routine
			for (Routine routine : classFile.getRoutinesTable().values()) {
				// Write id
				fos.write(routine.getId());
				// Write name size
				fos.write(routine.getName().getBytes(StandardCharsets.UTF_8).length);
				// Write actual name
				fos.write(routine.getName().getBytes(StandardCharsets.UTF_8));
				// Write instruction size
				fos.write(routine.getData().size());
				// Write instructions
				for (Integer data : routine.getData()) { fos.write(data); }
			}
		}

	}

}
