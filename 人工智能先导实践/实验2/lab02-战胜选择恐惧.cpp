#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>// ���� ege ͷ�ļ�
#include <math.h>

int main(){
	srand(time(NULL));//��ǰʱ����Ϊ��������� 
	
	double sum=0;//����1������10000��ģ�⣬�������ȡ1����Ϊ����ֵ�ĸ���
	int k_cnt[100]={0};//����2������ÿ��k���������������п�ѡ����߼�ֵ�Ĵ���
	for(int i=0;i<10000;i++){//ģ��10000��
		int max_value_cnt=0,max_value=0;//��¼ÿ��ģ�������ֵ���ظ����� 
		int uniform_int_random_1_100[100]={0};//���ڴ洢ÿ��ģ�����ɵ�100�������
		for(int j=0;j<100;j++){//ÿ������100������� 
			uniform_int_random_1_100[j] = 1 + rand() % 100;
			if(uniform_int_random_1_100[j]>max_value){//����max_value����¼�ظ����� 
				max_value=uniform_int_random_1_100[j];
				max_value_cnt=1;
			}else if(uniform_int_random_1_100[j]==max_value){
				max_value_cnt++;
			}
		}
		
		//����ÿ���ֲ����ֱ���k����1��99
		for(int k=1;k<=99;k++){
			int v=0;//��ǰ k ����Ʒ����߼�ֵΪ v 
			for(int m=0;m<k;m++){ //ȷ��v 
				if(v<uniform_int_random_1_100[m]){
					v=uniform_int_random_1_100[m];
				}
			} 
			
			if(v==max_value){//�����߼�ֵ��ǰk����Ʒ�У���һ������ѡ����߼�ֵ�Ľ�Ʒ
				continue;
			}else{//��֮��ѡ����߼�ֵ�ĸ���Ϊ�����أ�
				for(int m=k;m<100;m++){
					if(uniform_int_random_1_100[m]>v){//ѡ���һ����ֵ���� v �Ľ�Ʒ
						if(uniform_int_random_1_100[m]==max_value){//���������ֵ���¼ 
							k_cnt[k]++;
						}
						break;
					}
				}
			}
		} 
		sum += max_value_cnt;
	}
	
	//��ȡ������ֵ�ĸ���
	double ret1=0,ret2=0;
	ret1 = sum/(100*10000);ret1 *= 100;
	printf("����ģʽ1���ܹ��õ�����ֵ�ĸ���Ϊ��%f%%\n",ret1);
	
	int max_k_cnt=0,right_k=0;
	for(int i=1;i<=99;i++){
		//printf("k_cnt[%d]=%d\n",i,k_cnt[i]);
		printf("%d,",k_cnt[i]);
		if(max_k_cnt<k_cnt[i]){
			max_k_cnt=k_cnt[i];
			right_k=i;
		}
	} 
	ret2 = (double)max_k_cnt/10000;ret2 *= 100;
	printf("\n����ģʽ2����k=%dʱȡ����ֵ�Ĵ���Ϊ��%d,�ܹ��õ�����ֵ�ĸ���Ϊ��%f%%\n",37,max_k_cnt,ret2);
	
	//���Ƹ�������
	initgraph(640,480);// ��ʼ�����ڴ�С
	setbkcolor(WHITE);//���ñ�����ɫΪ��ɫ
	cleardevice();// ����
	//���￪ʼ��������
	setcolor(RED);// ����������ɫΪ��ɫ
	for (int k=1;k<=99;k++){
		int x = k;
		double y = (double)k_cnt[k]/100;// ����y ����
		putpixel(640/2+x, 480/2-y,RED);//��(x�� y)������һ�����ص�
	}
	getch();// �ȴ��û�����
	closegraph();//�ر�ͼ�δ���
	return 0;
} 
