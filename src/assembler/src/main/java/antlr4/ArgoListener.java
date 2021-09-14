package antlr4;

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ArgoParser}.
 */
public interface ArgoListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ArgoParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(ArgoParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(ArgoParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArgoParser#line}.
	 * @param ctx the parse tree
	 */
	void enterLine(ArgoParser.LineContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#line}.
	 * @param ctx the parse tree
	 */
	void exitLine(ArgoParser.LineContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArgoParser#routine}.
	 * @param ctx the parse tree
	 */
	void enterRoutine(ArgoParser.RoutineContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#routine}.
	 * @param ctx the parse tree
	 */
	void exitRoutine(ArgoParser.RoutineContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArgoParser#instruction}.
	 * @param ctx the parse tree
	 */
	void enterInstruction(ArgoParser.InstructionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#instruction}.
	 * @param ctx the parse tree
	 */
	void exitInstruction(ArgoParser.InstructionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArgoParser#label}.
	 * @param ctx the parse tree
	 */
	void enterLabel(ArgoParser.LabelContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#label}.
	 * @param ctx the parse tree
	 */
	void exitLabel(ArgoParser.LabelContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArgoParser#argument}.
	 * @param ctx the parse tree
	 */
	void enterArgument(ArgoParser.ArgumentContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#argument}.
	 * @param ctx the parse tree
	 */
	void exitArgument(ArgoParser.ArgumentContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArgoParser#opcode}.
	 * @param ctx the parse tree
	 */
	void enterOpcode(ArgoParser.OpcodeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#opcode}.
	 * @param ctx the parse tree
	 */
	void exitOpcode(ArgoParser.OpcodeContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArgoParser#name}.
	 * @param ctx the parse tree
	 */
	void enterName(ArgoParser.NameContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#name}.
	 * @param ctx the parse tree
	 */
	void exitName(ArgoParser.NameContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArgoParser#string}.
	 * @param ctx the parse tree
	 */
	void enterString(ArgoParser.StringContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#string}.
	 * @param ctx the parse tree
	 */
	void exitString(ArgoParser.StringContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArgoParser#number}.
	 * @param ctx the parse tree
	 */
	void enterNumber(ArgoParser.NumberContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#number}.
	 * @param ctx the parse tree
	 */
	void exitNumber(ArgoParser.NumberContext ctx);
	/**
	 * Enter a parse tree produced by {@link ArgoParser#comment}.
	 * @param ctx the parse tree
	 */
	void enterComment(ArgoParser.CommentContext ctx);
	/**
	 * Exit a parse tree produced by {@link ArgoParser#comment}.
	 * @param ctx the parse tree
	 */
	void exitComment(ArgoParser.CommentContext ctx);
}