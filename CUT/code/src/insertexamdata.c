#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <pthread.h>
#include "../header/struct.h"

extern struct examcenter *heade;
extern struct examcenter *taile;

 

void* insertexamdata(void* str)
{	
	char *ecn, *eid, *coll, *add;
	int ct=0;
	
	char *temp= (char*)str;

	char *token = strtok(temp, ":");			
	while (token != NULL) 
	{
		ct++;
		switch(ct)
		{
			case 1: ecn = calloc(strlen(token),sizeof(char)); 
				strcpy(ecn, token); 
				break;
			case 2: eid = calloc(strlen(token),sizeof(char)); 
				strcpy(eid, token); 
				break;
			case 3: coll = calloc(strlen(token),sizeof(char)); 
				strcpy(coll, token); 
				break;
			case 4: add = calloc(strlen(token),sizeof(char)); 
				strcpy(add, token); 
				break;
		}
		token = strtok(NULL, ":");
	}
	
	struct examcenter *newitem = calloc(1, sizeof(struct examcenter));
	
	newitem->examcno = calloc(strlen(ecn),sizeof(char));
	newitem->examcno = ecn;

	newitem->examid = calloc(strlen(eid),sizeof(char));
	newitem->examid = eid;
	
	newitem->college = calloc(strlen(coll),sizeof(char));
	newitem->college = coll;
	
	newitem->address = calloc(strlen(add),sizeof(char));
	newitem->address = add;
   	
	newitem->next = NULL;
	
	pthread_mutex_init(&newitem->lock, NULL);

	if(heade == NULL)
		heade = taile = newitem;
	else
	{
		taile->next = newitem;
		taile = newitem;
	}

}
