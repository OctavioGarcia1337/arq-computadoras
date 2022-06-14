			STMFD	SP!, {LR,R4,R5,R6,R7}
			MOV		R4, #0        ; v = 0
			MOV		R1, #0x1F400 ; speed=128000
			B		LOOPV
DONEV
			LDMFDEQ	SP!, {LR,R4,R5,R6,R7}   ;saco las cosas de la pila y las pongo en los registros
			;MOVEQ	PC,LR
			END
			
LOOPV
			CMP		R4, #6      	 ; v<6? check condition
			BGE		DONEV     	 ; if v >= 6 exit loop
			;init	LOOP
			MOV		R3, #0b10000000 ; Se resetea R3/printer
			MOV		R7, R3		 ; R7 = R3 (10000000)
			MOV		R5, #0		 ; R5 = 0
			
CONTARGENTE
			CMP		R5, R4       ; x<v? check condition
			BGE		CONTAR
			LSR		R7, R7, #1   ; 10000000 >> 01000000...
			ADD		R3, R7, R3   ; R3(11000000)=R7(01000000) + R3(10000000)VARIABLE
			
			ADD		R5, R5, #1   ; x = x + 1
			B		CONTARGENTE
			
CONTAR
			MOV		R6, #0       ; z = 0
			B		LOOPX
DONEX
			
			ADD		R4, R4, #1   ; v = v + 1
			;end.	LOOP
			B		LOOPV        ; repeat loop
			
			
			
LOOPX
			CMP		R6, #7       ; z<7? check condition
			BGE		DONEX        ; z >= 7 exit loop
			;BL		sleep, R1;
			;end.	LOOP
			LSR		R3, R3, #1   ; R3(11000000)VAR >> R3(01100000)
			ADD		R6, R6, #1   ; z = z + 1
			B		LOOPX        ; repeat loop
