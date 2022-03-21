#pragma once
class IState;
class InitializeState : public IState
{
	// IState을(를) 통해 상속됨
	virtual void Enter() override;
	virtual void Leave() override;
	virtual void ProcessCommand(const std::string& command) override;
};

