#include "pch.h"
#include "ClientPacketHandler.h"
#include "ClientChatPacketHandler.h"

bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
{
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);	
	return false;
}
