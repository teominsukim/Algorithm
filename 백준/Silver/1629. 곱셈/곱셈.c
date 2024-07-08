#include <stdio.h>
#include <stdlib.h>

long long divide(long long b,long long a,long long mod){
  if (b == 0)
    return 1;
  if (b == 1)
    return a%mod;
  if (b == 2)
    return (a * a) % mod;

  long long k;
  k = divide(b/2,a,mod) % mod;
  if(b % 2 == 0)
    return (k * k) % mod;
  else
    return ((k * k % mod) * a) % mod;
}

int main(){
  long long a, b, mod;
  scanf("%lld %lld %lld", &a, &b, &mod);
  printf("%lld",divide(b,a,mod));
  
}