#include "pch.h"
#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "BufferWriter.h"
#include "ClientPacketHandler.h"
#include <tchar.h>
#include "Protocol.pb.h"
#include "Job.h"
#include "Room.h"
#include "Player.h"

enum
{
	WORKER_TICK = 64
};

int main()
{
	GRoom->DoTimer(1000, [] { cout << "Hello 1000" << endl; });
	GRoom->DoTimer(2000, [] { cout << "Hello 2000" << endl; });
	GRoom->DoTimer(3000, [] { cout << "Hello 3000" << endl; });

	const int WorkerThreadCount = 4;
	const int NetworkThreadCount = 4;
	
	GRoom->DoAsync

	ClientPacketHandler::Init();

	ServerServiceRef service = MakeShared<ServerService>(
		NetAddress(L"127.0.0.1", 7777),
		MakeShared<IocpCore>(),
		MakeShared<GameSession>, // TODO : SessionManager 등
		100);

	ASSERT_CRASH(service->Start());

	for (int32 i = 0; i < NetworkThreadCount; i++)
	{
		GThreadManager->Launch([&service]()
			{
				service->GetIocpCore()->Dispatch(INFINITE);
			});
	}

	for (int32 i = 0; i < WorkerThreadCount; i++)
	{
		GThreadManager->Launch([]()
			{
				ThreadManager::DistributeReservedJobs();

				ThreadManager::DoGlobalQueueWork();
			});
	}

	while (true)
	{
		std::string commend;
		cin >> commend;
	}

	GThreadManager->Join();
}