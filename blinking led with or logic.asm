ORG 0000H
SETB P0.1
SETB P0.2
SETB P0.3
LOOP:MOV C,P0.1
ORL C,P0.2
MOV P0.3,A
SJMP LOOP
