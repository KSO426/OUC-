#include <stdio.h>

void lightShow(char *str,int n){
	//ͳ�����ֶε�����
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
	//ѡ������ٵ��ַ�
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
			//(2)�ڣ�1���Ļ����ϣ���ָ��� 9 �� 9 ��ͬѧ�л����ء��޸�Ϊ���� 9 ��ͬѧ�л����ء���(60 ��)
			if(cnt==0){
				printf("��%d��ͬѧ�л�����",tmp_i+1);
			}else{
				printf("��%d��%d��ͬѧ�л�����",tmp_i+1,tmp_i+cnt+1);
			}
			if(str[i+1]!='\0'){
				printf("\n");
			} 
			cnt=0;
		}
	}
}

	//18 XXOOOXXXOXOOXXOOOX
	//18 OOOOOOOOOOOOOOOOOX �������һ������
	//18 OOOOOOOXOOOOOOOOOX 
	//18 XOOOXOOXOOXOXOOOOX
	/*
	(3)�� 
	�ռ临�Ӷ�ΪO(n)�������ڴ洢�ַ����Ŀռ䡣 
	�и������㷨������˫ָ���ܹ����Ч�ʣ����Ǽ򻯵�12�����»����е��Ѷȵġ� 
	*/
	
int main(){
	int n;
	char str[256];
	scanf("%d ",&n);
	gets(str);
	lightShow(str,n);
	return 0;
}
 
