#include <iostream>
#include <vector>
#include <string>
using namespace std;

void zeros_ones(int N, string& temp, vector<string>& ans, int lev=0, int zeros=0, int ones=0) {
    if(N==lev) {
        ans.push_back(temp);
        return;
    }

    if(ones > zeros) {
        temp.push_back('0');
        zeros_ones(N,temp,ans,lev+1,zeros+1,ones);
        temp.pop_back();
    }

    temp.push_back('1');
    zeros_ones(N,temp,ans,lev+1,zeros,ones+1);
    temp.pop_back();

}

int main()
{
    int N;
    cin>>N;
    string temp;
    vector<string> ans;
    zeros_ones(N,temp,ans);

    cout << "N-bit binary numbers:\n";

    for(string& str:ans) {
        cout << str << "\n";
    }

    cout<<endl;
    return 0;
}
