

Void insertion_sort (elementType list[], int n){
    int i, j;
    elementType next;
    for (i = 1; i < n; i++){
        next = list[i];
        for (j = i - 1; j >= 0 && next.key < list[j].key; j--)
            list[j+1] = list[j];
        list[j+1] = next;
    }
}

void selection_sort (elementType a[], int n){
    int i , j , min, tmp;
    for (i = 0; i < n -1; i++){
        min = i;
        for (j = i+1; j <= n-1; j++)
            if (a[j].key < a[min].key)
                min = j;
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

void bubble_sort(elementType a[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = n-1; j > i; j --)
            if (a[j] < a[j-1])
                swap(a[j], a[j-1]);
}

