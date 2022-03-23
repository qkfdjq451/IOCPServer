#include "pch.h"
#include "CommandManager.h"
#include "StateController.h"
#include "LoginState.h"

void CommandManager::Init()
{
	m_stateController.ChangeState<LoginState>();
}

void CommandManager::ProcessCommand(const std::string& command)
{

}