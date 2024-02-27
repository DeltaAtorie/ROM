#pragma once
#include "Code/IronBall.h"
#include "Code/Player.h"

class IronBall;
class Player;

enum class ActorClass
{
	IRONBALL,
	PLAYER
};

class GameActor : public IGameObject
{
public:
	void ActorNewGO(ActorClass Class)
	{
		switch (Class)
		{
		case ActorClass::IRONBALL:
			P_IronBall =
			NewGO<IronBall>
			(0, "ironball");
		case ActorClass::PLAYER:
			P_Player =
			NewGO<Player>
			(0, "player");
			break;
		}
	}

	void ActorFindGO()
	{
		P_IronBall =
		FindGO<IronBall>
		("ironball");

		P_Player =
		FindGO<Player>
		("player");
	}

	void ActorDeleteGO()
	{
		DeleteGO(P_IronBall);
		DeleteGO(P_Player);
	}
	void ActorDeleteGO(ActorClass Class)
	{
		switch (Class)
		{
		case ActorClass::IRONBALL:
			DeleteGO(P_IronBall);
			break;
		case ActorClass::PLAYER:
			DeleteGO(P_Player);
			break;
		}
	}
public:
	IronBall* P_IronBall = nullptr;
	Player* P_Player = nullptr;
};