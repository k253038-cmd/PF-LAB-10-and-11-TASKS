#include<stdio.h>
#include<string.h>
 void reverse(char str[], int i){
 	if(i<0) 
	 return	;
 printf("%c",str[i]);
 		reverse(str, i-1);
 	}
 
	 int main(){
	char str[100];
	printf("enter a string");
         gets(str);
    str[strcspn(str, "\n")] = '\0';
	reverse(str, strlen(str)-1);
	return 0;
	
}
