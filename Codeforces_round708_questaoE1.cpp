#include <bits/stdc++.h>

using namespace std;

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
    int n, k, ans = 1;
    cin >> n >> k;
    set<int> st;

    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        for (auto val: st){
            if (compara(x, val)){
                ans++;
                st.clear();
                break;
            }
        }
        st.insert(x);
    }
    return ans;
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