#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int rope_length[] {1,2,3,4,5};
    int n=sizeof(rope_length)/sizeof(int);

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0;i<n;i++) {
        pq.push(rope_length[i]);
    }

    int cost=0;
    while(pq.size() > 1) {
        int min_len1=pq.top();
        pq.pop();
        int min_len2=pq.top();
        pq.pop();
        int len=min_len1+min_len2;
        cost+=len;
        pq.push(len);
    }

    cout << "Minimum cost possible : " << cost << "\n";

    cout<<endl;
    return 0;
}
