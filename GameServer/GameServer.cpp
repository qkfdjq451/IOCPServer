#include "pch.h"
#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "BufferWriter.h"
#include <tchar.h>
#include "Job.h"
#include "Player.h"
#include "ClientLoginPacketHandler.h"
#include "ClientChatPacketHandler.h"

enum
{
	WORKER_TICK = 64
};

int main()
{
	const int WorkerThreadCount = 4;
	const int NetworkThreadCount = 4;
	
	ClientLoginPacketHandler::Init();
	ClientChatPacketHandler::Init();

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