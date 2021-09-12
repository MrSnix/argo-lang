#ifndef ARGO_VM__TYPES_OPCODE_H
#define ARGO_VM__TYPES_OPCODE_H

typedef enum {
  HLT_ARGS = 0,
  PSH_ARGS = 1,
  POP_ARGS = 1,
  ADD_ARGS = 2,
  SUB_ARGS = 2,
  MUL_ARGS = 2,
  DIV_ARGS = 2,
  JMP_ARGS = 1,
  JME_ARGS = 1,
  JMN_ARGS = 1,
  JMG_ARGS = 1,
  JML_ARGS = 1,
  CMP_ARGS = 2,
  NOP_ARGS = 0
} OpCodeArgs;

typedef enum {
  HLT = 0,
  PSH = 1,
  POP = 2,
  ADD = 3,
  SUB = 4,
  MUL = 5,
  DIV = 6,
  JMP = 7,
  JME = 8,
  JMN = 9,
  JMG = 10,
  JML = 11,
  CMP = 12,
  NOP = 13
} OpCode;

#endif
