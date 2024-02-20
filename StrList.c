#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * StrList represents a StrList data structure.
 */

typedef struct _StrNode {
    char* _string;
    struct StrNode* _next;
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

    if(StrList == NULL){
        return;
    }

    StrNode* node = StrList->_root;

    //Iterate through the list until we find the last spot
    while(node->_next != NULL){
        node = node->_next;
    }

    node->_next = StrNode_alloc();
    if(node->_next == NULL){
        return; //Just in case..
    }
    node = node->_next;
    node->_string = data;

    StrList->_size++; 
}

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList, const char* data,int index);

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList);

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList);

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* Strlist,int index);

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* Strlist);

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data);

/*
	Given a string and a list, remove all the appearences of this string in the list.
*/

//use removeAt if the String matches. 
void StrList_remove(StrList* StrList, const char* data);

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index);

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
//Loop, if one string doesn't match the other at the same index return false.
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2);

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */

StrList* StrList_clone(const StrList* StrList);

/*
 * Reverces the given StrList. 
 */
void StrList_reverse( StrList* StrList);

/*
 * Sort the given list in lexicographical order 
 */
void StrList_sort( StrList* StrList);

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList);