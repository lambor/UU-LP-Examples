#ifndef UTMPLIB_HEADER
#define UTMPLIB_HEADER

utmp_open(char *filename);
struct utmp *utmp_next();
int utmp_reload();
utmp_close();

#endif
