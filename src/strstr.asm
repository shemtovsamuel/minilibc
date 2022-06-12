BITS 64
SECTION .text
GLOBAL strstr:function

;	char *strstr(const char *str1, const char *str2);
;	RDI = *str1 (arg1) 
;	RSI = *str2 (arg2)
;	RCX = compteur / index
;	R8B = registre temp (R8B = registre 8 bits de R8)

strstr:
	XOR RCX, RCX					;initialisation du registre RCX à 0 (index)
	XOR R8, R8						;initialisation du registre R8 à 0
	JMP .loop						;redirige vers loop

.check:
	CMP R8B, 0						;check si on atteind la fin de str1
	JE .not_found					;si fin de str1 alors on redirige vers not_found
	INC RDI							;else RDI ++

.loop:
	CMP BYTE [RSI + RCX], 0			;check si on atteind la fin de str2
	JE .find						;si fin de str2 alors on redirige vers find
	MOV R8B, BYTE [RDI + RCX]		;R8B prend le char de str1
	CMP R8B, BYTE [RSI + RCX]		;comparaison des deux char
	JNE .check						;if c1 == c2 -> on redirige vers check
	INC RCX							;RCX ++
	JMP .loop						;on retourne dans le label tant que l'une des conditions n'est pas valide

.find:
	MOV RAX, RDI					;RAX prend la valeur de RDI (str1)
	JMP .end						;redirige vers end

.not_found:
	XOR RAX, RAX					;RAX = 0
	JMP .end						;redirige vers end

.end:
	RET
