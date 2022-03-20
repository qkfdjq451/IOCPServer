#pragma once

class ChatRoom;

class ChatRoomManager : public JobQueue
{
public:	
	void CreateChatRoom(std::shared_ptr<Player> requester, std::string roomName);
	void JoinRoom(std::shared_ptr<Player> requester, std::string roomName);


private:
	void createChatRoomInternal(std::shared_ptr<Player> requester, std::string roomName);
	void joinRoomInternal(std::shared_ptr<Player> requester, std::string roomName);
	std::map<std::string, std::shared_ptr<ChatRoom>> m_chatRoomMap;
};

