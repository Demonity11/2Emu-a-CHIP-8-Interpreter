#include "../include/Debugger.h"

bool&                    Debugger::isDebugging() { return m_showDebugger; }
void                     Debugger::setDebugging(bool b) { m_showDebugger = b; } // if true the debugger will be shown

bool                     Debugger::isPaused() const { return m_isPaused; }
void                     Debugger::pauseEmulation(bool b) { m_isPaused = b; } // if true, pauses the emulation

bool                     Debugger::isSteping() { return m_isSteping; }
void                     Debugger::stepMode (bool b) { m_isSteping = b; } // if true, the emulator steps

std::vector<std::string> Debugger::getAllInstructions() const { return m_disassembledInstructions; }
void                     Debugger::setAllInstructions(std::vector<std::string> instructions) { m_disassembledInstructions = instructions; }

std::string              Debugger::getInstruction(int index) const { return m_disassembledInstructions.at(index); }
void                     Debugger::setInstruction(int index, std::string instruction) { m_disassembledInstructions[index] = instruction; }

int                      Debugger::getVisibleLinesCount() { return m_visibleLinesCount; }
void                     Debugger::setVisibleLinesCount(int linesCount) { m_visibleLinesCount = linesCount; }
