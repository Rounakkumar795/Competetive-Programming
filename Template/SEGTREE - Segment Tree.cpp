#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve();
int main() { solve(); }

// range Min
class segTree {
   public:
    ll n;          // size of array
    vector<ll> a;   // 1-index array
    vector<ll> St;  // segTree Storage
    segTree(ll n, vector<ll> a) {
        this->n = n;
        this->a.resize(n + 1, 0);
        for (ll i = 0; i < n; i++) {
            this->a[i + 1] = a[i];
        }
        St.resize(5 * n);
        build(1, 1, n);
    }
    void build(ll Si, ll Ss, ll Se) {
        if (Ss == Se) {
            St[Si] = a[Ss];
            return;
        }
        ll mid = (Ss + Se) >> 1;
        build(2 * Si, Ss, mid);
        build(2 * Si + 1, mid + 1, Se);
        St[Si] = min(St[2 * Si], St[2 * Si + 1]);
    }
    ll query(ll Si, ll Ss, ll Se, ll Qs, ll Qe) {
        if (Qs > Se or Qe < Ss) return 1e15;
        if (Qs <= Ss and Qe >= Se) return St[Si];
        ll mid = (Ss + Se) >> 1;
        ll lSubTree = query(2 * Si, Ss, mid, Qs, Qe);
        ll rSubTree = query(2 * Si + 1, mid + 1, Se, Qs, Qe);
        return min(lSubTree, rSubTree);
    }
    void update(ll Si, ll Ss, ll Se, ll q, ll val) {
        a[q] = val;
        if (Ss == Se) {
            St[Si] = a[Ss];
            return;
        }
        ll mid = (Ss + Se) >> 1;
        if (Ss <= q and q <= mid)
            update(2 * Si, Ss, mid, q, val);
        else
            update(2 * Si + 1, mid + 1, Se, q, val);
        St[Si] = min(St[2 * Si], St[2 * Si + 1]);
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &it : a) cin >> it;

    segTree seg(n, a);

    while (q-- > 0) {
        char c;
        cin >> c;
        ll l, r;
        cin >> l >> r;
        if (c == 'q') {
            cout << seg.query(1, 1, n, l, r) << '\n';
        } else {
            seg.update(1, 1, n, l, r);
        }
    }
}

/*Must Try*/
/*https://codeforces.com/contest/1642/problem/E*/