#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "C_Conversion.hpp"
extern "C" {
#include "Compile.h"
}

std::string args[8] = 
{ 
                "-i",
                "--input",
                "-o",
                "--output",
                "-s",
                "--segfault",
                "-nc",
                "--no-c"
};

int main(int argc, char **argv)
{
    std::string inputFileName = "";
    std::string outputFileName = "a.exe";
    std::string Content; 
    FILE *inputFile;
    char *buffer;
    bool segfault = false;
    bool nc = false;
    std::cout << "Processing Arguments...\n";
    std::string lastarg;
    for(int i = 0; i < argc; i++)
    {
        if(strcmp(argv[i], args[2].c_str()) != 0 || strcmp(argv[i], args[3].c_str()) != 0)
        {
            outputFileName = "";
        }
        else if(strcmp(argv[i], args[4].c_str()) != 0 || strcmp(argv[i], args[5].c_str()) != 0)
        {
            segfault = true;
        }
        else if(strcmp(argv[i], args[6].c_str()) != 0 || strcmp(argv[i], args[7].c_str()) != 0)
        {
            nc = true;
        }
        if(strcmp(lastarg.c_str(), args[0].c_str()) != 0 || strcmp(lastarg.c_str(), args[1].c_str()) != 0)
        {
            inputFileName += argv[i];
        }
        else if(strcmp(lastarg.c_str(), args[2].c_str()) != 0 || strcmp(lastarg.c_str(), args[3].c_str()) != 0)
        {
            outputFileName += argv[i];
        }
        lastarg = argv[i];
    }
    std::cout <<  "Reading input file...\n";
    inputFile = fopen(inputFileName.c_str(), "r");
    for (;;)
    {
        char c = fgetc(inputFile);
        if (c == EOF) break;
        if (c != (char)1) Content += c;
    }
    if(segfault) Content += '~';
    std::cout << "Writing executible file...\n";
    std::string tmpCFile = fileToC(Content, nc);
    std::string cFile;
    for(int i = 0; i < tmpCFile.length();)
    {
        const char *X1 = new char((char)1);
        if(strcmp((const char*)&tmpCFile.at(i), X1) == 0)
        {
            cFile += tmpCFile.at(i);
        }
    }
    char *CFile = (char*)cFile.c_str();
    char *OutputFilename = (char*)outputFileName.c_str();
    compile(CFile, OutputFilename);
    fclose(inputFile);
    if(segfault)
    {
        std::cout << "Exiting by triggering a segfault, have fun on the other side...\n";
        int *ptr = 0;
        *ptr = 0xDEADBEEF;
    }
}
