#include "pch.h"
#include "ServerLoginPacketHandler.h"

std::map<uint64, PacketHandlerFunc> GServerLoginPacketHandlerMap;
bool Handle_S_LOGIN_RESULT(PacketSessionRef& session, Protocol::S_LOGIN_RESULT& pkt)
{

	return false;
}
