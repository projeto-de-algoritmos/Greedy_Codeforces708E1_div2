#include <bits/stdc++.h>

using namespace std;

vector<int> primos;

bool compara(int a, int b){
    int tmp = sqrt(a*b);
    return (tmp*tmp == a*b);
}

int calc(int x){
    int div = 2, ans = 1, cnt;
    while (x > 1){
        cnt = 0;
        while (x % div == 0 ) cnt++, x /= div;
        if (cnt % 2 == 1) ans *= div;
        div++;
    }
    return ans;
}

int solve(){
    int n, k, ans = 1, vs[1000000];
    cin >> n >> k;
    set<int> st;

    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        x = calc(x);
        if (vs[x] == ans){
            ans++;
        }
        vs[x] = ans;
    }
    return ans;
}

void init(){
    bitset<10000> is_prime;
    is_prime.set();

    for (int i=2; i<10000; i++){
        if (is_prime[i]){
            primos.push_back(i);
            for (int j=i+i; j<10000; j+=i){
                is_prime[j] = 0;
            }
        }
    }
}

int main(){
    int tt;
    cin >> tt;

    while (tt--){
        auto ans = solve();
        cout << ans << endl;
    }

    return 0;
}