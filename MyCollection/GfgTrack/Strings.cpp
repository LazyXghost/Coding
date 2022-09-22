#include<bits/stdc++.h>
using namespace std;
// --------- NAIVE AND RABIN KARP ALGORITHM FOR PATTERN SEARCHING ---------
// Naive algo is to compare each substring with each pattern
// Time Complexity - O(mn)

// Rabin karp algo just uses hashing to reduce average time complexity of naive algo.
// Time Complexity - O(mn)
// (p0*d^2 + p1*d^1 + p2*d^0)%primeNumber
// ------------------------------------------------------------------------

// ---------------------------
// !!! STL FIND FUNCTION TAKES LINEAR TIME FOR PATTERN SEARCHING !!!
// To check if two strings are anagram or not we can use map or array of size 26
// -----------------------

// -------- KMP ALGORITHM ------------------
// ----- LPS ARRAY -------
vector<int> LPS(string s){
    vector<int> lps(s.size(), 0);
    int n = s.size();
    int len = 0;
    int i = 1;
    while(i<n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
            // abc d abca  For this s[4] = s[0]
            // 000 0 1.....
            // ?     ^      len = 1
        }
        else{
            if(len == 0){
                // abc d abcefg
                // 000 0 123...
                // ?        ^   len = 0
                lps[i] = 0;
                i++;
                // abc d abcefg
                // 000 0 1230..
                //           ^   len = 1
            }
            else{
                // abc d abca
                // 000 0 123...
                //     ?    ^   len = 3
                len = lps[len-1]; // ==> len = lps[2] => 0 
                // abc d abca
                // 000 0 123...
                // ?        ^   len = 0
            }
        }
    }
    return lps;
}
// -----------------------

vector<int> KMP(string txt, string pat){
    /* 
    When we changes j it basically means sliding pattern over text

=>  [a]aabacdabad _\   aaba[c]dabad
.   [a]bad         /    aba[d]      so now we check lps[3-1] = 1

=>  aaba[c]dabad     aaba[c]dabad     aabac[d]abad    aabacd[a]bad  _\ aabacdabad[]
.      a[b]ad            [a]bad            [a]bad           [a]bad   /       abad[]

    LPS array reduces time complexity to O(n)
    We can slide the pattern over txt atmost n times
    And also changing i n times
    So overall time complexity O(2n) => O(n)
    */
    int n = txt.size(), m = pat.size();
    vector<int> matches, lps = LPS(pat);
    int i = 0, j = 0;
    while(i<n){
        if(txt[i] == pat[j]){i++;j++;}
        if(j == m){matches.push_back(i-m);j = lps[j-1];}
        else if(txt[i] != pat[j])
        {
            if(j == 0) i++;
            else j = lps[j-1];
        }
    }
    return matches;
}
// -----------------------------------------

// ---------------- 
/* Check if two strings are rotations of each other
    s1, s2
    s1 = ABCD
    s2 = CDAB
    We can do pattern searching s2 in s1+s1
    => search CDAB in AB[CDAB]CD
*/ 
// ----------------
