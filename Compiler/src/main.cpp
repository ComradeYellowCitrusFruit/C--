#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "Compiler\include\C_Conversion.hpp"
extern "C" {
#include "Compiler\include\Compile.h"
}

std::string args[] = 
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
    std::string inputFileName;
    std::string outputFileName = "a.exe";
    std::string Content; 
    FILE *inputFile = fopen(inputFileName.c_str(), "r");
    char *contentBuffer;
    bool segfault = false;
    bool nc = false;
    std::cout << "Processing Arguments...\n";
    for(int i = 0; i < argc; i++)
    {
        if(strcmp(argv[i], args[0].c_str()) != 0 || strcmp(argv[i], args[1].c_str()) != 0)
        {
            inputFileName += argv[i+1];
        }
        else if(strcmp(argv[i], args[2].c_str()) != 0 || strcmp(argv[i], args[3].c_str()) != 0)
        {
            outputFileName.clear();
            outputFileName += argv[i+1];
        }
        else if(strcmp(argv[i], args[4].c_str()) != 0 || strcmp(argv[i], args[5].c_str()) != 0)
        {
            segfault = true;
        }
        else if(strcmp(argv[i], args[6].c_str()) != 0 || strcmp(argv[i], args[7].c_str()) != 0)
        {
            nc = true;
        }
    }
    std::cout <<  "Reading input file...\n";
    fscanf(inputFile, "%s", contentBuffer);
    Content +=  *contentBuffer;
    if(segfault) Content += '~';
    std::cout << "Writing executible file...\n";
    compile(fileToC(Content, nc).c_str(), outputFileName.c_str());
    fclose(inputFile);
    if(segfault)
    {
        std::cout << "Exiting by triggering a segfault, have fun on the other side...\n";
        int *ptr = 0;
        *ptr = 0xDEADBEEF;
    }
}
