#include <stdio.h>

int multRecur(int a, int b){
	if (b==0){
		return 0;
	}
	
	if (b==1){
		return a;
	}
	

	if (b==2){
		return a+a;
	}
	
	return multRecur(a,b-1)+a;
}

int main(){
	int mult=multRecur(0,3);
	printf("%d\n",mult);
	return 0;
}
