#include<stdio.h>
#include<string.h>



int main(){
	printf("%d",strcmp("2 4 6", "1 3 8"));
	printf("%d",strcmp("2 4 6", "1 3 8"));
	printf("%d",strcmp("2 4 6", "1 5 6"));
	printf("%d",strcmp("2 4 6", "1 5 6"));
	printf("%d",strcmp("2 4 6", "1 5 6"));
	printf("%d",strcmp("2 4 6", "3 4 5"));

/*
    1 2 9
1 3 8
1 4 7
1 5 6
2 3 7
2 4 6
3 4 5*/
	int i,j,k,n;
	int control = 0;
	
	scanf("%d",&n);
	
	i=1;
	while(i<n){
		j=i+1;
		while(j<n && !control){
			k=j+1;
			while(k<n && !control){
				if(i+j+k == n){
					if(i^j^k == 0){
						printf("%d %d %d\n",i,j,k);
						//control = 1;
					}
				}
				k++;
			}
			j++;
		}
		i++;	
	}
	
/*	int x = 1;
	i=n/3;
	while(i+x<n && i>1 && !control){
		if((i-x) ^ (i) ^ (i+x) == 0){
			printf("%d %d %d",i-x,i,i+x);
			control = 1;
		}
		x++;
	}*/
	
	if(control == 0){
		printf("-1");
	}
	return 0;
}