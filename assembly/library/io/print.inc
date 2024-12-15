%ifndef IOLIB_PRINT
%define IOLIB_PRINT


; ================================================================
; Wrapper of the (private) function __print
;
; PARAMETERS:
; 1 - Pointer of the content to write
; 
%macro print 1
    ; Setting the parameters
    push %1
    call __print
    pop rax
%endmacro
;
; ================================================================


; ================================================================
; Prints a null-terminated string
;
; DEPENDENCIES: 'string_len' from 'stringlib'
; PARAMETERS:
; 1 - Pointer of the content to write
; 
__print:
    ; Getting the size of the string
    mov rax, [rsp+8]
    call string_len
    mov r8, rax

    ; Printing the string
    sys_write STDOUT, [rsp+8], r8

    ret
;
; ================================================================


%endif
