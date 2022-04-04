#include "pch.h"
#include "PlayerManager.h"
#include "Player.h"

PlayerManager GPlayerManager;

void PlayerManager::Login(std::string name,function<void(bool,std::shared_ptr<PlayerInfo>)> loginResultCallback)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, name, loginResultCallback]
		{
			auto findIter = m_playerMap.find(name);
			if (findIter != m_playerMap.end())
			{			
				loginResultCallback(false, nullptr);
				return;
			}
			
			auto player = std::make_shared<PlayerInfo>();
			player->SetName(name);
			m_playerMap.emplace(name, player);
			loginResultCallback(true, player);
		});
}

void PlayerManager::Logout(std::string name)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, name]
		{
			auto findIter = m_playerMap.find(name);
			if (findIter == m_playerMap.end())
			{				
				return;
			}

			findIter->second->Clear();
			m_playerMap.erase(name);
		});
}
