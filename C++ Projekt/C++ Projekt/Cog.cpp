#include "Cog.h"
#include"GameObject.h"
#include<glm\glm.hpp>


Cog::Cog(glm::vec2 position) : GameObject(position, glm::vec2(1,1), ".\\cog.png")
{
}


Cog::~Cog()
{
}
