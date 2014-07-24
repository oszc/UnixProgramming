#include<stdio.h>
#define DEBUG_PRINT printf("File %s line %d:"\
                    "x=%d, y=%d, z=%d",\
                    __FILE__,__LINE__,\
                    x,y,z)
main(){
    int x =2;
    int y =3;
    int z = x*y;
    DEBUG_PRINT;

}
