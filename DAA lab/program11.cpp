#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void compareAndSwap(vector<int>& arr, int i, int j, int step) {
    cout << "Step " << step << " - Compare elements at positions " << i << " and " << j << ": ";
    cout << arr[i] << " and " << arr[j] << " -> ";
    
    if (arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
    }
    
    cout << arr[i] << " and " << arr[j] << endl;
}

void printArray(const vector<int>& arr, string message) {
    cout << message;
    for (int num : arr) {
        cout << setw(3) << num << " ";
    }
    cout << endl;
}

void sortingNetwork4(vector<int>& arr) {
    cout << "\nSorting Network Steps:\n";
    cout << "---------------------\n";
    
    // Stage 1
    cout << "Stage 1:\n";
    compareAndSwap(arr, 0, 1, 1);
    compareAndSwap(arr, 2, 3, 2);
    printArray(arr, "After Stage 1: ");
    
    // Stage 2
    cout << "\nStage 2:\n";
    compareAndSwap(arr, 0, 2, 3);
    compareAndSwap(arr, 1, 3, 4);
    printArray(arr, "After Stage 2: ");
    
    // Stage 3
    cout << "\nStage 3:\n";
    compareAndSwap(arr, 1, 2, 5);
    printArray(arr, "After Stage 3: ");
}

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int main() {
    srand(time(0));
    
    cout << "Sorting Network Implementation (4 elements)\n";
    cout << "==========================================\n";
    
    vector<pair<string, vector<int>>> test_cases = {
        {"Random Case 1", generateRandomArray(4)},
        {"Reverse Sorted", {4, 3, 2, 1}},
        {"Already Sorted", {1, 2, 3, 4}},
        {"Equal Elements", {2, 2, 2, 2}},
        {"Random Case 2", generateRandomArray(4)}
    };
    
    for(const auto& test : test_cases) {
        cout << "\nTest Case: " << test.first << "\n";
        cout << "----------------------------------------\n";
        
        vector<int> arr = test.second;
        printArray(arr, "Initial array: ");
        sortingNetwork4(arr);
        
        cout << "\nFinal Result:\n";
        printArray(arr, "Sorted array:  ");
        cout << "========================================\n";
    }
    
    return 0;
}