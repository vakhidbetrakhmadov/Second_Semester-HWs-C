#include <stdio.h>
#include <ctype.h>

int isPalindrome(char *str);
int rec(char *str,int startIndex,int lastIndex);
int stringlen(char *str);

int main(void)
{
	if(isPalindrome("a"))
	{
		printf("Is palindrome\n");
	}
	else
	{
		printf("Is not palindrome\n");
	}

	return 0;
}

int isPalindrome(char *str)
{
	int i;
	int len=0;
	int charInStr=0;

	if(str==NULL || str[0]=='\0')
	{
		return 0;
	}

	len=stringlen(str);

	for (i=0;i<len;++i)
	{
		if(isalpha(str[i]))
		{
			++charInStr;
		}
	}

	if(charInStr==0)
	{
		return 0;
	}

	if (rec (str,0,len-1))
	{
		return 1;
	}

	return 0;
}

int rec(char *str,int startIndex,int lastIndex)
{
	int ans=1;

	/* Terminating conditions: */

	/*(startIndex==lastIndex && str[startIndex]==str[lastIndex]) || 
		(startIndex+1==lastIndex && str[startIndex]==str[lastIndex])*/

	if (str[startIndex]=='\0')
	{
		ans=1;
	}
	else if(isalpha(str[startIndex]))
	{
		if(isalpha(str[lastIndex]))
		{
			if(str[startIndex]==str[lastIndex])
			{
				ans*=rec(str,startIndex+1,lastIndex-1);
			}
			else
			{
				ans=0;
			}
		}
		else
		{
			ans*=rec(str,startIndex,lastIndex-1);
		}	
	}
	else
	{
		ans*=rec(str,startIndex+1,lastIndex);
	}

	return (ans);
}

int stringlen(char *str)
{
	int ind=0;

	while(str[ind]!='\0')
	{
		++ind;
	}

	return (ind);
}