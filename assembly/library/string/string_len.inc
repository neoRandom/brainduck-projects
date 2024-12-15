%ifndef STRINGLIB_STRING_LEN
%define STRINGLIB_STRING_LEN


section .text

; ================================================================================================
; Counts the number of characters (bytes) on a null-terminated string
;
; TODO: Verify if the address is NULL and if the value pointed is NULL
; INPUT: RAX as a pointer to a null-terminated string
; OUTPUT: RAX as the length of the string
;
string_len:
    ; rax = address of the string
    ; rsp[0] = counter
    push 0

    .increment_counter:
    inc qword [rsp]         ; Increment the counter
    inc rax                 ; Increment the string pointer (move to the end)
    cmp byte [rax], 0       ; Compare the value of the character with 0
    jnz .increment_counter  ; If the value is not 0, jump to the loop label
    
    pop rax

    ret
;
; ================================================================================================


%endif
