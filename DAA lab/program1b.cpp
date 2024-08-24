#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Merge Sort
void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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

        // Measure time for Merge Sort
        measureSortTime([](vector<int> &arr)
                        { mergeSort(arr, 0, arr.size() - 1); }, arr, "Merge Sort");

        // Measure time for Quick Sort
        measureSortTime([](vector<int> &arr)
                        { quickSort(arr, 0, arr.size() - 1); }, arr, "Quick Sort");

        // Measure time for Heap Sort
        measureSortTime([](vector<int> &arr)
                        { heapSort(arr, arr.size()); }, arr, "Heap Sort");

        cout << "\n========================================\n"
             << endl;
    }

    return 0;
}