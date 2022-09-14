#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/struct.h"

#define SUCCESS 1
#define FAILURE 0

extern struct examcenter *heade;
extern struct examcenter *taile;

extern struct candidate *headc;
extern struct candidate *tailc;

int writetofile() 
{
   	struct examcenter* temp1 = NULL;
   	struct candidate* temp2 = NULL;
	
   	for(temp1 = heade; temp1 != NULL; temp1 = temp1->next) 
   	{	
		char file[100] = "/home/SAMSON PAUL M/code/reports/";
		strcat(file, temp1 -> examcno);
		strcat(file,".txt");

		FILE *fw;
		fw = fopen(file, "a");
		if (fw == NULL)
        		return FAILURE;

		for(temp2 = headc; temp2 != NULL; temp2 = temp2 -> next)
		{
			if(strcmp(temp1->examcno, temp2-> examcno) == 0)
			{
         			fputs(temp2->examcno, fw); fputs("  ", fw);
         			fputs(temp2->examid, fw); fputs("  ", fw);
				fputs(temp2->candidateid, fw); fputs("  ", fw);
				fputs(temp2->name, fw); fputs("  ", fw);
				fputs(temp2->college, fw); fputs("  ", fw);
				fputs(temp2->address, fw); fputs("  ", fw);
				fputs(temp2->stdate, fw); fputs("  ", fw);
				fputs(temp2->endate, fw); fputs("\n\n", fw);
			}
	      	}

		fclose(fw);	
   	}
}
