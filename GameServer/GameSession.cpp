#include "pch.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "Player.h"
#include "ClientChatPacketHandler.h"
#include "ClientLoginPacketHandler.h"


bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
{
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
	return false;
}

void GameSession::OnConnected()
{
	GSessionManager.Add(static_pointer_cast<GameSession>(shared_from_this()));
}

void GameSession::OnDisconnected()
{
	GSessionManager.Remove(static_pointer_cast<GameSession>(shared_from_this()));

	auto self(shared_from_this());
	jobQueue.DoAsync([this, self]
		{
			auto currentPlayer = m_player.lock();
			if (currentPlayer)
			{
				currentPlayer->Logout();
			}
		});
}

void GameSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	PacketSessionRef session = GetPacketSessionRef();

	if (ClientChatPacketHandler::HandlePacket(session, buffer, len))
	{
		return;
	}
	else if (ClientLoginPacketHandler::HandlePacket(session, buffer, len))
	{
		return;
	}

	Handle_INVALID(session, buffer, len);
}

void GameSession::OnSend(int32 len)
{
}

void GameSession::DoAsync(function<void()>&& func)
{
	jobQueue.DoAsync(std::move(func));
}
