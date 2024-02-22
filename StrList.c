#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * StrList represents a StrList data structure.
 */

typedef struct _StrNode {
    char* _string;
    struct _StrNode* _next;
} StrNode;

typedef struct _StrList {
    StrNode* _root;
    size_t _size;
} StrList;

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */

StrNode* StrNode_alloc(){

    //Allocate a node
    StrNode* node = (StrNode*)malloc(sizeof(StrNode));
    if(node == NULL){
        exit(1);
    }
    //Initialize to avoid unexpected errors.
    node->_next = NULL;
    node->_string = '\0'; //null string.

    return node;
}

StrList* StrList_alloc(){
    //Allocate a LinkedList

    StrList* linkedList = (StrList*)malloc(sizeof(StrList));
    if(linkedList == NULL){
        exit(1);
    }

    //Initialize to avoid unexpected errors.
    linkedList->_root = NULL;
    linkedList->_size = 0;

    return linkedList;
};

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */


void StrNode_free(StrNode* node){
    free(node->_string);
    free(node);
}

void StrList_free(StrList* root) {
    if(root == NULL){
        return;
    }

    StrNode* node = root->_root;
    StrNode* next;

    while(node){

        //Point to the next node so we don't lose it
        next = node->_next;
        //Free the current node's memory.
        free(node->_string);
        free(node);
        
        //Move onto the next node.
        node = next;
    }

    // free(root->_size); # Not dynamically allocated, therefore we don't need to free it.
    // free(root->_root); # Empty pointer that we already free in the code above. No need to free it twice!
    free(root); //This is enough to free the list.
};

/*
 * Returns the number of elements in the StrList.
 */

//We use "const" to indicate that the argument is "read-only" and that specific arugment will NOT be modified by this method.
size_t StrList_size(const StrList* StrList){
    return StrList->_size;
}

/*
 * Inserts an element in the end of the StrList.
 */

// Dangerous code, IDK if it's gonna work.
void StrList_insertLast(StrList* StrList, const char* data){

    if(StrList == NULL || data == NULL){
        return;
    }

    StrNode* node = StrList->_root;

    //Iterate through the list until we find the last spot
    while(node->_next != NULL){
        node = node->_next;
    }

    node->_next = StrNode_alloc();

    node = node->_next;
    node->_string = data;

    (StrList->_size)++; 
}

/*
* Inserts an element at given index
*/

// Test this ..
void StrList_insertAt(StrList* StrList, const char* data,int index){

    StrNode* node = StrList->_root;

    if(node == NULL || StrList->_size < sizeof(index)){
        return;
    } 

    //Allocate the new node
    StrNode* newNode = StrNode_alloc();
    newNode->_string = data;


    if(index == 0){
        newNode->_next = StrList->_root;
        StrList->_root = newNode;
    } else {

        for(int i = 0; i < index - 1; i++){
            node = node->_next;
        }

        newNode->_next = node->_next;
        node->_next = newNode;

    }

    (StrList->_size)++;

}

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList){
    return StrList->_root->_string;
}

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList){
    if(StrList == NULL){
        return;
    }
    StrNode* node = StrList->_root;
    while(node){
        printf("%s ",node->_string);
        node = node->_next;
    }
    printf("\n");
}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* list,int index){
    StrNode* node = list->_root;

    if(list->_size < sizeof(index)){
        return;
    } 

    if(index == 0){
        printf("%s \n",node->_string);
    } else {
        for(int i = 0; i < index - 1; i++){
            node = node->_next;
        }
        printf("%s \n",node->_string);
    }
}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* list){
    int sum = 0;
    StrNode* node = list->_root;
    while(node){
        sum += (int)strlen(node->_string);
        node = node->_next;
    }
    return sum;
}

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data){
    int result = 0;
    StrNode* node = StrList->_root;

    while(node){
        if(strcmp(node->_string,data) == 0){
            result++;
        }
        node = node->_next;
    }
    
    return result;
}

/*
	Given a string and a list, remove all the appearences of this string in the list.
*/

//use removeAt if the String matches. decrease size
void StrList_remove(StrList* list, const char* data){

    if(list == NULL){
        return; //List is empty or index out of bounds.
    }    

    StrNode* node = list->_root; //Index 0.
    StrNode* prevNode = NULL;
    
    while(node){

        if(strcmp(node->_string,data) == 0){
            if(prevNode){
                prevNode->_next = node->_next; //Connect the i-1'th index to the i+1'th index.
            } else{
                list->_root = node->_next; //Connect to the root.
            }

            StrNode_free(node);
            (list->_size)--;

            if(prevNode){
                node = prevNode->_next;
            }else{
                node = list->_root; //We deleted the first, therefore we connect to the root
            }
        }else{
          //Move onto the next node.
          prevNode = node;
          node = node->_next;  
        }
    }

}

/*
	Given an index and a list, remove the string at that index.
*/
// decrease size
void StrList_removeAt(StrList* list, int index){

    StrNode* node = list->_root; //Index 0.

    if(node == NULL || list->_size < sizeof(index)){
        return; //List is empty or index out of bounds.
    }    

    if(index == 0){
        list->_root = node->_next;
    } else {
        StrNode* prevNode = NULL;
        for(int i = 0; i < index - 1; i++){
            prevNode = node;
            node = node->_next;
        }
        prevNode->_next = node->_next; //Connect the i-1'th index to the i+1'th index.
    }

    StrNode_free(node);

    (list->_size)--;

}
/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */

//Loop, if one string doesn't match the other at the same index return false.
int StrList_isEqual(const StrList* list1, const StrList* list2){
  if(list1 == NULL || list2 == NULL || list2->_size != list1->_size){
        return 0; //List is empty or index out of bounds.
    }    

    StrNode* node1 = list1->_root; //Index 0.
    StrNode* node2 = list2->_root; //Index 0.

    while(node1 && node2){
        if(strcmp(node1->_string,node2->_string) == 0){
            node1 = node1->_next;
            node2 = node2->_next;
        }else{
            return 0;
        }
      
    }
    return 1;
}

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */

StrList* StrList_clone(const StrList* list){
    if(list == NULL){
        return NULL;
    }

    StrList* clone = StrList_alloc();
    clone->_root = StrNode_alloc();

    clone->_root->_string = strdup(list->_root->_string); //copy


    //Iterables
    StrNode* node = list->_root->next;
    StrNode* prevCloneNode = clone->_root;

    while(node){
        StrNode* newNode = StrNode_alloc();
        newNode->_string = strdup(node->_string);
        prevCloneNode->_next = newNode;

        prevCloneNode = prevCloneNode->_next;
        node = node->_next; //Move onto the next node;
    }

    clone->_size = list->_size;

    return clone;
}

/*
 * Reverces the given StrList. 
 */
void StrList_reverse(StrList* list){

    if (list == NULL){
        return;
    }

    StrNode* node = list->_root;
    StrNode* prevNode = NULL;
    StrNode* nextNode = NULL;

    while (prevNode) {
        nextNode = node->_next; //Move the nextNode pointer forward.
        node->_next = prevNode; //Change the pointer direction.
        prevNode = node; //Move the prevNode pointer forward.
        node = nextNode; //Move the node pointer forward.
    }

    //Finally, connect StrList to the new root.
    list->_root = prevNode;
}

/*
 * Sort the given list in lexicographical order 
 */

//In this approach, we will use bubble sort and change the strings between the nodes themselves, not the pointers.

void StrList_sort( StrList* list){
    if(list == NULL){
        return;
    }

    int n = (int)list->_size;

    //Pointers we need
    StrNode* nextNode;
    StrNode* currNode;

    for (int i = 0; i < n - 1; i++) {

        //Bring the pointers back
        currNode = list->_root;
        nextNode = currNode->_next;

        for (int j = 0; j < n - i - 1; j++) {

            if(strcmp(currNode->_string, nextNode->_string) > 0){
                //Swap
                char* temp = nextNode->_string;
                nextNode->_string = currNode->_string;
                currNode->_string = temp;
            }

            //Move the pointers forward
            currNode = currNode->_next; 
            nextNode = nextNode->_next; 
        }
    }
}

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* list){

    if(list == NULL){
        return 1;
    }

    //Pointers we need
    StrNode* currNode = list->_root;
    StrNode* nextNode = list->_next;

    while(currNode){
        if(strcmp(currNode->_string, nextNode->_string) > 0){
            return 0;
        }
        //Move the pointers forward
        currNode = currNode->_next; 
        nextNode = nextNode->_next; 
    }
    return 1;
}