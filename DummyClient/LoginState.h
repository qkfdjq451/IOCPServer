#pragma once
#include "IState.h"
class LoginState : public IState
{
    // IState��(��) ���� ��ӵ�
    virtual void Enter() override;
    virtual void Leave() override;
    virtual void ProcessCommand(const std::string& command) override;
};

