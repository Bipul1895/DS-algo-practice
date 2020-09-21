#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int memo[1001][1001];

int LCS_Memo(string& str1, string& str2, int len1, int len2) {
    //base condition
    if(len1==0 || len2==0) return 0;

    //memoization step
    if(memo[len1][len2] != -1) return memo[len1][len2];

    //choice diagram
    if(str1[len1-1] == str2[len2-1]) {
        memo[len1][len2]=1 + LCS_Memo(str1,str2,len1-1,len2-1);

    } else {
        int lcs1=LCS_Memo(str1,str2,len1,len2-1);
        int lcs2=LCS_Memo(str1,str2,len1-1,len2);
        memo[len1][len2]=max(lcs1,lcs2);
    }
    return memo[len1][len2];
}

int main()
{
    string str1 ("heap");
    string str2 ("pea");
    memset(memo,-1,sizeof(memo));

    int len_lcs=LCS_Memo(str1,str2,str1.length(),str2.length());

    cout << "Min no of ins and del : " << str1.length() + str2.length() - 2*len_lcs << "\n";

    cout << endl;
    return 0;
}
