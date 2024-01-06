from __future__ import print_function
import sys
import random
import logging

S = 8
MAX_TURNS = 300

def getSet():
    R = set()
    for i in range(2**S):
        p = toString(i)
        flag = 0
        for j in range(S):
            newp = p[j:] + p[:j]
            if newp in R: 
                flag = 1
        if flag:
            continue
        else:
            R.add(p)
    R = list(R)
    return R

def sxor(old_record, newp):
  new_record = ""
  for i in range(S):
    new_record += '1' if old_record[i] != newp[i] else '0'
  return new_record

def n1(record):
  number_of_one = 0
  for i in range(S):
    number_of_one += 1 if record[i] == '1' else 0
  return number_of_one

def rands(n, m):
    while(1):
        key = ""
        cnt = 0
        for i in range(n):
            tmp =  str(random.randint(0, 1))
            cnt += int(tmp == '1')
            key += tmp
        if(cnt == m):
            return key

def toString(x):
    s = ""
    for i in range(S):
        s += str(x%2)
        x//=2
    return s

def query(Q, A, x):
    print(x)
    Q += [x]
    A += [int(input())]
    return A[-1]

def solve(R):
    Q = []
    A = []
    # fix by intense querying?
    for i in range(120):
        a = query(Q, A, random.choice(R))
        if(a == 0 or a == -1):
            return
    # guess with ~70 rounds
    for i in range(205):
        a = query(Q, A, rands(S, A[-1]))
        if(a == 0 or a == -1):
            return
            
if __name__ == '__main__':
    # Use raw_input in Python2.
    try:
        input = raw_input
    except NameError:
        pass
    # logging.error(len(R))
    T = int(input())
    R = getSet()
    for t in range(T):
        b = solve(R)
        if(b == 1):
            exit(0)

