struct examcenter
{
	char *examcno;
	char *examid;
	char *college;
	char *address;
	struct examcenter *next;
	pthread_mutex_t lock;
};

struct candidate
{
	char *examcno;
	char *examid;
	char *college;
	char *address;
	char *candidateid;
	char *name;
	char *stdate;
	char *endate;
	struct candidate *next;
};