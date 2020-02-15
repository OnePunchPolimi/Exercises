#include <stdio.h>

int main(){
	FILE *fp;
	int ris,scan;
	fp=fopen("text.txt","r");
	if(fp){
		printf("opened\n");
		scan=fscanf(fp,"%d",&ris);
		printf("read %d values, ris is %d\n",scan,ris);
	}
	else{
		printf("file open error\n");
	}
	return 0;
}
