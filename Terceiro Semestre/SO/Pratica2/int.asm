; int.asm
;
; Para compilar: 
; $ nasm -f elf64 int.asm && ld int.o -o int && rm -f int.o
;
; * Arguments:
; * eax  system call number
; * ebx  arg1
; * ecx  arg2
; * edx  arg3
; * esi  arg4
; * edi  arg5      
; * ebp  arg6
;
; Depois da chamada, valor de retorno é colocado em eax. 
   
section .data       ; data segment
   msg     db      "Salve mano brown, tudo bom cntg?", 0x0a  ; the string and newline char

section .text       ; text segment
   global _start    ; Default entry point for ELF linking
   
_start:    
   ; SysCall: ssize_t write(int fd, const void *buf, size_t count);
   mov eax, 4        ; eax: número da syscall (*)e
   mov ebx, 1        ; ebx: primeiro argumento: fd (1 = STDOUT)
   mov ecx, msg      ; ecx: buff
   mov edx, 33       ; edx: count (tamanho da string)
   int 0x80          ; sycall via int 0x80
   
   ; SysCall: void _exit(int status);
   mov eax, 1        ; eax: número da syscall (*)
   mov ebx, 0        ; ebx: código de saída (0 = EXIT_SUCCESS)
   int 0x80          ; syscall via int 0x80
   
; (*) /usr/include/x86_64-linux-gnu/asm/unistd_32.h 
; #define __NR_exit 1

