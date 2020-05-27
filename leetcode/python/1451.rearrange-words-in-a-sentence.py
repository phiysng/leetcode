class Solution:
    def arrangeWords(self, text: str) -> str:
        words = text.split(' ')

        words = list(map(lambda x: x.lower(), words))
        words.sort(key=lambda x: len(x))
        words[0] = str.upper(words[0][0]) + words[0][1:]
        return str.join(' ', words)
