#include <stdio.h>

void lightShow(char *str,int n){
	//统计两种段的数量
	int X_cnt=0,O_cnt=0;
	char last = 'A';
	for(int i=0;str[i]!='\0';i++){
		if(last!=str[i]){
			if(str[i]=='X'){
				X_cnt++;
			}else{
				O_cnt++;
			}
			last = str[i];
		}
	} 
	//选择段数少的字符
	char flag = 'O';
	if(X_cnt<O_cnt){
		flag = 'X';
	}
	int cnt = 0,tmp_i=0;
	for(int i=0;str[i]!='\0';i++){
		if(str[i]==flag){
			if(i==0||str[i-1]!=flag){
				tmp_i = i;
			}else{
				cnt++;
			}
		}else if(i>=1&&str[i-1]==flag){
			//(2)在（1）的基础上，将指令“请 9 到 9 号同学切换开关”修改为“请 9 号同学切换开关”。(60 分)
			if(cnt==0){
				printf("请%d号同学切换开关",tmp_i+1);
			}else{
				printf("请%d到%d号同学切换开关",tmp_i+1,tmp_i+cnt+1);
			}
			if(str[i+1]!='\0'){
				printf("\n");
			} 
			cnt=0;
		}
	}
}

	//18 XXOOOXXXOXOOXXOOOX
	//18 OOOOOOOOOOOOOOOOOX 输出任意一个即可
	//18 OOOOOOOXOOOOOOOOOX 
	//18 XOOOXOOXOOXOXOOOOX
	/*
	(3)答： 
	空间复杂度为O(n)，是用于存储字符串的空间。 
	有更简洁的算法，采用双指针能够提高效率，但是简化到12行以下还是有点难度的。 
	*/
	
int main(){
	int n;
	char str[256];
	scanf("%d ",&n);
	gets(str);
	lightShow(str,n);
	return 0;
}
 
