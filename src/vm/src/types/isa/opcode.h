#ifndef ARGO_VM__TYPES_OPCODE_H
#define ARGO_VM__TYPES_OPCODE_H

typedef enum {
  NO_ARGS,
  UNARY_ARGS,
  BINARY_ARGS,
} vm__code_args_t;

typedef enum {
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
  PRINT,
} vm__code_t;

#endif
