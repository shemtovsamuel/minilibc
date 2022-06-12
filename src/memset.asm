BITS 64
SECTION .text
GLOBAL memset:function

;	void *memset(void *ptr, int value, size_t n)
;	RDI = *ptr (arg1)
;	SIL = value (arg2) (SIL = registre 8 bits de RSI)
;	RDX = n (arg3)
;	RCX = compteur / index

memset:
	XOR	RCX, RCX				;initialisation du registre RCX à 0 (compteur itération loop)
	MOV	RAX, RDI				;RAX prend la valeur de RDI (arg1)

.loop:
	CMP	RDX, RCX			 	;comparaison de l'index et de la size n
	JE	.end				  	;si index = size n alors on renvoie vers le label end 
	MOV	BYTE [RAX + RCX], SIL 	;arg1[index] = arg2
	INC	RCX						;incrémentation du registre RCX (compteur)
	JMP	.loop					;on retourne dans le label tant que RCX != RDX 

.end:
	RET
