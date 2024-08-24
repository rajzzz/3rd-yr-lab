#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Function to generate a vector of random integers
vector<int> generateRandomArray(int size)
{
    vector<int> arr(size);
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % size;
    }
    return arr;
}

// Linear search function
bool linearSearch(const vector<int> &arr, int target)
{
    for (int num : arr)
    {
        if (num == target)
        {
            return true;
        }
    }
    return false;
}

// Binary search function
bool binarySearch(const vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return true;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

template <typename Func>
void measureSearchTime(Func searchFunc, const vector<int> &arr, int target, const string &searchName)
{
    cout << "Starting " << searchName << "..." << endl;

    auto start = high_resolution_clock::now();
    bool found = searchFunc(arr, target);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start).count();
    cout << "Time Taken:\t" << duration << " ns" << endl;
    cout << "Target " << (found ? "found" : "not found") << endl;
    cout << "----------------------------------------" << endl;
}

int main()
{
    vector<int> sizes = {100, 500, 1000, 1500, 2000};

    for (int size : sizes)
    {
        cout << "Array size: " << size << endl;
        vector<int> arr = generateRandomArray(size);
        int target = arr[size / 2]; // Choose a target in the middle for consistency

        // Measure time for Linear Search
        measureSearchTime(linearSearch, arr, target, "Linear Search");

        // Sort the array for Binary Search
        sort(arr.begin(), arr.end());

        // Measure time for Binary Search
        measureSearchTime(binarySearch, arr, target, "Binary Search");

        cout << "\n========================================\n"
             << endl;
    }

    return 0;
}