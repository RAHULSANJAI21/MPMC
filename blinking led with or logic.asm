ORG 0000H
SETB P0.1;MAKING P0.1 AS INPUT
SETB P0.2;MAKING P0.2 AS INPUT
SETB P0.3;MAKING LED OFF
LOOP:MOV C,P0.1;COPYING  P0.1 TO CARRY
ORL C,P0.2;PERFORMING OR OPERATION WITH C AND P0.2
CPL C;COMPLIMENTING CARRY
MOV P0.3,C;COPYING CARRY TO P0.3
SJMP LOOP;JUMP TO LOOP
