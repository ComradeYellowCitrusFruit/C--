# ifuckedyourmomscript

An esoteric language I am making for fun. This language is inspired by brainfuck, and similar to assembly. With some modifications to the compiler, a very determined son of a bitch could create a very simple operating system kernel.

# Basic Syntax

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
\a \- Sets the varible a to the active memory cell \
\b \- Sets the varible b to the active memory cell \
\c \- Sets the varible c to the active memory cell \
\d \- Sets the varible d to the active memory cell \
\e \- Sets the varible e to the active memory cell \
\f \- Sets the varible f to the active memory cell \
\A \- Sets the active memory cell to the varible a \
\B \- Sets the active memory cell to the varible b \
\C \- Sets the active memory cell to the varible c \
\D \- Sets the active memory cell to the varible d \
\E \- Sets the active memory cell to the varible e \
\F \- Sets the active memory cell to the varible f \
\~ \- Easy Segfault (only way to exit (unless you are smart)) \

# Advanced Syntax

## While loop syntax

While loops repeat if the current active memory cell is unequal to zero.
