#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
int main(){
	int order = "white";
	int input1;
	int input2;
	
	do{
				printf(" invalid input! (should be less than 6)");
 				printf(" out a new %f othello : like 3 5 ", order);
  				scanf(" %d %d ",&input1, &input2);
  				}
  				while (input1<= 0 || input1>=6 || input2<=0 || input2 >=6);
	
	return 0;
			}
			
