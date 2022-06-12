BITS 64
SECTION .text
GLOBAL strcspn:function

;   size_t(*strcspn)(const char *str1, const char *str2);
;	RDI = *str1 (arg1) 
;	RSI = *str2 (arg2)
;	RCX = compteur / index pour RDI (arg1)
;   R9 = compteur / index pour RSI (arg2)
;	R8 = registre temp

strcspn:
    XOR RCX, RCX                    ;initialisation du registre RCX à 0 (index de RDI)
    XOR R8, R8                      ;initialisation du registre R8 à 0 (registre temp)

.loop:
    MOV AL, BYTE [RDI + RCX]        ;AL (registre 8 bit de R8) prend le char de str1
    CMP AL, 0                       ;check si on atteind la fin de str1
    JE .end                         ;si fin de la string alors on redirige vers end
    INC RCX                         ;RCX ++

.rdx
    XOR R9, R9                      ;initialisation du registre R9 à 0 (index de RSI)

.check:
    MOV R8B, BYTE [RSI + R9]        ;R8B = RSI + R9
    CMP R8B, 0                      ;check si on atteind la fin de str2
    JE .loop                        ;si fin de la string alors on redirige dans le label loop
    CMP AL, R8B                     ;comparaison de c1 et c2
    JE .end_same                    ;si c1 == C2 alors on redirige vers le label end_same
    INC R9                          ;R9 ++
    JMP .check                      ;on retourne dans le label tant que l'une des conditions n'est pas valide

.end_same:
    SUB RCX, 1                      ;RCX -= 1
    MOV RAX, RCX                    ;RAX = RCX
    RET                             ;return

.end:
    MOV RAX, RCX                    ;RAX = RCX
    RET                             ;return
