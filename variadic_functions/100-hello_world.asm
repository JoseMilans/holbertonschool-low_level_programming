section .data
    hello db 'Hello, World', 0Ah ; 'Hello, World' string ending with newline
    helloLen equ $ - hello ; length of 'Hello, World' string

section .text
    global main

main:
    ; sys_write syscall
    mov eax, 1 ; system call number (sys_write)
    mov edi, 1 ; file descriptor (stdout)
    mov rsi, hello ; pointer to message to write
    mov rdx, helloLen ; message length
    syscall ; call kernel

    ; sys_exit syscall
    mov eax, 60 ; system call number (sys_exit)
    xor edi, edi ; exit code
    syscall ; call kernel

