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
  NEG,
  SWP,
  JMP,
  JEQ,
  JNE,
  JMG,
  JML,
  JGE,
  JLE,
  CMP,
  CLL,
  RET,
  PRINT;

  static int mapToBytecode(String code) {
    return Opcode.valueOf(code).ordinal();
  }
}
