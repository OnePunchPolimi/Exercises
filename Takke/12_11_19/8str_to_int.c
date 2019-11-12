#include<stdio.h>
#define L 50


int main(){
	char s[L+1];
	int i=-1;
	int ris=0;
	scanf("%s",s);
	while(s[++i]-'0'>=0 && s[i]-'0'<=9){
		ris*=10;
		ris+=s[i]-'0';
	}
	if(s[i]=='\0'){
		printf("%d\n",ris);
	}
	else{
		printf("-1\n");
	}
	return 0;
}