#include "GameObject.h"
#include<GL\glut.h>
#include<SOIL.h>
#include<glm\glm.hpp>


GameObject::GameObject() : Position(0, 0), Size(1, 1)
{
}

GameObject::GameObject(glm::vec2 position, glm::vec2 size, const char* sprite)
{
	this->Position = position;
	this->Size = size;
	speed = 0.0000003f;
	Texture = SOIL_load_OGL_texture(sprite, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glBindTexture(GL_TEXTURE_2D, Texture);
	Destroyed = GL_FALSE;
}



GLboolean GameObject::CheckCollision(GameObject &one, GameObject &two)
{
	// Collision x-axis?
	bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
		two.Position.x + two.Size.x >= one.Position.x;
	// Collision y-axis?
	bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
		two.Position.y + two.Size.y >= one.Position.y;
	// Collision only if on both axes
	return collisionX && collisionY;
}

GameObject::~GameObject()
{

}

void GameObject::Draw()
{
	if (!Destroyed)
	{
		glPushMatrix();
		glTranslatef(Position.x, Position.y, 0);
		glBindTexture(GL_TEXTURE_2D, Texture);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();

		glPopMatrix();
	}
	
}
