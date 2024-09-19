#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <climits>

using namespace std;
using namespace std::chrono;

// Function to generate a vector of random matrix dimensions
vector<int> generateRandomArray(int size)
{
    vector<int> arr(size);
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100 + 1; // Generating random dimensions between 1 and 100
    }
    return arr;
}

// Function to perform Matrix Chain Multiplication
// DP Tabulation approach
void MatrixChainMulti(const vector<int>& p, int n)
{
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            C[i][j] = INT_MAX;

            // Try placing parentheses at different places and find the minimum cost
            for (int k = i; k < j; k++)
            {
                int q = C[i][k] + C[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < C[i][j])
                {
                    C[i][j] = q;
                }
            }
        }
    }

    cout << "Minimum number of multiplications is " << C[1][n - 1] << endl;
}

int main()
{
    srand(time(0));  // Initialize random seed

    vector<int> sizes = {101, 501, 1001, 1501, 2001};
    //because for n+1 size, dimensions for n matrices would be created

    for (int size : sizes)
    {
        vector<int> d = generateRandomArray(size);  // Matrix dimensions
        int n = d.size();

        cout << "No of Matrices: " << size-1 << endl;

        auto start = high_resolution_clock::now();
        MatrixChainMulti(d, n);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "Time Taken: " << duration << " microseconds" << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}
