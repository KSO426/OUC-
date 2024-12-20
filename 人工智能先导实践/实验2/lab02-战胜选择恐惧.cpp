#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>// 引入 ege 头文件
#include <math.h>

int main(){
	srand(time(NULL));//当前时间作为随机数种子 
	
	double sum=0;//方案1：对于10000次模拟，计算随机取1个即为最大价值的概率
	int k_cnt[100]={0};//方案2：对于每个k，记下整个过程中可选中最高价值的次数
	for(int i=0;i<10000;i++){//模拟10000次
		int max_value_cnt=0,max_value=0;//记录每次模拟的最大价值及重复次数 
		int uniform_int_random_1_100[100]={0};//用于存储每次模拟生成的100个随机数
		for(int j=0;j<100;j++){//每次生成100个随机数 
			uniform_int_random_1_100[j] = 1 + rand() % 100;
			if(uniform_int_random_1_100[j]>max_value){//更新max_value并记录重复次数 
				max_value=uniform_int_random_1_100[j];
				max_value_cnt=1;
			}else if(uniform_int_random_1_100[j]==max_value){
				max_value_cnt++;
			}
		}
		
		//对于每个分布，分别让k等于1到99
		for(int k=1;k<=99;k++){
			int v=0;//设前 k 个奖品的最高价值为 v 
			for(int m=0;m<k;m++){ //确定v 
				if(v<uniform_int_random_1_100[m]){
					v=uniform_int_random_1_100[m];
				}
			} 
			
			if(v==max_value){//如果最高价值在前k个奖品中，则一定不会选中最高价值的奖品
				continue;
			}else{//反之，选中最高价值的概率为多少呢？
				for(int m=k;m<100;m++){
					if(uniform_int_random_1_100[m]>v){//选择第一个价值大于 v 的奖品
						if(uniform_int_random_1_100[m]==max_value){//如果是最大价值则记录 
							k_cnt[k]++;
						}
						break;
					}
				}
			}
		} 
		sum += max_value_cnt;
	}
	
	//求取到最大价值的概率
	double ret1=0,ret2=0;
	ret1 = sum/(100*10000);ret1 *= 100;
	printf("对于模式1，能够拿到最大价值的概率为：%f%%\n",ret1);
	
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
	printf("\n对于模式2，当k=%d时取最大价值的次数为：%d,能够拿到最大价值的概率为：%f%%\n",37,max_k_cnt,ret2);
	
	//绘制概率曲线
	initgraph(640,480);// 初始化窗口大小
	setbkcolor(WHITE);//设置背景颜色为白色
	cleardevice();// 清屏
	//这里开始绘制曲线
	setcolor(RED);// 设置曲线颜色为红色
	for (int k=1;k<=99;k++){
		int x = k;
		double y = (double)k_cnt[k]/100;// 计算y 坐标
		putpixel(640/2+x, 480/2-y,RED);//在(x， y)处绘制一个像素点
	}
	getch();// 等待用户按键
	closegraph();//关闭图形窗口
	return 0;
} 
