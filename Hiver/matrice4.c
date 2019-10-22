#include <stdio.h>
#define dim 4

int main(void) {
	
	int mat[dim][dim]={1,9,10,4,55,-5,7,4,19,23,22,12,3,4,5,88};
	int mat2[dim][dim]; //结果矩阵
	int i, j, ml=1; //ml=max locale
	
	//输出原始矩阵
	for(i=0; i<dim; i++) {
		for(j=0; j<dim; j++) {
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	for(i=0; i<dim; i++) {
		ml=1; //默认max locale为true
		
		for(j=0; (j<dim)&&(ml=1); j++) {
			
			//上方数字对比 （若上方为矩阵边界，对比同列最后一行）
			if((i-1)>=0) {
				if(mat[i][j]<mat[i-1][j]) {
					ml=0;
				}
			}
			else {
				if(mat[i][j]<mat[dim-1-i][j]) {
					ml=0;
				}
			}
			
			
			//左侧数字对比 （若左侧为矩阵边界，对比同行最后一列）
			if((j-1)>=0) {
				if(mat[i][j]<mat[i][j-1]) {
					ml=0;
				}
			}
			else {
				if(mat[i][j]<mat[i][dim-1-j]) {
					ml=0;
				}
			}
			
			//下方数字对比 （若下方为矩阵边界，对比同列第一行）
			if((i+1)!=dim) {
				if(mat[i][j]<mat[i+1][j]) {
					ml=0;
				}
			}
			else {
				if(mat[i][j]<mat[dim-1-i][j]) {
					ml=0;
				}
			}
			
			//右侧数字对比 （若右侧为矩阵边界，对比同行第一列）
			if((j+1)!=dim) {
				if(mat[i][j]<mat[i][j+1]) {
					ml=0;
				}
			}
			else {
				if(mat[i][j]<mat[i][dim-1-j]) {
					ml=0;
				}
			}
			
			//移动数字到结果矩阵，若max locale仍为true，数字替换为0
			if(ml==1) {
				mat2[i][j]=0;
			}
			else {
				mat2[i][j]=mat[i][j];
			}
		}
	}
	
	//输出结果矩阵
	printf("\n");
	for(i=0; i<dim; i++) {
		for(j=0; j<dim; j++) {
			printf("%d\t", mat2[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	return 0;
}