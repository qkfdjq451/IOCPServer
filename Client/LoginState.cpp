#include "pch.h"
#include "LoginState.h"
#include "ServerLoginPacketHandler.h"

void LoginState::Enter()
{
	std::cout << "닉네임을 입력해 주세요." << std::endl;
}

void LoginState::Leave()
{
}

void LoginState::ProcessCommand(const std::string& command)
{
	Protocol::C_LOGIN pkt;
	pkt.set_name(command);
	auto sendBuffer = ServerLoginPacketHandler::MakeSendBuffer(pkt);

	Send(sendBuffer);
}
