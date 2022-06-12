BITS 64
SECTION .text
GLOBAL strncmp:function

;	int strncmp(const char *str1, const char *str2, size_t n);
;	RDI = str1 
;	RSI = str2
;   RDX = n
;   RCX = compteur

strncmp:
	XOR RAX, RAX				;initialisation R9 à 0 -> get le char de str1
	XOR R8, R8				;initialisation R8 à 0 -> get le char de str2
    XOR RCX, RCX            ;initialisation du registre RCX à 0 (compteur itération loop) 

.loop:
	MOV AL, BYTE [RDI]		;AL (registre 8 bit de R9) prend le char de str1
	MOV R8B, BYTE [RSI]		;R8B (registre 8 bit de R8) prend le char de str2
    CMP RCX, RDX            ;check if compteur == n
    JE .return_zero         ;Si compteur == n on redirige vers return_zero
    CMP BYTE [RDI], 0		;check si on atteind la fin de la str1
	JE .end					;si fin de la string alors on redirige vers end
	CMP BYTE [RSI], 0		;check si on atteind la fin de la str2
	JE .end					;si fin de la string alors on redirige vers end
	CMP AL, R8B			;comparaison des deux char -> if c1 != c2
	JNE .end				;JNE = if not equal, on redirige vers end
	INC RSI					;RSI ++
	INC RDI					;RDI ++
	INC RCX                 ;RCX ++ (compteur itération)
    JMP .loop				;on retourne dans le label tant que l'une des conditions n'est pas valide

.return_zero
	MOV RAX, 0
	RET

.end:
	SUB AL, R8B				;R9 = R9 - R8
	MOVSX RAX, AL			;RAX prend la valeur de AL
	RET
