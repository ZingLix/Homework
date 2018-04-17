#include <glut.h>

int flag = 2;
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

void KeyPlot(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:{
		degree += 1;
		break;
	}
	case GLUT_KEY_DOWN: {
		degree -= 1;
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

float abs(float x) {
	return x < 0 ? -x : x;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glOrtho(-1.0, 1.0, -1, 1.0, -10, 10);

	glPushMatrix();
	glRotatef(degree, 1, 0, 0);
	glRotatef(degreeY, 0, 1, 0);
	if (flag == 2) {
		glColor3f(0.0, 0.0, 0.0);
		glEnable(GL_POLYGON_STIPPLE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glPolygonStipple(chess);
		glCallList(lineList);
		glRectf(50.0f, 100.0f, 150.0f, 50.0f);
		glDisable(GL_POLYGON_STIPPLE);
	}

	glLineWidth(5.0);
	glColor4f(0.0, 0.6, 1.0, 1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glCallList(lineList);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void Initial() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);

	lineList = glGenLists(1);
	glNewList(lineList, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(2.0, 1.0, 0.0);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(2.0, 0.0, 0.0);
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

void displayW() {
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLineWidth(12.0);
	glColor4f(0.0, 0.6, 1.0, 1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glCallList(lineList);
	glFlush();
}


void ProcessMenu(int value) {
	flag = value;
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Experiment 1");
	glutReshapeFunc(changeSize);
	glutDisplayFunc(display);
	glutCreateMenu(ProcessMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Ïß¿ò", 1);
	glutAddMenuEntry("Ìî³ä", 2);
	glutSpecialFunc(KeyPlot);
	Initial();

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Experiment 1w");
	glutReshapeFunc(changeSize);
	glutDisplayFunc(displayW);
	Initial();
	glutMainLoop();
	return 0;
}



