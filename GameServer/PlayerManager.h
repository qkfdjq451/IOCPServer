#pragma once

class PlayerManager : public JobQueue
{
public:
	void Login(std::string name, function<void(bool, std::shared_ptr<PlayerInfo>)> loginResultCallback);
	void Logout(std::string name);
private:
	map<std::string, std::shared_ptr<PlayerInfo>> m_playerMap;
};

extern PlayerManager GPlayerManager;