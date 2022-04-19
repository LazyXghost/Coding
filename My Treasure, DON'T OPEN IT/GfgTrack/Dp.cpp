/* -----------LONGEST SUBSEQUENCE SUM----------------
    ----Memoisation---
    if characters are same then 
        LSS(i,s1,j,s2) = 1 + LSS(i+1, s1, j+1, s2)
        AXYZ __\   A + [XYZ]
        ABAZ   /   A + [BAZ]
    else
        LSS(i,s1,j,s2) = max(LSS(i+1,s1,j,s2), LSS(i,s1,j+1,s2));
        AXYZ __\   [XYZ] , [AXYZ]
        BAZ   /    [BAZ] , [AZ]
    ----------------

    ---Tabulation---
    if characters are same then
        dp[i][j] = 1 + dp[i-1][j-1];
    else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    dp table-:
         - B A Z
        - 0 0 0 0
        A 0 0 1 1
        X 0 0 1 1
        Y 0 0 1 1
        Z 0 0 1 2
    -----------------
 */