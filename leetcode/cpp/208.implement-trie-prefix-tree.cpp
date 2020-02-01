/// 空间换时间
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

/**
 * @brief Trie impl(前缀树).
 * 
 */

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie() : _root(new TrieNode())
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *p = _root.get();

        for (auto c : word)
        {
            // c not exists.
            if (!p->children[c - 'a'])
            {
                p->children[c - 'a'] = new TrieNode();
            }
            // DFS like ops. traverse to next level.
            p = p->children[c - 'a'];
        }
        p->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto last_ptr = _find(word);
        // if the word is shorter , is_word == false
        // if longer , last_ptr == nullptr
        // return true when exactly the word matches.
        return last_ptr && last_ptr->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return _find(prefix) != nullptr;
    }

private:
    struct TrieNode
    {
        TrieNode() : is_word(false), children(26, nullptr){}

        ~TrieNode()
        {
            for (auto ptr : children)
            {
                if (ptr)
                {
                    delete ptr;
                }
            }
        }
        bool is_word;
        vector<TrieNode *> children;
    };

    const TrieNode *_find(const string &prefix)
    {
        const TrieNode *p = _root.get();

        for (auto c : prefix)
        {
            p = p->children[c - 'a']; //go to Trie's next level.
            if (!p)
                break;
        }

        return p;
    }

    unique_ptr<TrieNode> _root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
