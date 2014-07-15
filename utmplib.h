#ifndef utmplib
#define utmplib

int utmp_open(char* filename);
struct utmp* load_next();
void utmp_close();


#endif
