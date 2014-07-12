#include<stdio.h>
#define LEN 30
struct namect{
    char fname[LEN];
    char lname[LEN];
    int letters;
};

struct namect getinfo(struct namect p);
struct namect makeinfo(struct namect p);
void showinfo(struct namect p);

int main(void){
    struct namect person;
    person=getinfo(person);
    person = makeinfo(person);
    showinfo(person);
}

struct namect getinfo(struct namect p){

    printf("please,enter your first name\n");
    gets(p.fname);
    printf("please enter your last name\n");
    gets(p.lname);
    return p;
}

struct namect makeinfo(struct namect p){
    
    p.letters = strlen(p.fname)+strlen(p.lname);
    return p;

}
void showinfo(struct namect p){

    printf("%s %s, your name contains %d letters.\n",p.fname,p.lname,p.letters);

}
