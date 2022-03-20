#pragma once


class IState
{
public:
	virtual void Enter() = 0;
	virtual void Leave() = 0;
	virtual void ProcessCommand(const std::string& command) = 0;
};

class LoginState : public IState
{
	virtual void Enter() override;
	virtual void Leave() override;
	virtual void ProcessCommand(const std::string& command) override;
};


class CommandManager
{
public:
	void Init();
	void ProcessCommand(const std::string& command);
private:
	
};

