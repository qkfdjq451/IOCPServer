#include "pch.h"
#include "ClientChatPacketHandler.h"
#include "ChatRoomManager.h"
#include "GameSession.h"
#include "Player.h"
#include "ChatRoom.h"
std::map<uint64, PacketHandlerFunc> GClientChatPacketHandlerMap;

bool Handle_C_CHAT_CREATE_ROOM_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_CREATE_ROOM_MESSAGE& pkt)
{
	auto gameSession = std::static_pointer_cast<GameSession>(session);
	std::string roomName = pkt.roomname();
	gameSession->DoAsync([gameSession, roomName]
		{
			auto player = gameSession->GetPlayer();
			if (player == nullptr)
			{
				gameSession->Disconnect(L"Invaild State");
				return;
			}

			GChatRoomManager.CreateChatRoom(player, roomName);
		});

	return true;
}

bool Handle_C_CHAT_JOIN_ROOM_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_JOIN_ROOM_MESSAGE& pkt)
{
	auto gameSession = std::static_pointer_cast<GameSession>(session);
	std::string roomName = pkt.roomname();
	gameSession->DoAsync([gameSession, roomName]
	{
		auto player = gameSession->GetPlayer();
		if (player == nullptr)
		{
			gameSession->Disconnect(L"Invaild State");
			return;
		}

		GChatRoomManager.JoinRoom(player, roomName);
	});

	return true;
}

bool Handle_C_CHAT_REQUEST_ROOM_LIST_MESSAGE(PacketSessionRef& session, Protocol::C_CHAT_REQUEST_ROOM_LIST_MESSAGE& pkt)
{
	auto gameSession = std::static_pointer_cast<GameSession>(session);	
	gameSession->DoAsync([gameSession]
		{
			auto player = gameSession->GetPlayer();
			if (player == nullptr)
			{
				gameSession->Disconnect(L"Invaild State");
				return;
			}

			GChatRoomManager.GetRoomList([gameSession](const std::vector<std::string>& roomList)
				{
					int index = 0;
					Protocol::S_CHAT_RESPONSE_ROOM_LIST_MESSAGE roomListMessage;
					for (const auto& roomName : roomList)
					{
						roomListMessage.set_roomnamelist(index++, roomName);
					}
					auto sendBuffer = ClientChatPacketHandler::MakeSendBuffer(roomListMessage);
					gameSession->Send(sendBuffer);
				});
		});

	return true;
}

bool Handle_C_CHATMESSAGE(PacketSessionRef& session, Protocol::C_CHATMESSAGE& pkt)
{
	auto gameSession = std::static_pointer_cast<GameSession>(session);
	std::string msg = pkt.msg();
	gameSession->DoAsync([gameSession, msg]
		{
			auto player = gameSession->GetPlayer();
			if (player == nullptr)
			{
				gameSession->Disconnect(L"Invaild State");
				return;
			}

			player->GetRoom([msg, player](std::weak_ptr<ChatRoom> chatRoom)
				{
					auto chatRoomShared = chatRoom.lock();
					if (chatRoomShared)
					{
						Protocol::S_CHATMESSAGE chatMessage;
						chatMessage.set_name(player->GetName());
						chatMessage.set_msg(msg);
						auto sendBuffer = ClientChatPacketHandler::MakeSendBuffer(chatMessage);
						chatRoomShared->Broadcast(sendBuffer);
					}
				});
		});

	return true;
}
