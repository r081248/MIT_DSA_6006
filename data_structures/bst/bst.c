#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

bst *get_min_key_node(bst *root)
{
    if(root->left)
    {
        return get_min_key_node(root->left);
    }
    return root;
}
void inorder(bst *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

bst *new_node(int key)
{
    bst *node = (bst *)malloc(sizeof(bst));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bst *insert(bst *node, int key)
{
    if(node == NULL)
    {
        node = new_node(key);
    }
    else if(key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else if(key < node->key)
    {
        node->left = insert(node->left, key);
    }
    return node;
}

bst *search(bst *node, int key)
{
    if(node == NULL)
    {
        return NULL;
    }
    else if(key < node->key)
    {
        return search(node->left, key);
    }
    else if(key > node->key)
    {
        return search(node->right, key);
    }
    else
    {
        return node;
    }
    
}

bst *delete(bst *root, int key)
{
    if(!root)
    {
        return root;
    }
    else if(key > root->key)
    {
        root->right = delete(root->right, key);
    }
    else if(key < root->key)
    {
        root->left = delete(root->left, key);
    }
    else
    {
        if(root->left == NULL)
        {
            bst *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            bst *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            bst *temp = get_min_key_node(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
        
    }
    return root;
    
}
