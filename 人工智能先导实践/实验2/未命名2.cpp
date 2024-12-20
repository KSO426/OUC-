#include <graphics.h>// 引入 ege 头文件
#include <math.h>
int main(){
	initgraph(640,480);// 初始化窗口大小
	setbkcolor(WHITE);//设置背景颜色为白色
	cleardevice();// 清屏
	//这里开始绘制曲线
	
	setcolor(RED);// 设置曲线颜色为红色
	for (int x =0;x <= 640; x++){
		int y = 240 - 100 * sin(x * 3.14 / 180);// 计算y 坐标
		putpixel(x, y,RED);//在(x， y)处绘制一个像素点
	}
	getch();// 等待用户按键
	closegraph();//关闭图形窗口
	return 0;
}
