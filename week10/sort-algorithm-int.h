#include <stdio.h>

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
    for (i = 0; i < size-1; i++){
        min = i;
        for (j = i+1; j < size-1; j++)
            if (List[j] < List[min]) min = j;
        swap(&List[i], &List[min]);
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
