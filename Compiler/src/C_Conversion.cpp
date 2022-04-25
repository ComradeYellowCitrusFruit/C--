#include <string>
#include <cstdlib>
#include <cstdio>
#include "C_Conversion.hpp"

char commands[] = { '-', '+', '*', '\\', '>', '<', '(', ')', '{', '}', '@', '$', '!', '?', '~', 'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F' };

std::string c_commands[] =
{
    "ptr[offset]--;",
    "ptr[offset]++;",
    "ptr[offset] *= ptr[offset+1];",
    "ptr[offset] = ptr[offset]/ptr[offset+1];",
    "offset++;",
    "offset--;",
    "while(ptr[offset] != 0){",
    "}",
    "if(ptr[offset] == 0){",
    "}",
    "putchar(ptr[offset]);",
    "ptr[offset] = getchar();",
    "ptr[offset] <<= ptr[offset+1];",
    "ptr[offset] >>= ptr[offset-1];",
    "int *segfaultPtr = 0; *segfaultPtr = 0xDEADBEEF;",
    "a = ptr[offset];",
    "b = ptr[offset];",
    "c = ptr[offset];",
    "d = ptr[offset];",
    "e = ptr[offset];",
    "f = ptr[offset];",
    "ptr[offset] = a;",
    "ptr[offset] = b;",
    "ptr[offset] = c;",
    "ptr[offset] = d;",
    "ptr[offset] = e;",
    "ptr[offset] = f;"
};

std::string fileTemplate = "#include <stdlib.h>\n#include <stdio.h>\n#include <string.h>\nint a; int b; int c; int d; int e; int f; int *ptr = (int*)malloc(4000); int offset = 0;\nint %s(void){%s}";

void fileToC(std::string content, std::string filename, bool nc)
{
    FILE *fileC;
    std::string functionName;
    std::string translation;
    int x = 0;
    // Extract function name from file
    while(content[x] =! '\n')
    {
        functionName += content[x];
        x++;
    }
    content.erase(0, x);
    // Translate the code to C
    printf("Translating code to C...\n");
    for(int i = 0; i < content.length(); i++)
    {
        translation += commandToC(content[i], nc);
    }
    translation += functionName.c_str();
    translation += "();";
    printf("Writing translated C code...\n");
    fileC = fopen(filename.c_str(), "w");
    // Write the file
    fprintf(fileC, fileTemplate.c_str(), functionName.c_str(), translation.c_str());
    // Close the file
    fclose(fileC);
}
std::string commandToC(char command, bool nc)
{
    // DO NOT IMPROVE THE FUCKING FORMATING I REPEAT DO NOT UNDO THE FUCKING FORMATING
    if(!nc){static bool isCSeg = false;static char cDesignator = '`';if(isCSeg){std::string ret;ret += command;return ret;}if(strcmp(&command, &cDesignator) != 0){isCSeg = !isCSeg;}}
    for(int i = 0; i < 26; i++)
        if(strcmp(&command, &commands[i]) != 0)
            return c_commands[i];
    std::string ret = "";
    return ret;
}
