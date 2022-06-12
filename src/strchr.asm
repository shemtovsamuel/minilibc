BITS 64
SECTION .text
GLOBAL strchr:function

;	char *strchr(const char *str, int c);
;	RDI = *str 
;	SIL = c

strchr:
    MOV RAX, RDI                ;RAX prend la valeur de RDI (str)

.loop:
    CMP BYTE [RAX], SIL         ;check si str == c 
    JE .end                     ;si str == c alors on renvoie vers le label end
    CMP BYTE [RAX], 0           ;check si on atteind la fin de la string
    JE .end_not_found           ;si fin de la string alors on redirige vers end_not_found
    INC RAX                     ;RAX ++
    JMP .loop                   ;on retourne dans le label tant que l'une des conditions n'est pas valide

.end_not_found:
    XOR RAX, RAX                ;RAX -> nullptr
    JMP .end                    ;renvoie vers le label end

.end:
	RET
