#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/struct.h"

#define SUCCESS 1
#define FAILURE 0

extern struct candidate *headc;
extern struct candidate *tailc;

int printhallticket(char *cid) 
{	
	struct candidate* temp = NULL;

	for(temp = headc; temp != NULL; temp = temp->next) 
   	{	
		if(strcmp(temp->candidateid, cid) == 0)
		{
         		printf("\n\nNAME           :  %s\n\nCANDIDATE ID   :  %s\n\nEXAM ID        :  %s\n\nEXAM CENTER    :  %s\n\nCOLLEGE        :  %s\n\nADDRESS        :  %s\n\nSTART DATE     :  %s\n\nEND DATE       :  %s",temp->name, temp->candidateid, temp->examid, temp->examcno, temp->college, temp->address, temp->stdate, temp->endate);
			return SUCCESS;
		}
   	}
	
	return FAILURE;	
}
