#include <stdio.h>
#include <string.h>

int count (char *str,char *substr);

int main(void)
{
	printf("Returnd: %d\n",count(" ece ece ece","ece"));

	return 0;
}

int count (char *str,char *substr)
{
	int i,j;
	int sizeOfStr;
	int sizeOfSubstr;
	int match;
	int counter;

	if(str==NULL || substr==NULL)
	{
		return 0;
	}

	sizeOfStr=strlen(str);
	sizeOfSubstr=strlen(substr);
	counter=0;

	for(i=0;i<=sizeOfStr-sizeOfSubstr;++i)
	{
		match=1;

		if (sizeOfSubstr%2==0)
		{
			for (j = 0; j<= sizeOfSubstr-2; j+=2)
			{
				if(substr[j]!=str[i+j])
				{
					match=0;
				}			
			}
		}

		else
		{
			for (j = 0; j<= sizeOfSubstr-1; j+=2)
			{
				if(substr[j]!=str[i+j])
				{
					match=0;
				}			
			}

		}

		if(match)
		{
			++counter;
		}
	}

	return counter;	


}