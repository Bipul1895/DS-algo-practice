#include <iostream>
#include <string>
#include <algorithm>
#include<cstring>
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
        return memo[len1][len2];
    } else {
        int lcs1=LCS_Memo(str1,str2,len1,len2-1);
        int lcs2=LCS_Memo(str1,str2,len1-1,len2);
        return memo[len1][len2]=max(lcs1,lcs2);
    }
}

int main()
{
    string str1 ("bcacaaab"), str2 ("bbabaccc");
    int len1=str1.length(), len2=str2.length();
    memset(memo,-1,sizeof(memo));

    cout << "Length of lcs : "<< LCS_Memo(str1,str2,len1,len2) << "\n";

    cout << "Longest common substring is : ";

    int i=len1,j=len2;
    string lcs;
    while(i>0 && j>0) {
        if(str1[i-1] == str2[j-1]) {
            lcs.push_back(str1[i-1]);
            i--;j--;
        } else {
            if(memo[i-1][j] >= memo[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    i=len1;
    j=len2;
    string scss;
    while(i>0 && j>0) {
        if(str1[i-1] == str2[j-1]) {
            scss.push_back(str1[i-1]);
            i--;j--;
        } else {
            if(memo[i-1][j] >= memo[i][j-1]) {
                scss.push_back(str1[i-1]);
                i--;
            } else {
                scss.push_back(str2[j-1]);
                j--;
            }
        }
    }
    while(i>0) {
        scss.push_back(str1[i-1]);
        i--;
    }
    while(j>0) {
        scss.push_back(str2[j-1]);
        j--;
    }

    reverse(lcs.begin(), lcs.end());
    reverse(scss.begin(), scss.end());
    cout << "Longest common subsequence : " << lcs << "\n";
    cout << "Shortest common supersequence : " << scss << "\n";
    cout << scss.length() << "  " << len1+len2-lcs.length() << "\n";

    cout<<endl;
    return 0;
}
