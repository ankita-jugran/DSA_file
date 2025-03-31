#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nextptr;
    } *top=NULL,*tail; // Declaring top and tail as global pointers


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
        if ( top == NULL ) {
        top = newnode;
        tail = top;
        }
    
    else {
        tail->nextptr = newnode;
        tail = newnode;
    }
    }
    }
    
    void display() {
     struct node *temp = top;
     if ( top == NULL ) {
     printf("List is empty\n");
     } 
     else {
     while ( temp != NULL ) {
     printf("Data: %d\n",temp->data);
     temp=temp->nextptr; }
    }
    }

    void push(struct node *newnode){
       newnode->nextptr=top;
        top=newnode;
        }
        
    struct node *create_onenode() {
        printf("enter newnode details:-\n");
        struct node *newnode=(struct node*) malloc(sizeof(struct node));
        if ( newnode == NULL) {
            printf("memory allocation failed\n");
            exit(1);
        }
        int val;
        printf("enter value of newnode to add:- ");
        scanf("%d", &val);
        newnode->data=val;
        newnode->nextptr=NULL;
        return newnode;
        }

    void pop(){
        if ( top == NULL ){
            printf("stack underflow , can't pop element\n");
            return;
        }    
        struct node *ptr;
        ptr=top;
        top=top->nextptr;
        ptr->nextptr=NULL;
        free(ptr);
        }
            
    void peek(){
        if ( top == NULL ){
            printf("stack is empty\n");
            return;
        }    
        int x=top->data;
    printf("element at the top is %d\n",x);
    }

    int main() {
        int n;
        printf("enter no.of nodes:- ");
        scanf("%d",&n);
        create(n);
        printf("linked list is created\n");
        display();
        struct node *newnode = create_onenode();
        push(newnode);
        printf("linked list after push operation:- \n");
        display();
        printf("linked list after pop operation:-\n");
        pop();
        display();
        peek();
        return 0;
    }