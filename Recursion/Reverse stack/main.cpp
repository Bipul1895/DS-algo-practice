#include <iostream>
#include <stack>
#include <string>
using namespace std;

void insert_stack(stack<int>& stk, int ele) {
    if(stk.empty()) {
        stk.push(ele);
        return;
    }

    int curr=stk.top();
    stk.pop();
    insert_stack(stk, ele);
    stk.push(curr);

}

void rev_stack(stack<int>& stk) {
    //base condition
    if(stk.empty()) return;

    //Hypothesis
    int curr=stk.top();
    stk.pop();
    rev_stack(stk);

    //induction
    insert_stack(stk, curr);

}

void print_stack(stack<int> stk) {
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";
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

    print_stack(stk);

    rev_stack(stk);

    print_stack(stk);

    cout << endl;
    return 0;
}
