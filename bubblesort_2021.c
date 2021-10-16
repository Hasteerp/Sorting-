// Bubble sort 2021
#include <stdio.h>
#include <stdbool.h>

// Print Array
void printArray(int list[], int listLength) {
  for (int i = 0; i < listLength; i++) 
    printf("%d ", list[i]);
  printf("\n");
}

// Bubble Sort V0
void bubbleSortV0(int list[], int listLength) {
    int top, i, temp;

    for (top = listLength - 1; top > 0 ; top--) {

      for (i = 0; i < top; i++)
        if (list[i] > list[i+1]) {
          temp = list[i];
          list[i] = list[i+1];
          list[i+1] = temp;

        }
    }
}


// Bubble Sort
void bubbleSort(int list[], int listLength) {
    int top, i, temp;
    bool sorted = false; 

    for (top = listLength - 1; top > 0 && !sorted; top--) {
      sorted = true; 
      for (i = 0; i < top; i++)
        if (list[i] > list[i+1]) {
          temp = list[i];
          list[i] = list[i+1];
          list[i+1] = temp;
          sorted = false; 
        }
          // debug
     puts("--- Bubble Sort DEBUG ---");
     printArray(list, listLength);  
     puts("---  ---");  
    }
}


int main(void) {
 // int list[] = {6, 3, 5, 8, 2};
  int list[] = {7, 2, 5, 1};
  int size = (int)( sizeof(list)/sizeof(list[0]) );

  puts("--- Org. Array ---");  
  printArray(list, size);

  bubbleSort(list, size);
  puts("--- Sorted Array ---");  
  printArray(list, size);
}

