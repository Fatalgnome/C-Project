#include "Spike.h"



Spike::Spike(glm::vec2 position) : GameObject(position, glm::vec2(1,1), ""){}

void Spike::Draw()
{
	glPushMatrix();

	glTranslatef(Position.x, Position.y, 0);
	glBindTexture(GL_TEXTURE_2D, GameObject::Texture);

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();

	glPopMatrix();
}

Spike::~Spike()
{
}
