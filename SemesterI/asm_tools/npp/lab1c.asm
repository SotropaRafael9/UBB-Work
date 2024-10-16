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
    ;[100-10*a+4*(b+c)]-d = 100-70+12 = 42-3 = 39  = 0010 0111 = 27
    a db 7
    b db 1
    c db 2
    d dw 3
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov al, [b]
        mov ah, [c]
        add al, ah ; b+c
        mov bl, 4
        mul bl
        
        mov dx, ax
        
        mov al, 0
        mov al, [a]
        mov cl, 10
        mul cl ; ax=a*10
        
        mov bx, 0
        mov bx, 100
        sub bx, ax
        
        add bx, dx
        
        mov ax, 0
        mov ax, [d]
        
        sub bx,ax
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
