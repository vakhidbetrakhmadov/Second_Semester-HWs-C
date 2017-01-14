#include <stdio.h>
#include <math.h>

long num;
int status,choise;
int choiseCheck;
char check;
char skipCh;


void beOrNotToBe(void);
void oddOrNot(void);
void factoiralOrNot(void);
void narcissisticOrNOt(void);
void skipLine(void);

int main(void){
	printf("****************************************************\n"
	       "*                     WELCOME!                     *\n"
	       "*  This program checks whether the given number    *\n"
	       "* is an odd, a factorial or a narcissistic number  *\n"
	       "*                                                  *\n"
	       "****************************************************\n");

	do 
	{
		check='f';
		printf("\nPlease enter a positive integer: ");
		status=scanf("%ld",&num);
	
		skipLine();

		if (status==1)
		{
	
			if (num<=0)
			{
				printf("The entered number is not positive.\n");
				beOrNotToBe();
			}
			else 
			{	
				choiseCheck=0;
				while(choiseCheck!=1)
				{
					choise=0;
					printf("Which property would you like to check?\n"
					"1)Odd number\n"
					"2)Factorial number\n"
					"3)Narcissistic number\n"
					"Please enter(1/2/3): ");
					scanf("%d",&choise);
					skipLine();
	
					switch (choise)
					{
						case 1:
							oddOrNot();choiseCheck=1; break;
						case 2:
							factoiralOrNot();choiseCheck=1;break;
						case 3:
							narcissisticOrNOt();choiseCheck=1;break;
		
						default:
							break;		
					}	
				}
				beOrNotToBe();
			}
		
		}

		else 
		{
			printf("The entered number is not positive.\n");
			beOrNotToBe();
		}
		
	}
	while(check=='y');
	
	printf("Good bye !\n");
	
	return(0);	
}

void beOrNotToBe(void){

	while ((check!='y') && (check!='n')) {
	printf("Do you want to continue (y/n) ? ");
	scanf("%c",&check);
	
	skipLine();
	
	}

}

void skipLine(void){
	do 
		scanf("%c",&skipCh);
	while (skipCh!='\n');
}

void oddOrNot(void){
	if (num%2==0)
		printf("%ld is not an odd number !\n",num);
	else 
		printf("%ld is an odd number !\n",num);
}

void factoiralOrNot(void){
	int product;
	int divider;
	int flag;
	
	if (num==1)
		printf("%ld is a factorial number !\n",num);
	else 
	{
		if ((num%2)!=0)
			printf("%ld is not a factorial number !\n",num);
		else 
		{
			product=num;
			divider=1;
			while(product%divider==0)
			{
				flag=0;
				product=product/divider;
				divider+=1;
				if (product==1)
				{
				  	flag=1;
					break;
				}
			}
			if (flag==1)
				printf("%ld is a factorial number !\n",num);
			else 
				printf("%ld is not a factorial number !\n",num);
		}
	}

}

void narcissisticOrNOt(void){
	int numOfInt=0;
	int divider=10;
	double product;
	int counter;
	double intPart;
	long sum=0;
	
	do
	{
		++numOfInt;
		product=num/divider;
		divider*=10;
	}while(product>=1);
	
	intPart=num;
	for (counter=0;counter<numOfInt;++counter)
	{
		sum+=pow(((int)(intPart)%10),numOfInt);
		intPart/=10;
		modf(intPart,&intPart);
	}
	
	if (sum==num)
		printf("%ld is narcissistic number !\n",num);
	else 
		printf("%ld is not narcissistic number !\n",num);
		
}
































