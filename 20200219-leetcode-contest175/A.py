class Solution(object):
    def checkIfExist(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        n = len(arr)
        ret = 0
        for i in range(n):
            for j in range(n):
                if(i!=j):
                    ret |= arr[i] == 2*arr[j]
        return ret
                    
