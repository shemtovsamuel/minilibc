BITS 64
SECTION .text
GLOBAL strlen:function

strlen:
    XOR RCX, RCX                ;initialisation du registre RCX à 0 (compteur itération loop)
    MOV RAX, RDI                ;RAX prend la valeur de RDI (str)

.loop:
    CMP BYTE[RAX + RCX], 0      ;check si on atteind la fin de la string
    JE .end                     ;si fin de la string alors on redirige vers end
    INC RCX                     ;RCX ++
    JMP .loop                   ;retourne dans le label loop tant que la condition n'est pas valide

.end:
    MOV RAX, RCX                ;RAX prend la valeur de RCX
    RET
