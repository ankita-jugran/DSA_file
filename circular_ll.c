#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *nextptr;
}*head;

void create(){
    int n;
    printf("input no. of nodes:-\n");
    scanf("%d",&n);
    int num,i;
    struct node *newnode,*tail;
    head=(struct node*) malloc(sizeof(struct node));

if (head==NULL){
printf("MEMORY IS NOT ALLOCATED\n"); }
else{
printf("input data:-\n");
scanf("%d",&num);
head->data=num;
head->nextptr=NULL;
tail=head;

//for creating multiple node

for (i=2;i<=n;i++){
newnode=(struct node*) malloc(sizeof(struct node));
if (newnode==NULL){
printf("MEMORY ALLOCATION FAILED!");
break;
}
else{
printf("input value for node %d:-\n",i);
scanf("%d",&num);
newnode->data=num;
newnode->nextptr=NULL;
tail->nextptr=newnode;
tail=tail->nextptr;
}
}
}
tail->nextptr=head;
printf("Linked list is created\n");
printf("\n");
}


//funcion for displaying list

void display(){
struct node *tail;
if (head==NULL){
printf("list is empty\n");}
else{
tail=head;
do{
printf("%d\t",tail->data);
tail=tail->nextptr;}
while (tail!=head);
printf("\n");
}}

//delete node at beginning 
void add_beg(){
struct node *newnode,*ptr;
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter data of new node:\n ");
scanf("%d",&newnode->data);

ptr=head;
while(ptr->nextptr!=head){
ptr=ptr->nextptr;}
ptr->nextptr=newnode;
newnode->nextptr=head;
head=newnode;
display();
printf("\n");
}

void add_end() {
    struct node *newnode,*ptr;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data of new node:\n ");
    scanf("%d",&newnode->data);

    ptr = head;
    while ( ptr->nextptr!=head ) {
        ptr = ptr->nextptr;
    }
    ptr->nextptr = newnode;
    newnode->nextptr = head;
    printf("element is added at the end\n");
}


void del_beg(){
    struct node *ptr = head;
    while ( ptr->nextptr != head) {
        ptr = ptr->nextptr;
    }
    ptr->nextptr = head->nextptr;
    free(head);
    head = ptr->nextptr;
    printf("element is deleted\n");
    printf("\n");
}

void del_end(){
    struct node *ptr = head , *preptr;
    while ( ptr->nextptr != head )
    {
        preptr = ptr;
        ptr = ptr->nextptr;
    }
    preptr->nextptr = head;
    free(ptr);
    printf("element is deleted\n");
}

void del_afternode() {
    int val;
    if ( head == NULL)
    {
        printf("linked list is not created");
    }
    
    printf("enter value of node after which you want to delete:- ");
    scanf("%d",&val);
    struct node *preptr = head , *ptr;
    if ( preptr->nextptr->nextptr == head) {
        printf("circular list has only 2 nodes , cannot delete");
    }
    while ( preptr->data != val) {
        preptr = preptr->nextptr;
    }
    ptr = preptr->nextptr;
    preptr->nextptr = ptr->nextptr;
    if ( ptr == head) {
        head = ptr->nextptr;
    }
    free(ptr);
    printf("node is deleted\n");
}

//main function
int main(){
int n;
int ch;
while (1) {
    printf("\n");
    printf("****MAIN MENU****\n");
    printf("1. Create circular ll\n");
    printf("2. Display circular ll\n");
    printf("3. Insert at the beginning\n");
    printf("4. Insert at the end\n");
    printf("5. Delete at beginning\n");
    printf("6. Delete at end\n");
    printf("7. Delete a node after a given node\n");
    printf("8. Exit\n");
    printf("\n");
    printf("enter your choice:- \n");
    scanf("%d",&ch);
    switch (ch) {
        case 1:
        create();
        break;

        case 2:
        display();
        break;
        
        case 3:
        add_beg();
        break;

        case 4:
        add_end();
        break;

        case 5:
        del_beg();
        break;

        case 6:
        del_end();
        break;

        case 7:
        del_afternode();

        case 8:
        printf("exiting the program!\n");
        exit (0);

        default:
        printf("invalid choice\n");
        break;
    }
}
return 0;
}