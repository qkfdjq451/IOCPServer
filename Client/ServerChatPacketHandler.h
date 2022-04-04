#pragma once
#include "Chat.pb.h"

using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
extern std::unordered_map<uint64, PacketHandlerFunc> GPacketHandlerMap;
enum : uint64
{
	PKT_C_CHAT_CREATE_ROOM_MESSAGE = 223299265443336684i64,
	PKT_S_CHAT_CREATE_ROOM_RESULT_MESSAGE = 223299269738303980i64,
	PKT_C_CHAT_JOIN_ROOM_MESSAGE = 223299274033271276i64,
	PKT_S_CHAT_JOIN_ROOM_RESULT_MESSAGE = 223299278328238572i64,
	PKT_C_CHAT_REQUEST_ROOM_LIST_MESSAGE = 223299282623205868i64,
	PKT_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE = 223299286918173164i64,
	PKT_C_CHATMESSAGE = 223299291213140460i64,
	PKT_S_CHATMESSAGE = 223299295508107756i64,
};	
bool Handle_S_CHAT_CREATE_ROOM_RESULT_MESSAGE(PacketSessionRef& session, Protocol::S_CHAT_CREATE_ROOM_RESULT_MESSAGE& pkt);	
bool Handle_S_CHAT_JOIN_ROOM_RESULT_MESSAGE(PacketSessionRef& session, Protocol::S_CHAT_JOIN_ROOM_RESULT_MESSAGE& pkt);	
bool Handle_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE(PacketSessionRef& session, Protocol::S_CHAT_RESPONSE_ROOM_LIST_MESSAGE& pkt);	
bool Handle_S_CHATMESSAGE(PacketSessionRef& session, Protocol::S_CHATMESSAGE& pkt);

class ServerChatPacketHandler
{
public:
	static void Initialize()
	{
		GPacketHandlerMap.emplace(PKT_S_CHAT_CREATE_ROOM_RESULT_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::S_CHAT_CREATE_ROOM_RESULT_MESSAGE>(Handle_S_CHAT_CREATE_ROOM_RESULT_MESSAGE, session, buffer, len); });
		GPacketHandlerMap.emplace(PKT_S_CHAT_JOIN_ROOM_RESULT_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::S_CHAT_JOIN_ROOM_RESULT_MESSAGE>(Handle_S_CHAT_JOIN_ROOM_RESULT_MESSAGE, session, buffer, len); });
		GPacketHandlerMap.emplace(PKT_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::S_CHAT_RESPONSE_ROOM_LIST_MESSAGE>(Handle_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE, session, buffer, len); });
		GPacketHandlerMap.emplace(PKT_S_CHATMESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::S_CHATMESSAGE>(Handle_S_CHATMESSAGE, session, buffer, len); });
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