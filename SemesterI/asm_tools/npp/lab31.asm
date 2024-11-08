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
    a db 1h
    b dw 2h
    c dd 5h 
    d dq 3h
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;(c+c-a)-(d+d)-b = (5+5-1)-(3+3)-2 =  ;unsigned

        mov eax, [c]
        mov ebx, [c]
        add eax, ebx
        
        mov ecx, 0
        mov cl, [a]
        
        sub eax, ecx
        
        push eax
        
        mov eax, [d]
        mov ebx, [d+4]
        mov ecx, [d]
        mov edx, [d+4]
        
        add eax, ecx
        adc ebx, edx
        
        
        
        mov ecx, eax
        mov ebx, edx
        
        pop eax ;c+c-a
        
        mov edx, 0
        
        sub eax, ecx
        sbb ebx, edx
        
        mov ecx, 0
        mov cx, [b]
        mov edx, 0
        
        sub eax, ecx
        sbb ebx, edx
        
        
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
