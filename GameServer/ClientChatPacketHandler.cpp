#include "pch.h"
#include "ClientChatPacketHandler.h"

std::map<int64, PacketHandlerFunc> GClientChatPacketHandlerMap;


bool Handle_C_CHAT_CREATE_ROOM_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_CREATE_ROOM_MESSAGE& pkt)
{
	
	return false;
}

bool Handle_C_CHAT_JOIN_ROOM_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_JOIN_ROOM_MESSAGE& pkt)
{
	return false;
}

bool Handle_C_CHAT_REQUEST_ROOM_LIST_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_REQUEST_ROOM_LIST_MESSAGE& pkt)
{
	return false;
}

bool Handle_C_CHATMESSAGE(PacketSessionRef& session, Protocol::C_CHATMESSAGE& pkt)
{
	return false;
}
