#include <complex>
#include <glut.h> 
#include <windows.h>

GLsizei iMode = 3;
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
int wid = 1000, hei = 500;
GLfloat eyeX = 5.0f, eyeY = 5.0f, eyeZ = 5.0f;
const float PI = 3.1415926;

#define MAX_CHAR 128
void drawString(const char* str, GLfloat x, GLfloat y, GLfloat z) {
	static GLuint lists;
	lists = glGenLists(MAX_CHAR);
	wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	glListBase(lists);
	glRasterPos3f(x, y, z);
	glCallLists(strlen(str), GL_UNSIGNED_BYTE, str);
	glDeleteLists(lists, MAX_CHAR);
}

void draw() {
	glColor4f(1, 0, 0, 0);
	drawString("x", -2, 0.1, 0);
	glColor4f(0, 1, 0, 0);
	drawString("y", 0.1, 2, 0);
	glColor4f(0, 0, 1, 0);
	drawString("z", 0.1, 0.1, 2);
}

void rotateX(float degree)
{
	degree *= PI / 180;
	double tmp = eyeY * cos(degree) - eyeZ * sin(degree);
	eyeZ = eyeY * sin(degree) + eyeZ * cos(degree);
	eyeY = tmp;
}

void rotateY(float degree)
{
	degree *= PI / 180;
	float tmp = eyeZ * sin(degree) + eyeX * cos(degree);
	eyeZ = eyeZ * cos(degree) - eyeX * sin(degree);
	eyeX = tmp;
}

void KeyPlot(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: {
		rotateX(1);
		break;
	}
	case GLUT_KEY_DOWN: {
		rotateX(-1);
		break;
	}
	case GLUT_KEY_LEFT: {
		rotateY(1);
		break;
	}
	case GLUT_KEY_RIGHT: {
		rotateY(-1);
		break;
	}
	default: break;
	}

	glutPostRedisplay();
}

void triangle(GLsizei mode) {
	float x;
	if (wid > hei * 2) x = (float)(hei) / ((float)wid / 2.0);
	else { x = ((float)wid / 2) / (float)(hei); }
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3 * x, 3 * x, -3 * x, 3 * x, -20, 20);
	if (mode == 1) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		switch (iMode) {
		case 3: gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); break;
		case 2: gluLookAt(5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f); break;
		case 1: default: gluLookAt(0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		}
		glCallList(lineList);
		glCallList(coordinate);
		glPopMatrix();
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glMatrixMode(GL_PROJECTION);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eyeX, eyeY, eyeZ, 0, 0, 0, 0, 1, 0);
		glPushMatrix();
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
	glColor4f(1, 0, 0, 0);
	glVertex3f(-3, 0, 0);
	glVertex3f(3, 0, 0);
	glColor4f(0, 1, 0, 0);
	glVertex3f(0, -3, 0);
	glVertex3f(0, 3, 0);
	glColor4f(0, 0, 1, 0);
	glVertex3f(0, 0, 3);
	glVertex3f(0, 0, -3);
	glEnd();
	glEndList();
}

void changeSize(GLsizei w, GLsizei h) {
	wid = w;
	hei = h;
	glLoadIdentity();
	glutPostRedisplay();
}

void ProcessMenu(int value)
{
	iMode = value;
	glutPostRedisplay();
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
	glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("正视图XOZ(V)", 1);
	glutAddMenuEntry("侧视图YOZ(W)", 2);
	glutAddMenuEntry("俯视图XOY(H)", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	Initial();

	glutMainLoop();
	return 0;
}
