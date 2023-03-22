//a to the power n using devide and conqure
#include <iostream>
using namespace std;

int power(int a ,int n){
    
    //base case
    if(n==1)    return a;

    int i = power(a , n/2);
    if(n%2 == 0){
        return i*i;
    }
    else{
        return a*i*i;
    }
}

int main()
{
  
    int a,n;
    // cout<<"Enter a :"<<endl;
    // cin>>a;
    // cout<<"Enter n :"<<endl;
    // cin>>n;
    // cout<<a<<" to the power "<<n<<" is : "<<power(a,n)<<endl;
    int ans = power(2,5);
    cout<<ans;
    return 0;
}
