#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// List of 62 C++ keywords
vector<string> cpp_keywords = {
    "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
    "char", "char16_t", "char32_t", "class", "compl", "const", "constexpr", "const_cast", "continue", "decltype",
    "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false",
    "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept",
    "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast",
    "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "template",
    "this", "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void",
    "volatile", "wchar_t", "while", "xor", "xor_eq"};

// Function to check if a word is a keyword
bool is_keyword(const string &word)
{
    return find(cpp_keywords.begin(), cpp_keywords.end(), word) != cpp_keywords.end();
}

int main()
{
    
    string filePath = "D:/docs ND stuff/3rd yr coding stuff/CD lab/08517702722_Pulkit/exp2/input.txt";

    // Open input file
    ifstream file(filePath);
    if (!file)
    {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    // Read the entire file into a string
    stringstream buffer;
    buffer << file.rdbuf();
    string programText = buffer.str();

    // Output the string read from input.txt
    cout << "Program text from input.txt:" << endl;
    cout << programText << endl;

    // Prepare to count keywords
    unordered_map<string, int> keyword_count;
    stringstream ss(programText);
    string word;

    // Parse the program and count keyword frequency
    while (ss >> word)
    {
        // Remove punctuation from word
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        if (is_keyword(word))
        {
            keyword_count[word]++;
        }
    }

    // Output the keywords and their frequencies
    cout << "\nKeywords found and their frequencies:" << endl;
    for (const auto &pair : keyword_count)
    {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
