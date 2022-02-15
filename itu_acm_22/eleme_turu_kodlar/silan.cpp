#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int X,Y,N,D;
	int **board;
	int *control;
	int i,j,t,z,k,a,b,c,d,m,n;
	int count;
	int check;
	
	scanf("%d %d %d %d",&X,&Y,&N,&D);
	board = (int **)calloc(sizeof(int*), Y);
	for(i=0; i<Y; ++i){
		board[i] = (int *)calloc(sizeof(int), X);
	}
	
	control = (int *)calloc(sizeof(int), X);
	
	for(i=0; i<N; ++i){
		scanf("%d %d %d %d",&a,&b,&c,&d);	
		for(j=c; j<d; ++j){
			for(k=a; k<b; ++k){
				board[j][k] = 1;
			}
		}
	}
	
for(z=0; z<D; ++z){
	scanf("%d %d",&m,&n);

	count = 0;
	for(i=0; i<Y; ++i){
		for(j=0; j<X; ++j){
			if(board[i][j] == 0){
				control[j]++;
			}
			else{
				control[j] = 0;
			}
		}
		if(i >= n-1){
			check = 0;
			for(t=0; t<X; t++){
				if(control[t] >= n){
					check++;
				}
				else{
					check = 0;
				}
					
				if(check >= m){
					count++;
				}
				if(check + (X-t) < m){
					break;
				}	
			}
		}		
	}
	printf("%d\n",count);
}
	
	
	
	
	return 0;
}