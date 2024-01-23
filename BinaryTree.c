
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorderTraversal(struct node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
void preorderTraversal(struct node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(struct node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
int main() {
    int data, n, i;
    struct node *root, *temp;

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);
    printf("Enter the values for the binary tree:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        if (i == 0) {
            root = createNode(data);
        } else {
            temp = root;
            while (temp != NULL) {
                if (data < temp->data) {
                    if (temp->left == NULL) {
                        temp->left = createNode(data);
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == NULL) {
                        temp->right = createNode(data);
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");
    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");
    return 0;
}