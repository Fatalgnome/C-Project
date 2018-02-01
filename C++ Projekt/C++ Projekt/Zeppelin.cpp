#include "Zeppelin.h"
#include<SOIL.h>



Zeppelin::Zeppelin(glm::vec2 position) : GameObject::GameObject(position, glm::vec2(1,1), ".\\Zeppelin.jpg")
{
}

void GameObject::MoveObjectMX(float gameTime)
{
	Position.x -= speed*gameTime;
}

void GameObject::MoveObjectX(float gameTime)
{
	Position.x += speed*gameTime;
}

void GameObject::MoveObjectMY(float gameTime)
{
	Position.y -= speed*gameTime;
}

void GameObject::MoveObjectY(float gameTime)
{
	Position.y += speed*gameTime;
}

Zeppelin::~Zeppelin()
{

}
