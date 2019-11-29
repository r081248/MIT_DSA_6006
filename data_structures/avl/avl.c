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

/*
             z
            /\          Right Rotation
           y T4        ==============>                   y           
          /\                                          /    \  
         x T3                                        x      z 
        /\                                          / \    / \        
       T1 T2                                       T1 T2 T3  T4
*/
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
    if(root == NULL) // Insertion 
    {
        return newNode(key); // create new node with key
    }
    else if(key < root->key) // Traverse left
    {
        root->left = insertion(root->left, key);
    }
    else if(key > root->key) // Traverse right
    {
        root->right = insertion(root->right, key);   
    }
    else
    {
        return root;
    }

    root->height = 1 + maxHeight(root->left, root->right); // Update the height of the ancestor below which insertion is done

    int balance = balanceFactor(root->left, root->right); // Check if AVL balance factor is violated

    if(balance>1 && key < root->left->key) // Left sub tree is heavy and left-left insertion scenario
    {
        return rightRotation(root); // Perform right rotation
    }
    else if(balance<-1 && key > root->right->key ) // Right sub tree is heavy and right-right insertion scenario
    {
        return leftRotation(root); // Perform left Rotation
    }
    else if(balance>1 && key > root->left->key) // Left Sub tree is heavy and left-right insertion scenario
    {
        root->left = leftRotation(root->left); // Left Rotation
        return rightRotation(root); //Right rotation
    }
    else if(balance<-1 && key < root->right->key) // Right Sub tree is heavy and right-left insertion scenario
    {
        root->right = rightRotation(root->right); //Right rotation
        return leftRotation(root); // Left Rotation
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