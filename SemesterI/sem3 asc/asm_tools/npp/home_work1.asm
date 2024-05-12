bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;a,b,c,d-byte, e,f,g,h-word
    ;a*d*e/(f-5)
    a db 5
    d db 10
    e dw 4
    f dw 6
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ax, [a]
        mov bx, [d]
        mul bx ; 50:16=32h
        mov dx, [e]
        mul dx; 200 : 16 =C8
        mov ecx, [f]
        sub ecx, 5
        div ecx
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
