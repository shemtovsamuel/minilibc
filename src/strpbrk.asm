BITS 64
SECTION .text
GLOBAL strpbrk:function

;	char *my_strpbrk(const char *str1, const char *str2)
;	RDI = *str1 (arg1)
;   RSI = *str2 (arg2)
;	RCX = compteur / index pour RDI (arg1)
;   R9 = compteur / index pour RSI (arg2)
;	R8 = registre temp

strpbrk:
    XOR RCX, RCX                    ;initialisation du registre RCX à 0 (index de RDI)               
    XOR R8, R8                      ;initialisation du registre R8 à 0 (registre temp)

.check:
    MOV AL, BYTE [RDI + RCX]        ;AL (registre 8 bit de R8) prend le char de str1
    CMP AL, 0                       ;check si on atteind la fin de str1
    JE .not_found                   ;si fin de la string alors on redirige vers le label not_found
    INC RCX                         ;RCX ++

.rdx
    XOR R9, R9                      ;initialisation du registre R9 à 0 (index de RSI)

.loop:
    MOV R8B, BYTE [RSI + R9]        ;R8B = RSI + R9
    CMP R8B, 0                      ;check si on atteind la fin de str2
    JE .check                       ;si fin de la string alors on redirige dans le label check
    CMP R8B, AL                     ;comparaison de c1 et c2
    JE .find                        ;si c1 == C2 alors on redirige vers le label find
    INC R9                          ;R9 ++
    JMP .loop                       ;on retourne dans le label tant que l'une des conditions n'est pas valide

.find:
    SUB RCX, 1                      ;RCX -= 1
    ADD RDI, RCX                    ;RDI += RCX
    MOV RAX, RDI                    ;RAX = RDI
    RET                             ;return

.not_found:
    MOV RAX, 0                      ;RAX = 0
    RET                             ;return
