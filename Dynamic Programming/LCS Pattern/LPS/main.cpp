#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int memo[1001][1001];

int LPS(const string& str, int i, int j){
    if(i>j) return 0;
    else if(i==j) return 1;

    if(memo[i][j] != -1) return memo[i][j];

    if(str[i]==str[j]) return memo[i][j]=2 + LPS(str,i+1,j-1);
    else return memo[i][j]=max(LPS(str,i,j-1), LPS(str,i+1,j));

}


int main()
{
    //Lps Recursive
    string str;
    cin>>str;
    int len=str.length();
    memset(memo,-1,sizeof(memo));

    cout << "Length of LPS : " << LPS(str,0,len-1) << "\n";

    string lps;

    int i=0,j=len-1;
    while(i<len && j>=0) {
        if(str[i]==str[j]) {
            lps.push_back(str[i]);
            i++;j--;
        }
        else {
            if(memo[i][j-1] >= memo[i+1][j]) {
                j--;
            }
            else {
                i++;
            }
        }
    }

    cout << "LPS string : " << lps << "\n";

    cout << endl;
    return 0;
}
