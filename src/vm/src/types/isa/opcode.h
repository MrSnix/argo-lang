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
  NEG_ARGS = 1,
  JMP_ARGS = 1,
  JEQ_ARGS = 1,
  JNE_ARGS = 1,
  JMG_ARGS = 1,
  JML_ARGS = 1,
  JLE_ARGS = 1,
  JGE_ARGS = 1,
  CMP_ARGS = 2,
  NOP_ARGS = 0,
  CLL_ARGS = 1,
  RET_ARGS = 1,
  PRINT_ARGS = 1,
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
