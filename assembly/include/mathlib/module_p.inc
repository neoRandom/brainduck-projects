%ifndef MATHLIB_MODULE_P
%define MATHLIB_MODULE_P


; ================================================================
; Performs the MOD(ule) operation with parameters
;
; PARAMETERS:
; 1 - Dividend
; 2 - Divisor
; OUTPUT:
; - RAX as the quotient
; - RDX as the remainder
;
%macro module_p 2
    mov rax, %1
    mov rcx, %2
    mov rdx, 0
    div rcx
%endmacro
;
; ================================================================


%endif
