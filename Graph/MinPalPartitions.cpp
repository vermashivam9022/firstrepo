#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int MinPalPartitions(string s) {
    int n = s.length();
    
    // Create a 2D array to check if s[i:j+1] is a palindrome
    bool isPalindrome[n][n];
    memset(isPalindrome, 0, sizeof(isPalindrome));
    
    // All single characters are palindromes
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
    }
    
    // Check for palindromes of length 2 and greater
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && (len == 2 || isPalindrome[i + 1][j - 1])) {
                isPalindrome[i][j] = true;
            }
        }
    }

    // Create a DP array to store the minimum palindromic partitions
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = i; // Initialize with the worst case (i partitions)
    }
    
    // Fill the DP table with the minimum partitions needed
    for (int i = 1; i < n; i++) {
        if (isPalindrome[0][i]) {
            dp[i] = 0; // No partition needed if s[0:i+1] is a palindrome
        } else {
            for (int j = 0; j < i; j++) {
                if (isPalindrome[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    
    // The answer will be stored in dp[n-1]
    return dp[n-1];
}

int main() {
    string s = "bobseesanna";
    cout << "Minimum Palindromic Partitions: " << MinPalPartitions(s) << endl;
    return 0;
}
