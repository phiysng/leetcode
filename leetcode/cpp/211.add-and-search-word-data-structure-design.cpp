#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary() : _trie_root(new TrieNode())
    {
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        auto p = _trie_root.get();
        for (auto ch : word)
        {

            if (!p->childrens[ch - 'a'])
            {
                p->childrens[ch - 'a'] = new TrieNode();
            }
            p = p->childrens[ch - 'a'];
        }
        p->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        auto p = _trie_root.get();

        return _search(word, p);
    }

private:
    struct TrieNode
    {
        TrieNode() : is_word(false), childrens(26, nullptr) {}

        ~TrieNode()
        {
            for (auto child : childrens)
            {
                if (child)
                    delete child;
            }
        }

        bool is_word;
        vector<TrieNode *> childrens;
    };

    bool _search(const string &word, TrieNode *root)
    {

        TrieNode *curr = root;

        for (size_t i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                for (auto child : curr->childrens)
                {
                    if (child && _search(word.substr(i + 1), child))
                    {
                        return true;
                    }
                }
                return false;
            }

            if(!curr->childrens[word[i]-'a']) return false;

            curr = curr->childrens[word[i]-'a']; 

        }
        return curr->is_word;
    }

    unique_ptr<TrieNode> _trie_root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
