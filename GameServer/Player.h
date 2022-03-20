#pragma once

class Player
{
public:
	std::shared_ptr<GameSession> GetSession() { return m_ownerSession; }
	uint64 GetPlayerID() { return m_playerId; }
	std::string GetName() { return m_name; }

private:
	uint64							m_playerId = 0;
	std::string						m_name;	
	std::shared_ptr<GameSession>	m_ownerSession; // Cycle
};

