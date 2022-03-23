#pragma once
#include "IState.h"
class LoginState : public IState
{
    // IState을(를) 통해 상속됨
    virtual void Enter() override;
    virtual void Leave() override;
    virtual void ProcessCommand(const std::string& command) override;
};

