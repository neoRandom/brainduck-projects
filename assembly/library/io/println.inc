%ifndef IOLIB_PRINTLN
%define IOLIB_PRINTLN


; ================================================================
; Wrapper of the (private) function __println
;
; PARAMETERS:
; 1 - Pointer of the content to write
; 
%macro println 1
    ; Setting the parameters
    push %1
    call __println
    pop rax
%endmacro
;
; ================================================================


; ================================================================
; Is like __print, but also prints a LF (20) at the end
;
; DEPENDENCIES: 'string_len' from 'stringlib'
; PARAMETERS:
; 1 - Pointer of the content to write
; 
__println:
    ; Getting the size of the string
    mov rax, [rsp+8]
    call string_len
    mov r8, rax

    ; Printing the string
    sys_write STDOUT, [rsp+8], r8

    ; Printing the new line
    push 10
    sys_write STDOUT, rsp, 1
    pop rax

    ret
;
; ================================================================


%endif
