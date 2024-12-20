#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
long long int sum;
int x[11];
int Check(int row, int col)
{
    for(int i = 1; i < row; i++)
    {
        if(col == x[i] || abs(row - i) ==abs(col - x[i])) 
        	//��ͬһ�л�����ͬһб�ߡ�һ������ͬһ��
            return 0;
    }
    return 1;
}

void backtrack(int k)
{
    if(k>n)     //���һ�ֽ⣬ sum+1
    {
        sum++;
        return;
    }
    for(int i=1; i<=n; i++)//n����
    {
        if(Check(k, i))     //��֦������Ƿ���������
        {
            x[k]=i;      //��¼��k�ʺ��ڵ�i��
            backtrack(k+1);   //�ݹ����
        }
    }

}
int main()
{
	printf("���ݷ�\n");
    for(n=4;n<=16;n++)
    {
        if(n==0)
        {
            break;
        }
        for(int i=0; i<n; i++)
        {
            x[i]=0;
        }
        sum=0;
        backtrack(1);
        printf("n=%d��%lld����\n",n,sum);
    }
    return 0;
}
/*
	int choice; 
	while(1){
		printf("1.���ݷ�n=4~16���н���� 2.λ����n=4~16���н�ͼ�λ�"
		" 3.����ʽʱ���㷨n=4~16���н���� 4.ģ���˻�n=4~16���н����\nchoice=");
		scanf("%d",&choice);
		if(choice==1){
			for(int n=4;n<=16;n++){
			
			}
		}else if(choice==2){
			for(int n=4;n<=16;n++){
				
			}
		}else if(choice==3){
			
		}else if(choice==4){
			
		}
*/
