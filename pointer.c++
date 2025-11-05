
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n= 5;
    cout<<&n<<endl;
    int *ptr= &n;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;

    int* ptr2 = &n;
    ptr2++;
    cout<<ptr2<<endl;
    cout<<*ptr2<<endl;
    

    return 0;
}