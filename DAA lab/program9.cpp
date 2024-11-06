#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

string generateRandomString(int length)
{
    string result;
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < length; i++)
    {
        result += characters[rand() % characters.length()];
    }
    return result;
}

string lcsAlgo(string S1, string S2, int m, int n)
{
    vector<vector<int>> LCS(m + 1, vector<int>(n + 1));

    // Building LCS matrix
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    // Backtrack to find the LCS
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcs = S1[i - 1] + lcs;
            i--;
            j--;
        }
        else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

int main()
{
    srand(time(0));

    vector<pair<int, int>> test_cases = {
        {5, 6},   // Small strings
        {8, 10},  // Slightly longer
        {12, 15}, // Medium sized
        {15, 18}, // Moderate length
        {20, 25}  // Longest test case
    };

    for (const auto &test : test_cases)
    {
        int len1 = test.first;
        int len2 = test.second;

        string S1 = generateRandomString(len1);
        string S2 = generateRandomString(len2);

        cout << "\nTest Case with Lengths: " << len1 << " and " << len2 << endl;
        cout << "String 1: " << S1 << endl;
        cout << "String 2: " << S2 << endl;

        auto start = high_resolution_clock::now();
        string lcs = lcsAlgo(S1, S2, len1, len2);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end - start).count();
        cout << "Longest Common Subsequence: " << lcs << endl;
        cout << "LCS Length: " << lcs.length() << endl;
        cout << "Time Taken: " << duration << " nanoseconds" << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}