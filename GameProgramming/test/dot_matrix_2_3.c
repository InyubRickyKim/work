#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, j;
  char num1[8]={0x00,0x38,0x44,0x04,0x08,0x10,0x20,0x7c};
  char num2[8]={0x00,0x38,0x44,0x04,0x18,0x04,0x44,0x38};

  while(1)
  {
      for(j=0;j<8;j++){
        	for(i=0;i<8;i++){
        		if( num1[j]& (0x80 >> i) ){
        			printf("*");
        
        		}
        		else
        			printf(" ");
        	}
        	printf("\n");
      }
      sleep(1000);
      system("cls");
    
      for(j=0;j<8;j++){
        	for(i=0;i<8;i++){
        		if( num2[j]& (0x80 >> i) ){
        			printf("*");
        
        		}
        		else
        			printf(" ");
        	}
        	printf("\n");
      }
      sleep(1000);
      system("cls");
  }
  system("PAUSE");	
  return 0;
}
