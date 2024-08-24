#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Insertion Sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Selection Sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

// Function to generate a vector of random integers
vector<int> generateRandomArray(int size)
{
    vector<int> arr(size);
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % size; // Random number between 0 and size - 1 otherwise rand() can generate large numbers (upto 32000 or more)
    }
    return arr;
}

template <typename Func>
// using template function to measure time for sorting algorithms
void measureSortTime(Func sortFunc, vector<int> &arr, const string &sortName)
{
    vector<int> arr_copy = arr; // Copy for sorting

    cout << "Starting " << sortName << "..." << endl;

    auto start = high_resolution_clock::now();
    sortFunc(arr_copy);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start).count();
    cout << "Time Taken:\t" << duration << " ns" << endl;
    cout << "----------------------------------------" << endl;
}

int main()
{
    vector<int> sizes = {100, 500, 1000, 1500, 2000};

    for (int size : sizes)
    {
        cout << "Array size: " << size << endl;
        vector<int> arr = generateRandomArray(size);

        // Measure time for Insertion Sort
        measureSortTime(insertionSort, arr, "Insertion Sort");

        // Measure time for Bubble Sort
        measureSortTime(bubbleSort, arr, "Bubble Sort");

        // Measure time for Selection Sort
        measureSortTime(selectionSort, arr, "Selection Sort");

        cout << "\n========================================\n"
             << endl;
    }

    return 0;
}