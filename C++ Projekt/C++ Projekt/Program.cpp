#include<GL\glut.h>
#include<SOIL.h>
#include"GameObject.h"
#include"GameWorld.h"
GameWorld* world;

void OpenGL()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f); 
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
 
void Window(int width, int height)
{
	if (height == 0) 
	{ 
		height = 1; 
	}

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, width / height, 0.0f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 119: //W
		world->MovePlayerMY();
		break;	
	case 97: //A
		world->MovePlayerX();
		break;
	case 100: //D
		world->MovePlayerMX();
		break;
	case 115: //S
		world->MovePlayerY();
		break;
	default:
		break;
	}
}


void processSpecialKeys(int key, int x, int y) 
{

	switch (key)
	{
	case GLUT_KEY_LEFT:
		world->MovePlayerX();
		break;
	case GLUT_KEY_DOWN:
		world->MovePlayerY();
		break;
	case GLUT_KEY_RIGHT:
		world->MovePlayerMX();
		break;
	case GLUT_KEY_UP:
		world->MovePlayerMY();
		break;
	default:
		break;
	}
}

void Loop()
{	
	world->DoCollisions();
	world->Draw();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE);
	glutInitWindowSize(1300, 500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Game");

	OpenGL();
	glutReshapeFunc(&Window);
	glutDisplayFunc(&Loop);
	glutKeyboardFunc(&Keyboard);
	glutSpecialFunc(processSpecialKeys);

	world = new GameWorld();
	glutMainLoop();
}