//  main.c
//  linked list
//  Created by Kunwar Rehan on 02/09/18.
//  Copyright © 2018 Kunwar Saaim. All rights reserved.
#include <stdio.h>
#include "stdlib.h"
struct node{
    int info;
    struct node *link;
};
struct node *create_list(struct node *start);
void display(struct node *start);
void count( struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data, int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data, int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);
int main(void){
    struct node *start=NULL;
    int choice,data,item,pos;
    while (1) {
        printf("1.Create list\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add to empty list/ Add at beginning\n");
        printf("6.Add at end\n");
        printf("7.Add before node\n");
        printf("8.Add after node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Reverse\n");
        printf("12.Quit\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                start=create_list(start);
                break;
            case 2:
                display(start);
                break;
            case 3:
                count(start);
                break;
            case 4:
                printf("enter the element to be searched : ");
                scanf("%d",&data);
                search(start, data);
                break;
            case 5:
                printf("enter element to be inseter : ");
                scanf("%d",&data);
                start = addatbeg(start, data);
                break;
            case 6:
                printf("enter element to be inserted : ");
                scanf("%d",&data);
                start = addatend(start, data);
                break;
            case 7:
                printf("enter element to be inserted : ");
                scanf("%d",&data);
                printf("enter the element after which to be inserted : ");
                scanf("%d",&item);
                start = addafter(start, data, item);
                break;
            case 8:
                printf("enter the element to inserted :");
                scanf("%d",&data);
                printf("enter the before which to insert : ");
                scanf("%d",&item);
                start = addbefore(start, data, item);
                break;
            case 9:
                printf("enter the element to be inseted : ");
                scanf("%d",&data);
                printf("enter the position at which to insert : ");
                scanf("%d",&pos);
                start = addatpos(start, data, pos);
                break;
            case 10:
                printf("enter the element to be deleted : ");
                scanf("%d",&data);
                start = del(start, data);
                break;
            case 11:
                start = reverse(start);
                break;
            case 12:
                exit(1);
            default:
                printf("wrong choice\n");
        }
    }
    return 0;
}
void display(struct node *start){
    struct node *p;
    if (start==NULL) {
        printf("list is empty");
        return;
    }
    p= start;
    while (p!=NULL) {
        printf("%d",p->info);
        p = p->link;
    }
    printf("\n\n");
}
void count(struct node *start){
    struct node *p;
    p = start;
    int cnt = 0;
    while (p!=NULL) {
        p= p->link;
        cnt++;
    }
    printf("%d ",cnt);
}
struct node *addatbeg(struct node *start,int data){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link = start;
    return start;
}
struct node *addatend(struct node *start, int data){
    struct node *temp,*p;
    temp = (struct node*)malloc(sizeof(struct node));
    p=start;
    while (p->link!=NULL) {
        p=p->link;
    }
    p->link = temp;
    temp->link = NULL;
    return start;
}
struct node *addafter(struct node *start, int data, int item){
    struct node *temp,*p;
    p = start;
    while (p!=NULL) {
        if (p->info==item) {
            temp = (struct node*)malloc(sizeof(struct node));
            temp->info=data;
            temp->link = p->link;
            p->link=temp;
            return start;
        }
        p=p->link;
    }
    printf("%d not present in the list\n",item);
    return start;
}
void search(struct node *start,int item){
    struct node *p=start;
    int pos = 1;
    while (p!=NULL) {
        if (p->info==item) {
            printf("item %d found at %d ",item,pos);
            return;
        }
        p=p->link;
        pos++;
    }
    printf("item %d not found in the list\n ",item);
}
struct node *addbefore(struct node *start,int data, int item){
    struct node *temp,*p;
    if (start==NULL) {
        printf("list is empty : ");
        return start;
    }
    if (item == start->info) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info=data;
        temp= start->link;
        start = temp;
        return start;
    }
    p=start;
    while (p->link!=NULL) {
        if (p->link->info == item) {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->info=data;
            temp->link = p->link;
            p->link=temp;
            return start;
        }
        p=p->link;
    }
    printf("%d not present in the list\n",item);
    return start;
}
struct node *addatpos(struct node *start, int data, int pos){
    struct node *temp,*p;
    int i;
    p=start;
    for (i=1; i<pos-1; i++) {
        p=p->link;
    }
    if (p==NULL) {
        printf("there are less than %d elements",pos);
    }
    else{
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info =data;
        if (pos==1) {
            temp->link= start;
            start=temp;
        }
        else{
            temp->link= p->link;
            p->link= temp;
        }
    }
    return start;
}
struct node *create_list(struct node *start){
    int i,n,data;
    printf("enter number of nodes : ");
    scanf("%d",&n);
    start = NULL;
    if (n==0) {
        return start;
    }
    printf("enter the element to be inserted : ");
    scanf("%d",&data);
    start = addatbeg(start, data);
    for (i=2; i<=n; i++) {
        printf("enter element to be inseted : ");
        scanf("%d",&data);
        start = addatend(start, data);
    }
    return start;
}
struct node *del(struct node *start, int data){
    struct node *temp,*p;
    if (start ==NULL) {
        printf("list is empty \n");
        return start;
    }
    if (start->info==data) {
        temp=start;
        temp=start->link;
        free(temp);
    }
    p=start;
    while (p->link!=NULL) {
        if (p->link->info==data) {
            temp=p->link;
            temp->link = p->link;
            free(temp);
            return start;
        }
        p=p->link;
    }
    printf("element %d not found \n",data);
    return start;
}
struct node *reverse(struct node *start){
    struct node *prev,*ptr,*next;
    prev=NULL;
    ptr=start;
    while (ptr!=NULL) {
        next=ptr->link;
        ptr->link=prev;
        prev= ptr;
        ptr=next;
    }
    start =prev;
    return start;
}
    
    
    
    
    
    
    
    

