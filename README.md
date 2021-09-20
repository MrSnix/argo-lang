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
| CMP   | CMP         | Peeks the last two values from the stack, then set the CMP register to one of these values: (EQUALS, LESSER, GREATER) |
| JMP   | JMP, idx    | Jumps at given instruction index                                                                                      |
| JME   | JME, idx    | Jumps at given instruction index only if the CMP flag is set to EQUALS                                                |
| JMN   | JMN, idx    | Jumps at given instruction index only if the CMP flag is NOT set to EQUALS                                            |
| JMG   | JMG, idx    | Jumps at given instruction index only if the CMP flag is set to GREATER                                               |
| JML   | JML, idx    | Jumps at given instruction index only if the CMP flag is set to LESSER                                                |
| JEG   | JEG, idx    | Jumps at given instruction index only if the CMP flag is set to EQUALS or GREATER                                     |
| JEL   | JEL, idx    | Jumps at given instruction index only if the CMP flag is set to EQUALS or LESSER                                      |
| CLL   | CLL, idx    | Executes the given routine identifier                                                                                 |
| RET   | RET         | Routine specific instruction, it's used to terminate the current routine flow                                         |
| PRINT | PRINT       | Peeks the last value from the stack and print it.                                                                     |
