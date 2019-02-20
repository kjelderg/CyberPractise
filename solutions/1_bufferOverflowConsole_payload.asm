BITS 64
sys_execve equ 59

;xor eax,eax ; clear eax
;push eax ; NULL
;push 0x68732f2f6e69622f ; /bin//sh
;mov ebx, esp ; ebx holds /bin/sh
;push eax
;mov edx, esp
;mov ecx, esp
;int 0x80

section .data
	child db "/bin/sh", 0

global _start

section .text
	_start:
mov rax, sys_execve ; prepare syscall
mov rdi, child ; FILE
mov rsi, 0 ; ARGV
mov rdx, 0 ; ENVP
syscall
