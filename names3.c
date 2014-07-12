#include<stdio.h>

struct namect{
    char* fname;
    char* lname;
    int letters;
};

void getinfo(struct namect* p);
void makeinfo(struct namect* p);
void showinfo(struct namect* p);
void cleanup(struct namect* p);

int main(void){

   struct namect p;
   getinfo(&p);
   makeinfo(&p);
   showinfo(&p);
   cleanup(&p);


}

void getinfo(struct namect* p)
{
    char temp[81];
    printf("Please input your first name.\n");
    gets(temp);
    p->fname = (char*)malloc(strlen(temp)+1);
    strcpy(p->fname,temp);

    printf("Please input you last name.\n");
    gets(temp);
    p->lname = (char*)malloc(strlen(temp)+1);
    strcpy(p->lname,temp);
}
void makeinfo(struct namect* p){
    p->letters = strlen(p->fname)+strlen(p->lname);

}
void showinfo(struct namect* p){
    printf("%s %s your name contain %d letters",p->fname,p->lname,p->letters);
}
void cleanup(struct namect* p){
    free(p->fname);
    free(p->lname);
}

