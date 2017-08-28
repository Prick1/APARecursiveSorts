#include<stdio.h>


void Merge(int ar[],int low, int mid, int high){
    int left,right,i;
    int aux[high+1];

    for(left = low, right = mid + 1, i = low; left <= mid && right <= high; i++){
        if(ar[left] <= ar[right])
            aux[i] = ar[left++];
        else
            aux[i] = ar[right++];
    }

    while(left <= mid)
        aux[i++] = ar[left++];

    while(right <= mid)
        aux[i++] = ar[right++];

    for(i = low; i <= high; i++)
        ar[i] = aux[i];
    
}

void MergeSort(int ar[], int low, int high){


    if(low < high){
        int mid;
        mid = (low + high) / 2;
        MergeSort(ar, low, mid);
        MergeSort(ar, mid + 1, high);
        Merge(ar, low, mid, high);
    }
    else
        return;
}

int Partition(int ar[], int left, int right, int pivot){
    int leftP = left - 1;
    int rightP = right;

    while(1){
        while(ar[++leftP] < pivot);

        while(ar[rightP] > 0 && ar[--rightP] > pivot);

        if(leftP >= rightP)
            break;

        else{
            int aux = ar[leftP];
            ar[leftP] = ar[rightP];
            ar[rightP] = aux;
        }
    }

    int aux = ar[leftP];
    ar[leftP] = ar[right];
    ar[right] = aux; 

    return leftP;

}

void QuickSort(int ar[], int left, int right){
    if(right-left <= 0)
        return;
    else{
        int pivot = ar[right];
        int part = Partition(ar, left, right, pivot);
        QuickSort(ar, left, part-1);
        QuickSort(ar, part+1, right);
    }
}


void PrintArray(int ar[], int size){
    for(int i = 0; i < size; i++)
        printf("%d\t", ar[i]);
}


void InsertOnHeap(int heapAr[], int value, int size){
    unsigned int pos;
    for(pos = ++size; pos > 1 && heapAr[pos/2] > value; pos /= 2){
        int aux = heapAr[pos];
        heapAr[pos] = heapAr[pos/2];
        heapAr[pos/2] = aux;
    }
    heapAr[pos] = value;
}
void sinkDown(int heapAr[], int pos, int size){//int a = mH[k];
		int smallest = pos;
		if(2*pos <= size && heapAr[smallest] > heapAr[2*pos]){
			smallest = 2*pos;
		}

        if(2*pos+1<= size && heapAr[smallest] > heapAr[2*pos + 1]){
			smallest = 2*pos + 1;
		}
        
		if(smallest != pos){
            //printf("Smallest: %d, Pos: %d\n",smallest, pos);
			int aux = heapAr[pos];
			heapAr[pos] = heapAr[smallest];
			heapAr[smallest] = aux;
			sinkDown(heapAr, smallest, size);
		}
}
int GetFromHeap(int heapAr[], int size){
    int ret = heapAr[1];
    heapAr[1] = heapAr[size];
    sinkDown(heapAr, 1 ,--size);
    return ret;
}

void HeapSort(int ar[], int size){
    int heapAr[size+1];
    int count = size;
    for(int i = 0; i < size; i++){
        InsertOnHeap(heapAr, ar[i], i);
    }
    for(int i = 0; i < size; i++){
        ar[i] = GetFromHeap(heapAr, count--);
    }

}

int main(){
	int ar[] = {5, 4, 3, 2, 1};
	int ar2[] = {5, 4, 3, 2, 1};
    int ar3[] = {5, 4, 3, 2, 1};

	printf("Array antes da ordenação: \n");

	PrintArray(ar, 5);

	MergeSort(ar, 0, 4);
	printf("\nOrdenação por Merge Sort: \n");

	PrintArray(ar, 5);

	QuickSort(ar2, 0, 4);
	printf("\nOrdenação por Quick Sort: \n");

	PrintArray(ar, 5);

    HeapSort(ar3, 5);
	printf("\nOrdenação por Heap Sort: \n");

    PrintArray(ar, 5);

	return 0;
}

