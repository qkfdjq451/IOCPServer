#pragma once
#include "pch.h"
#include "IState.h"
#include <type_traits>
#include "InitializeState.h"

class IState;
class StateController
{
public:
	StateController() : m_currentState(std::make_unique<InitializeState>()) {}
	template<typename T,
		typename = std::enable_if_t<
		std::is_base_of<IState, std::decay_t<T>>::value
		&& !std::is_same<IState, std::decay_t<T>>::value
		>>
	void ChangeState()
	{
		m_currentState->Leave();
		m_currentState.release();
		m_currentState = std::make_unique<T>();
		m_currentState->Enter();
	}

	void ProcessCommand(const std::string& command)
	{
		m_currentState->ProcessCommand(command);
	}
private:
	std::unique_ptr<IState> m_currentState;
};