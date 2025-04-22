#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
} *tree;

struct node* create_tree() {
    int value;
    printf("Enter data for node: ");
    scanf("%d", &value);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void inorderTraversal(struct node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node* search(struct node* root, int val) {
    if (root == NULL) return NULL;
    if (root->data == val) return root;

    struct node* leftResult = search(root->left, val);
    if (leftResult) return leftResult;

    return search(root->right, val);
}

int main() {
    printf("Creating tree:\n");
    tree = create_tree();
    printf("Root node is created\n");

    while (1) {
    int choice;
    printf("Enter where you want to add a new node:\n");
    printf("1. LEFT\n");
    printf("2. RIGHT\n");
    printf("3. EXIT\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (tree->left == NULL) 
        {
            tree->left = create_tree();
        } 
        else {
            printf("Left node already exists.\n");
        }
    } 
    else if (choice == 2) {
        if (tree->right == NULL) 
        {
            tree->right = create_tree();
        } 
        else {
            printf("Right node already exists.\n");
        }
    } 
    else if (choice == 3) {
        printf("exiting.....\n");
        break;
    }
    else {
        printf("Invalid choice.\n");
    }
}   int ch;
    while (1) {
    printf("1. INORDER TRAVERSAL\n");
    printf("2. POSTORDER TRAVERSAL\n");
    printf("3. PREORDER TRAVERSAL\n");
    printf("4. SEARCH NODE\n");
    printf("5. EXIT\n");
    printf("enter choice:- ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("\nInorder traversal of the tree:\n");
        inorderTraversal(tree);
        printf("\n");
        break;

    case 2:
        printf("\nPostorder traversal:\n");
        postorder(tree);
        printf("\n");
        break;

    case 3:
        printf("\nPreorder traversal:\n");
        preorder(tree);
        printf("\n");
        break;

    case 4:
    {
        int key;
        printf("Enter value to search in tree: ");
        scanf("%d", &key);

        struct node* result = search(tree, key);
        if (result != NULL) {
           printf("Node with value %d found!\n", key);
        } else {
          printf("Node with value %d not found in the tree.\n", key);
         }
        }
        break;

    case 5:
    exit;
    
    default:
        break;
    }
}
    return 0;
}
