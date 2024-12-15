%ifndef IOLIB_PUT
%define IOLIB_PUT


; ================================================================
; Wrapper of the (private) function __put
;
; PARAMETERS:
; 1 - Value of the character (ASCII) to display
; 
%macro put 1
    ; Setting the parameters
    push %1
    call __put
    pop rax
%endmacro
;
; ================================================================


; ================================================================
; Prints single character based on its value
;
; PARAMETERS:
; 1 - Value of the character (ASCII) to display
; 
__put:
    ; Printing the string
    mov r8, rsp
    add r8, 8
    sys_write STDOUT, r8, 1

    ret
;
; ================================================================


%endif
