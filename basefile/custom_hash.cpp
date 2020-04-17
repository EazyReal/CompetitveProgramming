// https://codeforces.com/blog/entry/62393

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

signed main()
{
    unordered_map<long long, int, custom_hash> safe_map;
    gp_hash_table<long long, int, custom_hash> safe_hash_table;

    unordered_map<string, int>unordered_dict;  
    unordered_dict.insert(pair<string, int>("apple", 2));  
    unordered_dict.insert(unordered_map<string, int>::value_type("orange", 3));  
    unordered_dict["banana"] = 10;  
}