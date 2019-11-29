typedef struct AVL
{
    int key;
    struct AVL *left;
    struct AVL *right;
    int height;
}avl;

int maxHeight(avl *left, avl *right);
int balanceFactor(avl *left, avl *right);
avl *newNode(int key);
void preOrder(avl *root);
avl *rightRotation(avl *z);
avl *leftRotation(avl *z);
avl *insertion(avl *root, int key);
avl *getMinKeyNode(avl *root);
avl *deletion(int key);