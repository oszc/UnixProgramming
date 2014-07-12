#include<stdio.h>
#define FUNDLEN 50
#define N 2

struct funds{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds[],int n);

int main(void){

    struct funds jones[N]={
    
        {
            "Bank China",
            3024.72,
            "Lucky's Savings and Loan",
            9237.11
        
        },
        {
            "Bank SRCB",
            3534.28,
            "Party Time Savings",
            3203.89
        
        }
    
    
    
    };

    printf("The Joneses have a total of %.2f.\n",sum(jones,N));
    return 0;
}

double sum(const struct funds fund[],int n)
{
    int i = 0;

    double totle = 0;
    for(i=0;i<n;i++)
    {
        totle+=fund[i].savefund;
        totle+=fund[i].bankfund;
    }
    return totle;
}
