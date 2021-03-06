package bytecode;

import compiler.ArgoBaseVisitor;
import compiler.ArgoParser;
import org.antlr.v4.runtime.tree.ParseTree;

public class Generator extends ArgoBaseVisitor<ClassFile> {

	public static final int MAJOR_VERSION = 1;
	public static final int MINOR_VERSION = 0;

	private final ClassFile classFile;

	public Generator() {
		this.classFile = new ClassFile(MAJOR_VERSION, MINOR_VERSION);
	}

	@Override
	public ClassFile visitArgument(ArgoParser.ArgumentContext ctx) {
		// Get routine name
		final String name = ((ArgoParser.RoutineContext) ctx.parent.parent).label().name().getText();
		// Get instruction
		final String instruction = ((ArgoParser.InstructionContext) ctx.parent).opcode().getText();
		// Get routine data
		final Routine routine = this.classFile.getRoutinesTable().get(name);
		// Verify special case
		if(Opcode.valueOf(instruction) == Opcode.CLL) {
			// We need to translate identifier to address CLL instruction
			final String callee = ctx.name().getText();
			// Check for existence and add if necessary
			this.classFile.initRoutineIfAbsent(callee);
			// Add identifier
			routine.getData().add(this.classFile.getRoutinesTable().get(callee).getId());
		}else {
			// Add value
			routine.getData().add(Integer.parseInt(ctx.number().getText()));
		}
		// Keep going
		return super.visitArgument(ctx);
	}

	@Override
	public ClassFile visitInstruction(ArgoParser.InstructionContext ctx) {
		// Get routine name
		final String name = ((ArgoParser.RoutineContext) ctx.parent).label().name().getText();
		// Get routine data
		final Routine routine = this.classFile.getRoutinesTable().get(name);
		// Get instruction name
		final String instruction = ctx.opcode().getText();
		// Parse opcode and insert
		routine.getData().add(Opcode.mapToBytecode(instruction));
		// Keep going
		return super.visitInstruction(ctx);
	}

	@Override
	public ClassFile visitRoutine(ArgoParser.RoutineContext ctx) {
		// Identify routine name
		final String name = ctx.label().name().getText();
		// Insert into mapper
		this.classFile.initRoutineIfAbsent(name);
		// Keep going
		return super.visitRoutine(ctx);
	}

	@Override
	public ClassFile visit(ParseTree tree) {
		super.visit(tree);
		return this.classFile;
	}
}
