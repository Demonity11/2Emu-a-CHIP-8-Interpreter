#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <vector>
#include <string>

class Debugger 
{
public:
	auto isDebugging() 											   -> bool&;
	auto setDebugging(bool b) 									   -> void; // if true the debugger will be shown

	auto isPaused() const 										   -> bool;
	auto pauseEmulation(bool b) 								   -> void; // if true, pauses the emulation

	auto isSteping() 											   -> bool;
	auto stepMode(bool b) 										   -> void; // if true, the emulator steps

	auto getAllInstructions() const 							   -> std::vector<std::string>;
	auto setAllInstructions(std::vector<std::string> instructions) -> void;

	auto getInstruction(int index) const 						   -> std::string;
	auto setInstruction(int index, std::string instruction) 	   -> void;

	auto getVisibleLinesCount() 								   -> int;
	auto setVisibleLinesCount(int linesCount) 					   -> void; 

private:
    std::vector<std::string> m_disassembledInstructions;

    int 					 m_visibleLinesCount{ 15 };

    bool 					 m_isPaused{ false };
    bool 					 m_isSteping{ false };
	bool 					 m_showDebugger{ false };
};

#endif
