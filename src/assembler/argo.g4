grammar argo;

prog
   : (routine EOL) +
   ;

routine
   : ':' label '{' instruction+ '}'
   ;

instruction
   : opcode (',' argument)?
   ;

label
   : name
   ;

argument
   : number
   | string
   | name
   ;

opcode
   : OPCODE
   ;

name
   : NAME
   ;

string
   : STRING
   ;

number
   : NUMBER
   ;

comment
   : COMMENT
   ;

OPCODE
   : (H L T) | (N O P) | (P S H) | (P O P) | (A D D) | (S U B) | (M U L) | (D I V) | (J M P) | (J M E) | (J M N) | (J M G) | (J M L) | (C M P) | (C L L) | (R E T)
   ;

fragment A
   : ('a' | 'A')
   ;

fragment B
   : ('b' | 'B')
   ;

fragment C
   : ('c' | 'C')
   ;

fragment D
   : ('d' | 'D')
   ;

fragment E
   : ('e' | 'E')
   ;

fragment F
   : ('f' | 'F')
   ;

fragment G
   : ('g' | 'G')
   ;

fragment H
   : ('h' | 'H')
   ;

fragment I
   : ('i' | 'I')
   ;

fragment J
   : ('j' | 'J')
   ;

fragment K
   : ('k' | 'K')
   ;

fragment L
   : ('l' | 'L')
   ;

fragment M
   : ('m' | 'M')
   ;

fragment N
   : ('n' | 'N')
   ;

fragment O
   : ('o' | 'O')
   ;

fragment P
   : ('p' | 'P')
   ;

fragment Q
   : ('q' | 'Q')
   ;

fragment R
   : ('r' | 'R')
   ;

fragment S
   : ('s' | 'S')
   ;

fragment T
   : ('t' | 'T')
   ;

fragment U
   : ('u' | 'U')
   ;

fragment V
   : ('v' | 'V')
   ;

fragment W
   : ('w' | 'W')
   ;

fragment X
   : ('x' | 'X')
   ;

fragment Y
   : ('y' | 'Y')
   ;

fragment Z
   : ('z' | 'Z')
   ;

NAME
   : [a-zA-Z] [a-zA-Z0-9."]*
   ;
NUMBER
   : '$'? [0-9a-fA-F] +
   ;
COMMENT
   : '#' ~ [\r\n]* -> skip
   ;
STRING
   : '"' ~ ["]* '"'
   ;
EOL
   : [\r\n] +
   ;
WS
   : [ \t] -> skip
   ;