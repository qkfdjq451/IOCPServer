#pragma once

class CommandManager
{
public:
	void Init();
	void ProcessCommand(const std::string& command);
private:
	class StateController m_stateController;
};

