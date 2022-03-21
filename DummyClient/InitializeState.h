#pragma once
class IState;
class InitializeState : public IState
{
	// IState��(��) ���� ��ӵ�
	virtual void Enter() override;
	virtual void Leave() override;
	virtual void ProcessCommand(const std::string& command) override;
};

