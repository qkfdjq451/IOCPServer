#include "pch.h"
#include "ServerChatPacketHandler.h"

std::map<uint64, PacketHandlerFunc> GServerChatPacketHandlerMap;

bool Handle_S_CHAT_CREATE_ROOM_RESULT_MESSAGE(PacketSessionRef& session, Protocol::S_CHAT_CREATE_ROOM_RESULT_MESSAGE& pkt)
{
	return false;
}

bool Handle_S_CHAT_JOIN_ROOM_RESULT_MESSAGE(PacketSessionRef& session, Protocol::S_CHAT_JOIN_ROOM_RESULT_MESSAGE& pkt)
{
	return false;
}

bool Handle_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE(PacketSessionRef& session, Protocol::S_CHAT_RESPONSE_ROOM_LIST_MESSAGE& pkt)
{
	return false;
}

bool Handle_S_CHATMESSAGE(PacketSessionRef& session, Protocol::S_CHATMESSAGE& pkt)
{
	printf("%s : %s", pkt.name().c_str(), pkt.msg().c_str());
	return true;
}
