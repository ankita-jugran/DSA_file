#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
} *tree ,*newnode;

struct node* create_tree() {
    int value;
    printf("enter data for node:- ");
    scanf("%d",&value);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int main()
{
    printf("creating tree: \n");
    create_tree();
    printf("root node is created\n");
    int choice;
    printf("enter choice where you want to add element:-");
    printf("1. LEFT");
    printf("2. RIGHT");
    scanf("%d",&choice);
    if (choice = 1) {
        if (newnode->left == NULL)
        {
            newnode->left = create_tree();
        }
        else {
            printf("leftnode is not null\n");
        }}
    else if ( choice = 2) {
        if ( newnode->right == NULL){
            newnode->left = create_tree();
        }
        else {
            printf("rightnode is null\n");
        }
    }
        
return 0;
}