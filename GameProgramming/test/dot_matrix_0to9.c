#include <stdio.h>
#include <stdlib.h>

void Delay_Clear(int nMsecond)
{
     sleep(nMsecond);
     system("cls");    
}

void Print_Dot(int a)
{
    unsigned char szDot[11][8]={
                 {0x00, 0x38, 0x44, 0x4C, 0x54, 0x64, 0x44, 0x38}, // dot 0
                 {0x00, 0x10, 0x30, 0x50, 0x10, 0x10, 0x10, 0x7C}, // dot 1
                 {0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7C}, // dot 2
                 {0x00, 0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38}, // dot 3
                 {0x00, 0x08, 0x18, 0x28, 0x48, 0x7C, 0x08, 0x08}, // dot 4
                 {0x00, 0x7C, 0x40, 0x78, 0x04, 0x04, 0x44, 0x38}, // dot 5
                 {0x00, 0x38, 0x40, 0x40, 0x78, 0x44, 0x44, 0x38}, // dot 6
                 {0x00, 0x7C, 0x04, 0x08, 0x10, 0x20, 0x20, 0x20}, // dot 7
                 {0x00, 0x38, 0x44, 0x44, 0x38, 0x44, 0x44, 0x38}, // dot 8
                 {0x00, 0x38, 0x44, 0x44, 0x3C, 0x04, 0x44, 0x38}}; // dot 9
     
     int j, i, b;
     //unsigned char num[8] = {0,};
     
     //num = (unsigned char *)szDot;
     
                   /*for(i=0; i<8; i++)
              {
                       if(cBit & (0x80 >> i))
                       {
                             printf("*");
                       }
                       else
                           printf("-");
                       //Print_Dot(i, j, b);
              }
              //cBit = cBit >> 1;

              printf("\n");*/
     
    for(j=0;j<8;j++)
    {
        for(i=0;i<8;i++)
        {
            if( szDot[a][j] & (0x80 >> i) )
            {
                printf("*");
            }
            else
                printf("-");
        }
        printf("\n");
        //sleep(1000);
    }
     
    /*
    if( num[b][j]& (0x80 >> i) ){
        printf("*");
    }
    else
        printf(" ");
    char a=0x23;
    if((a >> i) & 0x01)
          printf("*");
    else
        printf("-");*/
}

int main(int argc, char *argv[])
{

    //unsigned char cBit=0x23;
    int i, j, a, b;

    while(1)
    {
        //Print_Dot(&num[2][0]);
        Print_Dot(2);
        /*if(cBit & 0x01)
        {
              cBit = cBit >> 1;
              cBit = cBit | 0x80;
        }
        else
        {
              cBit=cBit >> 1;
        }*/
        Delay_Clear(1000);
/*      for(b=0;b<10;b++){
          for(a=0;a<10;a++){
              for(j=0;j<8;j++){
                	for(i=0;i<8;i++){
                		if( num[a][j]& (0x80 >> i) ){
                			printf("*");
                
                		}
                		else
                			printf(" ");
                	}
                	if(j==7)
                	{
                            printf("*");
                            //sleep(500);
                    }
 	               printf("\n");
                   //sleep(1000);
 	               
              }
              sleep(500);
              system("cls");
              for(j=0;j<8;j++){
                	for(i=0;i<8;i++){
                		if( num[b][j]& (0x80 >> i) ){
                			printf("*");
                
                		}
                		else
                			printf(" ");
                	}
                	for(i=0;i<8;i++){
                		if( num[a][j]& (0x80 >> i) ){
                			printf("*");
                
                		}
                		else
                			printf(" ");
                	}
 	               printf("\n");
              }
          sleep(500);
          system("cls");
          }
      }*/
  }
  system("PAUSE");	
  return 0;
}
