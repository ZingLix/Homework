#include <iostream>
#include <list>
#include <glut.h>

static int iMode = 1;
int win_width = 400, win_height = 300;
int point_number = 0;
int X1 = 0, X2 = 0, Y1 = 0, y2 = 0;

struct node
{
	int x;
	int y;
};

std::list<node>* nodeList;

void Initial(){
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void ChangeSize(int w,int h) {
	win_width = w;
	win_height = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, win_width, 0.0, win_height);
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	if (point_number > 0) {
		glBegin(GL_LINES);
		if (iMode == 1) {
			auto it = nodeList->begin();
			int x_tmp = it->x, y_tmp = it->y;
			++it;
			while (it!=nodeList->end()) {

				glVertex2i(x_tmp, y_tmp);
				glVertex2i(it->x, it->y);
				x_tmp = it->x;
				y_tmp = it->y;
				++it;
			}
			if(point_number==1) {
				glVertex2i(x_tmp, y_tmp);
				glVertex2i(X2, y2);
			}
		}
		else {
			glVertex2i(X1, Y1);
			glVertex2i(X1, y2);
			glVertex2i(X1, y2);
			glVertex2i(X2, y2);
			glVertex2i(X2, y2);
			glVertex2i(X2, Y1);
			glVertex2i(X2, Y1);
			glVertex2i(X1, Y1);
		}
		glEnd();
	}
	glutSwapBuffers();
}

void MousePlot(GLint button,GLint action,GLint x_mouse,GLint y_mouse) {
	if(button==GLUT_LEFT_BUTTON&&action==GLUT_DOWN) {
		node tmp;
		tmp.x = x_mouse;
		tmp.y = win_height - y_mouse;
		nodeList->push_back(tmp);
	}
	if(button==GLUT_RIGHT_BUTTON&&action==GLUT_DOWN) {
		point_number = 0;
		glutPostRedisplay();
	}
}

void PassiveMouseMove(GLint x_mouse, GLint y_mouse) {
	if (point_number == 1) {
		X2 = x_mouse;
		y2 = win_height - y_mouse;
		glutPostRedisplay();
	}
}

void KeyPlot(unsigned char key, int x_mouse, int y_mouse) {
	switch (key) {
	case 'P':
	case 'p': {
		point_number = 1;
		if(iMode==1) nodeList->clear();
		X1 = x_mouse;
		Y1 = win_height - y_mouse;
		node tmp;
		tmp.x = x_mouse;
		tmp.y = win_height- y_mouse;
		if (iMode == 1) nodeList->push_back(tmp);
		glutMouseFunc(MousePlot);
		glutPassiveMotionFunc(PassiveMouseMove);
		break;
	}
	case 'C':
	case 'c': {
		point_number = 2;
		X2 = x_mouse;
		y2 = win_height - y_mouse;
		glutPostRedisplay();
		glutMouseFunc(nullptr);
		glutPassiveMotionFunc(nullptr);
	}
	default: break;

	}
}


void ProcessMenu(int value) {
	iMode = value;
	point_number = 0;
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	nodeList = new std::list<node>;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Experiment 1");
	glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Ö±Ïß", 1);
	glutAddMenuEntry("¾ØÐÎ", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(Display);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(KeyPlot);

	Initial();
	glutMainLoop();
	delete nodeList;
	return 0;
}

