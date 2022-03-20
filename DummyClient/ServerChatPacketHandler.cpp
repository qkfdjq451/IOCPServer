#include "pch.h"
#include "ServerChatPacketHandler.h"

std::map<int64, PacketHandlerFunc> GServerChatPacketHandlerMap;

bool Handle_S_CHATMESSAGE(PacketSessionRef& session, Protocol::S_CHATMESSAGE& pkt)
{
	printf("%s : %s", pkt.name().c_str(), pkt.msg().c_str());
	return true;
}
