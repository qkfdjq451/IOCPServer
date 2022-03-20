#pragma once

class ChatRoom;

class ChatRoomManager : public JobQueue
{
public:	
	void CreateChatRoom(std::shared_ptr<PlayerInfo> requester, std::string roomName);
	void JoinRoom(std::shared_ptr<PlayerInfo> requester, std::string roomName);
	void GetRoomList(function<void(const std::vector<std::string>&)> func);

private:
	void createChatRoomInternal(std::shared_ptr<PlayerInfo> requester, const std::string& roomName);
	void joinRoomInternal(std::shared_ptr<PlayerInfo> requester, const std::string& roomName);
	std::map<std::string, std::shared_ptr<ChatRoom>> m_chatRoomMap;
};


extern class ChatRoomManager GChatRoomManager;