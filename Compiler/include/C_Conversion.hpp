#ifndef IFUCKEDYOURMOMSCRIPT_C_CONVERTER_HPP
#define IFUCKEDYOURMOMSCRIPT_C_CONVERTER_HPP

#include <string>

void fileToC(std::string content, std::string filename, bool nc);
std::string commandToC(char command, bool nc);

#endif