#include<stdio.h>
# define max 5
int front = -1 , rear = -1;

void insert(int q[]) {
int num;
printf("enter the no. to be inserted:- \n");
scanf("%d",&num);
if ( rear == max -1 ) {
    printf("overflow \n");
}
else if ( front == -1 && rear == -1){
    front = rear = 0;
    q[rear] = num;
    printf("%d is inserted in queue\n",num);  
    }
else {
    rear++;
    q[rear] = num;
    printf("%d is inserted in queue\n",num); 
}
}

void del( int queue[] ) {
    int val;
    if ( front == -1 || rear == -1) {
        printf("underflow\n");
    }
    else if ( front == rear ){
        val = queue[front];
        front = rear = -1;
        printf("%d is deleted from queue\n",val);
    }
    else {
        val = queue[front];
        front++;
        printf("%d is deleted from queue\n",val);
    }
}

void display( int queue[] ) {
    int i;
    if ( front < rear ){
        for ( i=front ; i<=rear ; i++ ) {
            printf("%d\t ",queue[i]);
        }
        printf("\n");
    }
}
int main() {
    int queue[max];
    int ch;
    printf("enter 1 to insert an element\n");
    printf("enter 2 to delete an element\n");
    printf("enter 3 to display\n");
    printf("enterr 4 to stop\n");
    while (1){
        printf("enter choice:- ");
        scanf("%d",&ch);
    if (ch == 1) {
    insert(queue);
    }
    else if (ch == 2) {
    del(queue);
    }
    else if (ch == 3){
        display(queue);
    }
    else if (ch == 4){
        break;
    }
    else {
        printf("invalid choice\n");
    }

}
    return 0;
}