#By sotanishy, contest: Educational Codeforces Round 81 (Rated for Div. 2), problem: (C) Obtain The String, Accepted, #, Copy, hack it!
#to learn python on CP
#bisect and defaultdict
import sys
from bisect import bisect_left
from collections import defaultdict

for _ in range(int(input())):
	s = input()
	t = input()
	inds = defaultdict(list)
	for i in range(len(s)):
		inds[s[i]].append(i)

	cnt = 1
	ti = 0
	si = 0
	for ti in range(len(t)):
		if t[ti] not in inds:
			print(-1)
			break
		ci = bisect_left(inds[t[ti]], si)
		if ci != len(inds[t[ti]]):
			si = inds[t[ti]][ci] + 1
		else:
			si = inds[t[ti]][0] + 1
			cnt += 1
	else:
		print(cnt)
