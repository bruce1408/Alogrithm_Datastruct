#include<iostream>
#include<vector>
using namespace std;

/**
 * 212 在一个二维的矩阵中查找单词
 * 使用trie树来构造单词，然后使用深度优先搜索来做
*/
class Solution {
public:
    struct Node
    {
        int id;
        Node *son[26];
        Node()
        {
            id = -1;
            for(int i=0;i<26;i++) son[i] = NULL;
        }
    }*root;
    unordered_set<int>ids;
    vector<vector<char>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0,1,0,-1};

    void insert(string & word, int id)
    {
        auto p = root;
        for(auto c: word)
        {
            int u = c - 'a';
            if(!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->id = id;
    }

    vector<string>findWords(vector<vector<char>> & board, vector<string>&words)
    {
        g = board;
        root = new Node();
        for(int i= 0;i<words.size();i++) insert(words[i], i);
        for(int i= 0;i<g.size();i++)
        {
            for(int j = 0;j<g[i].size();j++)
            {
                int u = g[i][j] - 'a';
                if(root->son[u])
                {
                    dfs(i, j, root->son[u]);
                }
            }
        }
        vector<string> res;
        for(auto  id: ids) res.push_back(words[id]);
        return res;
    }

    void dfs(int x, int y, Node*p)
    {
        if(p->id !=-1)
        {
            ids.insert(p->id);
        }
        char t = g[x][y];
        g[x][y] = '.';
        for(int i=0;i<4;i++)
        {
            int a = dx[i] + x, b = dy[i] + y;
            if(a>=0 && a < g.size() && b >=0 && b<g[0].size() && g[a][b] != '.')
            {
                int u = g[a][b] - 'a';
                if(p->son[u]) dfs(a, b, p->son[u]);
            }
        }
        g[x][y] = t;
    }
};