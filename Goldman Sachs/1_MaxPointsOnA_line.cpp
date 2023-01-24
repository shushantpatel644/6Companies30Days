#include <bits/stdc++.hh>
using namespace std;
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ans = 1;
        for (int i = 0; i < points.size() - 1; i++)
        {
            unordered_map<double, int> mp;
            for (int j = i + 1; j < points.size(); j++)
            {
                if (points[i][0] == points[j][0])
                {
                    mp[10000001]++;
                }
                else
                {
                    double slope = double(points[j][1] - points[i][1]) /
                                   double(points[i][0] - points[j][0]);
                    mp[slope]++;
                }
            }
            int temp = 0;
            for (auto x : mp)
            {
                temp = max(temp, x.second);
            }
            ans = max(ans, temp + 1);
        }
        return ans;
    }
};




class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        
        for(auto c:s){
            if(st.size() && st.back().first != c){
                st.push_back({c,1});
        }
        else{
            st.back().second++;
        }
        
        if(st.back().second==k){
            st.pop_back();
        }
    }
        string res;
        
        for(auto x:st){
            res.append(x.second,x.first);
        }
        return res;
    }
};