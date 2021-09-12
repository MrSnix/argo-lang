// [HEAD] Definitions
#include "../core/runtime.h"
// [IMPL] Headers
#include <stdio.h>
#include "../diagnostic/snapshots.h"
#include "../core/decoder.h"
#include "../core/instructions.h"

void vm__decode(VM *vm, int32_t instr)
{

  switch (instr)
  {
  case HLT:
    vm__dec_hlt(vm);
    break;
  case PSH:
    vm__dec_psh(vm);
    break;
  case POP:
    vm__dec_pop(vm);
    break;
  case ADD:
    vm__dec_add(vm);
    break;
  case SUB:
    vm__dec_sub(vm);
    break;
  case MUL:
    vm__dec_mul(vm);
    break;
  case DIV:
    vm__dec_div(vm);
    break;
  case JMP:
    vm__dec_jmp(vm);
    break;
  case JME:
    vm__dec_jme(vm);
    break;
  case JMN:
    vm__dec_jmn(vm);
    break;
  case JMG:
    vm__dec_jmg(vm);
    break;
  case JML:
    vm__dec_jml(vm);
    break;
  case CMP:
    vm__dec_cmp(vm);
    break;
  case NOP:
    vm__dec_nop(vm);
    break;
  case CLL:
    vm__dec_cll(vm);
    break;
  default:
    printf("Cannot decode unknown instruction: %d", instr);
    break;
  }

}

void vm__execute(VM *vm)
{

  bool increase_ip = true;

  switch (vm->op->id)
  {
  case HLT:
    increase_ip = vm__exc_hlt(vm);
    break;
  case PSH:
    vm__exc_psh(vm);
    break;
  case POP:
    vm__exc_pop(vm);
    break;
  case ADD:
    vm__exc_add(vm);
    break;
  case SUB:
    vm__exc_sub(vm);
    break;
  case MUL:
    vm__exc_mul(vm);
    break;
  case DIV:
    vm__exc_div(vm);
    break;
  case JMP:
    increase_ip = vm__exc_jmp(vm);
    break;
  case JME:
    increase_ip = vm__exc_jme(vm);
    break;
  case JMN:
    increase_ip = vm__exc_jmn(vm);
    break;
  case JMG:
    increase_ip = vm__exc_jmg(vm);
    break;
  case JML:
    increase_ip = vm__exc_jml(vm);
    break;
  case CMP:
    vm__exc_cmp(vm);
    break;
  case NOP:
    break;
  case CLL:
    vm__exc_cll(vm);
    break;
  default:
    printf("Cannot execute instruction: %d", vm->op->id);
    break;
  }

  // Increment instruction for next iteration
  if (increase_ip) vm__increase_ip(vm);

}

void vm__increase_ip(VM *vm) { vm->ip += 1; }
void vm__decrease_ip(VM *vm) { vm->ip -= 1; }
void vm__set_ip(VM *vm, int32_t addr) { vm->ip = addr; }
int32_t vm__current_ip(VM *vm) { return vm->ip; }

int32_t vm__fetch(VM *vm) { return vm->bytecode[vm->ip]; }
int32_t vm__fetch_peek(VM *vm, int32_t offset) { return vm->bytecode[vm->ip + offset]; }
int32_t vm__fetch_next(VM *vm){ vm__increase_ip(vm); return vm->bytecode[vm->ip]; }
