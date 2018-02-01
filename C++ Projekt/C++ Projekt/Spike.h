#pragma once
#include"GameObject.h"
#include<glm\glm.hpp>
class Spike : public GameObject
{
public:
	Spike(glm::vec2 position);
	void Draw();
	~Spike();
};

