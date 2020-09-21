#include <iostream>

using namespace std;


void TOH(int N, int src_rod, int dest_rod, int aux_rod) {
    if(N==0) return;

    TOH(N-1, src_rod, aux_rod, dest_rod);

    cout << "Move disk : " << N << " from tower " << src_rod << " to " << dest_rod << "\n";

    TOH(N-1, aux_rod, dest_rod, src_rod);

}

void TOH(int N, int src, int dest) {
    if(N==0) return;

    if(src==1 && dest==3) TOH(N-1,src,2);
    else if(src==1 && dest==2) TOH(N-1,src,3);
    else if(src==2 && dest==3) TOH(N-1,src,1);
    else if(src==2 && dest==1) TOH(N-1,src,3);
    else if(src==3 && dest==1) TOH(N-1,src,2);
    else if(src==3 && dest==2) TOH(N-1,src,1);

    cout << "Move disk : " << N << " from tower " << src << " to " << dest << "\n";

    if(src==1 && dest==3) TOH(N-1,2,dest);
    else if(src==1 && dest==2) TOH(N-1,3,dest);
    else if(src==2 && dest==3) TOH(N-1,1,dest);
    else if(src==2 && dest==1) TOH(N-1,3,dest);
    else if(src==3 && dest==1) TOH(N-1,2,dest);
    else if(src==3 && dest==2) TOH(N-1,1,dest);

}

int main()
{
    int N;
    cout << "Enter number of disks : ";
    cin>>N;

    TOH(N,1,3,2);

    cout << endl;
    return 0;
}
