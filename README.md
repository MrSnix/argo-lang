# Argo

ArgoVM is a stack-based virtual machine similar to JVM.  

It runs the file provided by ArgoC (Argo Compiler) which transform the _argo-lang_ into an executable byte-code format.

### Instruction Set

|  OP   |    Usage    |                                                       Function                                                        |
|-------|-------------|-----------------------------------------------------------------------------------------------------------------------|
| HLT   | HLT         | Terminate the program                                                                                                 |
| NOP   | NOP         | Nothing                                                                                                               |
| PSH   | PSH, value  | Pushes value on the stack                                                                                             |
| POP   | POP         | Pops value from stack                                                                                                 |
| ADD   | ADD         | Pops the last two values from the stack, it sums then push the result                                                 |
| SUB   | SUB         | Pops the last two values from the stack, it subtracts then push the result                                            |
| MUL   | MUL         | Pops the last two values from the stack, it multiplies then push the result                                           |
| DIV   | DIV         | Pops the last two values from the stack, it divides then push the results (value and rest)                            |
| NEG   | NEG         | Pops the last value from the stack, it negate then push the results                                                   |
| SWP   | SWP         | Pops the last two values from the stack, it swap them then push the result on the stack                               |
| CMP   | CMP         | Peeks the last two values from the stack, then set the CMP register to one of these values: (EQUALS, LESSER, GREATER) |
| JMP   | JMP, idx    | Jumps at given instruction index                                                                                      |
| JEQ   | JEQ, idx    | Jumps at given instruction index only if the CMP flag is set to EQUALS                                                |
| JNE   | JNE, idx    | Jumps at given instruction index only if the CMP flag is NOT set to EQUALS                                            |
| JMG   | JMG, idx    | Jumps at given instruction index only if the CMP flag is set to GREATER                                               |
| JML   | JML, idx    | Jumps at given instruction index only if the CMP flag is set to LESSER                                                |
| JGE   | JGE, idx    | Jumps at given instruction index only if the CMP flag is set to EQUALS or GREATER                                     |
| JLE   | JLE, idx    | Jumps at given instruction index only if the CMP flag is set to EQUALS or LESSER                                      |
| CLL   | CLL, idx    | Executes the given routine identifier                                                                                 |
| RET   | RET         | Routine specific instruction, it's used to terminate the current routine flow                                         |
| PRINT | PRINT       | Peeks the last value from the stack and print it.                                                                     |

### Grammar

#### Basics
Let's see some syntax in action

```
# sum.argo
#
# Define the main function (entry point)

:main {
    PSH, 5
    PSH, 4
    ADD
    PRINT
    HLT
}
```
#### Iteration

You can reproduce any conditional-structure you like with the following instructions

```
# iterate.argo
#
# function main() {
#   for(var i = 0; i <= 100; ++i) {
#     print(i); 
#   }
# }
#

:main {
  PSH, 1
  PRINT
  PSH, 1
  ADD
  PSH, 100 
  CMP
  POP
  JLE, 2
  HLT
}
```
#### Routines

Splitting the code workflow among other calls, arguments should be pushed on stack before calling the function meanwhile the return address is managed automatically.

```
# The following .argo equals to this code:
# 
# function printer(var x){
#   print(x);
# }
#
# function sum(var a, var b) {
#   return a + b;
# }
#
# function main() {
#   printer(sum(5, 4));
#   return;
# }
#

:main {
    PSH, 5
    PSH, 4 
    CLL, sum 
    HLT
}

:sum {
    ADD
    CLL, printer
    RET
}

:printer {
    PRINT
    RET
}
```

### The workflow

This is how its expected to work at the end of development:

`Argonauts (Lang) -> Argo (ASM) ->  Bytecode (ArgoCode) -> ArgoVM`

Currently there is no `Argonauts` lang, I'm still working on `Argo`.

## Project

### Structure

The current ArgoVM is written in C meanwhile the compiler ArgoC is written using Java, some additionals dev-tools are made in Perl.

```
src
|
|-- assembler  # The ArgoC  home directory
|-- vm         # The ArgoVM home directory

```

TODO ...
