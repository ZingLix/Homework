# Computer Graphics

## Experiment 1

- 实现菜单，菜单项为直线、矩形
- 通过鼠标移动实现橡皮筋效果
- 通过键盘输入'p'确定点坐标，‘c'结束橡皮筋绘制
- 通过链表实现多点折线橡皮筋技术

## Experiment 2

- 定义黑白相间的棋盘图案
- 通过段，定义四面体图元
- 设计菜单，菜单项是线框和填充，菜单项值分别为1、2，实现填充的、线框的正交观察四面体
- 利用 `glLineWidth(GLfloat width)`，适当设置线宽，利用颜色混合函数 `glBlendFunc(GL_SCR_ALPHA, GL_ONE_MINUS_SRC_ALPHA)`，观察线框的四面体反走样效果

## Experiment 3

- 参考p181程序6-2，使得窗口显示左右2个视区，左视区显示线框的四面体,右视区显示填充棋盘图案的四面体
- 利用 `GLint vp[4]; glGetIntegerv(GL_VIEWPORT ,vp)` 获得视区的左下角坐标、宽度和高度信息，通过`glOrtho(gldouble left, gldouble right, gldouble bottom, gldouble top,gldouble zNear, gldouble zFar)`，定义三维正交观察可视体，使得坐标原点在视区中心
- 参考p91程序4-1，利用键盘上、下、左、右（`GLUT_KEY_UP`、`GLUT_KEY_DOWN`、`GLUT_KEY_LEFT`、`GLUT_KEY_RIGHT`）功能键，控制右视区的四面体分别绕x、y轴旋转

## Experiment 4

- 通过段，定义三维坐标，x轴为红色、y轴为绿色、z轴为蓝色
- 利用`glOrtho(gldouble left, gldouble right, gldouble bottom, gldouble top,gldouble zNear, gldouble zFar)`，定义左视区的三维正交观察可视体
- 利用`gluPerspective(gldouble fovy,gldouble aspect, gldouble zNear, gldouble zFar)`，定义右视区的三维透视观察可视体
- 定义菜单，菜单项为“正视图XOZ(V)”、“侧视图YOZ(W)”和“俯视图XOY(H)”，菜单项值分别为1、2和3
- 利用`gluLookAt(gldouble eyex,gldouble eyey,gldouble eyez,gldouble centerx, gldouble centery,gldouble centerz,gldouble upx,gldouble upy,gldouble upz)`，控制左视区的照相机的位置，使得左视区按菜单选择，正视图、侧视图和俯视图正交观察四面体
- 利用键盘上、下、左、右功能键，控制右视区的照相机的位置，分别绕x、y 轴旋转
- 给出显示字符串的函数`drawString()`如下，显示坐标系的标志
``` cpp
#include <stdlib.h>  
#include <windows.h>
#define MAX_CHAR 128 
void drawString(const char* str,GLfloat x,GLfloat y,GLfloat z ){
    //按x,y,z为起始位置，显示字符串str  
    static GLuint lists;    
	lists = glGenLists(MAX_CHAR); 
	wglUseFontBitmaps(wglGetCurrentDC(),0,MAX_CHAR,lists);
	glListBase(lists);
	//起始位置
	glRasterPos3f(x,y,z);    
	glCallLists(strlen(str),GL_UNSIGNED_BYTE,str);
}

```