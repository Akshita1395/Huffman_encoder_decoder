
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

unordered_map<char, string> huffmanCode;
unordered_map<string, char> reverseCode;

void generateCodes(Node* root, string code) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
        reverseCode[code] = root->ch;
    }
    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

string encode(string text) {
    string encoded = "";
    for (char c : text) encoded += huffmanCode[c];
    return encoded;
}

string decode(string encoded, Node* root) {
    string result = "";
    Node* curr = root;
    for (char bit : encoded) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;
        if (!curr->left && !curr->right) {
            result += curr->ch;
            curr = root;
        }
    }
    return result;
}

int main() {
    ifstream inFile("input.txt");
    string text;
    getline(inFile, text, '\0');
    inFile.close();

    unordered_map<char, int> freq;
    for (char c : text) freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    Node* root = pq.top();
    generateCodes(root, "");
    string encodedText = encode(text);
    string decodedText = decode(encodedText, root);

    ofstream out1("encoded.txt");
    out1 << encodedText;
    out1.close();

    ofstream out2("decoded.txt");
    out2 << decodedText;
    out2.close();

    ofstream stats("compression_stats.txt");
    int originalBits = text.length() * 8;
    int compressedBits = encodedText.length();
    float ratio = (compressedBits * 100.0) / originalBits;
    stats << "Original size: " << originalBits << " bits\n";
    stats << "Compressed size: " << compressedBits << " bits\n";
    stats << "Compression ratio: " << ratio << "%\n";
    stats.close();

    return 0;
}
