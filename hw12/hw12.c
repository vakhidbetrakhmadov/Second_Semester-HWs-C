#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "mytxt"
#define OUTPUT "mydat"

typedef struct player_scores
{
	char *name;
	double *scores;
	int size;
	double average;
}PlayerScores; 

typedef struct ll_node_s
{
	PlayerScores player;
	struct ll_node_s *rest_ptr;
}ll_node_t;

typedef struct 
{
	ll_node_t * head_ptr;
}head_t;


int readTxt(FILE *file_ptr,head_t *head);
ll_node_t * recSortLL(ll_node_t *cur_head_ptr);
int writeDat(FILE *file_ptr,head_t *head);
int error(FILE *file_ptr);

int main(void)
{
	FILE *input_ptr;
	FILE *output_ptr;
	head_t head;

	head.head_ptr=NULL;

	input_ptr=fopen(INPUT,"r");

	if(readTxt(input_ptr,&head)==0)
	{
		fprintf(stderr, "%s\n","Error while opening the file" );
		exit(-1);
	}
	fclose(input_ptr);

	head.head_ptr=recSortLL(head.head_ptr);

	output_ptr=fopen(OUTPUT,"wb");

	if(writeDat(output_ptr,&head)==0)
	{
		fprintf(stderr, "%s\n","Error while writing to the file" );
		exit(-1);
	}
	fclose(output_ptr);

	return 0;
}

/*here we write linked list to the binary file */
int writeDat(FILE *file_ptr,head_t *head)
{
	ll_node_t *cur_node_ptr;

	if(file_ptr==NULL)
	{
		return 0;
	}

	for(cur_node_ptr=head->head_ptr;
		cur_node_ptr!=NULL;
		cur_node_ptr=cur_node_ptr->rest_ptr)
	{
		fwrite(cur_node_ptr->player.name,
			sizeof(char) *strlen(cur_node_ptr->player.name),
			1,file_ptr);
		fwrite(cur_node_ptr->player.scores,
			sizeof(double)*cur_node_ptr->player.size,
			1,file_ptr);
		fwrite(&(cur_node_ptr->player.size),sizeof(int),1,file_ptr);
		fwrite(&(cur_node_ptr->player.average),sizeof(double),1,file_ptr);
	}

	return 1;
}

/*here we sort linked list in descending order  */
ll_node_t * recSortLL(ll_node_t *cur_head_ptr)
{
	ll_node_t *temp_head_ptr;
	ll_node_t *largest_ptr;
	ll_node_t *before_larg_ptr;
	ll_node_t *cur_node_ptr;
	ll_node_t *before_cur_ptr;

	/*BASE CASE (lasr node)*/
	if(cur_head_ptr->rest_ptr==NULL)
	{
		temp_head_ptr=cur_head_ptr;
	}
	else
	{
		largest_ptr=cur_head_ptr;

		/*here we find the largest node in the unsorted list */
		for(before_cur_ptr=cur_head_ptr,cur_node_ptr=cur_head_ptr->rest_ptr;
			cur_node_ptr!=NULL;
			before_cur_ptr=cur_node_ptr,cur_node_ptr=cur_node_ptr->rest_ptr)
		{
			if(cur_node_ptr->player.average > largest_ptr->player.average)
			{
				largest_ptr=cur_node_ptr;
				before_larg_ptr=before_cur_ptr;
			}
		}

		if(largest_ptr->player.average!=cur_head_ptr->player.average)
		{
			before_larg_ptr->rest_ptr=largest_ptr->rest_ptr;
			temp_head_ptr=largest_ptr;
			temp_head_ptr->rest_ptr=recSortLL(cur_head_ptr);
		}
		else
		{
			temp_head_ptr=cur_head_ptr;
			temp_head_ptr->rest_ptr=recSortLL(cur_head_ptr->rest_ptr);
		}
	}

	return temp_head_ptr;
}

/*here we read a txt file and dynamicly construct linked list*/
int readTxt(FILE *file_ptr,head_t *head)
{
	int count;
	int sts_1=0;
	int sts_2=0;
	double sum;
	double temp_scr;
	char temp_str[100];
	ll_node_t **cur_node;

	if(error(file_ptr))
	{
		return 0;	
	}

	cur_node=&(head->head_ptr);

	for(sts_1=fscanf(file_ptr,"%s",temp_str);sts_1!=0 && sts_1!=EOF;
		sts_1=fscanf(file_ptr,"%s",temp_str))
	{
		*cur_node=(ll_node_t*) malloc(sizeof(ll_node_t));

		(*cur_node)->player.name=(char *) malloc (strlen(temp_str));
		strcpy((*cur_node)->player.name,temp_str);

		(*cur_node)->player.scores=NULL;
		count =0;
		sum=0;
		for(sts_2=fscanf(file_ptr,"%lf",&temp_scr);sts_2!=0 && sts_2!=EOF;
			sts_2=fscanf(file_ptr,"%lf",&temp_scr))
		{
			(*cur_node)->player.scores=
			(double*) realloc((*cur_node)->player.scores,sizeof(double) * (count+1));
			(*cur_node)->player.scores[count]=temp_scr;
			sum+=temp_scr;
			++count;
		}
		(*cur_node)->player.size=count;
		(*cur_node)->player.average=(double)sum/count;
		
		(*cur_node)->rest_ptr=NULL;	
		cur_node=&((*cur_node)->rest_ptr);
		
	}

	return 1;
}

int error(FILE *file_ptr)
{
	if(file_ptr==NULL)
	{
		return 1;
	}

	fseek(file_ptr,0,SEEK_END);
	if(ftell(file_ptr)==0)
	{
		fclose(file_ptr);
		return 1;
	}

	fseek(file_ptr,0,SEEK_SET);

	return 0;
}