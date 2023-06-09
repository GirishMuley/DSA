#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n ;
    cin >> n;
    int m  = n;
    if (n < 0)
    {
        n *= -1;
    }
    float ans = 0 , i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = ans + bit * pow(10, i);
        n = n >> 1;
        i++;
    }
    if(m < 0){
        cout <<"-" << ans << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}