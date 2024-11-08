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
    a dd 11
    b db 4
    c dw 2
    x dq 1
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;(a+b/c-1)/(b+2)-x = (11+4/2-1)/(4+2)-1 = 12 /6 -1
        mov eax, 0
        mov al, [b]
        mov bx, [c]
        div bl ; 4/2
        
        
        mov ecx, [a]
        add eax, ecx
        sub eax, 1 ;eax = 12
        
        ;add eax, ecx
        mov edx, 0
        mov ebx, 0
        mov bl, [b] 
        add bl, 2
        
        div ebx
        
        mov ebx, [x]
        mov ecx, [x+4]
        
        sub eax, ebx
        sbb edx, ecx
        
        
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
