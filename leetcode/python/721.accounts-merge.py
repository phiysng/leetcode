from typing import List

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        
        class QuickUnion:
            def __init__(self, size):
                self.parent = [x for x in range(size)]

            def find(self, id):
                if self.parent[id] != id:
                    return self.find(self.parent[id])
                return id

            def union(self, i, j):
                rootI = self.find(i)
                rootJ = self.find(j)
                if rootI != rootJ:
                    self.parent[rootJ] = self.parent[rootI]

        qu = QuickUnion(40000)
        mailToId = {}
        mailToName = {}
        id = 0
        for account in accounts:
            name = account[0]
            for mail in account[1:]:
                if mail not in mailToId:
                    mailToId[mail] = id
                    id += 1
                qu.union(mailToId[mail], mailToId[account[1]])
                mailToName[mail] = name

        # 同一个父节点的email放在一起
        # mailToName[mail],
        result = {}
        for mail in mailToName:

            _id = qu.find(mailToId[mail])
            if _id not in result:
                result[_id] = set()
            result[_id].add(mail)
            
        for item in result.keys():
            result[item] = list(result[item])
            result[item].sort()
            result[item].insert(0, mailToName[result[item][0]])
        return [result[x] for x in result.keys()]
