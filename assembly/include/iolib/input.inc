%ifndef IOLIB_INPUT
%define IOLIB_INPUT


; ================================================================
; Wrapper of the SYS_READ
;
; PARAMETERS:
; 1 - Buffer to receive the input
; 2 - Size of the buffer in bytes
;
%macro input 2
    mov rax, SYS_READ
    mov rdi, STDIN
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro
;
; ================================================================


%endif
