#include <stdio.h>
#include <math.h>


void getInputs(int* num,int* borderWidth,char* chr);
int printNumber(int num,int borderWidth,char chr);
int numOfDigits(int num);
void printUpDownBord(int borderWidth,int numOfDigits,char chr);
void printSideBord(int borderWidth,char chr);
void skipLine(void);
void zero(int line,char chr);
void one(int line,char chr);
void two(int line,char chr);
void three(int line,char chr);
void four(int line,char chr);
void five(int line,char chr);
void six(int line,char chr);
void seven(int line,char chr);
void eight(int line,char chr);
void nine(int line,char chr);




int main(void)
{

	int num;
	int borderWidth;
	char chr;	
	
	do 
	{	
		getInputs(&num,&borderWidth,&chr);
		if (num>=0)
		{
			printNumber(num,borderWidth,chr);
		}
	}while(num>=0);

	return 0;
}

int printNumber(int num,int borderWidth,char chr)
{
	int numOfDigitsVariable;
	numOfDigitsVariable=numOfDigits(num);
	int line;
	int i;
	int digit;

	printUpDownBord(borderWidth,numOfDigitsVariable,chr);

	for(line=1;line<=7;++line)
	{
		printSideBord(borderWidth,chr);

		for (i=1;i<=numOfDigitsVariable;++i)
		{
			digit=num/(pow(10,numOfDigitsVariable-i));
			digit%=10;

			switch (digit)
			{
				case 0:zero(line,chr);break;
				case 1:one(line,chr);break;
				case 2:two(line,chr);break;
				case 3:three(line,chr);break;
				case 4:four(line,chr);break;
				case 5:five(line,chr);break;
				case 6:six(line,chr);break;
				case 7:seven(line,chr);break;
				case 8:eight(line,chr);break;
				case 9:nine(line,chr);break;

				default:break;
			}
		}

		printSideBord(borderWidth,chr);
		printf("\n");	
	}

	printUpDownBord(borderWidth,numOfDigitsVariable,chr);
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
	int status=0;

	do 
	{
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

void printUpDownBord(int borderWidth,int numOfDigits,char chr)
{
	int i,j;

	for(i=0;i<borderWidth;++i)
	{
		for(j=0;j<((numOfDigits*7)+(2*borderWidth));++j)
		{
			printf("%c",chr);
		}
			printf("\n");
	}
}

void printSideBord(int borderWidth,char chr)
{
	int i;

	for(i=0;i<borderWidth;++i)
		{
			printf("%c",chr);
		}
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

void zero(int line,char chr)
{
	switch(line)
	{
		
		case 1:printf("       ");break;
		case 2:printf("  %c%c%c  ",chr,chr,chr);break;
		case 3:printf("  %c %c  ",chr,chr);break;
		case 4:printf("  %c %c  ",chr,chr);break;
		case 5:printf("  %c %c  ",chr,chr);break;
		case 6:printf("  %c%c%c  ",chr,chr,chr);break;
		case 7:printf("       ");break;
		default:break;
	}

}
void one(int line,char chr)
{
	switch(line)
	{
		case 1:printf("       ");break;
		case 2:printf("   %c   ",chr);break;
		case 3:printf("  %c%c   ",chr,chr);break;
		case 4:printf("   %c   ",chr);break;
		case 5:printf("   %c   ",chr);break;
		case 6:printf("  %c%c%c  ",chr,chr,chr);break;
		case 7:printf("       ");break;
		default:break;
	}

}
void two(int line,char chr)
{
	switch(line)
	{
		case 1:printf("       ");break;
		case 2:printf("  %c%c%c  ",chr,chr,chr);break;
		case 3:printf("    %c  ",chr);break;
		case 4:printf("  %c%c%c  ",chr,chr,chr);break;
		case 5:printf("  %c    ",chr);break;
		case 6:printf("  %c%c%c  ",chr,chr,chr);break;
		case 7:printf("       ");break;
		default:break;
	}

}
void three(int line,char chr)
{
	switch(line)
	{
		case 1:printf("       ");break;
		case 2:printf("  %c%c%c  ",chr,chr,chr);break;
		case 3:printf("    %c  ",chr);break;
		case 4:printf("   %c%c  ",chr,chr);break;
		case 5:printf("    %c  ",chr);break;
		case 6:printf("  %c%c%c  ",chr,chr,chr);break;
		case 7:printf("       ");break;
		default:break;
	}

}
void four(int line,char chr)
{
	switch(line)
	{
		case 1:printf("       ");break;
		case 2:printf("  %c %c  ",chr,chr);break;
		case 3:printf("  %c %c  ",chr,chr);break;
		case 4:printf("  %c%c%c  ",chr,chr,chr);break;
		case 5:printf("    %c  ",chr);break;
		case 6:printf("    %c  ",chr);break;
		case 7:printf("       ");break;
		default:break;
	}

}
void five(int line,char chr)
{
	switch(line)
	{
		case 1:printf("       ");break;
		case 2:printf("  %c%c%c  ",chr,chr,chr);break;
		case 3:printf("  %c    ",chr);break;
		case 4:printf("  %c%c%c  ",chr,chr,chr);break;
		case 5:printf("    %c  ",chr);break;
		case 6:printf("  %c%c%c  ",chr,chr,chr);break;
		case 7:printf("       ");break;
		default:break;
	}

}
void six(int line,char chr)
{
	switch(line)
	{
		case 1:printf("       ");break;
		case 2:printf("  %c%c%c  ",chr,chr,chr);break;
		case 3:printf("  %c    ",chr);break;
		case 4:printf("  %c%c%c  ",chr,chr,chr);break;
		case 5:printf("  %c %c  ",chr,chr);break;
		case 6:printf("  %c%c%c  ",chr,chr,chr);break;
		case 7:printf("       ");break;
		default:break;
	}

}
void seven(int line,char chr)
{
	switch(line)
	{
		case 1:printf("      ");break;
		case 2:printf("  %c%c%c  ",chr,chr,chr);break;
		case 3:printf("    %c  ",chr);break;
		case 4:printf("    %c  ",chr);break;
		case 5:printf("    %c  ",chr);break;
		case 6:printf("    %c  ",chr);break;
		case 7:printf("       ");break;
		default:break;
	}

}
void eight(int line,char chr)
{
	switch(line)
	{
		case 1:printf("       ");break;
		case 2:printf("  %c%c%c  ",chr,chr,chr);break;
		case 3:printf("  %c %c  ",chr,chr);break;
		case 4:printf("  %c%c%c  ",chr,chr,chr);break;
		case 5:printf("  %c %c  ",chr,chr);break;
		case 6:printf("  %c%c%c  ",chr,chr,chr);break;
		case 7:printf("       ");break;
		default:break;
	}

}
void nine(int line,char chr)
{
	switch(line)
	{
		case 1:printf("       ");break;
		case 2:printf("  %c%c%c  ",chr,chr,chr);break;
		case 3:printf("  %c %c  ",chr,chr);break;
		case 4:printf("  %c%c%c  ",chr,chr,chr);break;
		case 5:printf("    %c  ",chr);break;
		case 6:printf("  %c%c%c  ",chr,chr,chr);break;
		case 7:printf("       ");break;
		default:break;
	}

}
