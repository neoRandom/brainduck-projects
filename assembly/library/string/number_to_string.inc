%ifndef STRINGLIB_NUMBER_TO_STRING
%define STRINGLIB_NUMBER_TO_STRING


section .bss
    number_to_string_buffer resb 1024

section .text

; ================================================================================================
; Converts a number into a null-terminated string
; 
; TODO: Allocate memory on the heap to replace the use of a BSS buffer
; DEPENDENCIES: 'module' from 'mathlib', number_to_string_buffer (1024, bss)
; INPUT: RAX as the number to be converted
; OUTPUT: 
; - RAX as a pointer to the generated string
; - RCX as the size of the string
;
number_to_string:
    ; Initial values
    mov rcx, 10   ; Divisor
    mov r8, 0     ; Digit counter
    mov r9, 1024  ; Index counter
    mov r10, 0    ; String size counter

    ; Clear the buffer
    .clear_the_buffer:
        dec r9                                    ; Decrementing the counter
        mov byte [number_to_string_buffer+r9], 0  ; Cleaning the cell. Note: r9 starts at 1023, because the buffer is already at cell 1
        cmp r9, 0
        jnz .clear_the_buffer

    ; Test for negative numbers
    cmp rax, 0
    jge .not_negative

    ; If it's negative
    neg rax                                 ; Inverting the number
    mov byte [number_to_string_buffer], 45  ; Pushing the negative sign as the first character
    mov r10, 1                              ; Incrementing the string size counter

    .not_negative:
    ; Test for zero
    cmp rax, 0
    jnz .not_zero

    ; If it's zero
    mov byte [number_to_string_buffer], 48
    inc r10
    jmp .skip_if_zero

    .not_zero:
    ; Looping to add each digit of the RAX to the stack
    .add_digit_to_stack:         ; DO WHILE the value of RAX is greater than 0
        module                       ; RDX = RAX % RCX (10) and RAX /= RCX (10)
        push rdx                     ; Pushing the remainder (digit) to the stack
        inc r8                       ; Incrementing the counter
        cmp rax, 0
        jnz .add_digit_to_stack

    ; For each digit stored in the stack, convert into character and add it to the buffer
    .push_digit_to_buffer:
        pop rax                                     ; Removing the value from the stack and storing at RAX
        dec r8                                      ; Decrementing the digit counter
        add rax, 48                                 ; Converting the number to an ASCII character
        mov byte [number_to_string_buffer+r10], al  ; Storing the character in the buffer
        inc r10                                     ; Incrementing the string size counter
        cmp r8, 0
        jnz .push_digit_to_buffer

    .skip_if_zero:
    ; Adding a null character to the end of the string
    mov byte [number_to_string_buffer+r10], 0
    inc r10

    ; Setting RAX as the buffer
    mov rax, number_to_string_buffer
    mov rcx, r10

    ret
;
; ================================================================================================


%endif
