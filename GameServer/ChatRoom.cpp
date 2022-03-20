#include "pch.h"
#include "ChatRoom.h"
#include "Player.h"
#include "GameSession.h"

shared_ptr<ChatRoom> GRoom = make_shared<ChatRoom>();

void ChatRoom::Enter(std::shared_ptr<PlayerInfo> player)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, player]
		{
			m_players[player->GetPlayerID()] = player;
		});
}

void ChatRoom::Leave(std::shared_ptr<PlayerInfo> player)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, player]
		{
			m_players.erase(player->GetPlayerID());
		});
}

void ChatRoom::Broadcast(std::shared_ptr<SendBuffer> sendBuffer)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, sendBuffer]
		{
			for (auto& p : m_players)
			{
				p.second->GetSession()->Send(sendBuffer);
			}
		});
}