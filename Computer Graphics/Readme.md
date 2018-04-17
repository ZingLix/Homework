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
