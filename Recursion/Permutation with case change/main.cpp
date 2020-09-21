#include <iostream>
#include <string>
using namespace std;

void print_string(string& str) {
    for(char& ch:str) cout << ch ;
    cout<<"\n";
}

void permute_with_case(string& str,string& ans, int idx) {
    if(idx>=str.length()) {
        print_string(ans);
        return;
    }

    ans.push_back(str[idx]);

    permute_with_case(str,ans,idx+1);

    ans.pop_back();
    ans.push_back(char(int(str[idx])-32));

    permute_with_case(str,ans,idx+1);
    ans.pop_back();

}

int main()
{
    string str,ans;
    cin>>str;
    permute_with_case(str,ans,0);


    cout<<endl;
    return 0;
}
