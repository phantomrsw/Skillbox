#include <iostream>

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(float arr[], int N, int i)
{
    // Initialize largest as root
    int largest = i;
    // left = 2*i + 1
    int l = 2 * i + 1;
    // right = 2*i + 2
    int r = 2 * i + 2;
    // If left child is larger than root
    if (l < N && arr[l] < arr[largest]) largest = l;// the arr[l] < arr[largest] is for Min-Heap,
    // If right child is larger than largest so far // and the arr[l] > arr[largest] is for Max-Heap
    if (r < N && arr[r] < arr[largest]) largest = r;//
    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Recursively heapify the affected subtree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(float arr[], int N)
{
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--) heapify(arr, N, i);
    // One by one extract an element from heap
    for (int i = N - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    float numbers[15] = {8.5,10.2,13.3,10.0,2.0,156.2,1.0,
                         8.36,9.2,3.4,6.6,7.0,1.25,3.00,48.5};
    std::cout << "Enter 15 real numbers" << std::endl;

    int numbersLength = sizeof(numbers) / sizeof(numbers[0]);
    for(int i = 0; i < numbersLength; i++)
    {
        std::cout << i + 1 << ":";
        std::cin >> numbers[i];
    }

    std::cout << "Array before Heap sorting:" << std::endl;

    for(int i = 0; i < numbersLength; i++) std::cout << numbers[i] << "    ";

    heapSort(numbers, numbersLength);

    std::cout << std::endl <<  "Array after Heap sorting:" << std::endl;

    for(int i = 0; i < numbersLength; i++) std::cout << numbers[i] << "    ";

    return 0;
}
