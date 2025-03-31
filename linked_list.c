#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *nextptr;
} *head,*tail; // Declaring head and tail as global pointers


void create() 
{
    int num,i;
    struct node *newnode;
    int n;
    printf("Input number of nodes:\n");
    scanf("%d", &n);
    for ( i=1 ; i<=n ; i++ ) {
    newnode = (struct node*) malloc(sizeof(struct node)); 
    if (newnode == NULL) {
    printf("MEMORY ALLOCATION FAILED!\n");
    break;
    }
    else {
        printf("enter data for node %d:- ",i);
        scanf( "%d",&num );
        newnode->data = num;
        newnode->nextptr = NULL;
        if ( head == NULL ) {
        head = newnode;
        tail = head;}
        else {
        tail->nextptr = newnode;
        tail = newnode;}
    }}
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

void addbeg(struct node *newnode)
{
    newnode->nextptr = head;
    head = newnode;
}
    
struct node *create_onenode()
{
    printf("enter newnode details:-\n");
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    int val;
    printf("enter value of newnode to add:- ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->nextptr = NULL;
    return newnode;
}

void addend(struct node *newnode) 
{
    if (tail!=NULL) {
        tail->nextptr=newnode;
        tail=newnode;
    }
}

void addbefore(struct node *newnode) 
{
    int value;
    printf("enter data you want to add before a node:-");
    scanf("%d",&value);
    if (head->data == value) 
    {
      newnode->nextptr = head;
      head = newnode; 
    }
    else 
    {
    struct node *ptr;
    ptr = head;
    while (ptr->nextptr != NULL && ptr->nextptr->data != value)
    {
    ptr = ptr->nextptr;
    }
    newnode->nextptr = ptr->nextptr;
    ptr->nextptr = newnode;
    }
}

void addafter(struct node *newnode) 
{
    int value;
    printf("enter data after you want to add node:-");
    scanf("%d",&value);
    if (head->data == value) {
      newnode->nextptr = head->nextptr;
      head->nextptr = newnode; }
    else 
    {
    struct node *ptr;
    ptr = head;
    while (ptr->data != value)
    {
    ptr = ptr->nextptr;
    }
    newnode->nextptr = ptr->nextptr;
    ptr->nextptr = newnode;
    }
}
    
void delbeg()
{
    if ( head == NULL){
        printf("list is empty\n");
    }
    else if ( head == tail ){
        free (head);
        tail = NULL;
        head = NULL;
        printf("now list is empty\n");
    }
    else {
    struct node *ptr;
    ptr=head;
    head=head->nextptr;
    ptr->nextptr=NULL;
    free(ptr);
    printf("node is deleted\n");
    }
   
}

void delend()
{   
    if ( head == NULL)
    {
        printf("list is empty\n");
    }
    else if ( head == tail ){
        free (tail);
        head = NULL;
        tail = NULL;
        printf("now list is empty\n");
    }
    else {
    struct node *ptr;
    ptr = head;
    while (ptr->nextptr != NULL && ptr->nextptr->nextptr != NULL){
    ptr = ptr->nextptr;}
    free(tail);
    ptr->nextptr = NULL;
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

void del_list (){
    if ( head == NULL ) {
        printf("list is already empty\n");
    }
    else if ( head == tail ){
    free(head);
    head = NULL;
    tail = NULL;
    }
    else {
        while ( head != NULL )
        {
            struct node *ptr = head;
            head = head->nextptr;
            free(ptr);
        }
        printf("linked list is deleted\n");
    }
}

void sort() 
{
    if ( head == NULL) {
        printf("list is empty\n");
    }
    else if ( head == tail ) {
        printf("list is already sorted");
    }
    else {
        struct node *ptr = head , *ptr2;
        int temp;
        while ( ptr->nextptr != NULL ){
            ptr2 = ptr->nextptr;
            while ( ptr2 != NULL )
            {
            if ( ptr->data > ptr2->data ){
                temp = ptr->data;
                ptr->data = ptr2->data;
                ptr2->data = temp;}

                ptr2 = ptr2->nextptr;
            } 
        ptr = ptr->nextptr; 
        }
        }
        printf("list is sorted\n");
}

void reverse() {
    if ( head == NULL) {
        printf("list is empty\n");
    }
    struct  node *q = NULL, *r = q , *s = head , *p = s;
    while ( p != NULL )
    {
        r = q;
        q = p;
        p = p->nextptr;
        q->nextptr = r;
    }
    tail = head;
    head = q;
    printf("list is reversed\n");
}

void find_mid() {
    if ( head == NULL) {
        printf("list is empty\n");
    }
    struct node *slow = head , *fast = head;
    while ( fast != NULL && fast->nextptr != NULL )
    {
        slow = slow->nextptr;
        fast = fast->nextptr->nextptr;
    }
    printf("the middle element is %d \n",slow->data);
}


int main()
{
    int ch;
    while (1)
    {
    printf("***MAIN MENU***\n");
    printf("1. Create a list\n");
    printf("2. Display the list\n");
    printf("3. Add a node at the beginning\n");
    printf("4. Add a node at the end\n");
    printf("5. Add a node before a given node\n");
    printf("6. Add a node after a given node\n");
    printf("7. Delete a node at the beginning\n");
    printf("8. Delete a node at the end\n");
    printf("9. Delete a given node\n");
    printf("10. Delete a node after a given node\n");
    printf("11. Delete the entire list\n");
    printf("12. sort the list\n");
    printf("13. Reverse the list\n");
    printf("14. Finding middle element in list\n");
    printf("15. Exit\n");
    printf("enter your choice:- ");
    scanf("%d",&ch);
    switch (ch) {

        case 1:
        create();
        break;

        case 2:
        printf("list:- \n");
        display();
        break;

        case 3: {
        struct node *newnode = create_onenode();
        if (newnode != NULL) 
        {
        addbeg(newnode);
        }
        else {
        printf("memory is not allocated\n"); }
        }
        break;

        case 4: {
        struct node *newnode = create_onenode();
        if (newnode != NULL) 
        {
        addend(newnode);
        }
        else {
        printf("memory is not allocated\n"); 
        }
        }

        case 5: {
        struct node *newnode = create_onenode();
        if (newnode != NULL) 
        {
        addbefore(newnode);
        }
        else {
        printf("memory is not allocated\n"); 
        }
        }
        break;

        case 6: {
        struct node *newnode = create_onenode();
        if (newnode != NULL) 
        {
        addafter(newnode);
        }
        else {
        printf("memory is not allocated\n"); 
        }
        }
        break;

        case 7:
        delbeg();
        break;

        case 8:
        delend();
        break;

        case 9:
        delnode();
        break;

        case 10:
        del_afternode();
        break;

        case 11:
        del_list();
        break;

        case 12:
        sort();
        break;

        case 13:
        reverse();
        break;

        case 14:
        find_mid();
        break;

        case 15:
        printf("exiting program....");
        exit (0);

        default:
        printf("Invalid choice");
        break;
    }}
return 0;
}

