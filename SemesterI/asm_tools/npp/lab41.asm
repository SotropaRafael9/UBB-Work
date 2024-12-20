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
    a dw 0100110001001100b
    b dw 1010101010101011b
    c dw 0000111100001111b
    d dw 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;izolate bits(1-5) and save them in bx
        mov ax, [a]
        shr ax, 1
        and ax, 0000000000011111b 
        mov bx, ax ; 10
        
        ;load word B in ax the bits(6-10)
        mov ax, [b]
        shr ax, 6
        and ax, 0000000000011111b
        add bx, ax ;
        
        ;same for C (11-15)
        mov ax, [c]
        shr ax, 11
        and ax, 0000000000011111b
        add bx, ax
        
        
        
        mov [d], bx
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
