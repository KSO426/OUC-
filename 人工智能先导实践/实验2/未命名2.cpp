#include <graphics.h>// ���� ege ͷ�ļ�
#include <math.h>
int main(){
	initgraph(640,480);// ��ʼ�����ڴ�С
	setbkcolor(WHITE);//���ñ�����ɫΪ��ɫ
	cleardevice();// ����
	//���￪ʼ��������
	
	setcolor(RED);// ����������ɫΪ��ɫ
	for (int x =0;x <= 640; x++){
		int y = 240 - 100 * sin(x * 3.14 / 180);// ����y ����
		putpixel(x, y,RED);//��(x�� y)������һ�����ص�
	}
	getch();// �ȴ��û�����
	closegraph();//�ر�ͼ�δ���
	return 0;
}
