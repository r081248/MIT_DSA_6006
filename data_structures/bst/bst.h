#include<stdio.h>

typedef struct BST{
int key;
struct BST *left,*right;
}bst;


bst *new_node(int key);
bst *search(bst *root, int key);
bst *insert(bst *root, int key);
bst *delete(bst *root, int key);
bst *get_min_key_node(bst *root);
void inorder(bst *root);