from typing import Optional, Union


class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = {}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        p = self.root
        for c in word:
            if c not in p:
                p[c] = {}
            p = p[c]
        p['#'] = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        r = self._search(word)
        return r and r.get('#', False)

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        return self._search(prefix)

    def _search(self, prefix: str)->Optional[dict[str,Union[bool,dict]]]:
        p = self.root

        for c in prefix:
            if c not in p:
                return None
            p = p[c]
        return p

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
