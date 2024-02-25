#include <stdio.h>
#include "StrList.h"
// #include "StrList.c"


int main(){

    int currentNumber;

    StrList* list;

    while (TRUE){
        scanf(" %d", &currentNumber);

        char string_input[50]; //"pneumonoultramicroscopicsilicovolcanoconiosis" is the longest word in the english dictionary and is of length 45. I'll round it up to 50 for good measure.
        int index;

        switch (currentNumber){
            case 1:
                //Append a string to the end of the LinkedList.

                int words;
                list = StrList_alloc();

                scanf(" %d", &words);

                for (int i = 0; i < words; i++) {
                    scanf("%s", string_input);
                    StrList_insertLast(list,string_input); //Yes, I should've created a pointer to the end of the list but it's too late now.
                }
                break;
            case 2:
            //Input: Index and then a String. Add the String at the specific Index.

                scanf("%d",&index);
                scanf("%s",string_input);

                StrList_insertAt(list,string_input,index);
                break;
            case 3:
                //Iterate Upon LinkedList and print each of the indices.
                StrList_print(list);
                break;
            case 4:
                //print LinkedList's Length
                printf("%d \n",(int)(StrList_size(list)));
                break;
            case 5:
                //Print a String at a specific index.

                scanf("%d",&index);

                StrList_printAt(list,index);
                break;
            case 6:
                //Return the collective character amount of every String in the LinkedList.
                printf("%d \n",StrList_printLen(list));
                break;
            case 7:
                //Input: String. Output: How many times does this String Appear
                scanf("%s",string_input);
                printf("%d \n",StrList_count(list,string_input));
                break;
            case 8:
                //Input: String, remove indices that contain this string.
                scanf("%s",string_input);
                StrList_remove(list,string_input);
                break;
            case 9:
                //Remove a string at a given index.
                scanf("%d",&index);
                StrList_removeAt(list,index);
                break;
            case 10:
                //Reverse the entire LinkedList
                StrList_reverse(list);
                break;
            case 11:
                //Delete the entire LinkedList
                StrList_free(list);
                list = NULL; //We pointed to a list we freed. This created an error.
                break;
            case 12:
                //Sort the LinkedList lexicographically 
                StrList_sort(list);
                break;
            case 13:
                //Test if the LinkedList is sorted Lexicographically.
                StrList_isSorted(list);
                break;
            case 0:
                printf("\n");
                //Bye bye
                return 0;
            default:
                return 0;
        }
    }
}