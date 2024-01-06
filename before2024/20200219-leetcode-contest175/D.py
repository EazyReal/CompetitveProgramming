class Solution(object):

    def bitcount(self, _x):
        ret = 0
        x = _x
        while x:
            if x & 1:
                ret += 1
            x >>= 1
        return ret

    def maxStudents(self, seats):
        m, n = len(seats), len(seats[0])
        mp = [0]*m
        for i in range(m):
            for j in range(n):
                if seats[i][j] == '#':
                    mp[i] |= (1 << j)
        allsub = []
        allsubc = []
        for s in range(2**n):
            if not ((s & (s << 1)) and (s & (s >> 1))):
                allsub.append(s)
                allsubc.append(self.bitcount(s))

        dp = [[0]*(2**n) for i in range(m)]

        for i in range(len(allsub)):
            if not (mp[0] & allsub[i]): #cant take broken
                dp[0][allsub[i]] = allsubc[i]

        for i in range(1, m):
            for j in range(len(allsub)):
                if allsub[j] & mp[i]:
                    continue
                for k in range(len(allsub)):
                    if allsub[k] & mp[i - 1]:
                        continue
                    if (allsub[j] & (allsub[k] >> 1)) or (allsub[j] & (allsub[k] << 1)) :
                        continue
                    dp[i][allsub[j]] = max(dp[i][allsub[j]], dp[i - 1][allsub[k]] + allsubc[j])
        return max(dp[-1])
