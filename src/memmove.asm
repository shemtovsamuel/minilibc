BITS 64
SECTION .text
GLOBAL memmove:function

;   void *memmove(void *dest, const void *src, size_t n);
;	RDI = *dest (arg1) 
;	RSI = *src (arg2)
;	RDX = n (arg3)
;	RCX = compteur / index
;	R8 = registre temp

memmove:
    XOR RCX, RCX                ;initialisation du compteur RCX à 0
    XOR R8, R8                  ;initialisation du registre R8 à 0
    MOV	RAX, RDI				;RAX prend la valeur de RDI (dest)
    CMP RDI, RSI                ;comparaison de RDI et RSI
    JG .check                   ;RDI > RSI
    JE .end                     ;RDI == RSI
    JL .memcpy                  ;RDI < RSI

.check:                         ;SI RDI > RSI
    MOV RCX, RDX                ;RCX = RDX
    DEC RCX                     ;RCX--
    JMP .loop_memmove           ;on redirige vers le label loop_memmove

.loop_memmove:
    CMP RCX, 0                  ;comparaison de RCX et 0
    JL .end                     ;RCX < 0 on redirige vers end
    MOV	R8B, BYTE [RSI + RCX]   ;R8B prend la valeur de src[index]  
    MOV	BYTE [RDI + RCX], R8B   ;la valeur de dest[index] = R8B
    DEC	RCX                     ;incrémentation du registre RCX (compteur)
    JMP	.loop_memmove           ;on retourne dans le label tant que RCX != RDX 

.memcpy:
    CMP	RDX, RCX                ;comparaison de l'index et de la size n
    JE	.end                    ;si index = size n alors on renvoie vers le label end 
    MOV	R8B, BYTE [RSI + RCX]   ;R8B prend la valeur de src[index]  
    MOV	BYTE [RDI + RCX], R8B   ;la valeur de dest[index] = R8B
    INC	RCX                     ;incrémentation du registre RCX (compteur)
    JMP	.memcpy                 ;on retourne dans le label tant que RCX != RDX 

.end:
    RET                         ;return
