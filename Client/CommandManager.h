#pragma once
#include "StateController.h"

class StateController;

class CommandManager
{
public:
	void Init();
	void ProcessCommand(const std::string& command);
	StateController& GetStateController() { return m_stateController; }
	StateController m_stateController;

};

extern CommandManager commandManager;