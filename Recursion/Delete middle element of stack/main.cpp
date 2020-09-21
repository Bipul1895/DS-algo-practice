#include <iostream>
#include <stack>
using namespace std;

void delete_middle(stack<int>& stk, int n) {
    if(stk.size() == n/2 + 1) {
        stk.pop();
        return;
    }

    int curr=stk.top();
    stk.pop();

    delete_middle(stk,n);
    stk.push(curr);

}

void print_stack(stack<int>& stk) {
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
}

int main()
{
    int n;
    cin>>n;
    stack<int> stk;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        stk.push(num);
    }

    delete_middle(stk, stk.size());

    cout << "Print stack : ";
    print_stack(stk);

    cout << endl;
    return 0;
}
