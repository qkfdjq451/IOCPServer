#include "pch.h"
#include "CommandFacade.h"
#include "LoginState.h"
#include "ServerLoginPacketHandler.h"
#include  "ServerSession.h"
#include "ServerChatPacketHandler.h"

std::unordered_map<uint64, PacketHandlerFunc> GPacketHandlerMap;

void ServerSession::Initialize()
{
}

bool ServerSession::handle_invalid(PacketSessionRef& session, BYTE* buffer, int32 len)
{
}

void ServerSession::OnConnected()
{
	
}

void ServerSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	PacketSessionRef session = GetPacketSessionRef();

	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
	auto handler = GPacketHandlerMap.find(header->id);
	if (handler != GPacketHandlerMap.end())
	{
		handler->second(session, buffer, len);
	}
	else
	{
		handle_invalid(session, buffer, len);
	}
}
