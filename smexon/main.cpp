#pragma once
#include <windows.h>
#include <Gl/gl.h>
#include <Gl/glut.h>
#include <ctime>
#include <cstdio>
#include "Vector2.h"
#include "FormationManager.h"
#include "Body.h"
using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")

/*** Global Variables ***/
UINT prevFrameTime = 0;
Body body [50];

FormationManager * formationMan = new FormationManager();


/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
*/
void InitGraphics(int argc, char *argv[]);

/**
Sets the logical coordinate system we will use to specify
our drawings.
*/
void SetTransformations() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //CT <- I
}
void Update()
{
	UINT currTime = timeGetTime();
	//the first update?
	if(prevFrameTime == 0) {
		prevFrameTime = currTime;
		return;
	}
	//interframe time (in seconds)
	float dt = (currTime - prevFrameTime)/1000.0;

	//...........................
	//TODO: Write all update code here.
	//...........................
	for (int i=0 ; i< 50 ; i++)
		body[i].Update(dt);


	prevFrameTime = currTime;
	//Display the number of frames per seconds (fps)
	char fpsString[128];
	sprintf(fpsString, "%f fps", 1/dt);
	glutSetWindowTitle(fpsString);
}
void OnDisplay() {
	//set the background color to white
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	SetTransformations();

	//drawing code goes here
	for (int i=0 ; i< 50 ; i++) 
		body[i].Render();
	
	vector <postion> x = formationMan->formUnits();
	for (int i=0 ; i< 50 ; i++) 
	{
		body[i].P.Set(x[i].x,x[i].y);
		body[i].Size.Set(2,2);
	}
	glFlush();
	glutSwapBuffers();
	Update();
	glutPostRedisplay();
}
int main(int argc, char* argv[]) {
	timeBeginPeriod(1);
	InitGraphics(argc, argv);
	timeEndPeriod(1);
	return 0;
}
/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
*/
void InitGraphics(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100); //pass (-1, -1) for Window-Manager defaults
	glutInitWindowSize(800, 800);
	glutCreateWindow("OpenGL Lab");
	glutDisplayFunc(OnDisplay);
	//glutSpecialFunc(OnSpecialKey);

	//TODO: Initiate multiple boxes
	postion* pos = new postion [50]; 
	
	//FormationManager *f = new FormationManager(7 ,10,5,10,50 ,0,l);
	//vector <postion> postionsss ;
	//postionsss = f -> formUnits();
	//pos = f->loadToLinearArray();
	postion lead;
	lead.x = 0;
	lead.y = -20;
	FormationData data (50,10,10,5,0,100,FWEDGE,lead);
	formationMan->setParametars(data);
	/*for (int i = 0 ; i < 50 ; i++)
	{
		body[i].P.Set(postionsss[i].x,postionsss[i].y);
		body[i].Size.Set(2,2);
	}*/
	glutMainLoop();
}