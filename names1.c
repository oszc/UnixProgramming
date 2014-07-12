#include<stdio.h>
#include<string.h>

struct namect{

    char fname[20];
    char lname[20];
    int letters;
};

void getinfo(struct namect*);
void makeinfo(struct namect*);
void showinfo(const struct namect*);

int main(void){
    
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
}

void getinfo(struct namect* p){
    printf("Please input your first name:\n");
    gets(p->fname);
    printf("Please input your last name:\n");
    gets(p->lname);
}

void makeinfo(struct namect* p){

    p->letters = strlen(p->fname)+strlen(p->lname);

}

void showinfo(const struct namect* p){
    printf("%s %s, your name contain %d letters",p->fname,p->lname,p->letters);

}
