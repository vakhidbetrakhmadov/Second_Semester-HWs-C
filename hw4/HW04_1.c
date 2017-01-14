#include <stdio.h>

double cosine(int degree,int n);
double sine(int degree,int n);
void getInputs(int* degree,int* n,int* exit);
double power(double x,double n);
double factorial(int n);
void skipLine(void);

int main(void)
{	
	int degree;
	int n;
	int exit;

	do
	{
		getInputs(&degree,&n,&exit);

		if(!(exit))
		{
			printf("sin(%d) where n is %d = %.4lf\n",degree,n,sine(degree,n));
			printf("cos(%d) where n is %d = %.4lf\n",degree,n,cosine(degree,n));
		}

	}while(!(exit));

	return 0;
}

void getInputs(int* degree,int* n,int* exit)
{
	int status;
	char c;

	do 
	{
		status=0;
		printf("Please enter degree and number of elements of the series: ");
		status=scanf("%d%d",degree,n);

		if (status!=2)
		{
			scanf("%c",&c);
			if (c=='e' || c=='E')
			{
				status=2;
				*exit=1;
			}	
		}

		skipLine();

	}while(status!=2);
		
	if (c!='e' && c!='E')
		*exit=0;
}

void skipLine(void)
{
	char c;

	do
	{
		scanf("%c",&c);
	}while(c!='\n');
}

double power(double x,double n)
{
	int i;
	double product=1.0;

	if(n==0)
		return 1;
	else if(n==1)
		return x;
	else
	{
		for(i=1;i<=n;++i)
			{
			product*=x;
			}
	}
	return product;
}

double factorial(int n)
{
	int i;
	int fact=1;

	if(n==0)
		return 1;
	else if(n==1)
		return 1;
	else 
	{
		for(i=1;i<n;++i)
		{
			fact*=i+1;
		}				
		return fact;
	}
}

double sine(int degree,int n)
{
	double sum=0;
	double i;
	double radian;
	
	degree%=360;
	
	if (degree<0)
	{
		degree=360+degree;
	}

	radian=degree*3.14/180; 

	for(i=0;i<=n;++i)
	{
		sum+=((power(-1,i))/(factorial(2*i+1))*(power(radian,(2*i)+1)));
	}
	return (sum);
}

double cosine(int degree,int n)
{
	double sum=0;
	double i;
	double radian;

	degree%=360;
	
	if (degree<0)
	{
		degree=360+degree;
	}

	radian=degree*3.14/180;

	for (i=0;i<n;++i)
	{
		sum+=((power(-1,i))/(factorial(2*i))*(power(radian,2*i)));
	}
	return (sum);
}
