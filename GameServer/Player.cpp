#include "pch.h"
#include "Player.h"
#include "ChatRoom.h"
#include "PlayerManager.h"

void PlayerInfo::GetRoom(function<void(std::weak_ptr<class ChatRoom>)> func)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, func]
		{
			auto room = m_room.lock();
			if (room)
			{
				func(room);
			}
		});
}

void PlayerInfo::Clear()
{
	auto self(shared_from_this());
	this->DoAsync([this, self]
		{
			auto room = m_room.lock();
			if (room)
			{
				room->Leave(std::static_pointer_cast<PlayerInfo>(shared_from_this()));
			}
		});
}

void PlayerInfo::Logout()
{
	GPlayerManager.Logout(m_name);
}
