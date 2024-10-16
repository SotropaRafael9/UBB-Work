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
    ;(d+d-b)+(c-a)+d
    a db 2
    b db 5
    c db 4
    d db 3
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax, 0
        mov al, [d]
        mov bl, [d] ; d = 1
        add al, bl ; al = 1+1
        mov ah, [b] ; ah = b
        sub al, ah ; al = (d+d)-b
        mov cl, [c] ; cl = c
        mov ch, [a] ;ch= a
        sub cl, ch ; c-a
        add al, cl ; ((d+d)-b) + (c-a) 
        add al, bl
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
