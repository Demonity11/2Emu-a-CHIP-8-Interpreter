#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <cstdint>
#include <string>

class Disassembler
{
public:
    static auto hexToString(std::uint16_t hex, int size) 		  -> std::string;
    static auto getRegisterName(std::uint16_t regIndex)  		  -> std::string;
    static auto getOpcodeConvertedToString(std::uint16_t opcode)  -> std::string;
    static auto disassembler(std::uint16_t opcode) 			      -> std::string;
    static auto getFPS(double averageFPS)						  -> std::string;
};

#endif
