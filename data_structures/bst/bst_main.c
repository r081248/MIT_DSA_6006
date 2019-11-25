#include<stdio.h>
#include"bst.h"

int main()
{
    bst *root = NULL;
    char c;
    int key;
    do
    {
        printf("[i]: press i for insertion operation\n");
        printf("[d]: press d for deletion operation\n");
        printf("[p]: press p to print the tree in inorder traversal\n");
        printf("[e]: press e to exit the application\n");

        scanf(" %c",&c);
        switch (c)
        {
        case 'i':
            printf("Enter key to insert into the tree\n");
            scanf(" %d", &key);
            if(!root)
                root = insert(root, key);
            else
            {
                insert(root,key);
            }
            
            break;
        case 'd':
            printf("Enter key to delete from the tree");
            scanf(" %d", &key);
            root = delete(root,key);
            break;
        
        case 'p':
            inorder(root);
            printf("\n");
            break;
        case 'e':
            printf("Exiting the application\n");
            return 0;

        default:
            printf("Invalid option\n");
            break;
        }
        printf("Continue the process [Y/n]\n");
        scanf(" %c",&c);

    } while (c == 'Y' || c == 'y');
    
}