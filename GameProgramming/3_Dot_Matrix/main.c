#include <stdio.h>
#include <stdlib.h>

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
                 
unsigned char szNum[8][8]={
                           {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                           {0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x08},
                           {0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x18},
                           {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x28},
                           {0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x48},
                           {0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x7C},
                           {0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x08},
                           {0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x08}};

void Delay_Clear(int nMsecond)
{
     sleep(nMsecond);
     system("cls");
}

void Print_Dot(int a)
{
     int nRow, nCol;
     int j, i, b;
     unsigned char cLsbFlag=0;
     
    /*for(j=0;j<8;j++)
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
    }
    for ( j=0; j<8; j++)
    {
        if( szDot[a][j] & 0x01 )
        {
         szDot[a][j] = szDot[a][j] >> 1;
         szDot[a][j] = szDot[a][j] | 0x80;
        }
        else
        {
         szDot[a][j] = szDot[a][j] >> 1;
        }
    }*/
       	for(nCol=0; nCol<8; nCol++)
        {
            for(nRow=0; nRow<6; nRow++)
            {
                for(i=0; i<8; i++)
                {
                 if(szNum[nCol][nRow] & (0x80 >> i))
                         printf("*");
                 else
                         printf("-");
                }
                printf(" ");
            }
            printf("\n");
        }
        
        for(nCol=0; nCol<8; nCol++)
        {
            for(nRow=7; nRow>=0; nRow--)
            //for(nRow=5; nRow<6; nRow++)
            {
                     if(szNum[nCol][nRow] & 0x01)
                     {
                               szNum[nCol][nRow] = szNum[nCol][nRow] >> 1;
                               if(nRow==7)
                               {
                               			  cLsbFlag=1;
                                       continue;
                               }
                               szNum[nCol][nRow+1] |= 0x80;
                     }
                     else
                     {
                               szNum[nCol][nRow] = szNum[nCol][nRow] >> 1;
                     }
            }
            if(cLsbFlag)
            {
                        szNum[nCol][0] |= 0x80;
                        cLsbFlag=0;
            }
        }
		return;
}

int main(int argc, char *argv[])
{
    int i, j, a, b;
    unsigned char num[6] = {0x23, 0x00, 0x00, 0x00, 0x00, 0x00};

    while(1)
    {
        Print_Dot(2);
        printf("\n");
        Delay_Clear(500);
    }
  system("PAUSE");	
  return 0;
}
