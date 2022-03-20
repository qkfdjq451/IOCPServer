#pragma once
#include "Chat.pb.h"

using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
extern std::map<int64, PacketHandlerFunc> GClientChatPacketHandlerMap;

enum : int64
{
	PKT_C_CHAT_CREATE_ROOM_MESSAGE = 8018335245327230868629232335201590075i64,
	PKT_S_CHAT_CREATE_ROOM_RESULT_MESSAGE = 54003048798068435643868085783364988918i64,
	PKT_C_CHAT_JOIN_ROOM_MESSAGE = 75004573270106641495199368206038303540i64,
	PKT_S_CHAT_JOIN_ROOM_RESULT_MESSAGE = 264647470531780184296337857013334150944i64,
	PKT_C_CHAT_REQUEST_ROOM_LIST_MESSAGE = 320829548571840388824557705392418392957i64,
	PKT_S_CHAT_RESPONSE_ROOM_LIST_MESSAGE = 13206822154114440232420636461246329958i64,
	PKT_C_CHATMESSAGE = 192914568529657705320453526483045522768i64,
	PKT_S_CHATMESSAGE = 111586662928762846846717392907243751814i64,
};

// Custom Handlers
bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len);
bool Handle_C_CHAT_CREATE_ROOM_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_CREATE_ROOM_MESSAGE& pkt);
bool Handle_C_CHAT_JOIN_ROOM_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_JOIN_ROOM_MESSAGE& pkt);
bool Handle_C_CHAT_REQUEST_ROOM_LIST_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_REQUEST_ROOM_LIST_MESSAGE& pkt);
bool Handle_C_CHATMESSAGE(PacketSessionRef& session, Protocol::C_CHATMESSAGE& pkt);

class ClientChatPacketHandler
{
public:
	static void Init()
	{
		GClientChatPacketHandlerMap.emplace(PKT_C_CHAT_CREATE_ROOM_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_CHAT_CREATE_ROOM_MESSAGE>(Handle_C_CHAT_CREATE_ROOM_MESSAGE, session, buffer, len); });
		GClientChatPacketHandlerMap.emplace(PKT_C_CHAT_JOIN_ROOM_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_CHAT_JOIN_ROOM_MESSAGE>(Handle_C_CHAT_JOIN_ROOM_MESSAGE, session, buffer, len); });
		GClientChatPacketHandlerMap.emplace(PKT_C_CHAT_REQUEST_ROOM_LIST_MESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_CHAT_REQUEST_ROOM_LIST_MESSAGE>(Handle_C_CHAT_REQUEST_ROOM_LIST_MESSAGE, session, buffer, len); });
		GClientChatPacketHandlerMap.emplace(PKT_C_CHATMESSAGE,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_CHATMESSAGE>(Handle_C_CHATMESSAGE, session, buffer, len); });
	}

	static bool HandlePacket(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		auto handler = GClientChatPacketHandlerMap.find(header->id);
		if (handler != GClientChatPacketHandlerMap.end())
		{
			return handler->second(session, buffer, len);
		}
		else
		{
			return Handle_INVALID(session, buffer, len);
		}
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