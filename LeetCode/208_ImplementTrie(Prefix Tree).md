**题意: 实现trie树的insert、search、startsWith方法。输入为小写字母。**

<br/>
**AC解法**

```
class TrieNode {
public:
    // Initialize your data structure here.
    bool flag = 0;
    TrieNode* link[26];
    TrieNode() {
        for(int i = 0; i < 26; i++) link[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if(p->link[index] == NULL)
            {
                p->link[index] = new TrieNode();
            }
            p = p->link[index];
        }
        p->flag = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        return find(p, word) && p->flag;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        return find(p, prefix);
    }

private:
    TrieNode* root;
    bool find(TrieNode *&p, string w)
    {
        for(int i = 0; i < w.size(); i++)
        {
            int index = w[i] - 'a';
            if(p->link[index] == NULL) return false;
            p = p->link[index];
        }
        return true;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
```
**注意：**
1. link是一个指针数组。在实例化TrieNode时，构造函数中要对link数组初始化。
2. search方法与startsWith方法的区别是判断flag，那么在search方法中单独判断当前节点的flag是否为true，需要在调用find函数时对传入的参数p取地址。