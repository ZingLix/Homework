#include <glut.h>

GLuint lineList;
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	const int x = 8;
	const int y = 16;
	constexpr int p = x * y;
	GLubyte chess[p]={
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
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(chess);
	glRectf(-10.0, -10.0, 10.0, 10.0);
	glDisable(GL_POLYGON_STIPPLE);//¹Ø±Õ¿ª¹Ø

	glColor4f(0.0, 0.6, 1.0, 1.0);
	glCallList(lineList);

	glFlush();
}


void Initial() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glMatrixMode(GL_PROJECTION);       // Set projection parameters.
//    gluOrtho2D(0.0, 400.0, 0.0, 150.0);

	glLineWidth(12.0);
	glColor4f(0.0, 0.6, 1.0, 1.0);
	lineList = glGenLists(1);
	glNewList(lineList, GL_COMPILE);
//	glRotatef(0, 0, 0, 0);
//	glFrontFace(GL_CCW);
	glBegin(GL_LINE_LOOP);
	


	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(2.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, 1.0);

	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, 1.0);

	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, 1.0);

	//glVertex3f(0.0, 0.0, 0.0);
	//glVertex3f(0.0, 0.0, 0.0);
	//glVertex3f(0.0, 0.0, 0.0);

	glEnd();
	glEndList();
}

void changeSize(GLsizei w,GLsizei h) {
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
	glCallList(lineList);
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Experiment 1");
	glutReshapeFunc(changeSize);
	glutDisplayFunc(display);
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

