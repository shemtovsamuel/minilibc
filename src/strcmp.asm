BITS 64
SECTION .text
GLOBAL strcmp:function

;	int strcmp(const char *str1, const char *str2);
;	RDI = str1 (arg1)
;	RSI = str2 (arg2)

strcmp:
	XOR RAX, RAX				;initialisation R9 à 0 -> get le char de str1
	XOR R8, R8				;initialisation R8 à 0 -> get le char de str2

.loop:
	MOV AL, BYTE [RDI]		;AL (registre 8 bit de R9) prend le char de str1
	MOV R8B, BYTE [RSI]		;R8B (registre 8 bit de R8) prend le char de str2
    CMP BYTE [RDI], 0		;check si on atteind la fin de la str1
	JE .end					;si fin de la string alors on redirige vers end
	CMP BYTE [RSI], 0		;check si on atteind la fin de la str2
	JE .end					;si fin de la string alors on redirige vers end
	CMP AL, R8B			;comparaison des deux char -> if c1 != c2
	JNE .end				;JNE = if not equal, on redirige vers end
	INC RSI					;RSI ++
	INC RDI					;RDI ++
	JMP .loop				;on retourne dans le label tant que l'une des conditions n'est pas valide

.end:
	SUB AL, R8B				;R9 = R9 - R8
	MOVSX RAX, AL				;RAX prend la valeur de R9
	RET
