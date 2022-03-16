/*
    피보나치 수 6
    입력이 1e18까지 있다. long long 으로 받아야 하고
    O(sqrt(N))보다 작은 시간복잡도를 사용해야한다.
    찾아보니 도가뉴의 항등식으로 분할정복같은 dp를 하는것 같다.
    
    도가뉴의 항등식이란?
    피보나치의 n번째 수를 F(n)이라고 할때,
    F(m+n) = F(m-1)*F(n) + F(m)*F(n+1)
    위 식이 성립하는데 이를 도가뉴의 항등식이라고 한다.
    m+n = 2k 일때, f(2k) = f(k)*( f(k-1) + f(k+1))
    m+n = 2k+1일때, f(2k+1) = f(k+1)**2 + f(k)**2
    
    메모이제이션을 해야할거같은데 배열은 사용못하므로
    map을 사용해야한다.
*/
#include <iostream>
#include <map>
using namespace std;
#define mod 1000000007
map <long long, long long> dp;
long long fibo(long long n) {
    if (dp.find(n) != dp.end()) return dp[n];
    long long ret;
    if (n%2 == 0) ret = ((fibo(n/2)%mod) * (((fibo(n/2-1)%mod) + (fibo(n/2+1)%mod)%mod)))%mod;
    else ret = ((((fibo(n/2)%mod)*(fibo(n/2)%mod))%mod) + (((fibo(n/2+1)%mod)*(fibo(n/2+1)%mod))%mod))%mod;
    dp.insert({n,ret});
    return ret;
}
int main() {
    long long N;
    cin >> N;
    dp.insert({0,0});
    dp.insert({1,1});
    dp.insert({2,1});
    dp.insert({3,2});
    cout << fibo(N);
    return 0;
}