#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <map>

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

Node *createNode(char ch, int freq, Node *left = nullptr, Node *right = nullptr)
{
    Node *node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

void generateRandomString(std::string &str, int size)
{
    str.resize(size);
    for (int i = 0; i < size; ++i)
    {
        str[i] = 'a' + rand() % 26; // Random character from 'a' to 'z'
    }
}

void calculateFrequencies(const std::string &str, std::map<char, int> &freqMap)
{
    for (char ch : str)
    {
        freqMap[ch]++;
    }
}

void storeCodes(Node *root, char str[], int top, std::map<char, std::string> &huffmanCodes)
{
    if (root->left)
    {
        str[top] = '0';
        storeCodes(root->left, str, top + 1, huffmanCodes);
    }

    if (root->right)
    {
        str[top] = '1';
        storeCodes(root->right, str, top + 1, huffmanCodes);
    }

    if (!root->left && !root->right)
    {
        str[top] = '\0';
        huffmanCodes[root->ch] = str;
    }
}

void buildHuffmanTree(const std::map<char, int> &freqMap, std::map<char, std::string> &huffmanCodes)
{
    std::priority_queue<Node *, std::vector<Node *>, compare> minHeap;

    for (const auto &pair : freqMap)
    {
        minHeap.push(createNode(pair.first, pair.second));
    }

    while (minHeap.size() != 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        int sum = left->freq + right->freq;
        minHeap.push(createNode('\0', sum, left, right));
    }

    Node *root = minHeap.top();
    char str[256];
    storeCodes(root, str, 0, huffmanCodes);
}

int main()
{
    srand(time(0)); // Seed for random number generation

    int sizes[] = {100, 500, 1000, 1500, 2000};

    for (int i = 0; i < 5; ++i)
    {
        int size = sizes[i];
        std::string str;
        std::map<char, int> freqMap;
        std::map<char, std::string> huffmanCodes;

        generateRandomString(str, size);
        calculateFrequencies(str, freqMap);

        clock_t start = clock();
        buildHuffmanTree(freqMap, huffmanCodes);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000; // in microseconds
        printf("Time taken for Huffman coding with %d characters: %.2f microseconds\n", size, time_taken);

        // Print characters, their frequencies, and the allotted codes
        std::cout << "Character\tFrequency\tCode\n";
        for (const auto &pair : freqMap)
        {
            std::cout << pair.first << "\t\t\t\t" << pair.second << "\t\t" << huffmanCodes[pair.first] << "\n";
        }
        std::cout << "=============================================\n";
    }

    return 0;
}