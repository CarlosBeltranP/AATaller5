// 24.

//VERIFICA SI CADA NODO TIENE SOLAMENTE UN HIJO  OJOOOOO!!! esta en C 

/*Since all the descendants of a node must either be larger or smaller than the node. We can do following for every node in a loop.
1. Find the next preorder successor (or descendant) of the node.
2. Find the last preorder successor (last element in pre[]) of the node.
3. If both successors are less than the current node, or both successors are greater than the current node, then continue. Else, return false.*/

#include <stdio.h> 
  
bool hasOnlyOneChild(int pre[], int size) 
{ 
    int nextDiff, lastDiff; 
  
    for (int i=0; i<size-1; i++) 
    { 
        nextDiff = pre[i] - pre[i+1]; 
        lastDiff = pre[i] - pre[size-1]; 
        if (nextDiff*lastDiff < 0) 
            return false;; 
    } 
    return true; 
} 
  
// driver program to test above function 
int main() 
{ 
    int pre[] = {8, 3, 5, 7, 6}; 
    int size = sizeof(pre)/sizeof(pre[0]); 
    if (hasOnlyOneChild(pre, size) == true ) 
        printf("Yes"); 
    else
        printf("No"); 
    return 0; 
} 

/*

1. Scan the last two nodes of preorder & mark them as min & max.
2. Scan every node down the preorder array. Each node must be either smaller than the min node or larger than the max node. Update min & max accordingly.

#include <stdio.h> 
  
int hasOnlyOneChild(int pre[], int size) 
{ 
    // Initialize min and max using last two elements 
    int min, max; 
    if (pre[size-1] > pre[size-2]) 
    { 
        max = pre[size-1]; 
        min = pre[size-2]): 
    else
    { 
        max = pre[size-2]; 
        min = pre[size-1]; 
    } 
  
  
    // Every element must be either smaller than min or 
    // greater than max 
    for (int i=size-3; i>=0; i--) 
    { 
        if (pre[i] < min) 
            min = pre[i]; 
        else if (pre[i] > max) 
            max = pre[i]; 
        else
            return false; 
    } 
    return true; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int pre[] = {8, 3, 5, 7, 6}; 
    int size = sizeof(pre)/sizeof(pre[0]); 
    if (hasOnlyOneChild(pre,size)) 
        printf("Yes"); 
    else
        printf("No"); 
    return 0; 
} */
