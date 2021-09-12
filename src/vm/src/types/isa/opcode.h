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
  NOP_ARGS = 0,
  CLL_ARGS = 1,
} OpCodeArgs;

typedef enum {
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
  CLL
} OpCode;

#endif
