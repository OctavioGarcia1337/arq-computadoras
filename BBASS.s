.BB: R0 =X, R1=sum       -- Declaran variables del for
  MOV R1, #0               
  MOV R0, #0
  LDR R6, = array        -- Guarda array en R6

  FOR 
    CMP R0, #8           -- Checkea condicion
    BGE DONE             -- Si no la cumple sale
    ADD R1, R1, R0       -- sum = sum+i
    ADD R0, R0, #2       -- i=i+2


    R2 = z, R3 = sum2    -- Declaran variables del segundo for
    MOV R2, #0               
    MOV R3, #0
    
    R4 =i, R5 = sum3     -- Declaran variables del for
    MOV R4, R0             
    MOV R5, #0
    
    FOR 
      CMP R0, R2         -- Checkea condicion
      BGE DONE           -- Si no la cumple sale
      ADD R3, R3, R2     -- sum2 = sum2+z
      ADD R2, R2, #1     -- z++
      LDR R7, [R6, R4]   -- Guarda en R7 la secuencia final
	  LDI     dly1,   8 	
      B FOR 
    DONE
    FOR 
      CMP R4, #8         -- Checkea condicion
      BGE DONE           -- Si no la cumple sale
      ADD R5, R5, R4     -- sum3 = sum3 + i
      SUB R4, R4, #1     -- i--
	  LDR R7, [R6, R2]
      LDI     dly1,   8 
      B FOR 
    DONE
    B FOR 
  DONE

.array:
      .byte 0x80
      .byte 0x40
      .byte 0x20
	  .byte 0x10
	  .byte 0x08
	  .byte 0x04
	  .byte 0x02
	  .byte 0x01  
.end