%ifndef IOLIB_PRINT
%define IOLIB_PRINT


; ================================================================
; Wrapper of the SYS_WRITE
;
; PARAMETERS
; 1 - Pointer of the content to write
; 2 - Size of the content
; 
%macro print 2
    mov rax, SYS_WRITE
    mov rdi, STDOUT
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro
;
; ================================================================


%endif
