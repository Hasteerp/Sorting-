// Selection Sorting 2021
#include <stdio.h>


// Print Array
void printArray(int list[], int listLength) {
  for (int i = 0; i < listLength; i++) 
    printf("%d ", list[i]);
  printf("\n");
}


// Selection Sort
// First loop: start from top and moves down
void selectionSort(int list[], int listLength) {

  for (int top = listLength - 1; top > 0; top--) {
    // find largest from 0 to top
    int indexOfLargest = 0;
    
    // inner loop below finds the index of largest element
    for (int i = 1; i <= top; i++)
      if (list[i] > list[indexOfLargest])
        indexOfLargest = i;

    // put largest at top
    int temp = list[top];         // a placeholder
    list[top] = list[indexOfLargest];
    list[indexOfLargest] = temp;

      // debug
     puts("--- Selection Sort DEBUG ---");
     puts("--- Move the larget element to the END! ---");
     printArray(list, listLength);  
     puts("---  ---");  
  }
}

// MAIN

int main(void) {

  int list[] = {3, 1, 7, 4, 15, 5};
  int size = (int)( sizeof(list)/sizeof(list[0]) );

  puts("--- Original List ---");
  printArray(list, size);


  selectionSort(list, size);
  puts("--- Selection Sort ---");
  printArray(list, size);

}
