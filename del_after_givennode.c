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

void del_afternode(){
if ( head == NULL ) {
    printf("List is empty. you cannot delete anything\n");
    return;
}
struct node *ptr = head, *temp;
int val;
printf("enter data of node after which you want to delete:- ");
scanf("%d",&val);
while ( ptr !=NULL && ptr->data!=val ){
    ptr = ptr->nextptr;
}
if ( ptr == NULL) {
    printf("node with %d data not found\n ",val);
return;
}
if ( ptr == tail ) {
    printf("reached at the end of linked list , cannot delete after node\n");
    return;
}
else{
    temp = ptr->nextptr;
    ptr->nextptr = temp->nextptr; }
free(temp);
printf("node is deleted\n");

}

int main() {
int n;
printf("Input number of nodes:\n");
scanf("%d", &n);
create(n);
printf("list before deletion:-\n");
display();
del_afternode();
printf("List after deletion:\n"); 
display();
return 0;
}