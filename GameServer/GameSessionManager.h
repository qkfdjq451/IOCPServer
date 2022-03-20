#pragma once

class GameSession;

class GameSessionManager : JobQueue
{
public:
	void Add(GameSessionRef session);
	void Remove(GameSessionRef session);
	void Broadcast(SendBufferRef sendBuffer);

private:	
	Set<GameSessionRef> _sessions;
};

extern GameSessionManager GSessionManager;
