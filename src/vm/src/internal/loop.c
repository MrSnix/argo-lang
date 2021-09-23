// [HEAD] Definitions
#include "../core/runtime.h"
// [IMPL] Headers
#include <stdio.h>

#include "../core/decoder.h"
#include "../core/instructions.h"
#include "../diagnostic/snapshots.h"

void vm__decode(vm_t *vm, int32_t instr) {
  switch (instr) {
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
    case NEG:
      vm__dec_neg(vm);
      break;
    case SWP:
      vm__dec_swp(vm);
      break;
    case JMP:
      vm__dec_jmp(vm);
      break;
    case JEQ:
      vm__dec_jeq(vm);
      break;
    case JNE:
      vm__dec_jne(vm);
      break;
    case JMG:
      vm__dec_jmg(vm);
      break;
    case JML:
      vm__dec_jml(vm);
      break;
    case JGE:
      vm__dec_jge(vm);
      break;
    case JLE:
      vm__dec_jle(vm);
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
    case RET:
      vm__dec_ret(vm);
      break;
    case PRINT:
      vm__dec_print(vm);
      break;
    default:
      printf("Cannot decode unknown instruction: %d", instr);
      break;
  }
}

void vm__execute(vm_t *vm) {
  // Flag to incrase the ip
  vm__set_increase_ip(vm, true);

  switch (vm->op->id) {
    case HLT:
      vm__exc_hlt(vm);
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
    case NEG:
      vm__exc_neg(vm);
      break;
    case SWP:
      vm__exc_swp(vm);
      break;
    case JMP:
      vm__exc_jmp(vm);
      break;
    case JEQ:
      vm__exc_jeq(vm);
      break;
    case JNE:
      vm__exc_jne(vm);
      break;
    case JMG:
      vm__exc_jmg(vm);
      break;
    case JML:
      vm__exc_jml(vm);
      break;
    case JGE:
      vm__exc_jge(vm);
      break;
    case JLE:
      vm__exc_jle(vm);
      break;
    case CMP:
      vm__exc_cmp(vm);
      break;
    case NOP:
      break;
    case CLL:
      vm__exc_cll(vm);
      break;
    case RET:
      vm__exc_ret(vm);
      break;
    case PRINT:
      vm__exc_print(vm);
      break;
    default:
      printf("Cannot execute instruction: %d", vm->op->id);
      break;
  }

  // Increment instruction for next iteration
  vm__safe_increase_ip(vm);
}

void vm__safe_increase_ip(vm_t *vm) {
  if (vm->fetch_next) vm->bc->main->ip += 1;
}
void vm__set_running(vm_t *vm, bool running) { vm->running = running; }
void vm__set_increase_ip(vm_t *vm, bool fetch_next) { vm->fetch_next = fetch_next; }
void vm__set_ip(vm_t *vm, int32_t addr) { vm->bc->main->ip = addr; }

int32_t vm__current_ip(vm_t *vm) { return vm->bc->main->ip; }
int32_t vm__fetch(vm_t *vm) { return vm->bc->main->data[vm->bc->main->ip]; }
int32_t vm__fetch_peek(vm_t *vm, int32_t offset) { return vm->bc->main->data[vm->bc->main->ip + offset]; }
int32_t vm__fetch_next(vm_t *vm) { return vm->bc->main->data[++vm->bc->main->ip]; }
