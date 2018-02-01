#pragma once
#include"GameObject.h"
#include"Zeppelin.h"
#include"Cog.h"
#include"Spike.h"
class GameWorld
{
private:
	Zeppelin* player;
	Cog* items[5];
	Spike* spikes[5];
	int oldTimeStart;
	float deltatime;
	int startTime;
	int points;

public:
	GameWorld();
	void Time();
	void MovePlayerMX();
	void MovePlayerX();
	void MovePlayerMY();
	void MovePlayerY();
	void DoCollisions();
	void Draw();
	~GameWorld();
};

