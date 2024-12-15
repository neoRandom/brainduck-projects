%ifndef MMRLIB_MEMSET
%define MMRLIB_MEMSET


; ================================================================
; Sets a whole block of memory with a certain value
;
; PARAMETERS:
; 1 - Value to fill
; 2 - Pointer of the array
; 3 - Size in qwords
%macro memset 3
    mov rax, %1
    mov rdi, %2
    mov rcx, %3
    rep stosq
%endmacro
;
; ================================================================


%endif
