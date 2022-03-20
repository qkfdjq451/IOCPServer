#pragma once

class PlayerInfo : public JobQueue
{
public:
	void SetSession(std::shared_ptr<GameSession> session) { m_ownerSession = session; }
	void SetName(std::string name) { m_name = name; }
	void GetRoom(function<void(std::weak_ptr<class ChatRoom>)> func);

	std::shared_ptr<GameSession> GetSession() { return m_ownerSession.lock(); }
	uint64 GetPlayerID() { return m_playerId; }
	std::string GetName() { return m_name; }

	void Clear();
	void Logout();

private:
	std::weak_ptr<class ChatRoom>	m_room;
	uint64							m_playerId = 0;
	std::string						m_name;	
	std::weak_ptr<GameSession>		m_ownerSession;
};

