#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define MAXN 100

inline ll qpow(ll a, ll r){
// Passed
  ll ans = 1, base = a;
  while(r){
    if(r&1)
      ans = ans * base;
    base = base * base;
    r >>= 1;
  }
  return ans;
}

inline ll gcd(ll a, ll b){
// Passed
  return b?gcd(b, a%b):a;
}

inline ll exgcd(ull l, ull r, ll &x, ll &y){
// Passed 返回值 == gcd(l, r)
// x, y打死不能用ull
  if(r){
    ll d = exgcd(r, l%r, y, x);
    y -= l/r*x;
    return d;
  }else{
    x = 1;
    y = 0;
    return l;
  }
}

ll modInv(ll a, ll m){
// Passed
  ll x, y;
  if(exgcd(a, m, x, y) == 1)
    return (x%m+m)%m;
  return -1;
}

bool check(long x){
  if(x >= 10)
    return true;
  return false;
}

long binarySearch(long s, long e){
// Passed
// [, )
  long l = s, r = e, mid, ans = 0;
  while(l<r){
    mid = (l+r)>>1;
    if(check(mid)){
      ans = mid;
      l = mid + 1;
    }else{
      r = mid;
    }
  }
  return ans;
}

long BIT[MAXN], n;

void add(long pos, long value){
  while(pos <= n){
    BIT[pos] += value;
    pos += pos & -pos;
  }
  return;
}

long sum(long pos){
  long cnt = 0;
  while(pos){
    cnt += BIT[pos];
    pos -= pos & -pos;
  }
  return cnt;
}

ll a[MAXN];

struct Node{
  ll sum, lzy;
  Node(ll _sum = 0, ll _lzy = 0){
    sum = _sum; lzy = _lzy;
  }
};

Node sT[4*MAXN];

ll Create(long rt, long l, long r){
  if(l == r)
    return sT[rt].sum = a[l];
  long mid = (l+r)>>1;
  return sT[rt].sum = Create(rt<<1, l, mid) + Create(rt, mid+1, r);
}

void pushDown(long rt, long l, long r){
  if(sT[rt].lzy && (l != r)){
    long mid = (l+r)>>1,
    lLen = (mid)-(l)+1,
    rLen = (r)-(mid+1)+1;
    sT[rt<<1].lzy += sT[rt].lzy;
    sT[rt<<1|1].lzy += sT[rt].lzy;
    sT[rt<<1].sum += sT[rt].lzy * lLen;
    sT[rt<<1|1].sum += sT[rt].lzy * rLen;
    sT[rt].lzy = 0;
  }
  return;
}

void add(long rt, long l, long r, long s, long e, long v){
  // s, l, r, e
  if((s <= l) && (r <= e)){
    long len = r-l+1;
    sT[rt].lzy += v;
    sT[rt].sum += v * len;
    return;
  }
  pushDown(rt, l, r);
  long mid = (l+r)>>1;
  if(s <= mid) add(rt<<1, l, mid, s, e, v);
  if(mid+1 <= e) add(rt<<1|1, mid+1, r, s, e, v);
  sT[rt].sum = sT[rt<<1].sum + sT[rt<<1|1].sum;
  return;
}

ll query(long rt, long l, long r, long s, long e){
  if((s <= l) && (r <= e))
    return sT[rt].sum;
  pushDown(rt, l, r);
  long mid = (l+r)>>1;
  ll cnt = 0;
  if(s <= mid) cnt += query(rt<<1, l, mid, s, e);
  if(mid+1 <= e) cnt += query(rt<<1|1, mid+1, r, s, e);
  return cnt;
}

long par[MAXN];

long Find(long a){
  if(par[a] == a) return a;
  return par[a] = Find(par[a]);
}

void Join(long x, long y){
  par[Find(x)] = Find(y);
  return;
}

struct dNode{
  long v, w;
  dNode(long no = 0, long weight = 0){
   v = no; w = weight;
  }
  bool operator< (const dNode &b) const {
    return w > b.w;
  }
};

vector<dNode> Edge[MAXN];
long dist[MAXN];
bool vis[MAXN];
priority_queue<dNode, vector<dNode> > q;

void dijkstra(){
  long s = 1;
  dist[s] = 0;
  q.push(dNode(s, 0));
  for(long i = 1; i <= n; i++){
    if(q.empty())
      continue;
    long pos;
    do{
      pos = q.top().v;
      q.pop();
    }while((vis[pos]) && (!q.empty()));
    vis[pos] = true;
    for(unsigned long i = 0; i < Edge[pos].size(); i++){
      long v = Edge[pos][i].v, w = Edge[pos][i].w;
      if((!vis[v]) && (dist[v] > w + dist[pos])){
        dist[v] = w + dist[pos];
        q.push(dNode(v, dist[v]));
      }
    }
  }

  return;
}

int main(){

  return 0;

}
