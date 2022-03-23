#include "pch.h"
#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "BufferReader.h"
#include "ServerChatPacketHandler.h"
#include "ServerLoginPacketHandler.h"
#include "CommandManager.h"
#include "StateController.h"
#include "LoginState.h"

char sendData[] = "Hello World";


CommandManager commandManager;
class ServerSession : public PacketSession
{
public:
	~ServerSession()
	{
		cout << "~ServerSession" << endl;
	}

	virtual void OnConnected() override
	{
		Protocol::C_LOGIN pkt;
		auto sendBuffer = ServerLoginPacketHandler::MakeSendBuffer(pkt);
		Send(sendBuffer);
	}

	virtual void OnRecvPacket(BYTE* buffer, int32 len) override
	{
		PacketSessionRef session = GetPacketSessionRef();

		ServerLoginPacketHandler::HandlePacket(session, buffer, len);
	}

	virtual void OnSend(int32 len) override
	{
		//cout << "OnSend Len = " << len << endl;
	}

	virtual void OnDisconnected() override
	{		
		commandManager.GetStateController().ChangeState<LoginState>();
		//cout << "Disconnected" << endl;
	}
};

int main()
{
	commandManager.Init();
	ServerChatPacketHandler::Init();
	ServerLoginPacketHandler::Init();

	this_thread::sleep_for(1s);

	ClientServiceRef service = MakeShared<ClientService>(
		NetAddress(L"127.0.0.1", 7777),
		MakeShared<IocpCore>(),
		MakeShared<ServerSession>, // TODO : SessionManager 등
		1);

	ASSERT_CRASH(service->Start());

	for (int32 i = 0; i < 2; i++)
	{
		GThreadManager->Launch([=]()
			{
				while (true)
				{
					service->GetIocpCore()->Dispatch();
				}
			});
	}

	while (true)
	{
		std::string command;
		cin >> command;

	}

	//Protocol::C_CHAT chatPkt;
	//chatPkt.set_msg(u8"Hello World !");
	//auto sendBuffer = ServerPacketHandler::MakeSendBuffer(chatPkt);

	//while (true)
	//{
	//	service->Broadcast(sendBuffer);
	//	this_thread::sleep_for(1s);
	//}

	GThreadManager->Join();
}