/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW11_141044086_Vakhid_Betrakhmadov                                       */
/*                                                                          */
/* main.c                                                                   */
/* ---------                                                                */
/* Created on 05/15/2016 by Vakhid_Betrakhmadov                             */
/*                                                                          */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/* Includes 																*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*---------------------------------------------------------------------------*/
/* Function Prototypes                                                       */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*void posSeqInSt(int usDataSize,int fieldSize,char ***seqArr2D,int *numPos, */
/*	char *tempSeqPrm,int tempIndx)		                                     */
/* -----------   f                                                            */
/* usDataSize-size of the structer-avg                                    	 */
/* fieldSize- supposed size of the next data field in the structer  		 */
/* seqArr2D -dynamicly allocated two dimentional array 						 */
/* numPos - total number of all possibilies(stored in seqArr2D)				 */
/* tempSeqPrm - temporary one dimentional array to to manipulate within 	 */
/* function 																 */
/* tempIndx - lenght of the temporary array at the current  iteration 		 */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* Function does not return anything                                         */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This is recursive function, which calculates all possible permutations of */
/* digits 1,4 and 8 in order to get the given number(usDataSize).For example */
/* if usDataSize is 4 there is only 2 possible permutations : 1111 and 4 	 */
/* It stores this permutations and the total number of them int the two 	 */
/*dimentional dynamicly allocated output array and output int value(numPos)  */
/*---------------------------------------------------------------------------*/
void posSeqInSt(int usDataSize,int fieldSize,char ***seqArr2D,int *numPos,
	char *tempSeqPrm,int tempIndx);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*int isSeqTrue(FILE *inputPtr,char * seqArr1D,int * my_arr_out,			 */
/*	double avg,double myAvg,double numOfEl,int *tempArrPrm,int tempArrIndx)	 */    
/* -----------                                                               */
/* inputPtr - file pointer 												     */
/* seqArr1D - permutation to check 											 */
/* my_arr_out - temporary output array to store the answer 					 */
/* avg - average value of the structer 										 */
/* myAvg - average value calculated during a function call 					 */
/* numOfEl - number of data field in the given permutation 				     */
/* tempArrPrm - temporary array to manipulate within the function 		     */
/* tempArrIndx - lenght of the temporary array at the current iteration 	 */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* 1 - failure 																 */
/* 0 - on succcess 															 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This is recursive function, which checks if the given permutation 		 */
/* complies with current structer, if so it return answer array and 0 value  */
/* to indicate succcess 					 							     */
/*---------------------------------------------------------------------------*/
int isSeqTrue(FILE *inputPtr,char * seqArr1D,int * my_arr_out,
	double avg,double myAvg,double numOfEl,int *tempArrPrm,int tempArrIndx);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int error(FILE *inputPtr)										 		 */    
/* -----------                                                               */
/* inputPtr - file pointer 												     */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* 1 -on succcess 															 */
/* 0 - failure  															 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function checks if the given file exists and if there is anything in */
/* it. If  it doesnt exist or if it's empty returns 1 	     				 */
/*---------------------------------------------------------------------------*/
int error(FILE *inputPtr);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*int isItThere(char ** arr2D,int size,char *arr1D)							 */    
/* -----------                                                               */
/* arr2D -two dimentional array 										     */
/* size-number of elements in two dimentional array 						 */
/* arr1D - one dimentional array 										 	 */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* 1 -on succcess 															 */
/* 0 - failure  															 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/*This is small helper function which checks if the arr1D is already in arr2D*/
/*---------------------------------------------------------------------------*/
int isItThere(char ** arr2D,int size,char *arr1D);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*void copyArr(int *arr1,int *arr2,int size)	  							 */    
/* -----------                                                               */
/* arr2D -one dimentional array											     */
/* size- length of arr2 							 						 */
/* arr1D - one dimentional array 										 	 */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */				
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/*This is small helper function which copies one array to anothe given that  */
/* either arr1 is bigger of equals arr2 in size 							 */
/*---------------------------------------------------------------------------*/
void copyArr(int *arr1,int *arr2,int size);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*int hwDecode(const char *filename,int arr_out[])	  						 */    
/* -----------                                                               */
/* filename - file name	 	 											 	 */
/* arr_out - output array for the answer 									 */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* 	0-success 	   															 */
/* -1 -failure 																 */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This functions finds total size of the structer in the file, and size 	 */
/* of the useful part of the structer(structSize-sizeof(double)).		     */
/* Then calls another functions to calculate all possible permutation for the*/
/* founed usDataSize, and check all of this permutation on 1000 structers in */
/*file calling isSeqTrue function. If one of the permutations is true for all*/
/* 1000 structers, returns the answer 		 								 */
/*---------------------------------------------------------------------------*/
int hwDecode(const char *filename,int arr_out[]);

int main(void)
{	
	int i;
	int arr_out[10];

	if(hwDecode("myfile.dat",arr_out)==-1)
	{
		printf("ERROR\n");
	}

	for(i=0;i<10;++i)
	{
		printf("%d",arr_out[i]);
	}
	printf("\n");

	return 0;
}

/*---------------------------------------------------------------------------*/
/* Function Implementations                                                  */
/*---------------------------------------------------------------------------*/ 
/* Function hwDecode                                                         */
/* -----------                                                               */ 
/* This functions finds total size of the structer in the file, and size 	 */
/* of the useful part of the structer(structSize-sizeof(double)).		     */
/* Then calls another functions to calculate all possible permutation for the*/
/* founed usDataSize, and check all of this permutation on 1000 structers in */
/*file calling isSeqTrue function. If one of the permutations is true for all*/
/* 1000 structers, returns the answer 		 								 */
/*---------------------------------------------------------------------------*/
int hwDecode(const char *filename,int arr_out[])
{
	int i,j,k;
	int start,flag;
	FILE * inputPtr;
	int structSize=0;
	int usDataSize=0;
	double avg=0.0;
	char **seqArr2D;
	int numPos=0;
	int my_arr_out[10];
	int avgAdress;

	inputPtr=fopen(filename,"rb");

	if(error(inputPtr))
	{
		return -1;
	}

	fseek(inputPtr,0,SEEK_END);
	structSize=ftell(inputPtr)/1000;
	usDataSize=structSize-sizeof(double);

	if(structSize==sizeof(double))
	{
		for(i=0;i<10;++i)
		{
			arr_out[i]=-1;
		}

		return 0;
	}	

	posSeqInSt(usDataSize,0,&seqArr2D,&numPos,NULL,0);

	for(i=0;i<numPos;++i)
	{
		flag =1;

		for(j=0,start=0,avgAdress=start+usDataSize;j<10;
			++j,start+=structSize,avgAdress=start+usDataSize)
		{
			if(flag==0)
			{
				continue;
			}

			fseek(inputPtr,avgAdress,SEEK_SET);
			fread(&avg,sizeof(double),1,inputPtr);
			fseek(inputPtr,start,SEEK_SET);

			for(k=0;k<10;++k)
			{
				my_arr_out[k]=-1;
			}

			if(isSeqTrue(inputPtr,seqArr2D[i],my_arr_out,avg,0,
				((double)strlen(seqArr2D[i])),NULL,0))
			{
				flag=0;	
			}
		}

		if(flag==1)
		{
			copyArr(arr_out,my_arr_out,10);
		}
	}

	fclose(inputPtr);

	return 0;
}

/* Function isSeqTrue                                                        */
/* -----------                                                               */ 
/* This is recursive function, which checks if the given permutation 		 */
/* complies with current structer, if so it return answer array and 0 value  */
/* to indicate succcess 					 							     */
/*---------------------------------------------------------------------------*/
int isSeqTrue(FILE *inputPtr,char * seqArr1D,int * my_arr_out,
	double avg,double myAvg,double numOfEl,int *tempArrPrm,int tempArrIndx)
{
	int ans =1;
	int tempArr[10];
	unsigned char myChar='0';
	int myInt=0;
	long int myLongInt=0;
	float myFloat=0;
	double myDouble=0.0;
	int curPos=0;

	if (tempArrPrm==NULL)
	{
		ans*=isSeqTrue(inputPtr,seqArr1D,
			my_arr_out,avg,myAvg,numOfEl,tempArr,tempArrIndx);
	}
	/*BASE CASE 1*/
	else if((myAvg/numOfEl)==avg && seqArr1D[0]=='\0')
	{
		ans=0;
		copyArr(my_arr_out,tempArrPrm,tempArrIndx);
	}
	/*BASE CASE 2*/
	else if(seqArr1D[0]=='\0')
	{
		ans =1;
	}
	else
	{
		switch(seqArr1D[0])
		{
			case '1':
			{
				fread(&myChar,sizeof(unsigned char),1,inputPtr);
				tempArrPrm[tempArrIndx]=1;
				ans*=isSeqTrue(inputPtr,&seqArr1D[1],
				my_arr_out,avg,myAvg+myChar,numOfEl,tempArrPrm,tempArrIndx+1);
			}break;

			case '4':
			{
				curPos=ftell(inputPtr);
				fread(&myInt,sizeof(int),1,inputPtr);
				tempArrPrm[tempArrIndx]=2;
				copyArr(tempArr,tempArrPrm,10);
				ans*=isSeqTrue(inputPtr,&seqArr1D[1],
					my_arr_out,avg,myAvg+myInt,numOfEl,tempArr,tempArrIndx+1);


				fseek(inputPtr,curPos,SEEK_SET);
				fread(&myFloat,sizeof(float),1,inputPtr);
				tempArrPrm[tempArrIndx]=4;
				copyArr(tempArr,tempArrPrm,10);
				ans*=isSeqTrue(inputPtr,&seqArr1D[1],
					my_arr_out,avg,myAvg+myFloat,numOfEl,tempArr,tempArrIndx+1);
			}break;

			case '8':
			{
				curPos=ftell(inputPtr);
				fread(&myLongInt,sizeof(long int),1,inputPtr);
				tempArrPrm[tempArrIndx]=3;
				copyArr(tempArr,tempArrPrm,10);
				ans*=isSeqTrue(inputPtr,&seqArr1D[1],
					my_arr_out,avg,myAvg+myLongInt,numOfEl,tempArr,tempArrIndx+1);


				fseek(inputPtr,curPos,SEEK_SET);
				fread(&myDouble,sizeof(double),1,inputPtr);
				tempArrPrm[tempArrIndx]=5;
				copyArr(tempArr,tempArrPrm,10);
				ans*=isSeqTrue(inputPtr,&seqArr1D[1],
					my_arr_out,avg,myAvg+myDouble,numOfEl,tempArr,tempArrIndx+1);
			}break;
		}
	}

	return ans;
}

/* Function posSeqInSt                                                       */
/* -----------                                                               */ 
/* This is recursive function, which calculates all possible permutations of */
/* digits 1,4 and 8 in order to get the given number(usDataSize).For example */
/* if usDataSize is 4 there is only 2 possible permutations : 1111 and 4 	 */
/* It stores this permutations and the total number of them int the two 	 */
/*dimentional dynamicly allocated output array and output int value(numPos)  */
/*---------------------------------------------------------------------------*/
void posSeqInSt(int usDataSize,int fieldSize,char ***seqArr2D,int *numPos,
	char *tempSeqPrm,int tempIndx)
{
	char tempSeq[100];
	tempSeq[0]='\0';

	/*BASE CASE 1*/
	if(tempIndx>10 || usDataSize<0)
	{
		return;
	}
	/*BASE CASE 2*/
	else if(usDataSize==0)
	{
		if(*numPos==0)
		{
			*seqArr2D=(char **) malloc(sizeof(char *));
			(*seqArr2D)[0]=(char*) malloc (strlen(tempSeqPrm)+1);
			strcpy((*seqArr2D)[0],tempSeqPrm);
			++(*numPos);
		}
		else
		{
			if(isItThere(*seqArr2D,*numPos,tempSeqPrm)==0)
			{
				*seqArr2D=realloc(*seqArr2D,sizeof(char*)*(*numPos+1));
				(*seqArr2D)[(*numPos)]=(char *) malloc(strlen(tempSeqPrm)+1);
				strcpy((*seqArr2D)[*numPos],tempSeqPrm);
				++(*numPos);
			}
		}	

		return;
	}
	else
	{
		switch (fieldSize)
		{
			case 1:
			{
				strcat(tempSeqPrm,"1");
				tempIndx+=1;
			}break;
			case 4:
			{
				strcat(tempSeqPrm,"4");
				tempIndx+=1;
			}break;
			case 8:
			{
				strcat(tempSeqPrm,"8");
				tempIndx+=1;
			}break;
			default:break;
		}

		if(tempSeqPrm!=NULL)
		{
			strcpy(tempSeq,tempSeqPrm);
		}
		posSeqInSt(usDataSize-fieldSize,1,seqArr2D,numPos,
			tempSeq,tempIndx);

		if(tempSeqPrm!=NULL)
		{
			strcpy(tempSeq,tempSeqPrm);
		}
		else
		{
			memset(tempSeq,'\0',strlen(tempSeq));
		}

		posSeqInSt(usDataSize-fieldSize,4,seqArr2D,numPos
			,tempSeq,tempIndx);

		if(tempSeqPrm!=NULL)
		{
			strcpy(tempSeq,tempSeqPrm);
		}
		else
		{
			memset(tempSeq,'\0',strlen(tempSeq));
		}

		posSeqInSt(usDataSize-fieldSize,8,seqArr2D,numPos,
			tempSeq,tempIndx);
	}
}


/* Function isItThere                                                        */
/* -----------                                                               */ 
/*This is small helper function which checks if the arr1D is already in arr2D*/
/*---------------------------------------------------------------------------*/
int isItThere(char ** arr2D,int size,char *arr1D)
{
	int i;
	int flag =0;

	for(i=0;i<size;++i)
	{
		if(strcmp(arr2D[i],arr1D)==0)
		{
			flag =1;
		}
	}

	return (flag);
}

/* Function copyArr                                                          */
/* -----------                                                               */ 
/*This is small helper function which copies one array to anothe given that  */
/* either arr1 is bigger of equals arr2 in size 							 */
/*---------------------------------------------------------------------------*/
void copyArr(int *arr1,int *arr2,int size)
{
	int i;

	for(i=0;i<size;++i)
	{
		arr1[i]=arr2[i];
	}
}

/* Function error                                                            */
/* -----------                                                               */ 
/* This function checks if the given file exists and if there is anything in */
/* it. If  it doesnt exist or if it's empty returns 1 	     				 */
/*---------------------------------------------------------------------------*/
int error(FILE *inputPtr)
{
	if(inputPtr==NULL)
	{
		return 1;
	}

	fseek(inputPtr,0,SEEK_END);
	if(ftell(inputPtr)==0)
	{
		fclose(inputPtr);
		return 1;
	}

	return 0;
}