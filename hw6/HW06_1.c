#include <stdio.h>
#include <string.h>
#include <ctype.h>

void freq(char* str,int* fr);

int main(void)
{
	char c;
	int i;
	int j;
	int fr[37];

	freq("aaAAaa ********** 99999 00000",fr);

	for(c='A',i=0;c<='Z';++c,++i)
	{
		printf("%c => %d\n",c,fr[i]);
	}

	for(j=0;j<=9;++j,++i)
	{
		printf("%d => %d\n",j,fr[i]);
	}

	printf("Others => %d\n",fr[i]);

	return 0;
}

void freq(char* str,int* fr)
{
	char ch;
	int i,j;
	size_t size;

	size=strlen(str);

	/*initializes array of counters*/
	for(i=0;i<37;++i)
	{
		fr[i]=0;
	}

	/*scans for letters in the string*/
	for(ch='a',i=0;ch<='z';++ch,++i)
	{
		for(j=0;j<size;++j)
		{
			if(ch==str[j] || ch==tolower(str[j]))
			{
			++fr[i];
			}
		}	
	}

	/*scans for digits int the string*/ 
	for(ch='0';ch<='9';++ch,++i)
	{
		for(j=0;j<size;++j)
		{
			if(ch==str[j])
			{
				++fr[i];
			}
		}
	}

	/*scans for others int the string*/
	for(j=0;j<size;++j)
	{
		if(isspace(str[j]) || ispunct(str[j]))
		{
			++fr[36];
		}
	}
}