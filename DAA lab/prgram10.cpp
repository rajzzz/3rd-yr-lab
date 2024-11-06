#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// Function to generate random string
string generateRandomString(int length) {
    string result;
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for(int i = 0; i < length; i++) {
        result += characters[rand() % characters.length()];
    }
    return result;
}

// Naive String Matching Algorithm
void naiveSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> positions;

    for(int i = 0; i <= n - m; i++) {
        bool match = true;
        for(int j = 0; j < m; j++) {
            if(text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if(match) {
            positions.push_back(i);
        }
    }

    cout << "Naive Search found " << positions.size() << " matches at positions: ";
    for(int pos : positions) cout << pos << " ";
    cout << endl;
}
// Rabin-Karp Algorithm
void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    const int d = 256;  // number of characters in alphabet
    const int q = 101;  // a prime number
    int h = 1;
    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for text
    vector<int> positions;

    // Calculate d^(m-1) % q
    for(int i = 0; i < m-1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and first window
    for(int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide pattern over text one by one
    for(int i = 0; i <= n - m; i++) {
        if(p == t) {
            bool match = true;
            for(int j = 0; j < m; j++) {
                if(text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if(match)
                positions.push_back(i);
        }
        if(i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if(t < 0) t += q;
        }
    }

    cout << "Rabin-Karp found " << positions.size() << " matches at positions: ";
    for(int pos : positions) cout << pos << " ";
    cout << endl;
}

// KMP Algorithm
void kmp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m, 0);
    vector<int> positions;

    // Compute LPS array
    int len = 0;
    int i = 1;
    while(i < m) {
        if(pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if(len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }

    // Find pattern
    i = 0;
    int j = 0;
    while(i < n) {
        if(pattern[j] == text[i]) {
            i++;
            j++;
        }
        if(j == m) {
            positions.push_back(i - j);
            j = lps[j - 1];
        } else if(i < n && pattern[j] != text[i]) {
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }

    cout << "KMP found " << positions.size() << " matches at positions: ";
    for(int pos : positions) cout << pos << " ";
    cout << endl;
}

int main() {
    srand(time(0));

    vector<pair<int, int>> test_cases = {
        {20, 3},    // Small text, small pattern
        {30, 4},    // Medium text, small pattern
        {40, 5},    // Large text, medium pattern
        {50, 6},    // Larger text, medium pattern
        {60, 7}     // Largest text, large pattern
    };

for(const auto& test : test_cases) {
    int text_len = test.first;
    int pattern_len = test.second;

    string text = generateRandomString(text_len);
    string pattern = text.substr(rand() % (text_len - pattern_len), pattern_len);

    cout << "\nTest Case with Text Length: " << text_len << ", Pattern Length: " << pattern_len << endl;
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    // Naive Algorithm
    auto start = high_resolution_clock::now();
    naiveSearch(text, pattern);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Naive Search execution time: " << duration << " microseconds" << endl;

    // Rabin-Karp Algorithm
    start = high_resolution_clock::now();
    rabinKarp(text, pattern);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();
    cout << "Rabin-Karp execution time: " << duration << " microseconds" << endl;

    // KMP Algorithm
    start = high_resolution_clock::now();
    kmp(text, pattern);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();
    cout << "KMP execution time: " << duration << " microseconds" << endl;
    cout << "----------------------------------------" << endl;
}

    return 0;
}