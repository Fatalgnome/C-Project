#pragma once
#include"GameObject.h"
#include<glm\glm.hpp>
#include<GL\glut.h>
class Zeppelin : public GameObject
{
public:
	Zeppelin(glm::vec2 position);
	~Zeppelin();
};

