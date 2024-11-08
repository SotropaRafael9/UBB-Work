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
    c dd 3h
    d dq 4h
    

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;c+d-a-b+(c-a) -sign  = 3+4-1-2+(3-1) = 6
        
        mov eax, [c]
        cdq
        mov ebx, [d]
        mov ecx, [d+4]
        
        add eax, ebx
        adc edx, ecx
        
        mov ebx, eax
        mov ecx, edx
        
        mov al, [a]
        cbw
        cwd
        cdq
        
        sub ebx, eax
        sbb ecx, edx
        
        mov ax, [b]
        cwd
        cdq
        
        add ebx, eax
        adc ecx, edx ;  c+d-a-b
        
        mov al, [a]
        cbw
        cwd
        
        mov ebx, [c]
        
        add eax, ebx
        cdq
        
        add ebx, eax
        adc ecx, edx
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
