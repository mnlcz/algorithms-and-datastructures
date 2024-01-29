#include <iostream>

using namespace std;

// O(N (LOG N))
// PEOR CASO: O(N^2)
void Quicksort(int* A, int start, int end);
int Partition(int* A, int start, int end);

int main()
{
    int A[] = {5, 2, 6, 8, 1, 7, 3, 9};
    int size = sizeof(A)/sizeof(A[0]);
    Quicksort(A, 0, (size - 1));
    for (int i = 0; i < size; i++) cout << A[i] << " ";
    cout << endl;
    // ---------------------------------------
    int B[] = {8, 4, 8, 5, 6, 7, 9, 2, 12, 1, 7};
    int size2 = sizeof(B) / sizeof(B[0]);
    Quicksort(B, 0, (size - 1));
    for (int i = 0; i < size; i++) cout << B[i] << " ";
}

void Quicksort(int* A, int start, int end)
{
    if(start < end)
    {
        int partitionIndex = Partition(A, start, end);
        Quicksort(A, start, partitionIndex - 1);
        Quicksort(A, partitionIndex + 1, end);
    }
}

int Partition(int* A, int start, int end)
{
    int pivot = A[end];
    int partitionIndex = start;
    for(int i = start; i < end; i++)
    {
        if(A[i] <= pivot)
        {
            swap(A[i], A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(A[partitionIndex], A[end]);

    return partitionIndex;
}