#include <ctime>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int IA, IB, FA, FB;
    cin >> IA >> IB >> FA >> FB;

    int cnt = 0;
    if((IA != FA) != (IB != FB)) cnt++;
    if((IA != FA) && (IB != FB)) cnt++;

    cout << cnt << endl;
}