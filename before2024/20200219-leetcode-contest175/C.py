from collections import defaultdict
import bisect

class TweetCounts(object):
    def __init__(self):
        self.dic = defaultdict(list)


    def recordTweet(self, tweetName, time):
        bisect.insort_left(self.dic[tweetName] ,time)


    def getTweetCountsPerFrequency(self, freq, tweetName, startTime, endTime):
        if tweetName not in self.dic:
            return []
        ret = []
        t = 0
        if freq == 'minute':
            t = 60
        elif freq == 'hour':
            t = 60*60
        else:
            t = 60*60*24

        tl = startTime
        while tl <= endTime:
            tr = min(tl+t-1, endTime)
            l = bisect.bisect_left(self.dic[tweetName], tl)
            r = bisect.bisect_left(self.dic[tweetName], tr)
            v = r - l
            if r < len(self.dic[tweetName]) and self.dic[tweetName][r] == tr : #nxt = endtime
                v += 1
            ret.append(v)
            tl += t

        return ret
