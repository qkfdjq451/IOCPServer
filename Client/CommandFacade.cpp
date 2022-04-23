#include "pch.h"
#include "StateController.h"
#include "LoginState.h"
#include "CommandFacade.h"


void CommandFacade::Init()
{
	m_stateController.ChangeState<LoginState>();
}

void CommandFacade::ProcessCommand(const std::string& command)
{
	m_stateController.ProcessCommand(command);
}