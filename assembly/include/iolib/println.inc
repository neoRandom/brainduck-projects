%ifndef IOLIB_PRINTLN
%define IOLIB_PRINTLN


; ================================================================
; Wrapper of the SYS_WRITE, also prints a LF (20) at the end
;
; PARAMETERS:
; 1 - Pointer of the content to write
; 2 - Size of the content
; 
%macro println 2
    mov rax, SYS_WRITE
    mov rdi, STDOUT
    mov rsi, %1
    mov rdx, %2
    syscall

    push 10

    mov rax, SYS_WRITE
    mov rdi, STDOUT
    mov rsi, rsp
    mov rdx, 1
    syscall

    pop rax
    xor rax, rax
%endmacro
;
; ================================================================


%endif
