#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdlib.h>
#include <time.h>

#include "utmplib.h"

#define SHOWHOST

int main() {
	struct utmp *current_record;
	int utmpfd;
	int reclen = sizeof(current_record);
	if((utmp_open(UTMP_FILE)) == -1) {
		perror(UTMP_FILE);
		exit(1);
	}

	while((current_record = utmp_next())!=NULL)
		show_info(current_record);

	utmp_close();
	return 0;
}


void show_info(struct utmp *utbufp) {
	if(utbufp->ut_type != USER_PROCESS)
		return;
	printf("%-8.8s",utbufp->ut_name);
	printf(" ");
	printf("%-8.8s",utbufp->ut_line);
	printf(" ");
	showtime(utbufp->ut_time);

#ifdef SHOWHOST
	if(utbufp->ut_host[0] != '\0')
		printf(" (%s)",utbufp->ut_host);
#endif
	printf("\n");
}


void showtime(long timeval) {
	char *cp;
	cp = ctime(&timeval);
	printf("%12.12s",cp+4);
}


