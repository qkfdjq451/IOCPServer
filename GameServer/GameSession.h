#pragma once
#include "ClientChatPacketHandler.h"
#include "Session.h"

using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
extern std::unordered_map<uint64, PacketHandlerFunc> GPacketHandlerMap;

class GameSession : public PacketSession
{
public:
	virtual void OnConnected() override;
	virtual void OnDisconnected() override;
	virtual void OnRecvPacket(BYTE* buffer, int32 len) override;
	virtual void OnSend(int32 len) override;

	void SetPlayer(std::shared_ptr<class PlayerInfo> player) { m_player = player; }
	std::shared_ptr<class PlayerInfo> GetPlayer() { return m_player.lock(); }
	
	void DoAsync(function<void()>&& func);
private:
	JobQueue jobQueue;
	std::weak_ptr<class PlayerInfo> m_player;	
};