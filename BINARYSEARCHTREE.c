#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }
    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
void inOrder(struct node *temp)
{
    if (temp == NULL)
        return;
    inOrder(temp->left);
    printf("%d ", temp->data);
    inOrder(temp->right);
}
int main()
{
    struct node *root = NULL;
    int choice, data;
    while (1)
    {
        printf("\n1. Insert\n2. In-order traversal\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("In-order traversal: ");
            inOrder(root);
            printf("\n");
            break;
        case 3:
        printf("Exit SuccessFully");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}