# C--

C-- (pronounced C minus minus) is an esoteric programming language I made. It is based on C, and compiles to C (I would make it compile to a raw binary, but I am not about reinvent the wheel and create my own compiler). It is somewhat similar to assembly. I plan on creating an interpreter for it.

# Syntax

## Basic Syntax

\- \- Subtract from active memory cell \
\+ \- Add to active memory cell \
\* \- Multiply active memory cell by next memory cell \
\\ \- Divide active memory cell by next memory cell \
\> \- Move to next memory cell \
\< \- Move to last memory cell \
\( \- Start while loop \
\) \- End while loop \
\{ \- Start if loop \
\} \- End if loop \
\@ \- Print character from active memory cell \
\$ \- Gets user input into the active memory cell \
\! \- Bitshifts the current active memory cell to the left by the next memory cell \
\? \- Bitshifts the current active memory cell to the right by the last active memory cell \
\~ \- Easy Segfault (only way to exit (unless you are smart)) \
a \- Sets the varible a to the active memory cell \
b \- Sets the varible b to the active memory cell \
c \- Sets the varible c to the active memory cell \
d \- Sets the varible d to the active memory cell \
e \- Sets the varible e to the active memory cell \
f \- Sets the varible f to the active memory cell \
A \- Sets the active memory cell to the varible a \
B \- Sets the active memory cell to the varible b \
C \- Sets the active memory cell to the varible c \
D \- Sets the active memory cell to the varible d \
E \- Sets the active memory cell to the varible e \
F \- Sets the active memory cell to the varible f

## Advanced Syntax

If the function name is unequal to main it will return the value in f.

### While loop syntax

While loops repeat if the current active memory cell is unequal to zero.

### If loop syntax

If loops run if the current active memory cell is equal to zero.

## Additional info

File formats can be whatever you want, but they are recommended to be either .c-- or .cmm.

# Arguments

-i or --input will designate the next argument as the input file to be processed. \
-o or --output will designate the next argument as the output file to be created. If this argument is not found the default is out.c \
-s or --segfault will tell the compiler to put a segfault character command at the end of the input, and also tells the compiler to exit using a segfault.
