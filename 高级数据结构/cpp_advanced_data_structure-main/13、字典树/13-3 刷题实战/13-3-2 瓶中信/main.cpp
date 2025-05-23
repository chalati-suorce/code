#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 62;

template<typename T>
struct TrieNode {
    vector< TrieNode<T>* > children;
    bool isEndOfWord;
    int count;
    T val;
    TrieNode() : children(ALPHABET_SIZE, NULL), isEndOfWord(false), count(0), val() {

    }
};

template<typename T, typename Ti>
class Trie {
private:
    TrieNode<T>* m_root;
    Ti m_trieIndex;
    void deleteNode(TrieNode<T>* node);
public:
    Trie();
    ~Trie();
    void Insert(const string& key, const T& val);
    bool Search(const string& key, const T& val);
    int QueryPrefixCount(const string& prefix);
    int QueryMaxPrefix(const string& prefix);
};

template<typename T, typename Ti>
void Trie<T, Ti>::deleteNode(TrieNode<T>* node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < node->children.size(); ++i) {
        deleteNode(node->children[i]);
    }
    delete node;
}

template<typename T, typename Ti>
Trie<T, Ti>::Trie() : m_root(new TrieNode<T>()) {
}

template<typename T, typename Ti>
Trie<T, Ti>::~Trie() {
    deleteNode(m_root);
}

template<typename T, typename Ti>
void Trie<T, Ti>::Insert(const string& key, const T& val) {
    TrieNode<T>* node = m_root;
    for (int i = 0; i < key.size(); ++i) {
        int index = m_trieIndex(key[i]);
        if (node->children[index] == NULL) {
            node->children[index] = new TrieNode<T>();
        }
        node = node->children[index];
        node->count += 1;
    }
    node->isEndOfWord = true;
    node->val = val;
}

template<typename T, typename Ti>
bool Trie<T, Ti>::Search(const string& key, const T& val) {
    TrieNode<T>* node = m_root;
    for (int i = 0; i < key.size(); ++i) {
        int index = m_trieIndex(key[i]);
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    if (node->isEndOfWord) {
        val = node->val;
        return true;
    }
    return false;
}

template<typename T, typename Ti>
int Trie<T, Ti>::QueryPrefixCount(const string& prefix) {
    TrieNode<T>* node = m_root;
    for (int i = 0; i < prefix.size(); ++i) {
        int index = m_trieIndex(prefix[i]);
        if (node->children[index] == NULL) {
            return 0;
        }
        node = node->children[index];
    }
    return node->count;
}

template<typename T, typename Ti>
int Trie<T, Ti>::QueryMaxPrefix(const string& prefix) {
    TrieNode<T>* node = m_root;
    int maxLen = 0;
    for (int i = 0; i < prefix.size(); ++i) {
        int index = m_trieIndex(prefix[i]);
        if (node->children[index] == NULL) {
            break;
        }
        node = node->children[index];
        if (node->count > 1) {
            maxLen = i + 1;
        }
    }
    return maxLen;
}


struct TrieIndex {
    int operator() (char c) {
        if (c >= 'a' && c <= 'z') {
            return c - 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 26;
        }
        return c - '0' + 52;
    }
};

string str[10001];

int main() {
    int n;
    cin >> n;
    Trie<int, TrieIndex> tr;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
        tr.Insert(str[i], 1);
    }
    for (int i = 0; i < n; ++i) {
        cout << tr.QueryMaxPrefix(str[i]) << endl;
    }
    return 0;
}
