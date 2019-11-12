#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void max_heapify(int *arr, int heap_size, int level)
{
    int left_sub_tree_level = 2 * level;
    int right_sub_tree_level = 2 * level + 1;

    int max_node_level = level;
    if(left_sub_tree_level <= heap_size && arr[level] < arr[left_sub_tree_level] )
    {
        max_node_level = left_sub_tree_level;        
    }
    if(right_sub_tree_level <= heap_size && arr[max_node_level] < arr[right_sub_tree_level])
    {
        max_node_level = right_sub_tree_level;
    }

    if(max_node_level != level)
    {
        swap(arr+max_node_level, arr+level);
        max_heapify(arr, heap_size, max_node_level);
    }
}

void build_max_heap(int *arr, int heap_size)
{
    for(int i=heap_size/2;i>=1; --i)
    {
        max_heapify(arr,heap_size,i);
    }
}

int main()
{
    int arr[11] = {0,4,1,3,2,16,9,10,14,8,7};
    build_max_heap(arr,10);
    for(int i=1;i<=10;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

}
