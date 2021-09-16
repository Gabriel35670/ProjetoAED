; sc.asm
; 
; Para compilar;
; $ nasm -f elf64 sc.asm && ld sc.o -o sc && rm -f sc.o
;
; * Registers on entry:
; * rax  system call number
; * rcx  return address
; * r11  saved rflags (note: r11 is callee-clobbered register in C ABI)
; * rdi  arg0
; * rsi  arg1
; * rdx  arg2
; * r10  arg3 (needs to be moved to rcx to conform to C ABI)
; * r8   arg4
; * r9   arg5
; * (note: r12-r15, rbp, rbx are callee-preserved in C ABI)
; *
; * Only called from user space.
; *
; * When user can change pt_regs->foo always force IRET. That is because
; * it deals with uncanonical addresses better. SYSRET has trouble
; * with them due to bugs in both AMD and Intel CPUs.
;
section .data
 msg     db      "Hello, world!", 0x0a   ; the string and newline char

section .text
   global _start       ; Default entry point for ELF linking

_start:

   ; SysCall: ssize_t write(int fd, const void *buf, size_t count);

   mov     rax, 1      ; código da syscall write (*) 
   mov     rdi, 1      ; arquivo 1 = STDOUT
   mov     rsi, msg    ; endereço da mensagem
   mov     rdx, 14     ; número de bytes a escrever
   syscall

   ; SysCall: void _exit(int status);

   mov    rax, 60       ; código da syscall _exit syscall (*)
   mov    rdi, 0        ; valor de retorno
   syscall

; (*) /usr/include/x86_64-linux-gnu/asm/unistd_64.h 
; #define __NR_write 1
; #define __NR_exit 60

