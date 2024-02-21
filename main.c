#include <stdio.h>
#include "my_mat.h"
#include "my_mat.c"

#define SIZE 10


int main(){

    int currentNumber;

    while (TRUE){
        scanf(" %d", &currentNumber);
 
        switch (currentNumber){
            case 1:
            //Append a string to the end of the LinkedList.
                break;
            case 2:
            //Input: Index and then a String. Add the String at the specific Index.
                break;
            case 3:
            //Iterate Upon LinkedList and print each of the indices.
                break;
            case 4:
            //Print LinkedList's Length
                break;
            case 5:
            //Print a String at a specific index.
                break;
            case 6:
            //Return the collective character amount of every String in the LinkedList.
                break;
            case 7:
            //Input: String. Output: How many times does this String Appear
                break;
            case 8:
            //Input: String, remove indices that contain this string.
                break;
            case 9:
            //Remove a string at a given index.
                break;
            case 10:
            //Reverse the entire LinkedList
                break;
            case 11:
            //Delete the entire LinkedList
                break;
            case 12:
            //Sort the LinkedList lexicographically 
                break;
            case 13:
            //Test if the LinkedList is sorted Lexicographically.
                break;
            case 0;
            //Bye bye
                return 0;
            default:
                break;
        }
    }
}