class Solution(object):
    def peopleIndexes(self, favoriteCompanies):
        ans = []
        for index, i in enumerate(favoriteCompanies):
            for j in favoriteCompanies:
                sign = 1
                if j == i:
                    continue
                else:
                    if set(j) >= set(i):
                        sign = 0
                        break
            if sign == 1:
                ans.append(index)
        return ans