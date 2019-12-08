# An efficient Python3 program to compute
# sum of bitwise OR of all pair

# Returns sum of bitwise OR
# of all pairs
def sumXOR( arr,  n):
    s = 0
    for i in range(0, 60):
        #  Count of zeros and ones
        zc = 0
        oc = 0
        # Individual sum at each bit position
        idsum = 0
        for j in range(0, n):
            if (arr[j] % 2 == 0):
                zc = zc + 1
            else:
                oc = oc + 1
            arr[j] = arr[j]  >> 1;
        # calculating individual bit sum
        idsum = oc * zc * (1 << i)
        # final sum
        s = (s + idsum)%(1e9+7);
    return s



# driver function
s = 0
n = int(input())
arr = [int(i) for i in input().split()]
s = sumXOR(arr, n);
print(s)
