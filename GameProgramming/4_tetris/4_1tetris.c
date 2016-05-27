#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

#define 	MAX_ROW_SZ		13
#define 	MAX_COL_SZ		23

#define		MAX_BLOCK_WAY	4
#define		MAX_BLOCK_COL	4
#define		MAX_BLOCK_ROW	4

#define		TEXT_COLOR_BLUE		9
#define		TEXT_COLOR_RED		12
#define		TEXT_COLOR_WH		15

#define		RET_BLOCK_CONT		0
#define		RET_BLOCK_END		1

unsigned char szBG[10][10]={
		 	  				{0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		 	  				{0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		 	  				{0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		 	  				{0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		 	  				{0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00},
		 	  				{0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00},
		 	  				{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00},
		 	  				{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00},
		 	  				{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01},
		 	  				{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01}};

unsigned char szBoard[MAX_COL_SZ][MAX_ROW_SZ]={
		 	  				   {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
		 	  				   {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}};

unsigned char szBlock1[MAX_BLOCK_WAY][MAX_BLOCK_COL][MAX_BLOCK_ROW]={
		 	                   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x01, 0x00, 0x00}, {0x00, 0x01, 0x01, 0x01}, {0x00, 0x00, 0x00, 0x00}},
		 	                   {{0x00, 0x00, 0x01, 0x00}, {0x00, 0x00, 0x01, 0x00}, {0x00, 0x01, 0x01, 0x00}, {0x00, 0x00, 0x00, 0x00}},
		 	                   {{0x00, 0x00, 0x00, 0x00}, {0x01, 0x01, 0x01, 0x00}, {0x00, 0x00, 0x01, 0x00}, {0x00, 0x00, 0x00, 0x00}},
		 	                   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x01, 0x01, 0x00}, {0x00, 0x01, 0x00, 0x00}, {0x00, 0x01, 0x00, 0x00}}};

void Delay_Clear(int nMsecond)
{
     sleep(nMsecond);
     system("cls");
}

//void Print_Dot(int nCol, int nRow, unsigned char *szBoard)
void Print_Dot(int nCol, int nRow)
{
 	 int nBufCol, nBufRow;
 	 //int nInd;
 	 //unsigned char szBuf[MAX_COL_SZ][MAX_ROW_SZ]={0,};
 	 
 	 //*((unsigned char *)&szBuf) = (unsigned char *)szBoard;
 	 
 	 for(nBufCol = 0; nBufCol < nCol; nBufCol++)
	 {
		 	 for(nBufRow = 0; nBufRow < nRow; nBufRow++)
		 	 {
					//nInd = 1;
					//nInd = (nInd*nBufCol) + nBufRow;
			  		  //if(szBG[nBufCol][nBufRow] & 0x01)
			  		  //if( ( szBoard + nInd ) & 0x01 )
			  		  if(szBoard[nBufCol][nBufRow] & 0x01)
			  		  	   printf("*");
	                  else
	 				   	   printf("-");
	 		 }
	 		 printf("\n");
	 }
}

int Clear_BlockCol(int nCol, int nRow)
{
 	szBoard[nCol][nRow] = 0x00;
 	
 	return 0;
}

int Set_BlockCol(int nCol, int nRow)
{
 	//int nBufCol, nBufRow;
 	
 	szBoard[nCol][nRow] = 0x01;
 	
 	return 0;
}

int Clnup_BlockRow(int nMaxCol, int nMaxRow)
{
 	 unsigned char cBlockChg=0;
 	 unsigned int nBufCol;
 	 unsigned int nBufCol2;
	 unsigned int nBufRow;
 	 unsigned int nChkCount=0;

	 for(nBufCol = 1; nBufCol <= nMaxCol; nBufCol++)
	 {
	         nChkCount = 0;
	         if(szBoard[nBufCol][1] & 0x01)
	         {
				 	 for(nBufRow = 1; nBufRow <= nMaxRow; nBufRow++)
				 	 {
							 if(szBoard[nBufCol][nBufRow] & 0x01)
					  		 {
							     nChkCount++;
					  		 }
				     }
			 }
			 else
			 	 	 continue;

		     if(nChkCount == nMaxRow)
		     {
 			         cBlockChg = 1;
					 for(nBufRow = 1; nBufRow <= nMaxRow; nBufRow++)		// Clear 1 line
					 {
			 			 Clear_BlockCol(nBufCol, nBufRow);
			 			 //printf("clean up block row.[nChkCount = %d]\n", nChkCount);
			 			 for(nBufCol2=nMaxCol; nBufCol2 > 1; nBufCol2--)
			 			 {
					 			 if(szBoard[nBufCol2-1][nBufRow] & 0x01)
					 			 {
										szBoard[nBufCol2][nBufRow] = szBoard[nBufCol2-1][nBufRow];
										Clear_BlockCol(nBufCol2-1, nBufRow);
				  				 }
						 }
					 }
		     }
	 }
	 
	 if(cBlockChg)
	 {
		 for(nBufCol = 1; nBufCol <= nMaxCol; nBufCol++)
		 {
		  			 for(nBufRow = 1; nBufRow <= nMaxRow; nBufRow++)
		  			 {
					  			 if(szBoard[nBufCol][nBufRow] & 0x01)
					  			 {
	 							      gotoxy(nBufRow, nBufCol);
	 							      printf("*");
						  		 }
						  		 else
						  		 {
								  	  gotoxy(nBufRow, nBufCol);
								  	  printf(" ");
								 }
		 			 }
		 }
#if 0
		 unsigned int a, b;
	 	for(a=0; a < MAX_COL_SZ-1; a++)
	 	{
		 		 for(b=0; b < MAX_ROW_SZ-1; b++)
		 		 {
				  		  printf("%02X", szBoard[a][b]);
				  		  printf(" ");
	 		  	 }
	 		  	 printf("\n");
		}
#endif
	 }
	 return 0;
}

gotoxy(int x, int y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetCln_NewBlock(unsigned int nBlockCol, unsigned int nBlockRow)
{
     //gotoxy(nBlockRow, nBlockCol);
     //printf("*");
     Set_BlockCol(nBlockCol, nBlockRow);
	 Clnup_BlockRow(MAX_COL_SZ-3, MAX_ROW_SZ-3);
}

void Print_Block(int nBlockWay)
{
	unsigned int nBufBlockCol, nBufBlockRow;
	for(nBufBlockCol = 0; nBufBlockCol < MAX_BLOCK_COL; nBufBlockCol++)
	{
	 	for(nBufBlockRow = 0; nBufBlockRow < MAX_BLOCK_ROW; nBufBlockRow++)
 		{
			if(szBlock1[nBlockWay][nBufBlockCol][nBufBlockRow] & 0x01)
			{
	  			gotoxy(nBufBlockRow, nBufBlockCol);
	  			printf("*");
			}
			else
			{
				gotoxy(nBufBlockRow, nBufBlockCol);
	  			printf(" ");
			}
		}
	 }
	 sleep(1000);
}

#if 1
//int Chk_DupDotCnt(unsigned int nMinRow, unsigned int nMinCol, unsigned int nMaxRow, unsigned int nMaxCol, unsigned int nBlockWay)
int Chk_DupDot(unsigned int *pMinRow, unsigned int *pMinCol, unsigned int *pMaxRow, unsigned int *pMaxCol, unsigned int nBlockWay)
{
	unsigned int nDupCnt=0;
	unsigned int nBufRow, nBufCol;
	unsigned int nBlockRow;
	unsigned int nBlockCol = 0;
	unsigned int nMinRow =0, nMinCol=0, nMaxRow=0, nMaxCol=0;
	
	nMinRow = (unsigned int ) *pMinRow;
	nMinCol = (unsigned int ) *pMinCol;
	nMaxRow = (unsigned int ) *pMaxRow;
	nMaxCol = (unsigned int ) *pMaxCol;

	for(nBufRow = nMinRow, nBlockRow = 0; nBufRow < nMaxRow; nBufRow++, nBlockRow++)
	{
		if(szBoard[nMaxCol+1][nBufRow] & szBlock1[nBlockWay][MAX_BLOCK_COL-1][nBlockRow])
		{
			*pMinRow = 3;
			*pMaxRow = 6;
			*pMinCol = 0;
			*pMaxCol = 3;
			
			return RET_BLOCK_END;
		}
	}

	/*for(nChkCol = MAX_BLOCK_COL-1; nChkCol >= MAX_BLOCK_COL-2; nChkCol--)
	{
		nMinRow = 0;
		for(nChkRow = 0; nChkRow < MAX_BLOCK_ROW; nChkRow++)
		{
			if( (szBoard[nMaxCol-1][nMinRow] & szBlock1[0][nChkCol][nChkRow]) == 0x01)
			{
				*pMinRow = 3;
				*pMaxRow = 6;
				*pMinCol = 0;
				*pMaxCol = 3;
					
				return;
			}
			nMinRow++;
		}
	}
	
	for(nBufCol = nMinCol; nBufCol <= nMaxCol; nBufCol++)
	{
		nBlockRow = 0;
		for(nBufRow = nMinRow; nBufRow <= nMaxRow; nBufRow++)
		{
			if(szBG[nBufCol][nBufRow] & szBlock1[nBlockWay][nBlockCol][nBlockRow])
				nDupCnt++;
			nBlockRow++;
		}
		nBlockCol++;
	}*/
	
	return RET_BLOCK_CONT;
}

void Print_BG(unsigned int nCol, unsigned int nRow)
{
 	 int nBufCol, nBufRow;
 	 //int nInd;
 	 //unsigned char szBuf[MAX_COL_SZ][MAX_ROW_SZ]={0,};
 	 
 	 //*((unsigned char *)&szBuf) = (unsigned char *)szBoard;
 	 
 	 for(nBufCol = 0; nBufCol < nCol; nBufCol++)
	 {
		 	 for(nBufRow = 0; nBufRow < nRow; nBufRow++)
		 	 {
					gotoxy(nBufRow, nBufCol);
			  		  if(szBoard[nBufCol][nBufRow] & 0x01)
			  		  {
							//gotoxy(nBufRow, nBufCol);
			  		  	   printf("*");
						}
	                  else
	                  {
							//gotoxy(nBufRow, nBufCol);
	 				   	   printf(" ");
						}
	 		 }
	 		 //printf("\n");
	 }
	 
	 for(nBufCol = 0; nBufCol < 4; nBufCol++)
	 {
		 	 for(nBufRow = 0; nBufRow < 4; nBufRow++)
		 	 {
					gotoxy(nBufRow+nRow+1, nBufCol);
			  		  if(szBlock1[0][nBufCol][nBufRow] & 0x01)
			  		  	   printf("*");
	                  else
	 				   	   printf(" ");
	 		 }
	 		 printf("\n");
	 }
}

textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

void Mv_CheckGraphic(unsigned int *npMinRow, unsigned int *npMinCol, unsigned int *npMaxRow, unsigned int *npMaxCol)
{
	unsigned int nMinRow=0, nMinCol=0, nMaxRow=0, nMaxCol=0;
	unsigned int nChkCol, nChkRow;
	unsigned int nBlockWay = 0, nBlockRow, nBlockCol;

#if 1
	gotoxy(20, 0);
	printf("MinCol : %ld, MaxCol : %ld, MinRow : %ld, MaxRow : %ld\n", 
			*npMinCol, *npMaxCol, *npMinRow, *npMaxRow);
#endif

	nMaxRow = *npMaxRow;
	//nMinCol = *npMinRow;
	nMaxCol = *npMaxCol;
	
	nBlockCol = 0;
	for(nMinCol = *npMinCol; nMinCol <= nMaxCol; nMinCol++)
	{
		nBlockRow = 0;
		for(nMinRow = *npMinRow; nMinRow <= nMaxRow; nMinRow++)
		{
			if( szBlock1[nBlockWay][nBlockCol][nBlockRow] | 0x00)
			{
				//textcolor(TEXT_COLOR_BLUE);
				gotoxy(nMinRow, nMinCol);
				printf("*");
			}
			else
			{
				gotoxy(nMinRow, nMinCol);
				printf(" ");
			}
			nBlockRow++;
		}
		nBlockCol++;
	}
	//textcolor(TEXT_COLOR_WH);
}

void Unset_LeftCheckGraphicCol(unsigned int nMinCol, unsigned int nMaxCol, unsigned int nMinRow)
{
	unsigned int nCol;
	
	for(nCol = nMinCol; nCol <= nMaxCol; nCol++)
	{
		//textcolor(TEXT_COLOR_WH);
		if(szBG[nCol][nMinRow] & 0x01)
		{
			gotoxy(nMinRow, nCol);
			printf("*");
		}
		else
		{
			gotoxy(nMinRow, nCol);
			printf(" ");
		}
	}
}

void Unset_RightCheckGraphicCol(unsigned int nMinCol, unsigned int nMaxCol, unsigned int nMaxRow)
{
	unsigned int nCol;
	
	for(nCol = nMinCol; nCol <= nMaxCol; nCol++)
	{
		//textcolor(TEXT_COLOR_WH);
		if(szBG[nCol][nMaxRow] & 0x01)
		{
			gotoxy(nMaxRow, nCol);
			printf("*");
		}
		else
		{
			gotoxy(nMaxRow, nCol);
			printf(" ");
		}
	}
}

void Unset_UpperCheckGraphicRow(unsigned int nMinRow, unsigned int nMaxRow, unsigned int nMinCol)
{
	unsigned int nRow;
	
	for(nRow = nMinRow; nRow <= nMaxRow; nRow++)
	{
		//textcolor(TEXT_COLOR_WH);
		if(szBG[nMinCol][nRow] & 0x01)
		{
			gotoxy(nRow, nMinCol);
			printf("*");
		}
		else
		{
			gotoxy(nRow, nMinCol);
			printf(" ");
		}
	}
	
}

void Unset_LowerCheckGraphicRow(unsigned int nMinRow, unsigned int nMaxRow, unsigned int nMaxCol)
{
	unsigned int nRow;
	
	for(nRow = nMinRow; nRow <= nMaxRow; nRow++)
	{
		//textcolor(TEXT_COLOR_WH);
		if(szBG[nMaxCol][nRow] & 0x01)
		{
			gotoxy(nRow, nMaxCol);
			printf("*");
		}
		else
		{
			gotoxy(nRow, nMaxCol);
			printf(" ");
		}
	}
}

int main(int argc, char *argv[])
{
	unsigned int nRet=0;
	unsigned int nMinRow = 3, nMinCol = 0, nMaxRow = 6, nMaxCol = 3;
	unsigned int nPrevMinRow=0, nPrevMinCol=0 , nPrevMaxRow=0, nPrevMaxCol=0;
	unsigned int nKInput;
	unsigned int nCount;
	//Print_Dot(10, 10, (unsigned char *)szBG);
	Print_BG(MAX_COL_SZ, MAX_ROW_SZ-1);
	//Print_Block(0);
	nCount = 0;
	while(1)
	{

		if(nCount == 10)
		{
			nCount=0;
			Mv_CheckGraphic(&nMinRow, &nMinCol, &nMaxRow, &nMaxCol);
		
			nRet = Chk_DupDot(&nMinRow, &nMinCol, &nMaxRow, &nMaxCol, 0);
			nMinCol++;
			nMaxCol++;
		}
		nCount++;
		
		/*textcolor(TEXT_COLOR_WH);
		gotoxy(2, 14);
		printf("%d\n", nDupCnt);*/
			
		nKInput = 0;
		
		if(kbhit())
    		nKInput=getch();

		if(nKInput == 0x48 && nMinCol > 0)				// key input 'up'
	 	{
			nPrevMinCol=nMinCol;
			nPrevMaxCol=nMaxCol;
			nMinCol--;
			nMaxCol--;
			Unset_LowerCheckGraphicRow(nMinRow, nMaxRow, nPrevMaxCol);
	  	}
	 	else if(nKInput == 0x50 && nMaxCol < 9)		// key input 'down'
	 	{
			nPrevMinCol=nMinCol;
			nPrevMaxCol=nMaxCol;
			nMinCol++;
			nMaxCol++;
			Unset_UpperCheckGraphicRow(nMinRow, nMaxRow, nPrevMinCol);
        }
		else if(nKInput == 0x4B && nMinRow > 0)			// key input 'left'
		{
			nPrevMinRow=nMinRow;
			nPrevMaxRow=nMaxRow;
			nMinRow--;
			nMaxRow--;
			//if(nMaxRow < 10)
			Unset_RightCheckGraphicCol(nMinCol, nMaxCol, nPrevMaxRow);
		}
        else if(nKInput == 0x4D && nMaxRow < 9)		// key input 'right'
        {
			nPrevMinRow=nMinRow;
			nPrevMaxRow=nMaxRow;
			nMinRow++;
			nMaxRow++;
			Unset_LeftCheckGraphicCol(nMinCol, nMaxCol, nPrevMinRow);
		}

		//if(nDupCnt
		//printf("%d\n", nDupCnt);
		//nCount++;
		sleep(100);
	}
	system("PAUSE");	
  	return 0;
}

#else
int main(int argc, char *argv[])
{
 	unsigned int nBufRow, nBufCol;
 	unsigned int ch=0;
 	unsigned int nCount=0;
 	unsigned int nBlockCol = 1;
 	unsigned int nBlockRow = 5;
 	unsigned int nBlockPrevRow = 1;
 	unsigned int nBlockPrevCol = 5;
 	//unsigned int a, b;
 	//unsigned int nMvLft, nMvRgt, nBlockCrnt = 5;
 	
	Print_Dot(MAX_COL_SZ, MAX_ROW_SZ);

 	while(1)
 	{
	 	//Print_Block(MAX_BLOCK_WAY);
		ch = 0;

		if(kbhit())
    		ch=getch(); 	   

	 	if(ch == 0x20)					// key input 'spacebar'
	 	{
		 	  gotoxy(nBlockPrevRow, nBlockPrevCol);
              printf(" ");
			  gotoxy(nBlockRow, nBlockCol);
              printf(" ");
              
		 	  for(nBufCol = nBlockCol+1; nBufCol < MAX_COL_SZ-2; nBufCol++)
		 	  {
			   			  if(szBoard[nBufCol][nBlockRow] & 0x01)
								   break;
 			  }
 			  
 			  nBlockCol = nBufCol-1;
 			  gotoxy(nBlockRow, nBlockCol);
			  printf("*");
 			  SetCln_NewBlock(nBlockCol, nBlockRow);
 			  nBlockCol=1;
 			  nBlockRow=5;
	  	}
	 	else if(ch == 0x48)				// key input 'up'
	 	{
	  	}
	 	else if(ch == 0x50)// && nBlockCol < MAX_COL_SZ-3)		// key input 'down'
	 	{
	 	 	 gotoxy(nBlockPrevRow, nBlockPrevCol);
             printf(" ");
             if(szBoard[nBlockCol+1][nBlockRow] & 0x01)
             {
						gotoxy(nBlockRow, nBlockCol);
  						printf("*");
						SetCln_NewBlock(nBlockCol, nBlockRow);
						nBlockRow = 5;
						nBlockCol = 1;
			 }
			 else
			 {
				 		gotoxy(nBlockRow, nBlockCol);
	             		printf(" ");
		 		 		nBlockCol++;
		 		 		gotoxy(nBlockRow, nBlockCol);
	             		printf("*");
			 }
			 nCount=0;
			 continue;
        }
		else if(ch == 0x4B && nBlockRow >= 2)			// key input 'left'
		{
             if( (szBoard[nBlockPrevCol+1][nBlockPrevRow] & 0x01) != 0x01 )
			 {
			  			  gotoxy(nBlockPrevRow, nBlockPrevCol);
             			  printf(" ");
             }
			 if( (szBoard[nBlockCol][nBlockRow-1] & 0x01) != 0x01 )
			 {
						gotoxy(nBlockRow, nBlockCol);
			            printf(" ");
			            nBlockRow--;
			            gotoxy(nBlockRow, nBlockCol);
  						printf("*");
			 }
		}
        else if(ch == 0x4D && nBlockRow < MAX_ROW_SZ-3)		// key input 'right'
        {
             if( (szBoard[nBlockPrevCol+1][nBlockPrevRow] & 0x01) != 0x01 )
			 {
		 	  			  gotoxy(nBlockPrevRow, nBlockPrevCol);
             			  printf(" ");
			 }
			 if( ( szBoard[nBlockCol][nBlockRow+1] & 0x01 ) != 0x01)
			 {
			  			gotoxy(nBlockRow, nBlockCol);
			            printf(" ");
			            nBlockRow++;
			            gotoxy(nBlockRow, nBlockCol);
			            printf("*");
			 }
		}

        nCount++;
        //Print_Dot(MAX_COL_SZ, MAX_ROW_SZ);
        if(nCount == 10)
		{
		 		  //Print_Dot(MAX_COL_SZ, MAX_ROW_SZ);
		 		  nCount = 0;
		 		  if(nBlockCol > 0 && nBlockCol < 21)
		 		  {
				   			   if(nBlockCol > 1)
 			   	  			   {
	   			   						gotoxy(nBlockPrevRow, nBlockPrevCol);
	   			   						printf(" ");
				  			   }
				   			   gotoxy(nBlockRow, nBlockCol);
				   			   printf("*");
   			 			  	   nBlockPrevRow = nBlockRow;
				   			   nBlockPrevCol = nBlockCol;
				   			   if(szBoard[nBlockCol+1][nBlockRow] & 0x01)
				   			   {
  									    SetCln_NewBlock(nBlockCol, nBlockRow);
					  					nBlockCol=1;
	   									nBlockRow=5;
							   }
							   nBlockCol++;
                  }
		}
		//SetCln_NewBlock(nBlockCol, nBlockRow);
		sleep(100);
	}
  system("PAUSE");	
  return 0;
}
#endif
