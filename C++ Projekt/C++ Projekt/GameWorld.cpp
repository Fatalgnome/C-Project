#include "GameWorld.h"
#include"GameObject.h"
#include<GL/glut.h>
#include<glm\glm.hpp>
GameWorld::GameWorld()
{
	oldTimeStart = 0;
	player = new Zeppelin(glm::vec2(-5,0));
	items[0] = new Cog(glm::vec2(7, 2));
	items[1] = new Cog(glm::vec2(2, 3));
	items[2] = new Cog(glm::vec2(-2, -2));
	items[3] = new Cog(glm::vec2(-7, -3));
	items[4] = new Cog(glm::vec2(4, 2));
	spikes[0] = new Spike(glm::vec2(3,0));
	spikes[1] = new Spike(glm::vec2(5, 3));
	spikes[2] = new Spike(glm::vec2(-7, 3));
	spikes[3] = new Spike(glm::vec2(3, -3));
	spikes[4] = new Spike(glm::vec2(5, -4));
		
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void GameWorld::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -12.0f);

	player->Draw();
	for (int i = 0; i < 5; i++)
	{
		spikes[i]->Draw();
	}
	for (int i = 0; i < 5; i++)
	{
		items[i]->Draw();
	}

	glutSwapBuffers();
	glutPostRedisplay();
}

void GameWorld::Time()
{
	startTime = glutGet(GLUT_ELAPSED_TIME);
	deltatime = startTime - oldTimeStart;
	oldTimeStart = startTime;
}


void GameWorld::MovePlayerMX()
{	
	player->MoveObjectMX(deltatime / 1000);
}

void GameWorld::MovePlayerX()
{
	player->MoveObjectX(deltatime / 1000);
}

void GameWorld::MovePlayerMY()
{
	player->MoveObjectMY(deltatime / 1000);
}

void GameWorld::MovePlayerY()
{
	player->MoveObjectY(deltatime / 1000);
}

void GameWorld::DoCollisions()
{
	for each(GameObject* cog in items)
	{
		if (!cog->Destroyed)
		{
			if (cog->CheckCollision(*player, *cog))
			{
				cog->Destroyed = GL_TRUE;
				points++;
			}
		}	
	}

	for each(GameObject* spike in spikes)
	{
		if (!spike->Destroyed)
		{
			if (spike->CheckCollision(*player, *spike))
			{
				player->Destroyed = GL_TRUE;
			}
		}
	}
}



GameWorld::~GameWorld()
{
	delete player;
}