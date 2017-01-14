#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define INPUT "input.dat"
#define OUTPUT "output.txt"

typedef struct 
{
	int id;
	char name[30];
	char surname[30];
}StudentType;

typedef struct 
{
	char degree[30];
	int id;
	char name[30];
	char surname[30];
}LecturerType;

typedef struct 
{
	int code;
	char name[30];
	int lecturerId;
}LectureType;

typedef struct 
{
	char className[30];
	char day[30];
	int start;
	int duration;
	int lectureCode;
}ScheduleType;

typedef struct 
{
	int stdId;
	int lectureCode;
}CoursesType;

int lectureLecturer(int *numOfEntries,long int *posOfStruct);
int studentLecture(int *numOfEntries,long int *posOfStruct);
int studentDay(int *numOfEntries,long int *posOfStruct);
int numAndPosOfStruct(int *numOfEntries,long int *posOfStruct);
int whoGivesThisClass(FILE *inputPtr,int *numOfEntries,
	long int * posOfStruct,int lecturerId,char *name ,char *surname);
int stdTakeThisClass(FILE *inputPtr,int *numOfEntries,
	long int * posOfStruct,int lectureCode);
int stdTakesLect(FILE *inputPtr,int *numOfEntries,
	long int * posOfStruct,int stdId);
void whenThisStdStudy(FILE *inputPtr,int *numOfEntries,
	long int * posOfStruct,	int stdId,char * daysThereAreClass);
void whatDaysLectIs(FILE *inputPtr,int *numOfEntries,
	long int * posOfStruct,int lectureCode,char * daysThereAreClass);
int error(void);

/******************************************************************************/
int main(void)
{
	int numOfEntries[5];
	long int posOfStruct[5];

	if(error())
	{
		printf("Error while trying to open the file \n");
		return 0;
	}

	numAndPosOfStruct(numOfEntries,posOfStruct);
	lectureLecturer(numOfEntries,posOfStruct);
	studentLecture(numOfEntries,posOfStruct);
	studentDay(numOfEntries,posOfStruct);

	return 1;
}
/******************************************************************************/


int error(void)
{
	FILE * inputPtr;	

	if ((inputPtr=fopen(INPUT,"rb"))==NULL)
	{
		return 1;
	}

	fseek(inputPtr,0,SEEK_END);
	if(ftell(inputPtr)==0)
	{
		return 1;
	}

	fseek(inputPtr,0,SEEK_SET);

	fclose(inputPtr);

	return 0;

}
/******************************************************************************/

int numAndPosOfStruct(int *numOfEntries,long int * posOfStruct)
{	
	FILE * inputPtr;
	long int offset=0;

	inputPtr=fopen(INPUT,"rb");

	/* here we read the number of occurrences of studenType entries */
	/* in our input file*/
	fread(&numOfEntries[0],sizeof(int),1,inputPtr);

	offset+=sizeof(int);

	/*here we save start position of StudentType entries*/
	fseek(inputPtr,offset,SEEK_SET);
	posOfStruct[0]=ftell(inputPtr);

	offset+=sizeof(StudentType)*numOfEntries[0];

	/* here we set pointer in our input file to the place indicating */
	/* the number of occurrences of the LecturerType entries */
	fseek(inputPtr,offset,SEEK_SET);

	/* here we read the number of occurrences of LecturerType entries */
	/* in our input file*/
	fread(&numOfEntries[1],sizeof(int),1,inputPtr);

	offset+=sizeof(int);

	/*here we save start position of LecturerType entries*/
	fseek(inputPtr,offset,SEEK_SET);
	posOfStruct[1]=ftell(inputPtr);

	offset+=sizeof(LecturerType)*numOfEntries[1];

	/* here we set pointer in our input file to the place indicating */
	/* the number of occurrences of the LectureType entries */
	fseek(inputPtr,offset,SEEK_SET);

	/* here we read the number of occurrences of LectureType entries */
	/* in our input file*/
	fread(&numOfEntries[2],sizeof(int),1,inputPtr);

	offset+=sizeof(int);

	/*here we save start position of LectureType entries*/
	fseek(inputPtr,offset,SEEK_SET);
	posOfStruct[2]=ftell(inputPtr);

	offset+=sizeof(LectureType)*numOfEntries[2];	

	/* here we set pointer in our input file to the place indicating */
	/* the number of occurrences of the ScheduleType entries */
	fseek(inputPtr,offset,SEEK_SET);

	/* here we read the number of occurrences of ScheduleType entries */
	/* in our input file*/
	fread(&numOfEntries[3],sizeof(int),1,inputPtr);

	offset+=sizeof(int);

	/*here we save start position of ScheduleType entries*/
	fseek(inputPtr,offset,SEEK_SET);
	posOfStruct[3]=ftell(inputPtr);

	offset+=sizeof(ScheduleType)*numOfEntries[3];

	/* here we set pointer in our input file to the place indicating */
	/* the number of occurrences of the CoursesType entries */
	fseek(inputPtr,offset,SEEK_SET);

	/* here we read the number of occurrences of CoursesType entries */
	/* in our input file*/
	fread(&numOfEntries[4],sizeof(int),1,inputPtr);

	offset+=sizeof(int);

	/*here we save start position of CoursesType entries*/
	fseek(inputPtr,offset,SEEK_SET);
	posOfStruct[4]=ftell(inputPtr);

	fseek(inputPtr,0,SEEK_SET);
	fclose(inputPtr);

	return 1;
}
/******************************************************************************/

int lectureLecturer(int *numOfEntries,long int *posOfStruct)
{
	FILE * inputPtr;
	FILE * outputPtr;
	LectureType lecture;
	int i;
	char object[30];
	char name[30];
	char surname [30];
	int numOfStd=0;

	inputPtr=fopen(INPUT,"rb");
	outputPtr=fopen(OUTPUT,"w");

	fputs("Lecture-Lecturer\n",outputPtr);

	if(numOfEntries[2]==0)
	{
		fputs("\n",outputPtr);
		return 0;
	}

	for(i=0;i<numOfEntries[2];++i)
	{
		/*here we read entries of type LectureType*/
		fseek(inputPtr,posOfStruct[2]+sizeof(LectureType)*i,SEEK_SET);
		fread(&lecture,sizeof(LectureType),1,inputPtr);

		/*here we prepare name of the object for output*/
		strcpy(object,lecture.name);

		/*here we find lecturer by his/her ID and return name and surname*/
		if(whoGivesThisClass(inputPtr,numOfEntries,posOfStruct,
			lecture.lecturerId,name,surname)==0)
		{
			strcpy(name,"\0");
			strcpy(surname,"\0");
		}

		/*here we count number of students taking lecture*/
		numOfStd=stdTakeThisClass(inputPtr,numOfEntries,
			posOfStruct,lecture.code);

		/*and here we write to output*/
		fprintf(outputPtr,"%s %s %s %d\n",object,name,surname,numOfStd);

	}


	fputs("\n",outputPtr);

	fseek(inputPtr,0,SEEK_SET);
	fclose(inputPtr);
	fclose(outputPtr);

	return 1;
}
/******************************************************************************/

int studentLecture(int *numOfEntries,long int* posOfStruct)
{
	FILE * inputPtr;
	FILE * outputPtr;
	StudentType student;
	int i;
	int stdId;
	char stdName[30];
	char stdSurname[30];
	int numOfLectures=0;

	inputPtr=fopen(INPUT,"rb");
	outputPtr=fopen(OUTPUT,"a");

	fputs("Student-Lecture\n",outputPtr);

	if(numOfEntries[0]==0)
	{
		fputs("\n",outputPtr);
		return 0;
	}

	for (i = 0; i <numOfEntries[0]; ++i)
	{
		/*here we read entries of type studentType*/
		fseek(inputPtr,posOfStruct[0]+sizeof(StudentType)*i,SEEK_SET);
		fread(&student,sizeof(StudentType),1,inputPtr);

		/*here we prepare student ID,name,surname and number of */
		/*lectures taken for output*/
		stdId=student.id;
		strcpy(stdName,student.name);
		strcpy(stdSurname,student.surname);
		numOfLectures=stdTakesLect(inputPtr,numOfEntries,posOfStruct,stdId);

		/*here we write to output*/
		fprintf(outputPtr,"%d %s %s %d\n",stdId,stdName,stdSurname,
			numOfLectures);
	}

	fputs("\n",outputPtr);

	fseek(inputPtr,0,SEEK_SET);
	fclose(inputPtr);
	fclose(outputPtr);

	return 1;
}
/******************************************************************************/

int studentDay(int *numOfEntries,long int * posOfStruct)
{
	FILE * inputPtr;
	FILE * outputPtr;
	StudentType student;
	int i;
	int stdId;
	char stdName[30];
	char stdSurname[30];
	char daysThereAreClass[210];

	inputPtr=fopen(INPUT,"rb");
	outputPtr=fopen(OUTPUT,"a");

	fputs("Student-Day\n",outputPtr);

	if(numOfEntries[0]==0)
	{
		fputs("\n",outputPtr);
		return 0;
	}

	for (i = 0; i <numOfEntries[0]; ++i)
	{
		strcpy(daysThereAreClass,"\0");

		/*here we read entries of type StudentType*/
		fseek(inputPtr,posOfStruct[0]+sizeof(StudentType)*i,SEEK_SET);
		fread(&student,sizeof(StudentType),1,inputPtr);

		/*here we prepare student ID,name,surname for output*/
		stdId=student.id;
		strcpy(stdName,student.name);
		strcpy(stdSurname,student.surname);

		whenThisStdStudy(inputPtr,numOfEntries,posOfStruct,
			stdId,daysThereAreClass);
		
		/*here we write to output*/
		fprintf(outputPtr,"%d %s %s %s\n",stdId,stdName,stdSurname,
		daysThereAreClass);
	}

	fputs("\n",outputPtr);

	fseek(inputPtr,0,SEEK_SET);
	fclose(inputPtr);
	fclose(outputPtr);

	return 1;
}
/******************************************************************************/

void whenThisStdStudy(FILE *inputPtr,int *numOfEntries,
	long int * posOfStruct,	int stdId,char * daysThereAreClass)
{
	int i;
	CoursesType course;
	char tepm[210];

	strcpy(tepm,"\0");

	for(i=0;i<numOfEntries[4];++i)
	{
		fseek(inputPtr,posOfStruct[4]+sizeof(CoursesType)*i,SEEK_SET);
		fread(&course,sizeof(CoursesType),1,inputPtr);

		if(course.stdId==stdId)
		{
			whatDaysLectIs(inputPtr,numOfEntries,posOfStruct,
				course.lectureCode,daysThereAreClass);
		}
	}

	if(strlen(daysThereAreClass)>0)
	{
		strncpy(tepm,daysThereAreClass,strlen(daysThereAreClass)-1);
		tepm[strlen(daysThereAreClass)-1]='\0';
		strcpy(daysThereAreClass,tepm);
	}
}
/******************************************************************************/

void whatDaysLectIs(FILE *inputPtr,int *numOfEntries,
	long int * posOfStruct,int lectureCode,char * daysThereAreClass)
{
	int i;
	ScheduleType schedule;

	for(i=0;i<numOfEntries[3];++i)
	{
		fseek(inputPtr,posOfStruct[3]+sizeof(ScheduleType)*i,SEEK_SET);
		fread(&schedule,sizeof(ScheduleType),1,inputPtr);

		if(schedule.lectureCode==lectureCode)
		{
			strcat(daysThereAreClass,schedule.day);
			strcat(daysThereAreClass,",");
		}
	}
}
/******************************************************************************/

int whoGivesThisClass(FILE *inputPtr,int *numOfEntries,
	long int * posOfStruct,int lecturerId,char *name ,char *surname)
{
	int i;
	LecturerType lecturer;	

	for(i=0;i<numOfEntries[1];++i)
	{
		fseek(inputPtr,posOfStruct[1]+sizeof(LecturerType)*i,SEEK_SET);
		fread(&lecturer,sizeof(LecturerType),1,inputPtr);

		if(lecturer.id==lecturerId)
		{
			strcpy(name,lecturer.name);
			strcpy(surname,lecturer.surname);

			return 1;
		}

	}
	
	return 0;
}
/******************************************************************************/

int stdTakeThisClass(FILE *inputPtr,int *numOfEntries,
	long int * posOfStruct,int lectureCode)
{
	int i;
	int count=0;
	CoursesType course;

	for (i = 0; i < numOfEntries[4]; ++i)
	{
		fseek(inputPtr,posOfStruct[4]+sizeof(CoursesType)*i,SEEK_SET);
		fread(&course,sizeof(CoursesType),1,inputPtr);

		if(course.lectureCode==lectureCode)
		{
			++count;
		}
	}

	return (count);
}
/******************************************************************************/

int stdTakesLect(FILE *inputPtr,int *numOfEntries,
	long int * posOfStruct,int stdId)
{
	int i;
	int count=0;
	CoursesType course;

	for (i = 0;i < numOfEntries[4];++i)
	{
		fseek(inputPtr,posOfStruct[4]+sizeof(CoursesType)*i,SEEK_SET);
		fread(&course,sizeof(CoursesType),1,inputPtr);

		if(course.stdId==stdId)
		{
			++count;
		}
	}

	return (count);
}






