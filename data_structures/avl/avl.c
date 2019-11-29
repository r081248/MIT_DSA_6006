#include<stdio.h>
#include<stdlib.h>

#include "avl.h"

int maxHeight(avl *left, avl *right)
{
    int left_height = (left == NULL ? -1 : left->height);
    int right_height = (right == NULL ? -1 : right->height);
    return (left_height>right_height ? left_height : right_height);
}

int balanceFactor(avl *left, avl *right)
{
    int left_height = (left == NULL ? -1 : left->height);
    int right_height = (right == NULL ? -1 : right->height);
    return left_height - right_height;
}

avl *newNode(int key)
{
    avl *node = (avl *)malloc(sizeof(avl));
    node->key = key;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(avl *root)
{
    if(root != NULL)
    {
        printf("{%d %d} ",root->key, root->height);
        preOrder(root->left);
        preOrder(root->right);
    }
}

avl *rightRotation(avl *z)
{
    avl *y = z->left;
    avl *T3 = y->right;

    y->right = z;
    z->left = T3;
    
    z->height = 1 + maxHeight(z->left, z->right);
    y->height = 1 + maxHeight(y->left, y->right);

    return y;
}

avl *leftRotation(avl *z)
{
    avl *y = z->right;
    avl *T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = 1 + maxHeight(z->left, z->right);
    y->height = 1 + maxHeight(y->left, y->right);

    return y;
    
}

avl *getMinKeyNode(avl *root)
{
    if(root->left == NULL)
    {
        return root;
    }
    else
    {
        return getMinKeyNode(root->left);
    }
    
}

avl *insertion(avl *root, int key)
{
    if(root == NULL)
    {
        return newNode(key);
    }
    else if(key < root->key)
    {
        root->left = insertion(root->left, key);
    }
    else if(key > root->key)
    {
        root->right = insertion(root->right, key);   
    }
    else
    {
        return root;
    }

    root->height = 1 + maxHeight(root->left, root->right);

    int balance = balanceFactor(root->left, root->right);

    if(balance>1 && key < root->left->key)
    {
        return rightRotation(root); 
    }
    else if(balance<-1 && key > root->right->key )
    {
        return leftRotation(root);
    }
    else if(balance>1 && key > root->left->key)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    else if(balance<-1 && key < root->right->key)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
    
}


#if 1
int main()
{
    avl *root = NULL;
    root = insertion(root, 10);
    preOrder(root);
    printf("\n");
    root = insertion(root, 20);
    preOrder(root);
    printf("\n");

    root = insertion(root, 30);
    preOrder(root);
    printf("\n");


    root = insertion(root, 40);
    preOrder(root);
    printf("\n");

    root = insertion(root, 50);
    preOrder(root);
    printf("\n");

    root = insertion(root, 25);
    preOrder(root);
    printf("\n");

    return 0;

}
#endif