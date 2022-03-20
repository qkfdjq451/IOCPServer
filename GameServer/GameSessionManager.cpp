#include "pch.h"
#include "GameSessionManager.h"
#include "GameSession.h"

GameSessionManager GSessionManager;

void GameSessionManager::Add(GameSessionRef session)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, session]
		{
			_sessions.insert(session);
		});
}

void GameSessionManager::Remove(GameSessionRef session)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, session]
		{
			_sessions.erase(session);
		});
}

void GameSessionManager::Broadcast(SendBufferRef sendBuffer)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, sendBuffer]
		{
			for (GameSessionRef session : _sessions)
			{
				session->Send(sendBuffer);
			}
		});
}
