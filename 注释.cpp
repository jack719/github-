/*
@author: westfarlandia
@date: 2022/4/5
*/
#include <stdio.h>
void process(FILE*,int,int);
int main(){
	FILE*ptr=fopen("dict.dic","r");
	//结束行写在主函数吧 
	int endline[6],i,inputNum,count=0;
	endline[0]=0;
	//这里从1开始 
	for(i=1;i<=5;i++){
		fscanf(ptr,"%d",&(endline[i]));
	}
	fgetc(ptr);
	//输入数字 
	scanf("%d",&inputNum);
	//开始处理 
	process(ptr,endline[inputNum-1],endline[inputNum]);
	fclose(ptr);
	return 0;
}
void process(FILE*ptr,int linel,int line){
	int mark=0,enter=6;
	char ch=fgetc(ptr);
	while(enter<=linel){
		while(ch!=10){
			ch=fgetc(ptr);
		}
		ch=fgetc(ptr);
		enter++;
	}
	while(enter<=line){
		if(mark==0){
			if(ch=='/'){
				mark=1;
			}
			else{
				printf("%c",ch);
			}
		}
		else if(mark==1){
			if(ch=='/'){
				while(ch!=10&&ch!=EOF){
					ch=fgetc(ptr);
				}
				if(ch==10)
					printf("\n");
				mark=0;
			}
			else if(ch=='*'){
				mark=3;
			}
			else{
				printf("/%c",ch);
				mark=0;
			}
		}
		else if(mark==3){
			if(ch=='*'){
				mark=5;
			}
		}
		else if(mark==5){
			if(ch=='/'){
				mark=0;
			}
			else if(ch!='*'&&ch!='/'){
				mark=3;
			}
		}
		if(ch=='\n'||ch==EOF){
			enter++;
		} 
		ch=fgetc(ptr);
	}
}
