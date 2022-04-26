#ifndef C_MINUS_MINUS_C_CONVERTER_HPP
#define C_MINUS_MINUS_C_CONVERTER_HPP

#include <string>

std::string fileToC(std::string content, bool nc);
std::string commandToC(char command, bool nc);

#endif