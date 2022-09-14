#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <pthread.h>
#include "../header/struct.h"

#define SUCCESS 1
#define FAILURE 0

pthread_mutex_t lock;

struct examcenter *heade = NULL;
struct examcenter *taile = NULL;

struct candidate *headc  = NULL;
struct candidate *tailc  = NULL;

int insertcandidatedata(char *str)
{
	FILE *fw;
	fw = fopen("/home/SAMSON PAUL M/code/reports/InvalidCandidates.txt", "a");
	if (fw == NULL)
        	return FAILURE;

	char *cid, *nam, *eid, *std, *end, temp[100];
	strcpy(temp, str);	
	int ct=0;
	
	char *token = strtok(temp, ",");		
	while (token != NULL) 
	{
		ct++;
		switch(ct)
		{
			case 1: cid = calloc(strlen(token),sizeof(char)); 
				strcpy(cid, token); 
				break;
			case 2: nam = calloc(strlen(token),sizeof(char)); 
				strcpy(nam, token); 
				break;
			case 3: eid = calloc(strlen(token),sizeof(char)); 
				strcpy(eid, token); 
				break;
			case 4: std = calloc(strlen(token),sizeof(char)); 
				strcpy(std, token); 
				break;
			case 5: end = calloc(strlen(token),sizeof(char)); 
				strcpy(end, token); 
				break;
		}
		token = strtok(NULL, ",");
	}

	if(ct == 5)
	{
		struct examcenter *temp = NULL;
		int flag = 0;
   		for(temp = heade; temp != NULL; temp = temp->next) 
   		{
			if(strcmp(temp->examid, eid) == 0)
			{		
				pthread_mutex_lock(&lock);
				flag = 1;
				break;
			}
		}
			
	   	if(flag == 1)
	   	{
				struct candidate *newitem = calloc(1, sizeof(struct candidate));

				newitem->examcno = calloc(strlen(temp->examcno),sizeof(char));
				newitem->examcno = temp->examcno;
	
				newitem->examid = calloc(strlen(temp->examid),sizeof(char));
				newitem->examid = temp->examid;
	
				newitem->college = calloc(strlen(temp->college),sizeof(char));
				newitem->college = temp->college;
	
				newitem->address = calloc(strlen(temp->address),sizeof(char));
				newitem->address = temp->address;
	
				newitem->candidateid = calloc(strlen(cid),sizeof(char));
				newitem->candidateid = cid;
	
				newitem->name = calloc(strlen(nam),sizeof(char));
				newitem->name = nam;

				newitem->stdate = calloc(strlen(std),sizeof(char));
				newitem->stdate = std;
	
				newitem->endate = calloc(strlen(end),sizeof(char));
				newitem->endate = end;
   		
				newitem->next = NULL;

				if(headc == NULL)
					headc = tailc = newitem;
				else
				{
					tailc->next = newitem;
					tailc = newitem;
				}
   		}
		else
		{
			fputs(str, fw);
			fputs("\n\n", fw);
			
			return FAILURE;
		}

		pthread_mutex_unlock(&lock);
	}
	else
	{
		fputs(str, fw);
		fputs("\n\n", fw);
		
		return FAILURE;
	}

	fclose(fw);

	return SUCCESS;
}
