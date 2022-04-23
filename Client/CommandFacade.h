#pragma once
class StateController;

class CommandFacade
{
public:
	void Init();
	void ProcessCommand(const std::string& command);
	StateController& GetStateController() { return m_stateController; }
private:
	StateController m_stateController;
};