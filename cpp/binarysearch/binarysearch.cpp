#include <iostream>
#define SIZE 10

int buscar(const int* array, int target);
void print_array(const int* array);

int main()
{
    int array[SIZE] = {1, 4, 6, 9, 15, 20, 37, 43, 61, 80};
    int index;
    int target;
    target = 37;
    print_array(array);
    index = buscar(array, target);
    std::cout << "TARGET: " << target << std::endl;
    std::cout << "INDEX: " << index;

    return 0;
}

int buscar(const int* array, int target)
{
    int left = 0;
    int right = SIZE - 1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(array[mid] == target)
            return mid;
        else if(target < array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

void print_array(const int* array)
{
    std::cout << "ARRAY: [";
    for(int i = 0; i < SIZE; i++)
        std::cout << " " << array[i] << " ";
    std::cout << "]" << std::endl;
}