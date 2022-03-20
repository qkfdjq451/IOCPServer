#pragma once
#include "JobQueue.h"

class ChatRoom : public JobQueue
{
public:	
	ChatRoom(std::string name) : m_name(name) {}	

	void Enter(std::shared_ptr<Player> player);
	void Leave(std::shared_ptr<Player> player);
	void Broadcast(std::shared_ptr<SendBuffer> sendBuffer);

private:
	std::string m_name;
	map<uint64, std::shared_ptr<Player>> m_players;
};