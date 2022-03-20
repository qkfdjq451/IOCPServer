#include "pch.h"
#include "ChatRoomManager.h"
#include "Player.h"
#include "GameSession.h"
#include "ClientChatPacketHandler.h"
#include "Chat.pb.h"
#include "ChatRoom.h"

void ChatRoomManager::CreateChatRoom(std::shared_ptr<Player> requester, std::string roomName)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, requester, roomName]
		{
			auto findIter = m_chatRoomMap.find(roomName);
			if (findIter != m_chatRoomMap.end())
			{
				Protocol::S_CHAT_CREATE_ROOM_RESULT_MESSAGE chatCreateResultMessage;
				chatCreateResultMessage.set_chatcreateroomresult(Protocol::ChatCreateRoomResult::ChatCreateRoomResult_Fail_Already_Exist_Name_In_Rooms);
				auto sendBuffer = ClientChatPacketHandler::MakeSendBuffer(chatCreateResultMessage);

				requester->GetSession()->Send(sendBuffer);
			}
			else
			{
				createChatRoomInternal(requester, roomName);
			}
		});
}

void ChatRoomManager::JoinRoom(std::shared_ptr<Player> requester, std::string roomName)
{
	auto self(shared_from_this());
	this->DoAsync([this, self, requester, roomName]
		{
			this->joinRoomInternal(requester, roomName);
		});
}

void ChatRoomManager::createChatRoomInternal(std::shared_ptr<Player> requester, std::string roomName)
{
	auto findIter = m_chatRoomMap.find(roomName);
	if (findIter != m_chatRoomMap.end())
	{
		return;
	}

	auto chatRoom = std::make_shared<ChatRoom>(roomName);
	m_chatRoomMap[roomName] = chatRoom;

	joinRoomInternal(requester, roomName);
}

void ChatRoomManager::joinRoomInternal(std::shared_ptr<Player> requester, std::string roomName)
{
	auto findIter = m_chatRoomMap.find(roomName);
	if (findIter == m_chatRoomMap.end())
	{
		Protocol::S_CHAT_JOIN_ROOM_RESULT_MESSAGE chatJoinRoomResultMessage;
		chatJoinRoomResultMessage.set_chatjoinroomresult(Protocol::ChatJoinRoomResult::ChatJoinRoomResult_Fail_Is_Not_Exist_Room);
		auto sendBuffer = ClientChatPacketHandler::MakeSendBuffer(chatJoinRoomResultMessage);

		requester->GetSession()->Send(sendBuffer);

		return;
	}

	auto chatRoom = findIter->second;
	chatRoom->Enter(requester);

	Protocol::S_CHAT_JOIN_ROOM_RESULT_MESSAGE chatJoinRoomResultMessage;
	chatJoinRoomResultMessage.set_chatjoinroomresult(Protocol::ChatJoinRoomResult::ChatJoinRoomResult_Success);
	auto sendBuffer = ClientChatPacketHandler::MakeSendBuffer(chatJoinRoomResultMessage);

	requester->GetSession()->Send(sendBuffer);

}
