#pragma once

class CommandManager
{
public:
	void Init();
	void ProcessCommand(const std::string& command);
	StateController& GetStateController() { return m_stateController; }
private:
	class StateController m_stateController;
};

