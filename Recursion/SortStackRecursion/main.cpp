#include <iostream>
#include <stack>
using namespace std;

void insert_into_stack(stack<int>& stk, int top_element) {
    if(stk.empty() || stk.top() < top_element) {
        stk.push(top_element);
        return;
    }
    int curr_top=stk.top();
    stk.pop();
    insert_into_stack(stk, top_element);
    stk.push(curr_top);
}

void sort_stack(stack<int>& stk) {
    if(stk.empty()) return;

    int top_element=stk.top();
    stk.pop();

    sort_stack(stk);

    insert_into_stack(stk,top_element);

}

int main()
{
    stack<int> stk;
    stk.push(4);
    stk.push(1);
    stk.push(3);
    stk.push(2);

    sort_stack(stk);

    //stack is sorted, so printing elements will lead to reverse sort arrangement
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}
