#include <bits/stdc++.h>
using namespace std;

int memo[1001][1001];

int longest_common_substring(int len1, int len2,string& str1, string& str2) {
    for(int i=0;i<=len1;i++) memo[i][0]=0;
    for(int j=1;j<=len2;j++) memo[0][j]=0;

    int lcss=0;
    for(int i=1;i<=len1;i++) {
        for(int j=1;j<=len2;j++) {
            if(str1[i-1] == str2[j-1]) {
                memo[i][j]=1+memo[i-1][j-1];
                lcss=max(lcss, memo[i][j]);
            } else {
                memo[i][j]=0;
            }
        }
    }
    return lcss;
}

string print_lcss(int len1, int len2,string& str1, string& str2) {
    for(int i=0;i<=len1;i++) memo[i][0]=0;
    for(int j=1;j<=len2;j++) memo[0][j]=0;

    string lcss;
    int len_lcss=0;
    int ed_i=0, ed_j=0;
    for(int i=1;i<=len1;i++) {
        for(int j=1;j<=len2;j++) {
            if(str1[i-1] == str2[j-1]) {
                memo[i][j]=1+memo[i-1][j-1];
                if(memo[i][j] > len_lcss) {
                    len_lcss=memo[i][j];
                    ed_i=i;
                    ed_j=j;
                }
            } else {
                memo[i][j]=0;
            }
        }
    }

    while(ed_i>0 && ed_j>0 && str1[ed_i-1]==str2[ed_j-1]) {
        lcss.push_back(str1[ed_i-1]);
        ed_i--;ed_j--;
    }
    return lcss;
}

int LCSS_recursive(int len1, int len2,string& str1, string& str2, int curr_lcss) {
    if(len1==0 || len2==0) return curr_lcss;

    //if(memo[len1][len2] != -1) return memo[len1][len2];

    if(str1[len1-1] == str2[len2-1]) {
        curr_lcss=LCSS_recursive(len1-1,len2-1,str1,str2,curr_lcss+1);
    }
    else {
        curr_lcss=max({curr_lcss,
                    LCSS_recursive(len1,len2-1,str1,str2,0),
                    LCSS_recursive(len1-1,len2,str1,str2,0)});
    }

    cout << "before storing curr : " << curr_lcss << "\n";
    memo[len1][len2]=curr_lcss;

    return curr_lcss;
}

int main()
{
    string str1 ("babad");
    string str2 ("fabcdypqrmn");
    int len1=str1.length(), len2=str2.length();

    for(int i=0;i<=len1;i++) {
        for(int j=0;j<=len2;j++) memo[i][j]=-1;
    }

    //cout << "Length of longest common substring : " << longest_common_substring(len1,len2,str1,str2) << "\n";
    //cout << "Length of longest common substring : " << LCSS_recursive(len1,len2,str1,str2,0) << "\n";

    string S=str1;
    string rev_S=S;
    reverse(rev_S.begin(),rev_S.end());
    cout << "Longest palindromic substring : " << print_lcss(len1,len1,S,rev_S) << "\n";
/*
    for(int i=0;i<=len1;i++) {
        for(int j=0;j<=len2;j++) {
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }
*/

    cout <<endl;
    return 0;
}
