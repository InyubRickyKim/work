#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a, b, c, d;
  printf("For�� 2�� ���\n");
  
  for(a = 0; a<7; a++)
  {
        for(b= 0; b<=a; b++)
               printf("*");
        printf("\n");
  }
  
  printf("For�� 3�� ���\n");
  for(a=0; a<9; a=a+2)
  {
           for(b=8; b>a; b=b-2)
                    printf(" ");
           for(c=0; c<=a; c++)
                    printf("*");
           printf("\n");
  }
  
  printf("For�� 2�� ���, ���ǹ�(if) ���\n");
  for(a=0; a<9; a=a+2)
  {
           c=0;
           d=9;
           for(b=9; b>=0; b--)
           {
                    if(d>a)
                    {
                           printf(" ");
                           d=d-2;
                    }
                    else if(c<=a)
                    {
                            printf("*");
                            c++;
                            continue;
                    }
           }
           printf("\n");
  }
  system("PAUSE");
  
  return 0;
}