#include "pch.h"
#include "ClientLoginPacketHandler.h"
#include "PlayerManager.h"
#include "Player.h"
#include "GameSession.h"

bool Handle_C_LOGIN(PacketSessionRef& session, Protocol::C_LOGIN& pkt)
{
	auto gameSession = std::static_pointer_cast<GameSession>(session);	
	GPlayerManager.Login(pkt.name(), [gameSession](bool isSuccess, std::shared_ptr<PlayerInfo> player)
		{			
			Protocol::S_LOGIN_RESULT s_loginResult;		
			s_loginResult.set_success(isSuccess);

			if (isSuccess && player)
			{
				Protocol::Player playerPt;
				s_loginResult.set_allocated_players(&playerPt);
				playerPt.set_name(player->GetName());
				player->SetSession(gameSession);
			}

			gameSession->Send(ClientLoginPacketHandler::MakeSendBuffer(s_loginResult));
		});
	return true;
}
