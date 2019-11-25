#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

bst *get_min_key_node(bst *root)//Gets the minimum key in the subtree and returns its node address
{
    if(root->left)
    {
        return get_min_key_node(root->left);
    }
    return root;
}
void inorder(bst *root)//Inorder traversal(left node, parent, right node)
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

bst *insert(bst *node, int key)//Insert the node and returns its address
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

bst *search(bst *node, int key) // returns root adress if key matches and null if key is not found
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

bst *delete(bst *root, int key)//performs delete operation and returns root address(which will be modified in some cases)
{
    if(!root)//if tree is nill
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
        if(root->left == NULL) // Left node absent or both nodes absent
        {
            bst *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) //Right node absent or both nodes absent
        {
            bst *temp = root->left;
            free(root);
            return temp;
        }
        else// When 2 nodes are present
        {
            bst *temp = get_min_key_node(root->right);
            root->key = temp->key;//copying the contents of least minimum key from the right subtree
            root->right = delete(root->right, temp->key);//Deleting the lest minimum key from the right subtree
        }
        
    }
    return root;
    
}
