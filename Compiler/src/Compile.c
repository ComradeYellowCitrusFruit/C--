#include <stdio.h>
#include "libtcc.h"
#include "Compile.h"

int compile(char *C, char *outputName)
{
    FILE *outputFile;
    outputFile = fopen(outputName, "wb");
    TCCState *state = tcc_new();
    if(!state)
    {
        return 1;
    }
    tcc_set_output_type(state, TCC_OUTPUT_EXE);
    if (tcc_compile_string(state, C) > 0) {
        printf("Compilation error !\n");
        return 1;
    }
    tcc_output_coff(state, outputFile);
    fclose(outputFile);
    tcc_delete(state);
}
