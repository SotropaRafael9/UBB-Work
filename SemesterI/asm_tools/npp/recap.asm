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
    a db 5
    b db 15
    c db 3
    d dw 1
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;3*[20*(b-a+2)-10*c]+2*(d-3)
        ;3*[20*(10-5+2)-10*3]+2*(1-3)
        
        mov bh, [b]
        mov ah, [a]
        sub bh, al
        add bh, 2
        mov ch, 20
        mul ch
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
