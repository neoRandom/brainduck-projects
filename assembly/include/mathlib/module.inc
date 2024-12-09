%ifndef MATHLIB_MODULE
%define MATHLIB_MODULE


; ================================================================
; Performs the MOD(ule) operation
;
; NOTE: The values of RAX and RCX needs to be pre-defined
; OUTPUT:
; - RAX as the quotient
; - RDX as the remainder
;
%macro module 0
    mov rdx, 0
    div rcx
%endmacro
;
; ================================================================


%endif
