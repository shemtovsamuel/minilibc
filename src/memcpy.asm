BITS 64
SECTION .text
GLOBAL memcpy:function

;   void *memcpy(void *dest, const void *src, size_t n);
;	RDI = *dest (arg1) 
;	RSI = *src (arg2)
;	RDX = n (arg3)
;	RCX = compteur / index
;	R8B = registre temp (R8B = registre 8 bits de R8)

memcpy:
	XOR	RCX, RCX 				;initialisation du registre RCX à 0 (compteur itération loop)
	MOV	RAX, RDI				;RAX prend la valeur de RDI (dest)

.loop:
	CMP	RDX, RCX				;comparaison de l'index et de la size n
	JE	.end					;si index = size n alors on renvoie vers le label end 
	MOV	R8B, BYTE [RSI + RCX] 	;R8B prend la valeur de src[index]  
	MOV	BYTE [RAX + RCX], R8B 	;la valeur de dest[index] = R8B
	INC	RCX						;incrémentation du registre RCX (compteur)
	JMP	.loop					;on retourne dans le label tant que RCX != RDX 

.end:
	RET
