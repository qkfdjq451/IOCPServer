#pragma once
#include "Chat.pb.h"

using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
extern std::map<uint64, PacketHandlerFunc> GServerChatPacketHandlerMap;

enum : uint64
{
	PKT_C_CHAT_CREATE_ROOM_MESSAGE = 18386364185042948588i64,
	PKT_S_CHAT_CREATE_ROOM_RESULT_MESSAGE = 18386364189337915884i64,
	PKT_C_CHAT_JOIN_ROOM_MESSAGE = 18386364193632883180i64,
	PKT_S_CHAT_JOIN_ROOM_RESULT_MESSAGE = 18386364197927850476i64,
	PKT_C_CHAT_REQUEST_ROOM_LIST_MESSAGE = 18386364202222817772i64,
	PKT_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE = 18386364206517785068i64,
	PKT_C_CHATMESSAGE = 18386364210812752364i64,
	PKT_S_CHATMESSAGE = 18386364215107719660i64,
};
bool Handle_S_CHAT_CREATE_ROOM_RESULT_MESSAGE(PacketSessionRef& session, Protocol::S_CHAT_CREATE_ROOM_RESULT_MESSAGE& pkt);
bool Handle_S_CHAT_JOIN_ROOM_RESULT_MESSAGE(PacketSessionRef& session, Protocol::S_CHAT_JOIN_ROOM_RESULT_MESSAGE& pkt);
bool Handle_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE(PacketSessionRef& session, Protocol::S_CHAT_RESPONSE_ROOM_LIST_MESSAGE& pkt);
bool Handle_S_CHATMESSAGE(PacketSessionRef& session, Protocol::S_CHATMESSAGE& pkt);

class ServerChatPacketHandler
{
public:
	static void Init()
	{
		GServerChatPacketHandlerMap.emplace(PKT_S_CHAT_CREATE_ROOM_RESULT_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::S_CHAT_CREATE_ROOM_RESULT_MESSAGE>(Handle_S_CHAT_CREATE_ROOM_RESULT_MESSAGE, session, buffer, len); });
		GServerChatPacketHandlerMap.emplace(PKT_S_CHAT_JOIN_ROOM_RESULT_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::S_CHAT_JOIN_ROOM_RESULT_MESSAGE>(Handle_S_CHAT_JOIN_ROOM_RESULT_MESSAGE, session, buffer, len); });
		GServerChatPacketHandlerMap.emplace(PKT_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::S_CHAT_RESPONSE_ROOM_LIST_MESSAGE>(Handle_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE, session, buffer, len); });
		GServerChatPacketHandlerMap.emplace(PKT_S_CHATMESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::S_CHATMESSAGE>(Handle_S_CHATMESSAGE, session, buffer, len); });
	}

	static bool HandlePacket(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		auto handler = GServerChatPacketHandlerMap.find(header->id);
		if (handler != GServerChatPacketHandlerMap.end())
		{
			return handler->second(session, buffer, len);
		}
		else
		{
			return false;
		}
	}
	static SendBufferRef MakeSendBuffer(Protocol::C_CHAT_CREATE_ROOM_MESSAGE& pkt) { return MakeSendBuffer(pkt, PKT_C_CHAT_CREATE_ROOM_MESSAGE); }
	static SendBufferRef MakeSendBuffer(Protocol::C_CHAT_JOIN_ROOM_MESSAGE& pkt) { return MakeSendBuffer(pkt, PKT_C_CHAT_JOIN_ROOM_MESSAGE); }
	static SendBufferRef MakeSendBuffer(Protocol::C_CHAT_REQUEST_ROOM_LIST_MESSAGE& pkt) { return MakeSendBuffer(pkt, PKT_C_CHAT_REQUEST_ROOM_LIST_MESSAGE); }
	static SendBufferRef MakeSendBuffer(Protocol::C_CHATMESSAGE& pkt) { return MakeSendBuffer(pkt, PKT_C_CHATMESSAGE); }

private:
	template<typename PacketType, typename ProcessFunc>
	static bool HandlePacket(ProcessFunc func, PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketType pkt;
		if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
			return false;

		return func(session, pkt);
	}

	template<typename T>
	static SendBufferRef MakeSendBuffer(T& pkt, uint16 pktId)
	{
		const uint16 dataSize = static_cast<uint16>(pkt.ByteSizeLong());
		const uint16 packetSize = dataSize + sizeof(PacketHeader);

		SendBufferRef sendBuffer = GSendBufferManager->Open(packetSize);
		PacketHeader* header = reinterpret_cast<PacketHeader*>(sendBuffer->Buffer());
		header->size = packetSize;
		header->id = pktId;
		ASSERT_CRASH(pkt.SerializeToArray(&header[1], dataSize));
		sendBuffer->Close(packetSize);

		return sendBuffer;
	}
};