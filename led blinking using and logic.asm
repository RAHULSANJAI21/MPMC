ORG 0000H
SETB P0.1;MAKING P0.1
SETB P0.2;MAKING P0.2 
SETB P0.3;MAKING P0.3 
CLR C;CLEAR CARRY
LOOP:MOV C,P0.1;COPYING P0.1 TO CARRY
ANL C,P0.2;PERFORMING AND OPERATION BETWEEN C AND P0.2
CPL C;COMPLEMENTING CARRY
MOV P0.3,C;COPYING C TO P0.3
SJMP LOOP;JUMPING TO LOOP

