class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(' ')
        _len = len(searchWord)
        for idx, word in enumerate(words):
            if len(word) < _len:
                continue
            if searchWord == word[:_len]:
                return idx + 1

        return -1
