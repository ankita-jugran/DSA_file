#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *nextptr;
} *head,*tail; // Declaring head and tail as global pointers

void create(int n) {
int num,i;
struct node *newnode;
for ( i=1 ; i<=n ; i++ ) {
    newnode=(struct node*) malloc(sizeof(struct node)); 
    if (newnode==NULL) {
    printf("MEMORY ALLOCATION FAILED!\n");
    break;
    }
    printf("enter data for node %d:- ",i);
    scanf( "%d",&num );
    newnode->data = num;
    newnode->nextptr = NULL;
    if ( head == NULL ) {
    head = newnode;
    tail = head;
    }

else {
    tail->nextptr = newnode;
    tail = newnode;
}
}
}

void display() {
 struct node *temp = head;
 if ( head == NULL ) {
 printf("List is empty\n");
 } else {
 while ( temp != NULL ) {
 printf("Data: %d\n",temp->data);
 temp=temp->nextptr; }
}
}

void delnode(){
if ( head == NULL ) {
    printf("List is empty. you cannot delete anything\n");
    return;
}
struct node *ptr , *prev;
int val;
printf("enter data of node which you want to delete:- ");
scanf("%d",&val);
ptr = head;
if ( head->data == val ) {
    head = head->nextptr;
    free(ptr);
    printf("node is deleted\n");
    return;
}
while ( ptr !=NULL && ptr->data!=val ){
    prev = ptr;
    ptr = ptr->nextptr;
}
if ( ptr == NULL) {
    printf("node with %d data not found\n ",val);
return;
}
if ( ptr == tail ) {
    tail = prev;
    prev->nextptr == NULL;
}
prev->nextptr = ptr->nextptr;
free(ptr);
printf("node is deleted\n");
}

int main() {
int n;
printf("Input number of nodes:\n");
scanf("%d", &n);
create(n);
printf("list before deletion:-\n");
display();
delnode();
printf("List after deletion:\n"); 
display();
return 0;
}