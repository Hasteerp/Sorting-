
// QuickSort_V1.c
#include <stdio.h>


//print ARRAY
/* Function to print an array */
void printArray(int arrA[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arrA[i]);
    printf("\n");
}

//
void quickSortHelper(int list[], int low, int high)
  {
    if (low < high)             // Base case ... checking the range
    {
        int left = low;         // copy org, index as we need to travese the array           
        int right = high;
        int pivot = list[low];  // pick a index 0 content as the pivot 

        // debug:
        // printf("PIVIT  %d\n",pivot);
        // puts("-------");
      
        // PARTITION PHASE
        // Goal: to place the pivot in its right place 
        //      ie. all larger than P on the right, all less than P on the left
        // Outter while loop runs till lower and higher indices are equal.


        while (left < right){  

            // check the right of pivot side for items < pivot     
            while (list[right] >= pivot && left < right)
                right--;
            // At this point we either found an item on the wrong side or left = right 
            //   put the right on the current left
            list[left] = list[right];
        
            // check the left of pivot side for items > pivot
            while (list[left] <= pivot && left < right)
                left++;
            // At this point we either found an item on the wrong side or left = right 
            //  put the left on the current right
            list[right] = list[left];

        }
        list[left] = pivot;   // Here marker left = marker right so we can say list[right] = pivot
        // HERE partitioning for each recursive run ends. Pivot is at the right place
        // NOTE at this point left and right are pointing at the same location (index)
  
        // Recursive SORT PHASE
        quickSortHelper(list,low,left-1);
        quickSortHelper(list,right+1,high);

      }
      // COLLECT PHASE
      return;
}

// --
void quickSort(int list[], int listLength)
    {
      quickSortHelper(list, 0, listLength-1 );
    }



//-----------------------------

int main()
{

  
    int arrA[] = {61, 46, 12, 63, 52, 91, 27, 55, 74, 14, 71, 37, 87};

    int n = sizeof(arrA)/sizeof(arrA[0]);


    printf("Org array A: \n");
    printArray(arrA, n);
   
    quickSort(arrA, n);
    
    printf("Sorted array A: \n");
    printArray(arrA, n);

  
    return 0;
}
