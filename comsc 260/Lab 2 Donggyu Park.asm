;SP23 COMSC 260 5071 Lab 2 Donggyu Park

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
num1 dword 2
num2 dword 4
num3 dword 9
num4 dword 16
num5 dword 25
num6 dword 36
num7 dword 49
num8 dword 64
num9 dword 81
num10 dword 100

.code
main proc
    mov eax,0
    add eax,num1
    add eax,num2
    add eax,num3
    add eax,num4
    add eax,num5
    add eax,num6
    add eax,num7
    add eax,num8
    add eax,num9
    add eax,num10

    invoke ExitProcess,0
main endp
end main

