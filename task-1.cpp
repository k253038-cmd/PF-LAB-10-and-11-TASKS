#include<stdio.h>
  int sumofdigits(int n){
  	if(n==0){
  		return 0;
	  }
	  else{
	  	return (n%10)+sumofdigits(n/10);
	  }
  }
int main(){
	int num;
	printf("enter a number");
	scanf("%d", &num);
	printf(" %d\n",  sumofdigits(num));
	
}
