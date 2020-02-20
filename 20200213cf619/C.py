import sys
from bisect import bisect_left
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()

#print("executing")

for _ in range(int(sys.stdin.readline())):
    n, m = map(int,sys.stdin.readline().split())

    ze = n-m
    allp = (n*(n+1))//2
    mean = ze//(m+1)
    more = ze%(m+1)
    allp -= (m+1-more)*(mean*(mean+1)//2) + more*((mean+1)*(mean+2)//2)
    print(allp)

#use sys.stdin.readline() instead of input() will not get TLE...
"""
contest
71007431	Feb/14/2020 00:33UTC+8	maxwill	C - Ayoub's function	PyPy 3	Time limit exceeded on pretest 2	1000 ms	8900 KB
71006097	Feb/14/2020 00:30UTC+8	maxwill	C - Ayoub's function	PyPy 3	Wrong answer on pretest 1	155 ms	400 KB
71005284	Feb/14/2020 00:28UTC+8	maxwill	C - Ayoub's function	PyPy 3	Runtime error on pretest 1	233 ms	2200 KB
70993002	Feb/13/2020 23:49UTC+8	maxwill	B - Motarack's Birthday	GNU C++17	Accepted	140 ms	1800 KB
70988144	Feb/13/2020 23:35UTC+8	maxwill	B - Motarack's Birthday	GNU C++17	Wrong answer on pretest 2	46 ms	900 KB
70988009	Feb/13/2020 23:34UTC+8	maxwill	B - Motarack's Birthday	GNU C++17	Wrong answer on pretest 2	31 ms	900 KB
70987379	Feb/13/2020 23:32UTC+8	maxwill	B - Motarack's Birthday	GNU C++17	Wrong answer on pretest 2	77 ms	900 KB
70985951	Feb/13/2020 23:28UTC+8	maxwill	B - Motarack's Birthday	GNU C++17	Wrong answer on pretest 2	61 ms	800 KB
70981709	Feb/13/2020 23:17UTC+8	maxwill	B - Motarack's Birthday	GNU C++17	Wrong answer on pretest 2	61 ms	200 KB
70963551	Feb/13/2020 22:38UTC+8	maxwill	A - Three Strings	GNU C++17	Accepted	31 ms	100 KB

after
71014637	Feb/14/2020 02:16UTC+8	maxwill	C - Ayoub's function	Python 3	Accepted	577 ms	700 KB
71014592	Feb/14/2020 02:16UTC+8	maxwill	C - Ayoub's function	Python 3	Compilation error	0 ms	0 KB
71014426	Feb/14/2020 02:13UTC+8	maxwill	C - Ayoub's function	Python 3	Time limit exceeded on test 2	1000 ms	0 KB
71013138	Feb/14/2020 01:57UTC+8	maxwill	C - Ayoub's function	Python 3	Time limit exceeded on test 2	1000 ms	400 KB
71013019	Feb/14/2020 01:56UTC+8	maxwill	C - Ayoub's function	Python 3	Time limit exceeded on test 2	1000 ms	400 KB
71012894	Feb/14/2020 01:54UTC+8	maxwill	D - Time to Run	Python 3	Runtime error on test 1	109 ms	400 KB
71012808	Feb/14/2020 01:53UTC+8	maxwill	C - Ayoub's function	Python 3	Time limit exceeded on test 2	1000 ms	400 KB
71012777	Feb/14/2020 01:53UTC+8	maxwill	C - Ayoub's function	GNU C++17	Compilation error	0 ms	0 KB
71012573	Feb/14/2020 01:51UTC+8	maxwill	C - Ayoub's function	GNU C++17	Accepted	405 ms	0 KB
71012548	Feb/14/2020 01:51UTC+8	maxwill	C - Ayoub's function	PyPy 3	Compilation error	0 ms	0 KB
"""
