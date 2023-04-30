#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char ch;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char data)
    {
        ch = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        TrieNode *child;
        int idx = word[0] - 'a';

        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[idx] = child;
            root->childCount++;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string word, string &ans)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (root->isTerminal == true)
            {
                break;
            }
            char ch = word[i];
            if (root->childCount == 1)
            {
                ans.push_back(ch);
                int idx = ch - 'a';
                root = root->children[idx];
            }
            else
            {
                break;
            }
        }
    }
};
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        string word = strs[0];
        Trie *t = new Trie();
        for (int i = 0; i < strs.size(); i++)
        {
            t->insertWord(strs[i]);
        }
        t->lcp(word, ans);
        return ans;
    }
};
int main()
{

    return 0;
}