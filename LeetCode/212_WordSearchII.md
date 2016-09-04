**题意: 给一个字符矩阵，从中找出存在的单词。输入单词组均为小写字母。**

**样例：**
```
Given words = ["oath","pea","eat","rain"] and 
board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"]
```
<br/>
**AC解法：先对输入的单词组构建trie树。然后遍历矩阵，对矩阵中每一个字符，都从trie树的根节点开始去向下找。**

```
int id = 0;
struct Trie
{
    bool flag;
    int link[26];
    void init(){
        flag = false;
        for(int i = 0; i < 26; i++) link[i] = -1;
    }
};
vector<Trie> trie;

class Solution {
public:
    vector<string> ans;
    void build(string w)
    {
        int top = 0;
        for(int i = 0; i < w.size(); i++)
        {
            int index = w[i] - 'a';
            if(trie[top].link[index] == -1)
            {
                trie[top].link[index] = id;
                trie.push_back(Trie());
                trie[id].init();
                id++;
            }
            top = trie[top].link[index];
        }
        trie[top].flag = true;
    }
    void dfs(vector<vector<char>>& board, int i, int j, int top, string w)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '\0') return ;
        
        int p = trie[top].link[board[i][j] - 'a'];
        if(p == -1) return ;
        w += board[i][j];
        if(trie[p].flag)
        {
            //w不需要pop，因为w是以参数形式在dfs中传递的，回溯时依旧是上一次的w。
            //w也不需要clear，因为会有这种情况"tea","teach"，探索到"tea"时，依旧需要继续向下探索
            ans.push_back(w);
            trie[p].flag = false;//同一个串可能会被多次寻找到
        }
        
        char t = board[i][j];
        board[i][j] = '\0';
        dfs(board, i+1, j, p, w);
        dfs(board, i, j+1, p, w);
        dfs(board, i-1, j, p, w);
        dfs(board, i, j-1, p, w);
        board[i][j] = t;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ans.clear();
        trie.clear();
        trie.push_back(Trie());//new Trie()返回指针
        trie[0].init();
        id = 1;
        for(int i = 0; i < words.size(); i++)
        {
            build(words[i]);
        }
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, 0, "");
            }
        }
        return ans;
    }
};
```
**注意：**
1. 把trie树开成普通的自定义大小的数组，在样例words输入很大量时会RE，所以将trie定义为vector。

2. 每次需要先把Trie节点加入到vector中，才能对这个节点初始化。加入节点时，```new Trie()```返回的是指针，正确写法是```trie.push_nack(Trie())```。

3. dfs在做的过程中应该对正在搜索还没有回溯的点进行标记，可以另外开一个二位数组记录，也可以使用trick，将board[i][j]赋为```'\0'```。

4. 对于样例```board=["aa"], words=["a"]```，因为board中每一个字符都会去trie树中查找，输出结果为```["a", "a"]```，所以在单词被记过之后，应该将flag标记为false，防止同一个串被多次查找到。

<br/>
**上面是用struct构造trie，这里用类构造**
```
class TrieNode{
public:
    bool flag = 0;
    TrieNode *link[26];
    TrieNode()
    {
        for(int i = 0; i < 26; i++) link[i] = NULL;
    }
};
class Trie{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string w)
    {
        TrieNode *p = root;
        for(int i = 0; i < w.size(); i++)
        {
            int index = w[i] - 'a';
            if(p->link[index] == NULL)
            {
                p->link[index] = new TrieNode();
            }
            p = p->link[index];
        }
        p->flag = true;
    }
};
class Solution {
public:
    vector<string> ans;
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode *p, string w)//这里传入p不能取地址，因为深层修改会影响浅层的p
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '\0') return;
        p = p->link[board[i][j] - 'a'];
        if(p == NULL) return ;
        w += board[i][j];
        if(p->flag)
        {
            ans.push_back(w);
            p->flag = false;
        }
        char t = board[i][j];
        board[i][j] = '\0';
        dfs(board, i+1, j, p, w);
        dfs(board, i, j+1, p, w);
        dfs(board, i-1, j, p, w);
        dfs(board, i, j-1, p, w);
        board[i][j] = t;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(int i = 0; i < words.size(); i++)
        {
            trie.insert(words[i]);
        }
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                TrieNode *p = trie.root;
                dfs(board, i, j, p, "");
            }
        }
        return ans;
    }
};
```

<br/>
**类似题目：79. Word Search**

**题意: 给一个矩阵，问一个单词是否出现。单词可以由临近的单元格组成，可以是垂直相邻或水平相邻，且这个单元格在组成时只能用一次。**

**样例：**
```
For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
```
<br/>
**dfs解法**

```
class Solution {
public:
    bool dfs(vector<vector<char>> &board, string w, int x, int y, int i)
    {
        if(i == w.size()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() 
            || board[x][y] != w[i] || board[x][y] == '\0') //注意先判断边界条件，然后再判断board[x][y]，不然会RE
            return false;
        char t = board[x][y];
        board[x][y] = '\0';
        bool e = dfs(board, w, x+1, y, i+1) || dfs(board, w, x, y+1, i+1) 
            || dfs(board, w, x-1, y, i+1) || dfs(board, w, x, y-1, i+1);
        board[x][y] = t;
        return e;
    }
    bool exist(vector<vector<char>>& board, string w) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(dfs(board, w, i, j, 0)) return true;
            }
        }
        return false;
    }
};
```