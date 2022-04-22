# ifuckedyourmomscript

An esoteric language I am making for fun. This language is inspired by brainfuck, and similar to assembly. With some modifications to the compiler, a very determined son of a bitch could create a very simple operating system kernel.

# Basic Syntax

\- \- Subtract from active memory cell \
\+ \- Add to active memory cell \
\* \- Multiply active memory cell by next memory cell \
\\ \- Divide active memory cell by next memory cell \
\> \- Move to next memory cell \
\< \- Move to last memory cell \
\` \- Set registers (more details later) \
\@ \- Call the system (actually @s it on twitter.com, but whatever) \
\( \- Start while loop \
\) \- End while loop \
\{ \- Start if loop \
\} \- End if loop \
\: \- Compare the active memory cell and next memory cell \
\$ \- Gets user input \
\! \- Easy crash system \
\~ \- Easy Segfault (only way to exit (unless you are smart)) \
\" \- Start comment \
\' \- End comment

# Advanced Syntax

## Assembly convertion

Each file is converted to a single assembly function. The name of the function will be at the top of the file on the first line.

## Set Registers Syntax

Sets up the registers for a system call. The last active memory cell is set to the eax register. The second to last active memory cell is set to the edi register. The thrid to last active memory cell is set to the esi register. The fourth to last active memory cell is set to the edx register.

## While loop syntax

While loops repeat if the last comparison made evaluates to not equal. Comparisons must be made before the end of loop or else it is fucking meaning less.
