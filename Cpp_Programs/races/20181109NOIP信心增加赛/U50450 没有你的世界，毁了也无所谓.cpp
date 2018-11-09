#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000008
#define  ll long long
const ll MOD = 11111597780929;
struct Node{
  ll sum, lzy;
  inline Node(ll _sum = 0, ll _lazy = 0){
    sum = _sum; lzy = _lazy;
  }
};
long n, m;
ll a[MAXN];
Node sT[4*MAXN];
/*
inline ll gcd(ll a, ll b){
  return b?gcd(b, a%b):a;
}
*/
ll exgcd(ll l, ll r, ll &x, ll &y){
  if(r == 0){
    x = 1;
    y = 0;
    return l;
  }else{
    ll d = exgcd(r,l%r,y,x);
    y -= l/r*x;
    return d;
  }
}

ll mod_inverse(ll a, ll m){
  ll x, y;
  if(exgcd(a, m, x, y) == 1)
    return (x%m+m)%m;
  return -1;
}

inline ll mmp(const ll a, const ll b){
  return ((a % MOD) + (b % MOD)) % MOD;
}

inline ll mmm(const ll a, const ll b){
  return ((a % MOD) * (b % MOD)) % MOD;
}

ll Create(long rt, long l, long r){ // 返回 ll
  if(l == r)
    return sT[rt].sum = a[l] % MOD;
  long mid = (l+r)>>1;
  return sT[rt].sum = mmp(Create(rt<<1, l, mid), Create(rt<<1|1, mid+1, r));
}

inline void pushDown(long rt, long l, long r){
  if((sT[rt].lzy)&&(l != r)){ // 有lazy标记
    long mid = (l+r)>>1,
    lLen = mid-l+1,
    rLen = r-(mid+1)+1;
    sT[rt<<1].lzy = mmp(sT[rt].lzy, sT[rt<<1].lzy);
    sT[rt<<1|1].lzy = mmp(sT[rt].lzy, sT[rt<<1|1].lzy);
    sT[rt<<1].sum = mmp(sT[rt<<1].sum, mmm(sT[rt].lzy, lLen));
    sT[rt<<1|1].sum = mmp(sT[rt<<1|1].sum, mmm(sT[rt].lzy, rLen));
    sT[rt].lzy = 0;
  }
  return;
}

void add(long rt, long l, long r, long b, long e, ll v){
  v %= MOD;
  // b, l, r, e
  if((b <= l)&&(r <= e)){
    long len = r-l+1;
    sT[rt].lzy = mmp(sT[rt].lzy, v);
    sT[rt].sum = mmp(sT[rt].sum, mmm(v, len));
    return;
  }
  pushDown(rt, l, r);
  long mid = (l+r)>>1;
  if(b <= mid) add(rt<<1, l, mid, b, e, v);
  if(mid+1 <= e) add(rt<<1|1, mid+1, r, b, e, v);
  sT[rt].sum = mmp(sT[rt<<1].sum, sT[rt<<1|1].sum);
  return;
}

ll sum(long rt, long l, long r, long b, long e){
  // l, b, e, r
  if((b <= l)&&(r <= e))
    return sT[rt].sum;
  pushDown(rt, l, r);
  ll cnt = 0;
  long mid = (l+r)>>1;
  // b, [l, mid], e
  if(b <= mid) cnt = mmp(sum(rt<<1, l, mid, b, e), cnt);
  // b, [mid+1, r], e
  if(mid+1 <= e) cnt = mmp(sum(rt<<1|1, mid+1, r, b, e), cnt);
  return cnt;
}

inline void add(long l, long r, ll v){
  return add(1, 1, n, l, r, v);
}

inline ll sum(long l, long r){
  return sum(1, 1, n, l, r) % MOD;
}

int main(){

  scanf("%ld%ld", &n, &m);
  for(long i = 1; i <= n; i++)
    scanf("%lld", &a[i]);
  Create(1, 1, n);
  for(long i = 1; i <= m; i++){
    long o, l, r;
    ll x;
    scanf("%ld%ld%ld", &o, &l, &r);
    if(l > r) swap(l, r);
    if(o == 1){
      scanf("%lld", &x);
      add(l, r, x);
    }else if(o == 2){
      long long len = r-l+1,
      lenMI = mod_inverse(len, MOD);
      // cout<<"MI:"<<lenMI<<endl;
      printf("%lld\n", mmm(sum(l, r), lenMI));
    }
  }

  return 0;

}
