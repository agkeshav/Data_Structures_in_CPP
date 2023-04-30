#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char ch;
    TrieNode *children[26];
    bool isTerminal;

public:
    TrieNode(char ch)
    {
        this->ch = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
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
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefixStr)
    {
        if (curr->isTerminal == true)
        {
            temp.push_back(prefixStr);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefixStr.push_back(ch);
                printSuggestions(next, temp, prefixStr);
                prefixStr.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string &queryStr)
    {
        vector<vector<string>> ans;
        string prefixStr = "";
        TrieNode *prev = root;
        for (int i = 0; i < queryStr.length(); i++)
        {
            char lastch = queryStr[i];
            prefixStr.push_back(lastch);

            TrieNode *curr = prev->children[lastch - 'a'];
            // not found
            if (curr == NULL)
            {
                break;
            }
            vector<string> temp;
            printSuggestions(curr, temp, prefixStr);
            ans.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    //    Write your code here.
    Trie *t = new Trie();
    for (int i = 0; i < contactList.size(); i++)
    {
        t->insertWord(contactList[i]);
    }

    return t->getSuggestions(queryStr);
}
int main()
{

    return 0;
}