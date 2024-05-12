bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern fopen, fclose, fread, fwrite, perror
import fclose msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fwrite msvcrt.dll
import perror msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_descriptor_file_we_read_from dd -1
    file_descriptor_file_we_write_to dd -1
    item dd 0
    file_we_read_from db "read_file.txt", 0
    read_mode db 'r', 0
    file_we_write_to "write_file.txt", 0
    write_mode db 'w', 0
    error_message db "error", 0
    
    
segment code use32 class=code
    start:
        ; ...
        push read_mode
        push file_we_read_from
        call [fopen]
        add esp, 4*2 
        
        cmp eax, 0
        je end_1
        ;store the file descriptor in another place because eax is always used for smth else
        mov [file_descriptor_file_we_read_from], eax 
        
        ;now we open the file to write in
        push write_mode
        push file_we_write_to
        call [fopen]
        add esp, 4*2; eax=file_descriptor_file_we_write_to
        
        cmp eax, 0
        je end_2  ;uita-te pe c code de ce sarim altundeva
        mov [file_descriptor_file_we_write_to], eax 
        
        read_loop:
            push dword [file_descriptor_file_we_read_from]
            push dword 1 ;size of one char, size of one item you read
            push dword 1 ;we read one byte at a time, so one char (the size of one char is a byte), how many items we read
            push item    ;citim fiecare item din fisier in "item", ca sa ii dam increase (dam increase la fiecare byte)
            call [fread]
            add esp, 4*4
            
            cmp eax, 0 ;?why, poate cand nu mai are ce sa citeasca
            je out_of_loop 
            mov item, 5
            
            push dword [file_descriptor_file_we_write_to]
            push dword 1
            push dword 1
            push item
            call [fwrite]
            add esp, 4*4
            jmp read_loop
            
         out_of_loop:   
            push dword [file_descriptor_file_we_write_to]
            call [fclose]
            add esp, 4
        end_2:
         push dword error_message
            call [perror]
            add esp, 4
            
            push dword [file_descriptor_file_we_read_from]
            call [fclose]
            add esp, 4
            
            jmp no_error
         end_1:
            push dword error_message
            call [perror]
            add esp, 4
            
         no_error:
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program

            
            
            
        
        
    
        ; exit(0)