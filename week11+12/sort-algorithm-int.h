#include <stdio.h>
#include <stdbool.h>
typedef int ElementType;

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = *a;
}

int partition(ElementType A[], int L, int R, int indexPivot){
    ElementType pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    int storeIndex = L;
    int i;
    for (i = L; i <= R-1; i++){
        if (A[i] < pivot){
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quickSort(ElementType A[], int L, int R){
    if(L < R){
        int index = (L+R)/2;
        index = partition(A, L, R, index);
        if (L < index)
            quickSort(A, L, index-1);
        if (index < R)
            quickSort(A, index+1, R);
    }
}

void insertionSort(ElementType List[], int size){
    int i, j;
    ElementType next;
    for (i = 1; i < size; i++){
        next = List[i];
        for (j = i-1; j >= 0 && next < List[j]; j--)
            List[j+1] = List[j];
        List[j+1] = next;
    }
}

void selectionSort(ElementType List[], int size){
    int i, j, min;
    for (i = 0; i < size; i++){
        min = i;
        for (j = i+1; j < size; j++)
            if (List[j] < List[min]) 
                min = j;
        swap(&List[i], &List[min]);
    }
}

void bubbleSort(ElementType List[], int size){
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size-i-1; j++)
            if (List[j] > List[j+1])
                swap(&List[j], &List[j+1]);
}

//An optimized version of Bubble Sort
void opbubbleSort(ElementType List[], int size){
    int i, j;
    bool swapped;
    for (i = 0; i < size-1; i++)
    {
        swapped = false;
        for (j = 0; j < size - i - 1; j++)
        {
            if (List[j] > List[j+1])
            {
                swap(&List[j], &List[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//mergeSort
void merge(ElementType List[], int L, int M, int R){
    int i,j,k;
    int n1 = M - L + 1;
    int n2 = R - M;

    /* create temp arrays */
    ElementType Left[n1], Right[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        Left[i] = List[L + i];
    for (j = 0; j < n2; j++)
        Right[j] = List[M + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = L;
    while (i < n1 && j < n2){
        if (Left[i] <= Right[j]){
            List[k] = Left[i];
            i++;
        }
        else {
            List[k] = Right[j];
            j++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1){
        List[k] = Left[i];
        i++;
        k++;
    }

    while(j < n2){
        List[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(ElementType List[], int L, int R){
    if (L < R){
        int M = L + (R - L) / 2;
        mergeSort(List, L, M);
        mergeSort(List,M+1,R);
        merge(List,L,M,R);
    }
}

void printArray(ElementType List[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("̀%d ", List[i]);
    }
    printf("\n");
}