#include <bits/stdc++.h>

using namespace std;

vector<int> primos;

bool compara(int a, int b){
    int tmp = sqrt(a*b);
    return (tmp*tmp == a*b);
}

int calc(int x){
    int ans = 1, cnt;

    for (auto p: primos){
        if (p > x) break;
        cnt = 0;
        while (x % p == 0) cnt++, x/=p;
        if (cnt&1) ans*=p;
    }
    ans *= x;
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
    primos.push_back(2);

    for (int i=3; i<10000; i+=2){
        if (is_prime[i]){
            primos.push_back(i);
            for (int j=3*i; j<10000; j+=2*i){
                is_prime[j] = 0;
            }
        }
    }
}

int main(){
    int tt;
    cin >> tt;

    init();

    while (tt--){
        auto ans = solve();
        cout << ans << endl;
    }

    return 0;
}