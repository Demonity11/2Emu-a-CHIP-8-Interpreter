#include "chip8.h"
#include <sstream>

std::string hexToString(std::uint16_t hex, int size)
{
    std::stringstream ss{};

    ss << std::hex << std::setw(size) << std::setfill('0') << std::uppercase << hex;

    std::string hexString{ "0x" + ss.str() };

    // std::cout << "opcode: " << hexString << "\n";

    return hexString;
}

std::string getOpcodeConvertedToString(std::uint16_t opcode)
{
    std::stringstream ss{};

    ss << std::hex << std::uppercase << opcode;

    std::string hexString{ "0x" + ss.str() };

    // std::cout << "opcode: " << hexString << "\n";

    return hexString;
}

std::string getCallStack(const Chip8& cpu, int index)
{
    std::stringstream ss{};

    ss << std::hex << std::uppercase << cpu.stack[index];

    std::string hexString{ "0x" + ss.str() };

    return hexString;
}

void dissambler(const Chip8& cpu, std::uint16_t opcode)
{
    std::uint16_t firstNibble = (opcode >> 12) & 0x000F;
    std::uint16_t lastNibble = opcode & 0x000F;

    std::string instruction{ getOpcodeConvertedToString(opcode) };

    switch (firstNibble)
    {
    case 0x0:
        if (opcode == 0x00E0) instruction += " - CLS";
        if (opcode == 0x00EE) instruction += " - RET";

        break;

    case 0xA: 
    {
        std::string nnn{ hexToString(opcode & Masks::nnn, 3) };
        instruction += " - LD I, " + nnn; 
        break;
    }

    case 0x1: 
    {
        std::string nnn{ hexToString(opcode & Masks::nnn, 3) };
        instruction += " - JP " + nnn; 
        break;
    }

    case 0x2: 
    {
        std::string nnn{ hexToString(opcode & Masks::nnn, 3) };
        instruction += " - CALL " + nnn; 
        break;
    }

    case 0x3: 
    {
        std::uint16_t regIndex = (opcode & Masks::x) >> 8;
        
        std::stringstream ss{};
        ss << std::hex << std::uppercase << regIndex;
        
        std::string kk{ hexToString(opcode & Masks::kk, 2) };
        instruction += " - SE V" + ss.str() + ", " + kk;
        break;
    }

    case 0x4: 
    {
        std::uint16_t regIndex = (opcode & Masks::x) >> 8;

        std::stringstream ss{};
        ss << std::hex << std::uppercase << regIndex;
        
        std::string kk{ hexToString(opcode & Masks::kk, 2) };
        
        instruction += " - SNE V" + ss.str() + ", " + kk;
        break;
    }
    
    case 0x5: 
    {
        std::uint16_t regIndexX = (opcode & Masks::x) >> 8;
        std::uint16_t regIndexY = (opcode & Masks::y) >> 4;

        std::stringstream ssX{};
        std::stringstream ssY{};

        ssX << std::hex << std::uppercase << regIndexX;
        ssY << std::hex << std::uppercase << regIndexY;

        instruction += " - SE V" + ssX.str() + ", V" + ssY.str();
        break;

    }

    case 0x6: op_6xkk(cpu, opcode); break;

    case 0x7: op_7xkk(cpu, opcode); break;
    
    case 0x8:
        switch (lastNibble)
        {
        case 0x0: op_8xy0(cpu, opcode); break;

        case 0x1: op_8xy1(cpu, opcode); break;
        
        case 0x2: op_8xy2(cpu, opcode); break;
            
        case 0x3: op_8xy3(cpu, opcode); break;

        case 0x4: op_8xy4(cpu, opcode); break;

        case 0x5: op_8xy5(cpu, opcode); break;

        case 0x6: op_8xy6(cpu, opcode); break;

        case 0x7: op_8xy7(cpu, opcode); break;

        case 0xE: op_8xyE(cpu, opcode); break;
        }
        break;

    case 0x9: op_9xy0(cpu, opcode); break;

    case 0xB: op_Bnnn(cpu, opcode); break;

    case 0xC: op_Cxkk(cpu, opcode); break;

    case 0xD: op_Dxyn(cpu, opcode); break;
    
    case 0xE:
        if (lastNibble == 0xE) op_Ex9E(cpu, opcode);
        if (lastNibble == 0x1) op_ExA1(cpu, opcode);
        
        break;

    case 0xF:
        switch (opcode & 0x00FF)
        {
        case 0x07: op_Fx07(cpu, opcode); break;

        case 0x0A: op_Fx0A(cpu, opcode); break;

        case 0x15: op_Fx15(cpu, opcode); break;

        case 0x55: op_Fx55(cpu, opcode); break;

        case 0x65: op_Fx65(cpu, opcode); break;

        case 0x18: op_Fx18(cpu, opcode); break;

        case 0x1E: op_Fx1E(cpu, opcode); break;

        case 0x29: op_Fx29(cpu, opcode); break;

        case 0x33: op_Fx33(cpu, opcode); break;
        }
    }
}