
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution
{
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        int s = servers.size();
        vector<int> time(s, 0);
        auto cmp = [&](int &l, int &r)
        {
            return bool(make_tuple(time[l], servers[l], l) > make_tuple(time[r], servers[r], r));
        };
        auto cmp2 = [&](int &l, int &r)
        {
            return bool(make_tuple(servers[l], l) > make_tuple(servers[r], r));
        };
        priority_queue<int, vector<int>, decltype(cmp)> busy_servers;
        priority_queue<int, vector<int>, decltype(cmp2)> idle_servers;

        for (int i = 0; i < s; ++i)
        {
            idle_servers.push(i);
        }

        int t = tasks.size();
        vector<int> ans(t);
        for (int i = 0; i < t; ++i)
        {
            while (!busy_servers.empty() && time[busy_servers.top()] <= i)
            {
                idle_servers.push(busy_servers.top());
                busy_servers.pop();
            }
            if (idle_servers.empty())
            {
                int u = busy_servers.top(); // busy_servers cannot be empty here
                busy_servers.pop();
                ans[i] = u;
                time[u] += tasks[i];
                busy_servers.push(u);
            }
            else
            { //  idle_servers cannot be empty here
                int u = idle_servers.top();
                ans[i] = u;
                idle_servers.pop();
                time[u] = i + tasks[i];
                busy_servers.push(u);
            }
        }
        return ans;
    }
};