#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * matcher(char* haystack,char* needle);

int main(void)
{
	char * ptr;

	ptr=matcher("lorem ipsum dolor sit amet.", "lorem");

	printf("- - - - - - - - - -\n");
	printf("%s\n",ptr);

	return 0;
}

char * matcher(char* haystack,char* needle)
{
	int i,j;
	int sizeOfHaystack;
	int sizeOfNeedle;
	int match;

	/*return 0 if either of strings is NULL*/
	if(haystack==NULL || needle==NULL)
	{
		return NULL;
	}

	sizeOfHaystack=strlen(haystack);
	sizeOfNeedle=strlen(needle);

	/*goes through the Haystack str determining the start point of the substr */
	/*to be checked*/
	for(i=0;i<=sizeOfHaystack-sizeOfNeedle;++i)
	{
		match=1;

		/*if length of the substr to be searched for is even*/
		if (sizeOfNeedle%2==0)
		{
			/*checks if the substr in str is identical with given substr*/
			for (j = 0; j<= sizeOfNeedle-2; j+=2)
			{
				if(needle[j]!=haystack[i+j])	
				{
					match=0;
				}			
			}
		}

		/*if length of the substr to be searched for is odd*/
		else
		{
			for (j = 0; j<= sizeOfNeedle-1; j+=2)
			{
				if(needle[j]!=haystack[i+j])
				{
					match=0;
				}			
			}

		}

		if(match)
		{
			return(&haystack[i]);
		}
	}

	return NULL;	
}