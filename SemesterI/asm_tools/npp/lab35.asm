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
    a db 1
    b db 1
    c db 1
    e dd 0
    x dq 14
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;x-(a*b*25+c*3)/(a+b)+e; 29-(1*2*25+3*1)/(4)+4=29-(+3)/3+4=  33-32+4 = 5
        mov al, [a]
        mov bl, [b]
        mul bl
        
        mov cl, 25
        mul cl ;ax = a*b*25
        
        push ax
        
        mov bl, [c]
        mov cl, 3
        mul cl
        
        mov dx, ax
        
        pop ax
        
        add ax, dx ;(a*b*25+c*3)
        
        mov bl, [a]
        mov cl, [b]
        add bl, cl
        
        div bl ;ax=(a*b*25+c*3)/(a+b)
        
        mov bx, ax
        
        mov eax, 0
        mov edx, 0
        mov ax, bx
        
        mov ebx, [x]
        mov ecx, [x+4]
        
        sub ebx, eax
        sbb ecx, edx
        
        mov eax, [e]
        
        add ebx, eax
        
        
        
        
        
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
