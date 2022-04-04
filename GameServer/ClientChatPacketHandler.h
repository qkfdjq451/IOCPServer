#pragma once
#include "Chat.pb.h"

using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
extern std::unordered_map<uint64, PacketHandlerFunc> GPacketHandlerMap;
enum : uint64
{
	PKT_C_CHAT_CREATE_ROOM_MESSAGE = 199879770850922988i64,
	PKT_S_CHAT_CREATE_ROOM_RESULT_MESSAGE = 199879775145890284i64,
	PKT_C_CHAT_JOIN_ROOM_MESSAGE = 199879779440857580i64,
	PKT_S_CHAT_JOIN_ROOM_RESULT_MESSAGE = 199879783735824876i64,
	PKT_C_CHAT_REQUEST_ROOM_LIST_MESSAGE = 199879788030792172i64,
	PKT_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE = 199879792325759468i64,
	PKT_C_CHATMESSAGE = 199879796620726764i64,
	PKT_S_CHATMESSAGE = 199879800915694060i64,
};	
bool Handle_C_CHAT_CREATE_ROOM_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_CREATE_ROOM_MESSAGE& pkt);	
bool Handle_C_CHAT_JOIN_ROOM_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_JOIN_ROOM_MESSAGE& pkt);	
bool Handle_C_CHAT_REQUEST_ROOM_LIST_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_REQUEST_ROOM_LIST_MESSAGE& pkt);	
bool Handle_C_CHATMESSAGE(PacketSessionRef& session, Protocol::C_CHATMESSAGE& pkt);

class ClientChatPacketHandler
{
public:
	static void Initialize()
	{
		GPacketHandlerMap.emplace(PKT_C_CHAT_CREATE_ROOM_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_CHAT_CREATE_ROOM_MESSAGE>(Handle_C_CHAT_CREATE_ROOM_MESSAGE, session, buffer, len); });
		GPacketHandlerMap.emplace(PKT_C_CHAT_JOIN_ROOM_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_CHAT_JOIN_ROOM_MESSAGE>(Handle_C_CHAT_JOIN_ROOM_MESSAGE, session, buffer, len); });
		GPacketHandlerMap.emplace(PKT_C_CHAT_REQUEST_ROOM_LIST_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_CHAT_REQUEST_ROOM_LIST_MESSAGE>(Handle_C_CHAT_REQUEST_ROOM_LIST_MESSAGE, session, buffer, len); });
		GPacketHandlerMap.emplace(PKT_C_CHATMESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_CHATMESSAGE>(Handle_C_CHATMESSAGE, session, buffer, len); });
	}
	static SendBufferRef MakeSendBuffer(Protocol::S_CHAT_CREATE_ROOM_RESULT_MESSAGE& pkt) { return MakeSendBuffer(pkt, PKT_S_CHAT_CREATE_ROOM_RESULT_MESSAGE); }
	static SendBufferRef MakeSendBuffer(Protocol::S_CHAT_JOIN_ROOM_RESULT_MESSAGE& pkt) { return MakeSendBuffer(pkt, PKT_S_CHAT_JOIN_ROOM_RESULT_MESSAGE); }
	static SendBufferRef MakeSendBuffer(Protocol::S_CHAT_RESPONSE_ROOM_LIST_MESSAGE& pkt) { return MakeSendBuffer(pkt, PKT_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE); }
	static SendBufferRef MakeSendBuffer(Protocol::S_CHATMESSAGE& pkt) { return MakeSendBuffer(pkt, PKT_S_CHATMESSAGE); }

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