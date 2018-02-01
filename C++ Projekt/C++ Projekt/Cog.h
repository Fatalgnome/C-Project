#pragma once
#include"GameObject.h"
#include<glm\glm.hpp>
class Cog : public GameObject
{
public:
	Cog(glm::vec2 position);
	~Cog();
};

