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
        	//在同一列或者在同一斜线。一定不在同一行
            return 0;
    }
    return 1;
}

void backtrack(int k)
{
    if(k>n)     //求出一种解， sum+1
    {
        sum++;
        return;
    }
    for(int i=1; i<=n; i++)//n叉树
    {
        if(Check(k, i))     //剪枝，检查是否满足条件
        {
            x[k]=i;      //记录第k皇后在第i列
            backtrack(k+1);   //递归查找
        }
    }

}
int main()
{
	printf("回溯法\n");
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
        printf("n=%d有%lld个解\n",n,sum);
    }
    return 0;
}
/*
	int choice; 
	while(1){
		printf("1.回溯法n=4~16所有解个数 2.位运算n=4~16可行解图形化"
		" 3.多项式时间算法n=4~16所有解个数 4.模拟退火n=4~16所有解个数\nchoice=");
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
