#include <stdio.h>
#include <signal.h>

main() {
	void wakeup(int);

	printf("about to sleep for 4 seconds\n");
	signal(SIGALRM,wakeup);
	alarm(4);
	pause();
	printf("Morning so soom?\n");
}

void wakeup(int signum) {
#ifdef SHHHH
	printf("Alarm received from kernel\n");
#endif
}
