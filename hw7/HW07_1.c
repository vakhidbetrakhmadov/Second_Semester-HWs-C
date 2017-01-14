#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str);
int rec(char *str,int size,int lastIndex);

int main(void)
{
	if(isPalindrome("+%&%+%aa456bvv45t124ba4545a"))
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
	char strCopy[200];
	int i;
	int n;
	
	if(str==NULL || str=="")
	{
		return 0;
	}

	/*turns to lower case and copys all characters of 'str' to 'strCopy'*/
	for(i=0,n=0;i<strlen(str);++i)
	{
		if(isalpha(str[i]))
		{
			strCopy[n]=tolower(str[i]);
			++n;
		}
	}
	strCopy[n]='\0';

	if (rec (strCopy,n,n-1))
	{
		return 1;
	}

	return 0;
}

int rec(char *str,int size,int lastIndex)
{
	int ans=1;
	int len;

	len=strlen(str);

	/* Terminating conditions: */
	/* Terminates when the str's middle is reached (valid both for odd */
	/* and even sized strings)*/
	if ((len-1==size/2) && (str[0]==str[lastIndex]))
	{
		ans=1;
	}
	/* Matches symmetric pair of characters from both ends */
	/* if identical moves closer to the middle */
	else if(str[0]==str[lastIndex])
	{
		ans*=(rec(&str[1],size,lastIndex-2));
		
	}
	/*if at least one pair is not identical invokes chain reaction*/
	/* turning all 'ans's to 0 */
	else
	{
		ans=0;
	}

	return (ans);
}