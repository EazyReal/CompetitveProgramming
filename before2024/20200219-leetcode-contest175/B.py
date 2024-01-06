class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        n = len(s)
        cnts = [0]*(26)
        cntt = [0]*(26)
        for i in range(n):
            cnts[ord(s[i])-ord('a')] += 1
            cntt[ord(t[i])-ord('a')] += 1
        diff = 0
        for c in range(26):
            diff += abs(cnts[c] - cntt[c])

        return diff//2
        
