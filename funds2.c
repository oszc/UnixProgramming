#include <stdio.h>

#define FUNLEN 50
struct funds{
    char bank[FUNLEN];
    double bankfund;
    char save[FUNLEN];
    double savefund;
};
double sum(const struct funds *);

int main(void){

    struct funds stan={

        "Garlic-Melon Bank",
        3024.72,
        "Lucky's Savings and Loan",
        9237.11

    };  

    printf("Stan has a total of $%.2f.\n",sum(&stan));
    return 0 ; 



}
double sum(const struct funds* money){ 
    return money->bankfund+money->savefund;

}

