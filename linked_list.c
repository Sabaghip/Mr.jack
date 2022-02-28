
#include "linked_list.h"
#include <string.h>


void add_end(struct zamin *khoone,struct character *ch){
    if(khoone->characters==NULL){
        khoone->characters=ch;
        ch->next=NULL;
    }
    else{
        struct  character *curr;
        for(curr=khoone->characters;curr->next!=NULL;curr=curr->next);
        curr->next=ch;
        ch->next=NULL;
    }
}

void delete(struct zamin **khoone,char name[40]){
    struct character *curr;
    if((*khoone)->characters==NULL) {
        printf("IT IS EMPTY");
        return;
    }
    if((*khoone)->characters->next==NULL && strcmp((*khoone)->characters->name,name)!=0){
        printf("THERE IS NOT YOUR CHARACTER");
        return;
    }
    if((*khoone)->characters->next==NULL && strcmp((*khoone)->characters->name,name)==0){
        (*khoone)->characters=NULL;
        return;
    }
    if(strcmp((*khoone)->characters->name,name)==0){
        (*khoone)->characters=(*khoone)->characters->next;
        return;
    }

    for(curr=(*khoone)->characters;strcmp(curr->next->name,name)!=0;curr=curr->next);
    struct character *temp=curr->next->next;
    curr->next=temp;
}

int show_arrest_list(struct zamin *z){
    struct character *curr;
    int k=1;
    for(curr=z->characters;curr->next!=NULL;curr=curr->next)
        printf("%d.%s\n",k++,curr->name);
    return k-1;
}

struct character *get_num(struct zamin *z,int k){
    struct character *curr=z->characters;
    for(int i=1;i<k;i++)
        curr=curr->next;
    return curr;
}