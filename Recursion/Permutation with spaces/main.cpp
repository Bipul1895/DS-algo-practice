#include <iostream>
#include <string>
using namespace std;

void print_string(string& str) {
    for(char& ch:str) cout << ch ;
    cout<<"\n";
}

void permute_spaces(string& str, string& ans, int idx) {
    if(idx == str.length()-1) {
        ans.push_back(str[idx]);

        print_string(ans);

        ans.pop_back();

        return;
    }

    ans.push_back(str[idx]);

    permute_spaces(str,ans,idx+1);

    ans.push_back(' ');

    permute_spaces(str,ans,idx+1);

    ans.pop_back();
    ans.pop_back();

}

int main()
{
    string str, ans;
    cin>>str;
    permute_spaces(str,ans,0);

    cout << endl;
    return 0;
}
