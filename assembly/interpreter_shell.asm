; ++++++++++++++++++++++++++++++++++++++++++++++++.

%include "include/essential.inc"
%include "include/iolib/println.inc"
%include "include/iolib/print.inc"
%include "include/iolib/input.inc"

section .data
    title_label db "Brainfuck Interpreter Shell (Assembly x86_64 Linux/Unix Version) | 'e' or '0' to exit", 10
    input_label db "> ", 0
    data_size equ 32768

section .bss
    code resb data_size
    data resb data_size

section .text
    global _start

_start:
    println title_label, 86

    .main_loop:
        print input_label, 2   ; Printing the initial label
        input code, data_size  ; Receiving the code as input

        cmp byte [code], '0'
        jz .exit
        cmp byte [code], 'e'
        jz .exit

        ; Cleaning the data buffer
        mov rax, data_size
        mov rcx, 8
        mov rdx, 0
        div rcx
        mov rcx, rax        ; Number of qwords to write (32768 bytes / 8 bytes per qword)
        mov rdi, data       ; Destination address (start of the array)
        xor rax, rax        ; Value to fill (0 in this case)
        rep stosq           ; Fill the memory with zero

        mov r15, 0  ; Instruction pointer
        mov r14, 0  ; Data pointer

        sub rsp, 8  ; Growing the stack

        mov qword r15, 0  

        .read_instruction:
            mov rax, [code+r15]  ; Operation value
            mov [rsp], rax
            call _operator

            inc r15
            cmp byte [code+r15], NULL
            jnz .read_instruction
        
        add rsp, 8  ; Shrinking the stack

        push 10
        print rsp, 1
        pop rax

        jmp .main_loop
    
    .exit:
        exit 0

; PARAMETERS:
; +8 - Operator value
_operator:
    ; Jump Table
    cmp byte [rsp+8], 43
    je .inc_cell
    cmp byte [rsp+8], 46
    je .print_cell
    jmp .exit

    .inc_cell:
        inc byte [data+r14]

        jmp .exit

    .print_cell:
        mov rcx, data
        add rcx, r14
        print rcx, 1

        jmp .exit
    
    .exit:
        ret
