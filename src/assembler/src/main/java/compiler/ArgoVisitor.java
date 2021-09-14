package compiler;

import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link ArgoParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface ArgoVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link ArgoParser#prog}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProg(ArgoParser.ProgContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArgoParser#line}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLine(ArgoParser.LineContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArgoParser#routine}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRoutine(ArgoParser.RoutineContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArgoParser#instruction}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInstruction(ArgoParser.InstructionContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArgoParser#label}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLabel(ArgoParser.LabelContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArgoParser#argument}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArgument(ArgoParser.ArgumentContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArgoParser#opcode}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOpcode(ArgoParser.OpcodeContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArgoParser#name}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitName(ArgoParser.NameContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArgoParser#string}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitString(ArgoParser.StringContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArgoParser#number}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumber(ArgoParser.NumberContext ctx);
	/**
	 * Visit a parse tree produced by {@link ArgoParser#comment}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComment(ArgoParser.CommentContext ctx);
}