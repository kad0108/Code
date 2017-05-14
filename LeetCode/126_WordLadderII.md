**系列题目：127. Word Ladder**

**题意：给一个起始单词和终止单词，一个字典，找到从起始单词变换到终止单词的最短的改变顺序，每次改变只能改变一个字母，所有变形单词都必须出现在字典中。没找到返回0。**

<br/>

**样例：**

```
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
```

<br/>

**解：这个题居然没有意识到是在找最短路径，而bfs就可以解决无权重的最短路径求解。从当前begin单词出发，找到所有字典中变换了一个字母的单词放入队列，实际上就是按层在找。每次加入队列的都是距离当前单词最近的，代价最小的，也就保证了路径最短。**


需要注意的是，begin单词可能存在在字典中，会影响寻找路径，所以应该事先去掉。
```
struct Node {
    int cot;
    string s;
    Node() {};
    Node(int cot, string s): cot(cot), s(s) {};
};

class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        st.clear();
        queue<Node> q;
        for(int i = 0, len = wordList.size(); i < len; i++){
            
            st.insert(wordList[i]);
        }
        if(st.find(end) == st.end()) return 0;
        q.push(Node(1, begin));
        if(st.find(begin) != st.end()) st.erase(begin);
        while(!q.empty()){
            Node now = q.front();
            q.pop();
            if(now.s == end) return now.cot;
            vector<string> next = similar(now.s);
            if(next.empty()) continue; // 这儿不能直接return 0；
            for(int i = 0; i < next.size(); i++){
                q.push(Node(now.cot+1, next[i]));
                st.erase(next[i]);
            }
        }
        return 0;
    }
private:
    set<string> st;
    vector<string> similar(string s){
        vector<string> v;
        for(int i = 0; i < s.size(); i++){
            string tmp = s;
            for(int j = 0; j < 26; j++){
                if(j + 'a' != tmp[i]) {
                    tmp[i] = j + 'a';
                    if(st.find(tmp) != st.end()) v.push_back(tmp);    
                }
            }
        }
        return v;
    }
};
```

<br/>
**本题题意：输出所有从begin单词到end单词的最短变换路径**

<br/>
**样例：**
```
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
```

<br/>
**解：bfs＋dfs。记录路径很明显需要map映射，开始想的是记录前驱结点，bfs找到end结点然后回溯根据前驱结点逆着找路径。实际上只需要构造字典中结点到begin的距离即可也就是map，然后从end向前深搜直到找到距离begin的距离为1。**
```
struct Node{
    int cot;
    string s;
    Node() {};
    Node(int cot, string s): cot(cot), s(s) {};
};

class Solution {
public:
    vector<vector<string>> findLadders(string begin, string end, vector<string>& wordList) {
        mp.clear();
        ans.clear();
        getSet(wordList, begin);
        if(st.find(end) == st.end()) return ans;
        queue<Node> q;
        q.push(Node(0, begin));
        mp[begin] = 0;
        while(!q.empty()){
            Node now = q.front();
            q.pop();
            vector<string> next = similar(now.s);
            for(int i = 0; i < next.size(); i++){
                q.push(Node(now.cot+1, next[i]));
                mp[next[i]] = now.cot+1;
                st.erase(next[i]);
            }
        }
        getSet(wordList, end); // 进行bfs之后set中已经erase掉一些单词，所以应该重新构造set。
        dfs(end, end, begin);
        return ans;
    }
private:
    map<string, int> mp;
    set<string> st;
    vector<vector<string>> ans;
    vector<string> similar(string s){
        vector<string> v;
        for(int i = 0; i < s.size(); i++){
            string tmp = s;
            for(int j = 0; j < 26; j++){
                if(j + 'a' != tmp[i]){
                    tmp[i] = j + 'a';
                    if(st.find(tmp) != st.end()) v.push_back(tmp);
                }
            }
        }
        return v;
    }
    void getSet(vector<string> &wordList, string s){
        st.clear();
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] != s) st.insert(wordList[i]);
        }
    }
    vector<string> path;
    void dfs(string s, string end, string begin){
        if(s == end){
            path.clear();
            path.push_back(s);
        }
        if(mp[s] == 1){
            path.push_back(begin);
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }
        vector<string> next = similar(s);
        for(int i = 0; i < next.size(); i++){
            if(mp.find(next[i]) != mp.end() && mp[s] == mp[next[i]]+1){
                path.push_back(next[i]);
                dfs(next[i], end, begin);
                path.pop_back();
            }
        }
    }
};
```

