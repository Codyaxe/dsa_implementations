#include <iostream>
#include <queue>

using namespace std;

int main(){

    priority_queue<int> pq;

    pq.push(12);
    pq.push(43);
    pq.push(1);
    int temp = pq.top();

    cout << temp;



    return 0;
};