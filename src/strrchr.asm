BITS 64
SECTION .text
GLOBAL strrchr:function

;	char *strrchr(const char *str, int c);
;	RDI = *str 
;	SIL = c

strrchr:
    MOV RAX, RDI                ;RAX prend la valeur de RDI (str)

.my_strlen:
    CMP BYTE [RAX], 0           ;check si on atteind la fin de la string     
    JE .loop                    ;si fin de la string alors on redirige vers loop
    INC RAX                     ;RAX ++
    JMP .my_strlen              ;on retourne dans le label tant que la condition n'est pas valide

.loop:
    CMP BYTE [RAX], SIL         ;check si str == c 
    JE .end                     ;si str == c alors on renvoie vers le label end
    DEC RAX                     ;RAX --
    CMP BYTE [RAX], 0           ;check si on atteind la fin de la string
    JE .end_not_found           ;si fin de la string alors on redirige vers end_not_found
    JMP .loop                   ;on retourne dans le label tant que l'une des conditions n'est pas valide

.end_not_found:
    XOR RAX, RAX                ;RAX -> nullptr
    JMP .end                    ;renvoie vers le label end

.end:
	RET
