#pragma once
#include "JobQueue.h"

class ChatRoom : public JobQueue
{
public:	
	ChatRoom() {}
	ChatRoom(const std::string& name) : m_name(name) {}	

	void Enter(std::shared_ptr<PlayerInfo> player);
	void Leave(std::shared_ptr<PlayerInfo> player);
	void Broadcast(std::shared_ptr<SendBuffer> sendBuffer);

private:
	std::string m_name;
	map<uint64, std::shared_ptr<PlayerInfo>> m_players;
};