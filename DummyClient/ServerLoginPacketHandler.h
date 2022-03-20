#pragma once
#include "Login.pb.h"

using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
extern std::map<uint64, PacketHandlerFunc> GServerLoginPacketHandlerMap;

enum : uint64
{
	PKT_C_LOGIN = 18339848078614532588i64,
	PKT_S_LOGIN_RESULT = 18339848082909499884i64,
};
bool Handle_S_LOGIN_RESULT(PacketSessionRef& session, Protocol::S_LOGIN_RESULT& pkt);

class ServerLoginPacketHandler
{
public:
	static void Init()
	{
		GServerLoginPacketHandlerMap.emplace(PKT_S_LOGIN_RESULT,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::S_LOGIN_RESULT>(Handle_S_LOGIN_RESULT, session, buffer, len); });
	}

	static bool HandlePacket(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		auto handler = GServerLoginPacketHandlerMap.find(header->id);
		if (handler != GServerLoginPacketHandlerMap.end())
		{
			return handler->second(session, buffer, len);
		}
		else
		{
			return false;
		}
	}
	static SendBufferRef MakeSendBuffer(Protocol::C_LOGIN& pkt) { return MakeSendBuffer(pkt, PKT_C_LOGIN); }

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