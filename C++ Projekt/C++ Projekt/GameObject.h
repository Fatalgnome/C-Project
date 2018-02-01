#pragma once
#include<GL\glut.h>
#include<glm\glm.hpp>
class GameObject
{
private:
	
	
public:
	float speed;
	GLuint Texture;
	GLboolean Destroyed;
	glm::vec2 Position;
	glm::vec2 Size;
	GameObject();
	GameObject(glm::vec2 position, glm::vec2 Size, const char* sprite);
	virtual void MoveObjectMX(float gameTime);
	virtual void MoveObjectMY(float gameTime);
	virtual void MoveObjectX(float gameTime);
	virtual void MoveObjectY(float gameTime);
	GLboolean CheckCollision(GameObject &one, GameObject &two);
	virtual void Draw();
	~GameObject();

};

