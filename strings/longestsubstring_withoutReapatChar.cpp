#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string &s)
{

    int n = s.length();
    int maxLength = 0;
    int start = 0;

    map<char, int> m;

    for (int i = 0; i < n; i++) {
        if (m.find(s[i]) != m.end() && start <= m[s[i]])
         {
            start = m[s[i]] + 1;
        } 
        else 
        {
            maxLength = max(maxLength, i - start + 1);
        }
        m[s[i]] = i; 
    }

    return maxLength;
}

int main()
{
    string s1="abcdedsabcfs";
    cout << "Length of the longest substring without repeating characters is: "<< longestSubstring(s1) << endl;

    string s2="bbbbb";
    cout << "Length of the longest substring without repeating characters is: " << longestSubstring(s2) << endl;
    return 0;
}