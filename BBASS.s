		
		STMFD	SP!, {LR,R4,R5,R6}
		MOV		R4, #0 	   ; x = 0
		MOV		R2, #0	   ;	array.base
		MOV		R1, #0x1F400 ; speed=128000
		MOV		R3, #array
		B		LOOP0
DONE0
		LDMFDEQ	sp!, {LR,R4,R5,R6}	;saco las cosas de la pila y las pongo en los registros
		;MOVEQ	PC,LR
		END
		
array	DCB		0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010 , 0b00000001
		
LOOP0
		CMP		R4, #8 	 ; x<8? check condition
		BGE		DONE0      ; if x >= 8 exit loop
		;init	LOOP
		MOV		R6, R4	   ; i = x
		B		LOOP1
DONE1
		MOV		R5, #7	   ; z = 7
		ADD		R4, R4, #2   ;CONTROL DE REBOTE
		B		LOOP2
DONE2
		;end.	LOOP
		B		LOOP0	  ; repeat loop
LOOP1
		CMP		R6, #8 	  ; i<8? check condition
		BGE		DONE1       ; if x >= 8 exit loop
		;init	LOOP
		LDRB		R0, [R3, R6]	;BL printBin, R0;
		;BL		sleep, R1;
		;end.	LOOP
		ADD		R6, R6, #1 ; i = i + 1
		B		LOOP1	 ; repeat loop
		
LOOP2
		
		CMP		R4, R5 	 ; i<8? check condition
		BGE		DONE2       ; if x >= 8 exit loop
		;init	LOOP
		LDRB		R0, [R3, R5]	;BL printBin, R0;
		;BL		sleep, R1;
		;end.	LOOP
		SUB		R5, R5, #1 ; z = z + 1
		B		LOOP2	   ; repeat loop
