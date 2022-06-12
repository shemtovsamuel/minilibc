BITS 64
SECTION .text
GLOBAL strcasecmp:function

;   int strcasecmp(const char *str1, const char *str2);
;   RDI = str1 (arg1)
;   RSI = str2 (arg2)
;   R8B = registre temp (R8B = registre 8 bits de R8)
;   AL = registre temp (AL = registre 8 bits de RAX)

strcasecmp:
    XOR RAX, RAX                  ;initialisation RAX à 0 -> get le char de str1
    XOR R8, R8                  ;initialisation R8 à 0 -> get le char de str2

.loop:
    MOV AL, BYTE [RDI]         ;AL prend le char de str1
    MOV R8B, BYTE [RSI]         ;R8B prend le char de str2
    CMP BYTE [RDI], 0           ;check si on atteind la fin de la str1
    JE .end                     ;si fin de la string alors on redirige vers end
    CMP BYTE [RSI], 0           ;check si on atteind la fin de la str2
    JE .end                     ;si fin de la string alors on redirige vers end

.check_AL:                     ;si AL est en majuscule on le convertie en minuscule
    CMP AL, 'A'                ;comparaison AL et 'A' (65)
    JL .check_R8B               ;if AL < 'A' -> redirige vers le prochain check
    CMP AL, 'Z'                ;comparaison AL et 'Z' (90)
    JG .check_R8B               ;if AL > 'Z' -> redirige vers le prochain check
    ADD AL, 32                 ;sinon AL += 32 (pour convertir en minuscule)

.check_R8B:                     ;si R8B est en majuscule on le convertie en minuscule
    CMP R8B, 'A'                ;comparaison R8B et 'A' (65)
    JL .compare                 ;if R8B < 'A' -> redirige vers le label compare
    CMP R8B, 'Z'                ;comparaison R8B et 'Z' (90)
    JG .compare                 ;if R8B > 'Z' -> redirige vers le label compare
    ADD R8B, 32                 ;sinon R8B += 32 (pour convertir en minuscule)

.compare:
    CMP R8B, AL                ;comparaison des deux chars
    JNE .end                    ;if R8B != AL redirige vers le label end
    INC RDI                     ;RDI ++
    INC RSI                     ;RSI ++
    JMP .loop                   ;retourne dans le label loop

.end:
    SUB AL, R8B                  ;RAX = RAX - R8
    MOVSX RAX, AL                 ;RAX prend la valeur de RAX
    RET
