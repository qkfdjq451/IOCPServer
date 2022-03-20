#pragma once
#include "Login.pb.h"

using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
extern std::map<uint64, PacketHandlerFunc> GClientLoginPacketHandlerMap;

enum : uint64
{
	PKT_C_LOGIN = 18317769610250883564i64,
	PKT_S_LOGIN_RESULT = 18317769614545850860i64,
};
bool Handle_C_LOGIN(PacketSessionRef& session, Protocol::C_LOGIN& pkt);

class ClientLoginPacketHandler
{
public:
	static void Init()
	{
		GClientLoginPacketHandlerMap.emplace(PKT_C_LOGIN,[](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket<Protocol::C_LOGIN>(Handle_C_LOGIN, session, buffer, len); });
	}

	static bool HandlePacket(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		auto handler = GClientLoginPacketHandlerMap.find(header->id);
		if (handler != GClientLoginPacketHandlerMap.end())
		{
			return handler->second(session, buffer, len);
		}
		else
		{
			return false;
		}
	}
	static SendBufferRef MakeSendBuffer(Protocol::S_LOGIN_RESULT& pkt) { return MakeSendBuffer(pkt, PKT_S_LOGIN_RESULT); }

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