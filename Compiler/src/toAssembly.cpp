#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "toAssembly.hpp"

const char commands[] = "-+\\><`@(){}:$!?~";
const std::string assembly[] = 
{ 
                                "dec DWORD PTR [rbx+rcx]",
                                "inc DWORD PTR [rbx+rcx]",
                                "mov rax, DWORD PTR [rbx+rcx]\n idiv DWORD PTR [rbx+rcx+4]\nmov DWORD PTR [rbx+rcx], rax",
                                "add rcx, 4",
                                "sub rcx, 4",
                                "mov rax, DWORD PTR [rbx+rcx-4]\nmov rdi, DWORD PTR [rbx+rcx-8]\nmov rdi, DWORD PTR [rbx+rcx-12]\nmov rdx, DWORD PTR [rbx+rcx-16]",
                                "push rbx\npush rcx\nsyscall\npop rcx\npop rbx\nmov DWORD PTR [rbx+rcx], rax",
                                "je whileskip%i\nwhile%i:",
                                "jne while%i\nwhileskip%i:",
                                "je if%i", 
                                "ret",
                                "cmp DWORD PTR [rbx+rcx], DWORD PTR [rbx+rcx+4]",
                                "xor rax, rax\nxor rdi, rdi\nlea rsi, [rbx+rcx]\nmov rdx, 1\nsyscall",
                                "shl DWORD PTR [rbx+rcx], DWORD PTR [rbx+rcx+4]",
                                "shr DWORD PTR [rbx+rcx], DWORD PTR [rbx+rcx-4]",
                                "quicksegfault:\npush rax\npush rdi\npush rsi\npush rdx\npush rcx\npush rbx\npush rbp\npush rsp\njmp quicksegfault",
}
char headerP1[] = "section .data\nmemData: times 5000 dd 0\nsection .text\n.global %s\n";
char headerP2[] = "_%s:\nmov rbx, memData\n";

std::string fileToAssembly(std::string content)
{
    // First pass, gets the source code ready for further processing.
    std::string funcName;
    std::string preProcessed;
    std::string assemblyCode;
    int tmp = 0;
    while(content[tmp] =! '\n')
    {
        funcName += content[tmp];
        tmp++;
    }
    for(int i = 0; i < content.length(); i++)
    {
        bool isValid;
        for(int j = 0; j < 16; j++)
        {
            if(strcmp(content[i], commands[i]) == 0)
            {
                isValid = true;
                break;
            } 
        }
        if(isValid)
        {
            preProcessed += content[i];
        }
    }
    for(int i = 0; i < preProcessed.length(); i++)
    {
        assemblyCode += commandToAssembly(preProcessed[i]);
    }
}
std::string commandToAssembly(char command)
{
    for(int i = 0; i < 16; i++) if(strcmp(command, commands[i]) == 0) return assembly[i];
}