#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* processcandidatedata(void* file)
{
		char str[100];
		int ret;

		char *temp= (char*)file;
		
		FILE *f;
		f = fopen(temp, "r");
		while(1)  		
		{
       			if(fgets(str, 100, f) == NULL)
      				break;
			else
			{
				str[strlen(str)-1-1] = '\0';
				ret = insertcandidatedata(str);
				if(ret == 0)
					printf("\n\n!!!The candidate %s has incorrect data", strtok(str, ","));
			}
		}
		fclose(f);
}
