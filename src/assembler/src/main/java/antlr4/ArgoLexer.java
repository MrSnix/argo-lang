package antlr4;

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ArgoLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		OPCODE=1, ARG_SEP=2, ID_DECL=3, OPEN_STMT=4, CLOSE_STMT=5, NAME=6, NUMBER=7, 
		COMMENT=8, STRING=9, EOL=10, WS=11;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"OPCODE", "ARG_SEP", "ID_DECL", "OPEN_STMT", "CLOSE_STMT", "A", "B", 
			"C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", 
			"Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "NAME", "NUMBER", "COMMENT", 
			"STRING", "EOL", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, "','", "':'", "'{'", "'}'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "OPCODE", "ARG_SEP", "ID_DECL", "OPEN_STMT", "CLOSE_STMT", "NAME", 
			"NUMBER", "COMMENT", "STRING", "EOL", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public ArgoLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Argo.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\r\u00f2\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\5\2\u008e\n\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b"+
		"\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20"+
		"\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\25\3\25\3\26\3\26\3\27"+
		"\3\27\3\30\3\30\3\31\3\31\3\32\3\32\3\33\3\33\3\34\3\34\3\35\3\35\3\36"+
		"\3\36\3\37\3\37\3 \3 \3!\3!\7!\u00ce\n!\f!\16!\u00d1\13!\3\"\6\"\u00d4"+
		"\n\"\r\"\16\"\u00d5\3#\3#\7#\u00da\n#\f#\16#\u00dd\13#\3#\3#\3$\3$\7$"+
		"\u00e3\n$\f$\16$\u00e6\13$\3$\3$\3%\6%\u00eb\n%\r%\16%\u00ec\3&\3&\3&"+
		"\3&\2\2\'\3\3\5\4\7\5\t\6\13\7\r\2\17\2\21\2\23\2\25\2\27\2\31\2\33\2"+
		"\35\2\37\2!\2#\2%\2\'\2)\2+\2-\2/\2\61\2\63\2\65\2\67\29\2;\2=\2?\2A\b"+
		"C\tE\nG\13I\fK\r\3\2\"\4\2CCcc\4\2DDdd\4\2EEee\4\2FFff\4\2GGgg\4\2HHh"+
		"h\4\2IIii\4\2JJjj\4\2KKkk\4\2LLll\4\2MMmm\4\2NNnn\4\2OOoo\4\2PPpp\4\2"+
		"QQqq\4\2RRrr\4\2SSss\4\2TTtt\4\2UUuu\4\2VVvv\4\2WWww\4\2XXxx\4\2YYyy\4"+
		"\2ZZzz\4\2[[{{\4\2\\\\||\4\2C\\c|\7\2$$\60\60\62;C\\c|\3\2\62;\4\2\f\f"+
		"\17\17\3\2$$\4\2\13\13\"\"\2\u00eb\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2"+
		"\2\t\3\2\2\2\2\13\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2"+
		"\2I\3\2\2\2\2K\3\2\2\2\3\u008d\3\2\2\2\5\u008f\3\2\2\2\7\u0091\3\2\2\2"+
		"\t\u0093\3\2\2\2\13\u0095\3\2\2\2\r\u0097\3\2\2\2\17\u0099\3\2\2\2\21"+
		"\u009b\3\2\2\2\23\u009d\3\2\2\2\25\u009f\3\2\2\2\27\u00a1\3\2\2\2\31\u00a3"+
		"\3\2\2\2\33\u00a5\3\2\2\2\35\u00a7\3\2\2\2\37\u00a9\3\2\2\2!\u00ab\3\2"+
		"\2\2#\u00ad\3\2\2\2%\u00af\3\2\2\2\'\u00b1\3\2\2\2)\u00b3\3\2\2\2+\u00b5"+
		"\3\2\2\2-\u00b7\3\2\2\2/\u00b9\3\2\2\2\61\u00bb\3\2\2\2\63\u00bd\3\2\2"+
		"\2\65\u00bf\3\2\2\2\67\u00c1\3\2\2\29\u00c3\3\2\2\2;\u00c5\3\2\2\2=\u00c7"+
		"\3\2\2\2?\u00c9\3\2\2\2A\u00cb\3\2\2\2C\u00d3\3\2\2\2E\u00d7\3\2\2\2G"+
		"\u00e0\3\2\2\2I\u00ea\3\2\2\2K\u00ee\3\2\2\2MN\5\33\16\2NO\5#\22\2OP\5"+
		"\63\32\2P\u008e\3\2\2\2QR\5\'\24\2RS\5)\25\2ST\5+\26\2T\u008e\3\2\2\2"+
		"UV\5+\26\2VW\5\61\31\2WX\5\33\16\2X\u008e\3\2\2\2YZ\5+\26\2Z[\5)\25\2"+
		"[\\\5+\26\2\\\u008e\3\2\2\2]^\5\r\7\2^_\5\23\n\2_`\5\23\n\2`\u008e\3\2"+
		"\2\2ab\5\61\31\2bc\5\65\33\2cd\5\17\b\2d\u008e\3\2\2\2ef\5%\23\2fg\5\65"+
		"\33\2gh\5#\22\2h\u008e\3\2\2\2ij\5\23\n\2jk\5\35\17\2kl\5\67\34\2l\u008e"+
		"\3\2\2\2mn\5\37\20\2no\5%\23\2op\5+\26\2p\u008e\3\2\2\2qr\5\37\20\2rs"+
		"\5%\23\2st\5\25\13\2t\u008e\3\2\2\2uv\5\37\20\2vw\5%\23\2wx\5\'\24\2x"+
		"\u008e\3\2\2\2yz\5\37\20\2z{\5%\23\2{|\5\31\r\2|\u008e\3\2\2\2}~\5\37"+
		"\20\2~\177\5%\23\2\177\u0080\5#\22\2\u0080\u008e\3\2\2\2\u0081\u0082\5"+
		"\21\t\2\u0082\u0083\5%\23\2\u0083\u0084\5+\26\2\u0084\u008e\3\2\2\2\u0085"+
		"\u0086\5\21\t\2\u0086\u0087\5#\22\2\u0087\u0088\5#\22\2\u0088\u008e\3"+
		"\2\2\2\u0089\u008a\5/\30\2\u008a\u008b\5\25\13\2\u008b\u008c\5\63\32\2"+
		"\u008c\u008e\3\2\2\2\u008dM\3\2\2\2\u008dQ\3\2\2\2\u008dU\3\2\2\2\u008d"+
		"Y\3\2\2\2\u008d]\3\2\2\2\u008da\3\2\2\2\u008de\3\2\2\2\u008di\3\2\2\2"+
		"\u008dm\3\2\2\2\u008dq\3\2\2\2\u008du\3\2\2\2\u008dy\3\2\2\2\u008d}\3"+
		"\2\2\2\u008d\u0081\3\2\2\2\u008d\u0085\3\2\2\2\u008d\u0089\3\2\2\2\u008e"+
		"\4\3\2\2\2\u008f\u0090\7.\2\2\u0090\6\3\2\2\2\u0091\u0092\7<\2\2\u0092"+
		"\b\3\2\2\2\u0093\u0094\7}\2\2\u0094\n\3\2\2\2\u0095\u0096\7\177\2\2\u0096"+
		"\f\3\2\2\2\u0097\u0098\t\2\2\2\u0098\16\3\2\2\2\u0099\u009a\t\3\2\2\u009a"+
		"\20\3\2\2\2\u009b\u009c\t\4\2\2\u009c\22\3\2\2\2\u009d\u009e\t\5\2\2\u009e"+
		"\24\3\2\2\2\u009f\u00a0\t\6\2\2\u00a0\26\3\2\2\2\u00a1\u00a2\t\7\2\2\u00a2"+
		"\30\3\2\2\2\u00a3\u00a4\t\b\2\2\u00a4\32\3\2\2\2\u00a5\u00a6\t\t\2\2\u00a6"+
		"\34\3\2\2\2\u00a7\u00a8\t\n\2\2\u00a8\36\3\2\2\2\u00a9\u00aa\t\13\2\2"+
		"\u00aa \3\2\2\2\u00ab\u00ac\t\f\2\2\u00ac\"\3\2\2\2\u00ad\u00ae\t\r\2"+
		"\2\u00ae$\3\2\2\2\u00af\u00b0\t\16\2\2\u00b0&\3\2\2\2\u00b1\u00b2\t\17"+
		"\2\2\u00b2(\3\2\2\2\u00b3\u00b4\t\20\2\2\u00b4*\3\2\2\2\u00b5\u00b6\t"+
		"\21\2\2\u00b6,\3\2\2\2\u00b7\u00b8\t\22\2\2\u00b8.\3\2\2\2\u00b9\u00ba"+
		"\t\23\2\2\u00ba\60\3\2\2\2\u00bb\u00bc\t\24\2\2\u00bc\62\3\2\2\2\u00bd"+
		"\u00be\t\25\2\2\u00be\64\3\2\2\2\u00bf\u00c0\t\26\2\2\u00c0\66\3\2\2\2"+
		"\u00c1\u00c2\t\27\2\2\u00c28\3\2\2\2\u00c3\u00c4\t\30\2\2\u00c4:\3\2\2"+
		"\2\u00c5\u00c6\t\31\2\2\u00c6<\3\2\2\2\u00c7\u00c8\t\32\2\2\u00c8>\3\2"+
		"\2\2\u00c9\u00ca\t\33\2\2\u00ca@\3\2\2\2\u00cb\u00cf\t\34\2\2\u00cc\u00ce"+
		"\t\35\2\2\u00cd\u00cc\3\2\2\2\u00ce\u00d1\3\2\2\2\u00cf\u00cd\3\2\2\2"+
		"\u00cf\u00d0\3\2\2\2\u00d0B\3\2\2\2\u00d1\u00cf\3\2\2\2\u00d2\u00d4\t"+
		"\36\2\2\u00d3\u00d2\3\2\2\2\u00d4\u00d5\3\2\2\2\u00d5\u00d3\3\2\2\2\u00d5"+
		"\u00d6\3\2\2\2\u00d6D\3\2\2\2\u00d7\u00db\7%\2\2\u00d8\u00da\n\37\2\2"+
		"\u00d9\u00d8\3\2\2\2\u00da\u00dd\3\2\2\2\u00db\u00d9\3\2\2\2\u00db\u00dc"+
		"\3\2\2\2\u00dc\u00de\3\2\2\2\u00dd\u00db\3\2\2\2\u00de\u00df\b#\2\2\u00df"+
		"F\3\2\2\2\u00e0\u00e4\7$\2\2\u00e1\u00e3\n \2\2\u00e2\u00e1\3\2\2\2\u00e3"+
		"\u00e6\3\2\2\2\u00e4\u00e2\3\2\2\2\u00e4\u00e5\3\2\2\2\u00e5\u00e7\3\2"+
		"\2\2\u00e6\u00e4\3\2\2\2\u00e7\u00e8\7$\2\2\u00e8H\3\2\2\2\u00e9\u00eb"+
		"\t\37\2\2\u00ea\u00e9\3\2\2\2\u00eb\u00ec\3\2\2\2\u00ec\u00ea\3\2\2\2"+
		"\u00ec\u00ed\3\2\2\2\u00edJ\3\2\2\2\u00ee\u00ef\t!\2\2\u00ef\u00f0\3\2"+
		"\2\2\u00f0\u00f1\b&\2\2\u00f1L\3\2\2\2\t\2\u008d\u00cf\u00d5\u00db\u00e4"+
		"\u00ec\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}