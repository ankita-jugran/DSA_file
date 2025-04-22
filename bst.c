#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}


struct node *insertnode(struct node *tree, int val) {
    struct node *ptr, *nodeptr, *parentptr;
    ptr = createnode(val);

    if (tree == NULL)
        return ptr;

    parentptr = NULL;
    nodeptr = tree;

    while (nodeptr != NULL) {
        parentptr = nodeptr;
        if (val < nodeptr->data)
            nodeptr = nodeptr->left;
        else
            nodeptr = nodeptr->right;
    }

    if (val < parentptr->data)
        parentptr->left = ptr;
    else
        parentptr->right = ptr;

    return tree;
}

struct node* search(struct node* tree, int val) {
    if (tree == NULL || tree->data == val)
        return tree;
    if (val < tree->data)
        return search(tree->left, val);
    else
        return search(tree->right, val);
}


struct node* smallest(struct node* tree) {
    if (tree == NULL || tree->left == NULL)
        return tree;
    return smallest(tree->left);
}


struct node* del_node(struct node* root, int val) {
    if (root == NULL)
        return NULL; 

    if (val < root->data)
        root->left = del_node(root->left, val);
    else if (val > root->data)
        root->right = del_node(root->right, val);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct node* temp = smallest(root->right);
            root->data = temp->data;
            root->right = del_node(root->right, temp->data);
        }
    }
    return root;
}


struct node* mirror_image(struct node* tree) {
    if (tree != NULL) {
        struct node* temp = tree->left;
        tree->left = mirror_image(tree->right);
        tree->right = mirror_image(temp);
    }
    return tree;
}


int totalnodes(struct node* tree) {
    if (tree == NULL)
        return 0;
    return totalnodes(tree->left) + totalnodes(tree->right) + 1;
}


int external_nodes(struct node* tree) {
    if (tree == NULL)
        return 0;
    if (tree->left == NULL && tree->right == NULL)
        return 1;
    return external_nodes(tree->left) + external_nodes(tree->right);
}


int internal_nodes(struct node* tree) {
    if (tree == NULL || (tree->left == NULL && tree->right == NULL))
        return 0;
    return internal_nodes(tree->left) + internal_nodes(tree->right) + 1;
}

int height(struct node* tree) {
    if (tree == NULL)
        return 0;
    int left = height(tree->left);
    int right = height(tree->right);
    return (left > right ? left : right) + 1;
}


void inorder(struct node* tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

void preorder(struct node* tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(struct node* tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->data);
    }
}

void del_tree(struct node* tree) {
    if (tree != NULL) {
        del_tree(tree->left);
        del_tree(tree->right);
        free(tree);
    }
}


int main() {
    struct node* root = NULL;
    int val, choice;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Delete Element\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Total Nodes\n");
        printf("8. Leaf Nodes\n");
        printf("9. Internal Nodes\n");
        printf("10. Height of Tree\n");
        printf("11. Mirror Image\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insertnode(root, val);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("Value %d found in BST.\n", val);
                else
                    printf("Value %d not found.\n", val);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = del_node(root, val);
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Total nodes = %d\n", totalnodes(root));
                break;

            case 8:
                printf("Leaf nodes = %d\n", external_nodes(root));
                break;

            case 9:
                printf("Internal nodes = %d\n", internal_nodes(root));
                break;

            case 10:
                printf("Height = %d\n", height(root));
                break;

            case 11:
                root = mirror_image(root);
                printf("Mirror image created.\n");
                break;

            case 12:
                del_tree(root);
                printf("Tree deleted. Exiting.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
