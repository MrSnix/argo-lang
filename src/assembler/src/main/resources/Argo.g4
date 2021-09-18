grammar Argo;

prog
   : (line? EOL)+
   ;

line
   : comment
   | routine
   ;

routine
   : label OPEN_STMT EOL (instruction EOL)+ CLOSE_STMT
   ;

instruction
   : opcode (ARG_SEP argument)?
   ;

label
   : ID_DECL name
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
   : (H L T) | (N O P) | (P S H) | (P O P) | (A D D) | (S U B) | (M U L) | (D I V) | (J M P) | (J M E) | (J M N) | (J M G) | (J M L) | (J E G) | (J E L) | (C M P) | (C L L) | (R E T) | (P R I N T)
   ;

ARG_SEP
   : ','
   ;

ID_DECL
   : ':'
   ;

OPEN_STMT
   : '{'
   ;

CLOSE_STMT
   : '}'
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
   : [0-9]+
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
