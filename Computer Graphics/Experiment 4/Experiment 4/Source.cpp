#include <complex>
#include <glut.h>
#include <stdlib.h>  
#include <windows.h>



float degree = 0;
float degreeY = 0;
GLubyte chess[] = {
	0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,
	0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,
	0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,
	0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,
	0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,
	0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,
	0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,
	0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,
	0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,
	0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,
	0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,
	0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,
	0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,
	0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,
	0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,
	0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,
};
GLuint lineList;
GLuint coordinate;
int wid=1000, hei=500;

#define MAX_CHAR 128
void drawString(const char* str, GLfloat x, GLfloat y, GLfloat z) {
	//按x,y,z为起始位置，显示字符串str  
	GLuint lists;
	lists = glGenLists(MAX_CHAR);
	wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	glListBase(lists);
	//起始位置
	glRasterPos3f(x, y, z);
	glCallLists(strlen(str), GL_UNSIGNED_BYTE, str);
}

void draw() {
	glColor4f(0, 0.6, 1.0, 0.5);
	drawString("x", -2, 0.1, 0);
	glColor4f(1, 0.6, 0, 0.5);
	drawString("y", 0.1, 2, 0);
	glColor4f(0.6, 1, 0.6, 0.5);
	drawString("z", 0.1, 0.1, 2);
}

void KeyPlot(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: {
		degree -= 1;
		break;
	}
	case GLUT_KEY_DOWN: {
		degree += 1;
		break;
	}
	case GLUT_KEY_LEFT: {
		degreeY += 1;
		break;
	}
	case GLUT_KEY_RIGHT: {
		degreeY -= 1;
		break;
	}
	default: break;
	}

	glutPostRedisplay();
}

float getX() {
	return 6 * std::sin(degreeY / 180 * 3.1415926) * std::cos(degree/180*3.1415926);
}

float getY() {
	return 6 * std::sin(degreeY / 180 * 3.1415926)*std::sin(degree / 180 * 3.1415926);
}

float getZ() {
	return 6 * std::cos(degreeY / 180 * 3.1415926);
}

void triangle(GLsizei mode) {
	float x;
	if (wid > hei * 2) x = (float)(hei) / (float)(wid / 2);
	else { x = (float)(wid / 2) / (float)(hei); }
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3 * x, 3 * x, -3 * x, 3 * x, -20, 20);
	if(mode==1) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(0, 0, -7, 0, 0, 0, 0, 1, 0);
		glPushMatrix();
		glLoadIdentity();
		//glRotatef(degree, 1, 0, 0);
		//glRotatef(degreeY, 0, 1, 0);
		glCallList(lineList);
		glCallList(coordinate);
		glPopMatrix();
		//draw();
	} else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		//gluPerspective(45, 1, 0, 20);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(getX(), getY(), getZ(), 0, 0, 0, 0, 1, 0);
		glPushMatrix();

//		glRotatef(degree, 1, 0, 0);
//		glRotatef(degreeY, 0, 1, 0);
		glColor3f(0.0, 0.0, 0.0);
		glEnable(GL_POLYGON_STIPPLE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glPolygonStipple(chess);
		glCallList(lineList);
		glRectf(50.0f, 100.0f, 150.0f, 50.0f);
		glDisable(GL_POLYGON_STIPPLE);
		glLineWidth(5.0);
		glColor4f(0.0, 0.6, 1.0, 1.0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glCallList(lineList);
		glCallList(coordinate);
		glPopMatrix();
		draw();
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 0, 0);
	glViewport(0, 0, wid / 2, hei);
	triangle(1);
	glColor3f(0, 0, 1);
	glViewport(wid / 2, 0, wid / 2, hei);
	triangle(2);

	glFlush();
	glutSwapBuffers();
}

void Initial() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);

	lineList = glGenLists(1);
	glNewList(lineList, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	glColor4f(0, 0.6, 1.0, 0.5);
	glVertex3f(2, 0, 0);
	glVertex3f(2, 1, 0);
	glVertex3f(0, 1, 0);
	glColor4f(1, 0.6, 0, 0.5);
	glVertex3f(2, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, 1, 1);
	glColor4f(0.6, 1, 0.6, 0.5);
	glVertex3f(2, 1, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, 1, 1);
	glEnd();
	glEndList();

	coordinate = glGenLists(1);
	glNewList(coordinate, GL_COMPILE);
	glBegin(GL_LINES);
	glColor4f(0, 0.6, 1.0, 0.5);
	glVertex3f(-3, 0, 0);
	glVertex3f(3, 0, 0);
	glColor4f(1, 0.6, 0, 0.5);
	glVertex3f(0, -3, 0);
	glVertex3f(0, 3, 0);
	glColor4f(0.6, 1, 0.6, 0.5);
	glVertex3f(0, 0, 3);
	glVertex3f(0, 0, -3);
	glEnd();
	glEndList();
}

void changeSize(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(-2.5, 2.5, -3.0, 3.0*(GLfloat)h / (GLfloat)w);
	else
		gluOrtho2D(-2.5, 2.5*(GLfloat)w / (GLfloat)h, -3.0, 3.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(wid, hei);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Experiment 4");
	glutReshapeFunc(changeSize);
	glutDisplayFunc(display);
	glutSpecialFunc(KeyPlot);
	Initial();


	glutMainLoop();
	return 0;
}



