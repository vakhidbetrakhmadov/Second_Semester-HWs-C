/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW09_141044086_Vakhid_Betrakhmadov                                       */
/*                                                                          */
/* main.c                                                                   */
/* ---------                                                                */
/* Created on 04/28/2016 by Vakhid_Betrakhmadov                             */
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* Includes                                                                 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

/*--------------------------------------------------------------------------*/
/*                           #defines                                       */
/*--------------------------------------------------------------------------*/
#define MAX_COUNTRIES 100

/*--------------------------------------------------------------------------*/
/* 							typedefs										*/
/*--------------------------------------------------------------------------*/
enum choise{a,b,c,d,e};

typedef struct 
{
	int number;
	char name[10][26];

}NeighborInfo;

typedef struct 
{
	char name[26];
	int population;
	double area;
	int army;
	int visitedByExplorer;
	NeighborInfo neighbor;

}CountryInfo;

/*---------------------------------------------------------------------------*/
/* Function Prototypes                                                       */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  void addCountry(CountryInfo *country,int index)                          */
/* -----------                                                               */
/*                                                                           */
/* country - array of countries 		                                     */
/* index - index of the last element in the array 							 */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* nothing 																	 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* In this function we add a new country and information about it to 	     */
/* our array of countries. If invalid input is entered,user get warning,and  */ 
/* asked to reenter 													     */
/*---------------------------------------------------------------------------*/
void addCountry(CountryInfo *country,int index);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  int mostPowerful(CountryInfo *country, int index,char * givenCtr)	     */
/* -----------                                                               */
/*                                                                           */
/* country - array of countries 		                                     */
/* index - index of the last element in the array 							 */
/* givenCtr - country in vicinities of wich to check 						 */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* Index of the strongets country in array of counties - on success 		 */
/* -1 - on failure 															 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* This function finds strongets country in vicinities of given country      */
/*---------------------------------------------------------------------------*/
int mostPowerful(CountryInfo *country, int index,char * givenCtr);


/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int theLargest(CountryInfo *country, int index,char * givenCtr)		     */
/* -----------                                                               */
/*                                                                           */
/* country - array of countries 		                                     */
/* index - index of the last element in the array 							 */
/* givenCtr - country in vicinities of wich to check 						 */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* Index of the largest country in array of counties - on success			 */
/* -1 - on failure 															 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* This function finds the largest country in vicinities of given country    */
/*---------------------------------------------------------------------------*/
int theLargest(CountryInfo *country, int index,char * givenCtr);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*int tripFromTo(CountryInfo *country,int index,char *sourceCtr,			 */
/*char *targetCtr)														     */
/* -----------                                                               */
/*                                                                           */
/* country - array of countries 		                                     */
/* index - index of the last element in the array 							 */
/* sourceCtr - country where we start our trip from                          */
/* targetCtr- country where we are heading to 								 */
/* 																		     */
/* Return                                                                    */
/* ------                                                                    */
/*	min number of people should be seen to travel from sourceCtr to targetCtr*/
/* - on success																 */
/* -1 - on failure 														     */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* This function calls the explorer to find out if the targetCtr is reachble */
/* from sourceCtr,if so it calls traveler to find the best way 				 */
/*---------------------------------------------------------------------------*/
int tripFromTo(CountryInfo *country,int index,char *sourceCtr,char *targetCtr);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*int explorer(CountryInfo *country,int index,char *thrCtr,char *targetCtr,  */
/*	char *cameFrom)														     */
/* -----------                                                               */
/*                                                                           */
/* country - array of countries 		                                     */
/* index - index of the last element in the array 							 */
/* thrCtr - country through	which explorer check the accessability 			 */
/* of targetCtr															     */
/* targetCtr- country where explorer is heading to 							 */
/* cameFrom - country explorer came from to thrCtr           			     */
/* 																		     */
/* Return                                                                    */
/* ------                                                                    */
/* 0- on success 														     */
/* 1- on failure  															 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* In this function we check if the targetCtr can be reached through thrCtr	 */
/* Explorer starts from thrCtr searches for targetCtr 						 */ 
/*---------------------------------------------------------------------------*/
int explorer(CountryInfo *country,int index,char *thrCtr,char *targetCtr,
	char *cameFrom);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*int traveler(CountryInfo *country,int index,char *sourceCtr,char *targetCtr,*/
/* char *cameFrom,int *reachedParam,char ctrVisitedByTraveler[][26],		 */
/* int countryVisitedIndx)												     */
/* -----------                                                               */
/*                                                                           */
/* country - array of countries 		                                     */
/* index - index of the last element in the array 							 */
/* sourceCtr - country where traveler start his trip from                    */
/* targetCtr- country where traveler is heading to 							 */
/* cameFrom - previous country traveler came from        				     */
/* 																		     */
/* Return                                                                    */
/* ------                                                                    */
/*	min number of people should be seen to travel from sourceCtr to targetCtr*/
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* In this function our unsocial traveler finds out by which way he will     */
/* see less people while trying to get to targetCtr 					     */  
/*---------------------------------------------------------------------------*/
int traveler(CountryInfo *country,int index,char *sourceCtr,char *targetCtr,
 char *cameFrom,int *reachedParam,char ctrVisitedByTraveler[][26],
 int countryVisitedIndx);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*int FindCountryVisitedIndx(char countryVisited[][26], int index,char *     */
/*ctrToFind)															     */
/* -----------                                                               */
/*                                                                           */
/* countryVisited[][26] - array of strings,journal of our traveler,			 */
/* countries already visited 												 */
/* index - index of the last element in the array 							 */
/* ctrToFind- string representing name of the country 	       			     */
/* 																		     */
/* Return                                                                    */
/* ------                                                                    */
/*Index of country in the array of strings (journal of traveler)- on success */
/* -1 - on failer (country is not in journal)								 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* This function searches for country in journal of the traveler		     */  
/*---------------------------------------------------------------------------*/
int FindCountryVisitedIndx(char countryVisited[][26], int index,char *
 ctrToFind);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*int countryIndex(CountryInfo *country, int index,char * ctrToFind)	     */
/* -----------                                                               */
/*                                                                           */
/* country - array of countries 		                                     */
/* index - index of the last element in the array 							 */
/* ctrToFind- string representing name of the country 	       			     */
/* 																		     */
/* Return                                                                    */
/* ------                                                                    */
/*Index of country in the array of strings (array of countries)- on success  */
/* -1 - on failer (country is not in array of countries)					 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* This function searches for country in array of countries 			     */  
/*---------------------------------------------------------------------------*/
int countryIndex(CountryInfo *country, int index,char * ctrToFind);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*int compare(char* str1,char * str2)									     */
/* -----------                                                               */
/*                                                                           */
/* str1 -string , str2- string 												 */
/* 																		     */
/* Return                                                                    */
/* ------                                                                    */
/* 1- on success 															 */
/* 0 - on failure                           								 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* Compare to strings for identity(handles cases)						     */  
/*---------------------------------------------------------------------------*/
int compare(char* str1,char * str2);


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*int getInput(char *str,const char * mode)								     */
/* -----------                                                               */
/* str-output strings                                                        */
/* mode - type of expected input  											 */
/* 																		     */
/* Return                                                                    */
/* ------                                                                    */
/* 1- if (-1) is entered 													 */
/* 0- valid strig is entered(with no digits and punctuation marks)           */
/* -1 - on failure (invalid mode)             								 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* In this function we get input from user,to fill our array of countries 	 */
/*---------------------------------------------------------------------------*/
int getInput(char *str,const char * mode);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* 	int getChoice()						  								     */
/* -----------                                                               */
/* 																		     */
/* Return                                                                    */
/* ------                                                                    */
/* 0 -  a is Entered  			           									 */
/* 1- b is entered 															 */
/* 2- c is entered 															 */
/* 3 -d is entered 														     */
/* 4 -e is entered 															 */
/* -1 - anything else is entered (failure)									 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* In this function we get input from the user 								 */
/*---------------------------------------------------------------------------*/
int getChoice();

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* 	int strToInt(char * str)						  					     */
/* -----------                                                               */
/* 																			 */
/* str - string of digits													 */
/* Return                                                                    */
/* ------                                                                    */
/* integer 																     */
/*                                                                           */
/* Description                                                               */
/* -----------   															 */
/* This function converts string of digits to integer                        */
/*---------------------------------------------------------------------------*/
int strToInt(char * str);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* 	void flushbuff(void)							  					     */
/* -----------                                                               */
/* 																			 */
/* Return                                                                    */
/* ------                                                                    */
/*                                                                           */
/* Description                                                               */
/* -----------   															 */
/* Just flushes buffer off junk 					                         */
/*---------------------------------------------------------------------------*/
void flushbuff(void);

int main(void)
{
	/*array of countries*/
	CountryInfo country [MAX_COUNTRIES];

	int index=0;
	int invalidInput=0;
	int indexOfStrongest=0;
	int indexOfLargest=0;
	int willBeSeenAtMin=0;
	int choice;
	char givenCtr[26];
	char targetCtr[26];
	do
	{
		printf("-----------------------------------------"
				"----------------------------\n");
		if (invalidInput==0)
		{
			printf("a -> add a country\nb -> print name " 
					"of the most powerful country\n"
			  		"c -> print name of the largest country"
			  		"\nd -> how many people should be seen to "
			  		"travel from one country to another\n");
		}
		printf("Make your choice: ");

		choice=getChoice();

		switch (choice)
		{
			case a:
			{
				addCountry(country,index);
				++index;
				invalidInput=0;
			}break;

			case b:
			{
				printf("Enter the name of the country: ");
				while(getInput(givenCtr,"str"))
				{
					printf("Try again!\n");
				}

				if((indexOfStrongest=mostPowerful(country,index,givenCtr))==-1)
				{
					printf("-------------------------------------------"
					   "--------------------------\n");
					printf("The country was not found\n");
				}
				else
				{
					printf("-------------------------------------------"
					   "--------------------------\n");
					printf("%s\n",country[indexOfStrongest].name);
				}
				invalidInput=0;
			}break;

			case c:
			{	
				printf("Enter the name of the country: ");
				while(getInput(givenCtr,"str"))
				{
					printf("Try again!\n");
				}

				if((indexOfLargest=theLargest(country,index,givenCtr))==-1)
				{
					printf("-------------------------------------------"
					   "--------------------------\n");
					printf("The country was not found\n");
				}
				else
				{
					printf("-------------------------------------------"
					   "--------------------------\n");
					printf("%s\n",country[indexOfLargest].name);
				}
				invalidInput=0;

			}break;

			case d:
			{
				printf("From: ");
				while(getInput(givenCtr,"str"))
				{
					printf("Try again!\n");
				}
				printf("To: ");
				while(getInput(targetCtr,"str"))
				{
					printf("Try again!\n");
				}


				if((willBeSeenAtMin=tripFromTo(country,index,givenCtr,
					targetCtr))==-1)
				{
					printf("-------------------------------------------"
					   "--------------------------\n");
					printf("INACCESSIBLE\n");
				}
				else
				{	printf("-------------------------------------------"
					   "--------------------------\n");
					printf("Should be seen at minimum: %d people\n",
						willBeSeenAtMin);
				}
				invalidInput=0;
			}break;

			default:
			{
				printf("-------------------------------------------"
					   "--------------------------\n");
				printf("Try again!\n");
				invalidInput=1;
			}break;
		}

	}while(choice!=e && index<100);

	printf("Good Bye\n");
	return 0;

}

/*---------------------------------------------------------------------------*/
/* Function Implementations                                                  */
/*---------------------------------------------------------------------------*/
/* In this function we add a new country and information about it to 	     */
/* our array of countries. If invalid input is entered,user get warning,and  */ 
/* asked to reenter 													     */
/*---------------------------------------------------------------------------*/ 
/*here we add new country and information about it to our array of countries*/
void addCountry(CountryInfo *country,int index)
{
	int neighIndx=0;
	char neighbor[26];
	int error=0;

	neighbor[0]='\0';

	printf("Enter the name of the country to be added: ");
	while(getInput(country[index].name,"str"))
	{
		printf("Try again!\n");
	}

	printf("Enter country's population: ");
	do
	{
		if ((country[index].population=getInput(NULL,"int"))<=0)
		{
			printf("Try again!\n");
		}
		
	}while(country[index].population<=0);

	printf("Enter country's area: ");
	do
	{
		if((country[index].area=getInput(NULL,"int"))<=0)
		{
			printf("Try again!\n");
		}
	}while(country[index].area<=0);

	printf("Enter number of soldiers in army: ");
	do
	{
		if((country[index].army=getInput(NULL,"int"))<0)
		{
			printf("Try again!\n");
		}
	}while(country[index].army<0);


	country[index].neighbor.number=0;

	printf("Enter the name of the neighboring country or -1 to exit: ");

	while((!(getInput(neighbor,"str")) && neighIndx<10) || error)
	{
		error=0;
		/*if my neighbor is me*/
		if(strcmp(country[index].name,neighbor)==0)
		{
			printf("Try again!\n");
			error=1;
		}

		if(!error)
		{
			printf("Enter the name of the%sneighboring country or -1 to exit: ",
			" NEXT ");
			strcpy(country[index].neighbor.name[neighIndx],neighbor);
			++(country[index].neighbor.number);
			++neighIndx;
		}
	}
}

/* This function finds strongets country in vicinities of given country      */
/*---------------------------------------------------------------------------*/
int mostPowerful(CountryInfo *country, int index,char *givenCtr)
{
	int i,j;
	int givenCtrIndx=0;/*this country's index in array of countries*/
	int givenCtrNeighIndx=0;/*it's neighbors' indexes in array of counries*/
	int neighNeighIndx=0;/*their neighbors' indexes in array of counries*/

	CountryInfo strongest;

	/*if there is no country added */
	if(index==0)
	{
		return -1;
	}

	/*if such country exists we continue*/
	if((givenCtrIndx=countryIndex(country,index,givenCtr))!=-1)
	{
		/*so at first we suppose entered country is the most powerful */
		strongest=country[givenCtrIndx];

		/*here we check if any of the neighbors is stronger(if there is any) */
		for(i=0;i<country[givenCtrIndx].neighbor.number;++i)
		{
			/*let's check if such neighbor is in our array of countries*/
			if((givenCtrNeighIndx=countryIndex (country,index,
				country[givenCtrIndx].neighbor.name[i]))!=-1)
			{
				/*yeah he is there,but is he stronger ? */
				if(country[givenCtrNeighIndx].army>strongest.army)
				{
					strongest=country[givenCtrNeighIndx];
				}

				/*or are his neighbor stronger (if there are any)*/
				for(j=0;j<country[givenCtrNeighIndx].neighbor.number;++j)
				{
					if((neighNeighIndx=countryIndex(country,index,
						country[givenCtrNeighIndx].neighbor.name[j]))!=-1)
					{
						if(country[neighNeighIndx].army > strongest.army)
						{
							strongest=country[neighNeighIndx];
						}
					}
				}
			}
		}			
		
	}
	else /*if there is no such country added we exit*/
	{
		return -1;
	}

	return (countryIndex(country,index,strongest.name));
}

/* This function finds the largest country in vicinities of given country    */
/*---------------------------------------------------------------------------*/
int theLargest(CountryInfo *country, int index,char * givenCtr)
{
	int i,j;
	int givenCtrIndx=0;/*this country's index in array of countries*/
	int givenCtrNeighIndx=0;/*it's neighbors' indexes in array of counries*/
	int neighNeighIndx=0;/*their neighbors' indexes in array of counries*/

	CountryInfo largest;

	/*if there is no country added */
	if(index==0)
	{
		return -1;
	}

	/*if such country exists we continue*/
	if((givenCtrIndx=countryIndex(country,index,givenCtr))!=-1)
	{
		/*so at first we suppose entered country is the largest */
		largest=country[givenCtrIndx];

		/* here we check if any of the neighbors is larger(if there are any) */
		for(i=0;i<country[givenCtrIndx].neighbor.number;++i)
		{
			/*let's check if such neighbor is in our array of countries*/
			if((givenCtrNeighIndx=countryIndex (country,index,
				country[givenCtrIndx].neighbor.name[i]))!=-1)
			{
				/*yeah he is there,but is he larger ? */
				if(country[givenCtrNeighIndx].area>largest.area)
				{
					largest=country[givenCtrNeighIndx];
				}

				/*or are his neighbors larger (if there are any)*/
				for(j=0;j<country[givenCtrNeighIndx].neighbor.number;++j)
				{
					if((neighNeighIndx=countryIndex(country,index,
						country[givenCtrNeighIndx].neighbor.name[j]))!=-1)
					{
						if(country[neighNeighIndx].area > largest.area)
						{
							largest=country[neighNeighIndx];
						}
					}
				}
			}
		}			
		
	}
	else /*if there is no such country added, we exit*/
	{
		return -1;
	}

	return (countryIndex(country,index,largest.name));
}

/* This function calls the explorer to find out if the targetCtr is reachble */
/* from sourceCtr,if so it calls traveler to find the best way 				 */
/*---------------------------------------------------------------------------*/
int tripFromTo(CountryInfo *country,int index,char *sourceCtr,char *targetCtr)
{
	int i;
	int junk=0;
	char ctrVisitedByTraveler[100][26];/*journal of our traveler,where he holds*/
	/*names of the counries he's visited*/

	if(index==0)
	{
		return -1;
	}

	for(i=0;i<=index;++i)
	{
		country[i].visitedByExplorer=0;
	}

	for(i=0;i<100;++i)
	{
		strcpy(ctrVisitedByTraveler[i],"\0");
	}
	
	if(countryIndex(country,index,targetCtr)==-1)
	{
		return -1;
	}
	else if(explorer(country,index,sourceCtr,targetCtr,NULL)==0)
	{
		for(i=0;i<=index;++i)
		{
			country[i].visitedByExplorer=0;
		}

		return(traveler(country,index,sourceCtr,targetCtr,sourceCtr,
			&junk,ctrVisitedByTraveler,0));
	}

	return -1;
}

/* In this function we check if the targetCtr can be reached through thrCtr	 */
/* Explorer starts from thrCtr searches for targetCtr 						 */ 
/*---------------------------------------------------------------------------*/
/*here in this function we check if we can get to target country through given*/
/* one. If it finally leads to the target country we return 0,else 1*/
int explorer(CountryInfo *country,int index,char *thrCtr,char *targetCtr,
	char *cameFrom)
{
	int i,j;
	int ans=1;
	int thrCtrIndx;/*index of the country we are currently visiting*/
	int thereIsNoLoop;/*variable to indicate loop*/

	/*if such country doesn't exist*/
	if((thrCtrIndx=countryIndex(country,index,thrCtr))==-1)
	{
		ans=1;
	}
	/*if country is an island*/
	else if (country[thrCtrIndx].neighbor.number==0)
	{
		ans=1;
	}
	/*here we get to the target*/
	else if(compare(thrCtr,targetCtr)==1)
	{
		ans =0;
		++(country[thrCtrIndx].visitedByExplorer);
	}
	/*if explorer gets to the same country more then 10 times,that means there*/
	/*there is a loop,so we roll back*/
	else if(country[thrCtrIndx].visitedByExplorer>10)
	{
		ans=1;
		++(country[thrCtrIndx].visitedByExplorer);
	}
	else
	{
		/*we mark country as visited to our explorer journal*/
		++(country[thrCtrIndx].visitedByExplorer);

		/*so we discover new passes through current country's neighbors*/
		for(i=0;i<country[thrCtrIndx].neighbor.number;++i)
		{
			if(compare(country[thrCtrIndx].neighbor.name[i],cameFrom)==0)
			{
				thereIsNoLoop=1;

				/*here we check if there is a country i came from after on of*/
			   /*my neighbors,if so we mark it as loop,and skip(one step loop)*/
				for(j=0;j<country[countryIndex(country,index,
					country[thrCtrIndx].neighbor.name[i])].neighbor.number;++j)
				{
					if(compare(country[countryIndex(country,index,
						country[thrCtrIndx].neighbor.name[i])].neighbor.name[j],
						cameFrom))
					{
						thereIsNoLoop=0;
					}
				}

				if(thereIsNoLoop)
				{
					ans*=explorer(country,index,
						country[thrCtrIndx].neighbor.name[i],targetCtr,thrCtr);
				}
			}
		}
	}

	return (ans);
}

/* In this function our unsocial traveler finds out by which way he will     */
/* see less people while trying to get to targetCtr 					     */  
/*---------------------------------------------------------------------------*/
/*here we calculate the min amount of people i should see in order to travel */
/* from sourceCtr to targetCtr*/
int traveler(CountryInfo *country,int index,char *sourceCtr,char *targetCtr, 
	char *cameFrom,int *reachedParam,char ctrVisitedByTraveler[][26],
	int countryVisitedIndx)
{
	int i,j,k;
	int peopleSeen=0;
	int min = 99999999;
	int sourceCtrIndx;
	int thereIsNoLoop;
	int reached=0;
	int flag =0;

	sourceCtrIndx=countryIndex(country,index,sourceCtr);

	/*when we get to target*/
	if (compare(sourceCtr,targetCtr))
	{	
		*reachedParam=1;
		return 0;
	}
	/*if there is no field in our travel journal with name of cuurent country*/
	/*we continue,else there is a loop*/
	else if(FindCountryVisitedIndx(ctrVisitedByTraveler,countryVisitedIndx,
		sourceCtr) != -1)
	{	
		*reachedParam=0;
		return 0;
	}
	else
	{
		/*we write in the journal that the country is visited*/
		strcpy(ctrVisitedByTraveler[countryVisitedIndx],sourceCtr);

		/*then we try to find the way to the target country through neighbors*/
		for(i=0;i<country[sourceCtrIndx].neighbor.number;++i)
		{
			peopleSeen =0;

			if(explorer(country,index,
				country[sourceCtrIndx].neighbor.name[i],targetCtr,cameFrom)==0
				&& compare(country[sourceCtrIndx].neighbor.name[i],cameFrom)==0)
			{
				/*here we zero our explorer journal*/
				for(k=0;k<=index;++k)
				{
					country[k].visitedByExplorer=0;
				}

				thereIsNoLoop=1;

				for(j=0;j<country[countryIndex(country,index,
				country[sourceCtrIndx].neighbor.name[i])].neighbor.number;++j)
				{
					if(compare(country[countryIndex(country,index,
					country[sourceCtrIndx].neighbor.name[i])].neighbor.name[j],
						cameFrom) && cameFrom!=sourceCtr)
					{
						thereIsNoLoop=0;
					}
				}

				if(thereIsNoLoop)
				{
					peopleSeen=peopleSeen+country[countryIndex(country,index,
						country[sourceCtrIndx].neighbor.name[i])].population +
					traveler(country,index,
						country[sourceCtrIndx].neighbor.name[i],
						targetCtr,sourceCtr,&reached,
						ctrVisitedByTraveler,++countryVisitedIndx);

					/*when ever we roll back from one neighbor we zero our*/
					/*journal*/
					for(k=FindCountryVisitedIndx(ctrVisitedByTraveler,
					  countryVisitedIndx,sourceCtr)+1;k<=countryVisitedIndx;++k)
					{
						strcpy(ctrVisitedByTraveler[k],"\0");
					}

					if((peopleSeen<min) && reached)
					{
						flag =1;
						min=peopleSeen;
					}
				}	
			}
		}
	}
	
	if(flag)
	{
		*reachedParam=1;
	}
	else
	{
		*reachedParam=0;		
	}

	return min;
}

/* This function converts string of digits to integer                        */
/*---------------------------------------------------------------------------*/
int strToInt(char * str)
{
	int i;
	int ans=0;
	int exponent;

	exponent=strlen(str);

	for(i=0;i<strlen(str);++i)
	{
		ans+=(str[i]-48)*pow(10,--exponent);
	}

	return ans;
}

/* In this function we get input from the user 								 */
/*---------------------------------------------------------------------------*/
int getChoice()
{
	char input[100];

	scanf("%s",input);

	if(strcmp(input,"a")==0)
	{
		return 0;
	}
	else if(strcmp(input,"b")==0)
	{
		return 1;
	}
	else if(strcmp(input,"c")==0)
	{
		return 2;
	}
	else if(strcmp(input,"d")==0)
	{
		return 3;
	}
	else if(strcmp(input,"e")==0)
	{
		return 4;
	}
	else
	{
		/*do nothing */
	}

	return -1;
}

/* In this function we get input from user,to fill our array of countries 	 */
/*---------------------------------------------------------------------------*/
/*here we get inputs*/
/*function have 2 modes: str and int */
/*mode str -> if "-1" is entered RETURNS 1, else if any other string wich */
/*does not*/
/*contain digits or punctuation, RETURNS 0*/
/*mode int-> RETURNS entered integer */
/*invalid mode RETURNS (-1)*/
int getInput(char *str,const char * mode)
{
	int i;
	int status=0;
	char input[100];

	if(strcmp("str",mode)==0)
	{
		do
		{	
			status=0;
			scanf("%s",input);

			if(strcmp(input,"-1")==0)
			{
				return 1;
			}	

			for(i=0;i<strlen(input);++i)
			{
				if(isdigit(input[i]) || ispunct(input[i]))
				{
					status=1;
				}
			}	

			if(status)
				{
					printf("Try again!\n");
					flushbuff();
				}

		}while(status);

		strcpy(str,input);

		return 0;
	}
	else if(strcmp("int",mode)==0)
	{
		do
		{
			status=0;
			scanf("%s",input);

			for(i=0;i<strlen(input);++i)
			{
				if(!(isdigit(input[i])) || ispunct(input[i]))
				{
					status=1;
				}
			}
			if(status)
				{
					printf("Try again!\n");
					flushbuff();
				}
			
		}while(status);

		return (strToInt(input));
	}
	else
	{
		return -1;
	}
}

/* This function searches for country in array of countries 			     */  
/*---------------------------------------------------------------------------*/
/*here we check for existance of entered country */
/*this function returns index of country in array of countries, if found , */
/* (-1) if not*/
int countryIndex(CountryInfo *country, int index,char * ctrToFind)
{
	int i;

	for(i=0;i<=index;++i)
	{
		if(compare(country[i].name,ctrToFind))
		{	
			return i;
		}
	}

	return -1;
}

/* -----------                                                               */
/* This function searches for country in journal of the traveler		     */  
/*---------------------------------------------------------------------------*/
int FindCountryVisitedIndx(char countryVisited[][26], int index,char * ctrToFind)
{
	int i;

	for(i=0;i<=index;++i)
	{
		if(compare(countryVisited[i],ctrToFind))
		{	
			return i;
		}
	}

	return -1;
}

/* Compare to strings for identity(handles cases)						     */  
/*---------------------------------------------------------------------------*/
/*compares to strings. returns 1 if identical ,0 if not*/
int compare(char* str1,char * str2)
{
	int i;
	int match;

	if(str1==NULL || str2==NULL || str1[0]=='\0' || str2[0]=='\0')
	{
		return 0;
	}
	else
	{	
		if(strlen(str1)!=strlen(str2))
		{
			return 0;
		}
		else
		{
			for(i=0;i<strlen(str2);++i)
			{
				match=1;

				if(tolower(str1[i])!=tolower(str2[i]))
				{
					match=0;
				}
			}

			if(match)
			{
				return 1;
			}
		}
	}

	return 0;
}

/* -----------   															 */
/* Just flushes buffer off junk 					                         */
/*---------------------------------------------------------------------------*/
/*cleans buffer*/
void flushbuff(void)
{
	while(getchar()!='\n');
}