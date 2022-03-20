#pragma once

class PlayerManager : public JobQueue
{
public:

private:
	map<uint64, std::shared_ptr<Player>> m_players;
};

