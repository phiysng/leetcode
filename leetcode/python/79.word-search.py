from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        if not m:
            return False
        n = len(board[0])
        if not n:
            return False
        visited = [[False] * n for i in range(m)]

        for i in range(len(board)):
            for j in range(len(board[0])):
                exists = self.DFS(board, visited, word, i, j)
                if exists:
                    return exists
        return False

    def DFS(self, board: List[List[str]], visited: List[List[bool]], s: str, i: int, j: int):
        if len(s) == 0:
            return True
        m = len(board)
        n = len(board[0])

        if s[0] != board[i][j]:
            return False
        if len(s) == 1:
            return True
        # TODO: duplicate DFS code
        # m => [0,m) n => [0,n)
        visited[i][j] = True
        if (0 <= i + 1 < m and 0 <= j < n and not visited[i + 1][j]
                and self.DFS(board, visited, s[1:], i + 1, j)):
            return True

        if (0 <= i < m and 0 <= j + 1 < n and not visited[i][j + 1]
                and self.DFS(board, visited, s[1:], i, j + 1)):
            return True

        if (0 <= i - 1 < m and 0 <= j < n and not visited[i - 1][j]
                and self.DFS(board, visited, s[1:], i - 1, j)):
            return True

        if (0 <= i < m and 0 <= j - 1 < n and not visited[i][j - 1]
                and self.DFS(board, visited, s[1:], i, j - 1)):
            return True

        visited[i][j] = False

        return False
