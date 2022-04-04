#pragma once


class IState
{
public:
	virtual void Enter() = 0;
	virtual void Leave() = 0;
	virtual void ProcessCommand(const std::string& command) = 0;
};
