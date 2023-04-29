#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
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
        // assumption word will be in caps
        int index = word[0] - 'A';
        TrieNode *child;
        // present

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }

        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int idx = word[0] - 'A';
        TrieNode *child;
        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            if (root->isTerminal == true)
            {
                root->isTerminal = false;
                return;
            }
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            cout << "Word not present" << endl;
            return;
        }
        removeUtil(child, word.substr(1));
    }

    void removeWord(string word)
    {
        return removeUtil(root, word);
    }
};
int main()
{
    Trie *t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout << "Present or Not " << t->searchWord("TIM") << endl;
    t->removeWord("TIME");
    cout << "Present or Not " << t->searchWord("TIME") << endl;

    return 0;
}