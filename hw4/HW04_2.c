#include <stdio.h>
#include <math.h>

typedef enum
		 {zero,one,two,three,four,five,six,seven,eight,nine}
 number_type;

void getInputs(int* num,int* borderWidth,char* chr);
int printNumber(int num,int borderWidth,char chr);
void skipLine(void);
int numOfDigits(int num);
void borderInArray(char array[][200],int borderWidth,int num,char chr);
void writeDigitIntoArray(char array[][200],int digit,int row,int col,char chr);

char array[200][200];

int main(void)
{
	int num;
	int borderWidth;
	char chr;
	int status=1;
	
	do 
	{	

		getInputs(&num,&borderWidth,&chr);
		
		status=printNumber(num,borderWidth,chr);
		
	}while(status!=0);

	return 0;
}

void skipLine(void)
{
	char c;

	do 
	{
		scanf("%c",&c);
	}while(c!='\n');
}

void getInputs(int* num,int* borderWidth,char* chr)
{
	int status;

	do 
	{
		status=0;
		printf("Give an input: ");
		status+=(scanf("%d",num));
		
		if((status)&&(*num>=0))
		{			
			status+=(scanf("%d",borderWidth));
			status+=(scanf(" %c",chr));		
		}
		else
		{}
	
		skipLine();
		
	}while((status!=3) && (*num>=0));
}

int printNumber(int num,int borderWidth,char chr)
{
	int row;
	int col;
	int i,j;
	int numberOfDigits;
	int digit;
	int length;
	int height;	

	if(num>99999)
	{
		printf("\n");
		return 0;
	}
	if(num<0)
	{
		return 0;
	}
	
	numberOfDigits=numOfDigits(num);
	
	length=(numberOfDigits*7)+(borderWidth*2);
	height=(borderWidth*2)+7;
	
	row=borderWidth+1;
	col=borderWidth+2;

	for(i=0;i<height;++i)
	{
		for(j=0;j<length;++j)
		{
			array[i][j]=' ';
		}
	}

	borderInArray(array,borderWidth,num,chr);

	for(i=1;i<=numberOfDigits;++i)
	{
		digit=num/(pow(10,numberOfDigits-i));
		digit%=10;
				
		writeDigitIntoArray(array,digit,row,col,chr);
		col+=7;
	}

	for(i=0;i<height;++i)
	{
		for(j=0;j<length;++j)
		{	
			printf("%c",array[i][j]);
		}
		printf("\n");
	}

	return 1;
	
}

int numOfDigits(int num)
{
	double product=num;
	int counter=0;
	
	if(num==0)
		return 1;

	while(product>=1)
	{
		product/=10;
		++counter;
	}
	
	return counter;
}

void borderInArray(char array[][200],int borderWidth,int num,char chr)
{
	int i,j;
	int length;
	length = (numOfDigits(num)*7)+(borderWidth*2);
	
	/*upper border*/
	for(i=0;i<borderWidth;++i)
	{	
		for (j=0;j<length;++j)
		{
			array[i][j]=chr;
		}
	}

	/*lower border */	
	for (i=borderWidth+7;i<(2*borderWidth)+7;++i)
	{
		for (j=0;j<length;++j)
		{
			array[i][j]=chr;
		}
	}

	/*left border*/
	for (j=0;j<borderWidth;++j)
	{
		for(i=borderWidth;i<borderWidth+7;++i)
		{
			array[i][j]=chr;
		}
	}

	/*right border*/
	for(j=length-borderWidth;j<length;++j)
	{
		for(i=borderWidth;i<borderWidth+7;++i)
		{
			array[i][j]=chr;
		}
	}
	
}

void writeDigitIntoArray(char array[][200],int digit,int row,int col,char chr)
{
	int i;
	int j;

	switch (digit)
	{
		case zero:
			array[row][col]=chr;
			array[row][col+1]=chr;
			array[row][col+2]=chr;
			array[row+1][col]=chr;
			array[row+1][col+2]=chr;
			array[row+2][col]=chr;
			array[row+2][col+2]=chr;
			array[row+3][col]=chr;
			array[row+3][col+2]=chr;
			array[row+4][col]=chr;
			array[row+4][col+1]=chr;
			array[row+4][col+2]=chr;			
			break;
		
		case one:
			array[row][col+1]=chr;
			array[row+1][col]=chr;
			array[row+1][col+1]=chr;
			array[row+2][col+1]=chr;
			array[row+3][col+1]=chr;
			array[row+4][col]=chr;
			array[row+4][col+1]=chr;
			array[row+4][col+2]=chr;
			break;

		case two:
			array[row][col]=chr;
			array[row][col+1]=chr;
			array[row][col+2]=chr;
			array[row+1][col+2]=chr;
			array[row+2][col]=chr;
			array[row+2][col+1]=chr;
			array[row+2][col+2]=chr;
			array[row+3][col]=chr;
			array[row+4][col]=chr;
			array[row+4][col+1]=chr;
			array[row+4][col+2]=chr;
			break;

		case three:
			array[row][col]=chr;
			array[row][col+1]=chr;
			array[row][col+2]=chr;
			array[row+1][col+2]=chr;
			array[row+2][col+1]=chr;
			array[row+2][col+2]=chr;
			array[row+3][col+2]=chr;
			array[row+4][col]=chr;
			array[row+4][col+1]=chr;
			array[row+4][col+2]=chr;
			break;

		case four:
			array[row][col]=chr;
			array[row][col+2]=chr;
			array[row+1][col]=chr;
			array[row+1][col+2]=chr;
			array[row+2][col]=chr;
			array[row+2][col+1]=chr;
			array[row+2][col+2]=chr;
			array[row+3][col+2]=chr;
			array[row+4][col+2]=chr;
			break;
	
		case five:
			array[row][col]=chr;
			array[row][col+1]=chr;
			array[row][col+2]=chr;
			array[row+1][col]=chr;
			array[row+2][col]=chr;
			array[row+2][col+1]=chr;
			array[row+2][col+2]=chr;
			array[row+3][col+2]=chr;
			array[row+4][col]=chr;
			array[row+4][col+1]=chr;
			array[row+4][col+2]=chr;
			break;

		case six:
			array[row][col]=chr;
			array[row][col+1]=chr;
			array[row][col+2]=chr;
			array[row+1][col]=chr;
			array[row+2][col]=chr;
			array[row+2][col+1]=chr;
			array[row+2][col+2]=chr;
			array[row+3][col]=chr;
			array[row+3][col+2]=chr;
			array[row+4][col]=chr;
			array[row+4][col+1]=chr;
			array[row+4][col+2]=chr;
			break;

		case seven:
			array[row][col]=chr;
			array[row][col+1]=chr;
			array[row][col+2]=chr;
			array[row+1][col+2]=chr;
			array[row+2][col+2]=chr;
			array[row+3][col+2]=chr;
			array[row+4][col+2]=chr;
			break;

		case eight:
			array[row][col]=chr;
			array[row][col+1]=chr;
			array[row][col+2]=chr;
			array[row+1][col]=chr;
			array[row+1][col+2]=chr;
			array[row+2][col]=chr;
			array[row+2][col+1]=chr;
			array[row+2][col+2]=chr;
			array[row+3][col]=chr;
			array[row+3][col+2]=chr;
			array[row+4][col]=chr;
			array[row+4][col+1]=chr;
			array[row+4][col+2]=chr;
			break;

		case nine:
			array[row][col]=chr;
			array[row][col+1]=chr;
			array[row][col+2]=chr;
			array[row+1][col]=chr;
			array[row+1][col+2]=chr;
			array[row+2][col]=chr;
			array[row+2][col+1]=chr;
			array[row+2][col+2]=chr;
			array[row+3][col+2]=chr;
			array[row+4][col]=chr;
			array[row+4][col+1]=chr;
			array[row+4][col+2]=chr;
			break;
		
		default: 
			break;
	}

}



































