package bytecode;

public enum Opcode {

	HLT,
	NOP,
	PSH,
	POP,
	ADD,
	SUB,
	MUL,
	DIV,
	JMP,
	JME,
	JMN,
	JMG,
	JML,
	CMP,
	CLL,
	RET;

	static int mapToBytecode(String code) {
		return Opcode.valueOf(code).ordinal();
	}

}
