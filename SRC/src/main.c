#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <pthread.h>
#include "../header/functions.h"

#define SUCCESS 1
#define FAILURE 0
#define nt 100

extern pthread_mutex_t lock;

int main(int argc, char *argv[]) 
{
	pthread_t thread_id[nt];

	char str[100], cid[10];
	int ret;

	if(argc < 3)
	{
		printf("\n\n\t!!!Please provide the required command line arguments");
		return FAILURE;
	}
	
	FILE *f;
	f = fopen(argv[1], "r");
	if (f == NULL)
        	return FAILURE;
    	while(1)
    	{
       		if(fgets(str, 100, f) == NULL)
      			break;
       		else
		{
			str[strlen(str)-1-1] = '\0';
			pthread_create(&thread_id[0], NULL, insertexamdata, (void* )str);
			pthread_join(thread_id[0], NULL);
		}
	}
	fclose(f);

	for(int i=2; i<argc; i++)
	{
		pthread_create(&thread_id[i-1], NULL, processcandidatedata, (void* )argv[i]);
		pthread_join(thread_id[i-1], NULL);
	}
	
	writetofile();

	printf("\n\nEnter the candidate id to display the hall ticket: ");
	fgets(cid, 10, stdin);
	cid[strlen(cid)-1] = '\0';
	ret = printhallticket(cid);

	if(ret == 0)
		printf("\n\n\t!!!The person with the candidate id %s is not in the list", cid);
	
	pthread_mutex_destroy(&lock);
	pthread_exit(NULL);

   	return SUCCESS;
}
