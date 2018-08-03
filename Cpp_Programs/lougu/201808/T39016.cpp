#include <bits/stdc++.h>

using namespace std;

long n, m, seed;

int a[123456] = {0};

void generate_array(int a[], int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 0; i < n; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a[i] = x % m + 1;
    }
}

int main(){

  scanf("%ld %ld %ld", &n, &m, &seed);
  generate_array(a, n, m, seed);
  sort(a, a + n);
  return 0;

}
