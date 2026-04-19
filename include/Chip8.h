#ifndef CHIP8_H
#define CHIP8_H

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

class Chip8 // the chip 8 cpu works at a clock of 500 instructions per second (500 Hz)
{
public:
	enum State
	{
		RomSelection,
		Running,
		Paused,
	};

	Chip8();

	auto loadROM() 											-> void; 										 
	auto loadFontSprites()      							-> void;
	auto reset() 						  					-> void;
	auto getDisplay()										-> std::vector<std::uint8_t>;
	auto getOpcodeConvertedToString(std::uint16_t opcode)   -> std::string;

	auto getMemoryContent() const 							-> std::vector<std::string>;
	auto getCallStack(int index) const 						-> std::string;
	auto getRegister(int index) const 						-> std::string;

	auto setState(State emuState) 							-> void;
	auto getState() const 									-> State;

	auto setKeyBeingPressed(std::uint8_t key)   			-> void;
	auto getKeyBeingPressed() const 						-> std::uint8_t;

	auto setKeypad(int index, std::uint8_t key) 			-> void;
	auto getKeypad(int index) const 						-> std::uint8_t;

	auto waitForKey(bool b) 								-> void;
	auto isWaitingForKey() const 							-> bool;

	auto decrementDelayTimer() 								-> void;
	auto getDelayTimer() const 								-> std::uint8_t;

	auto decrementSoundTimer() 								-> void;
	auto getSoundTimer() const 								-> std::uint8_t;

	auto getPC() const 										-> std::uint16_t;
	auto getSP() const 										-> std::uint8_t;
	auto getI() const 										-> std::uint16_t;

	auto setFilename(const std::string& file) 				-> void;
	auto getFilename() 										-> std::string;

	friend class Opcodes;

private:
	std::uint8_t  m_memory[4096]{}; // most programs starts at 0x200 (512)
	std::uint8_t  m_V[16]{}; // general purpose 8-bit registers
	std::uint16_t m_I{}; // used to store addresses
	std::uint16_t m_pc{0x200}; // program counter (pc): holds the memory address of the instruction being executed
	std::uint16_t m_stack[16]{}; // used to hold the value of the address to get back to when a routine is finished
	std::uint8_t  m_sp{}; // used to hold the address of the top level of the stack

	std::uint8_t  m_delayTimer{}; // decrements 60 times per second (60 Hz)
	std::uint8_t  m_soundTimer{}; // decrements at a frequency established by the programmer (me). not defined yet 

	std::uint8_t  m_display[64 * 32]{}; // a 64x32 display represented by an array of size 2048
	std::uint8_t  m_keypad[16]{}; // a 16-key keypad, represented by hexadecimal numbers, from 0 to F

	// Chip-8 layout     // mapped to
	// 	  1 2 3 C      		1 2 3 4
	//    4 5 6 D 			Q W E R
	//    7 8 9 E           A S D F
	//    A 0 B F           Z X C V

	bool		  m_waitForAKeyPress{ false }; // when this is true, the program should stop the pc until a key is pressed
	std::uint8_t  m_keyBeingPressed{0xFF}; // 0xFF it will represent the that nothing is being pressed, otherwise it will store a number from 0x to 0xF
	State 		  m_state{State::RomSelection};

	std::string   m_filename{};
	int 		  m_fileSize{};
};

#endif
