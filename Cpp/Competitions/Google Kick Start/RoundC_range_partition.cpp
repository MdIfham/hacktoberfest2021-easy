#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


void helper(ll ind, vector<ll>& nums, ll sum, ll& alan_sum, vector<ll>& ds, vector<vector<ll>>& res) {

    if (sum == alan_sum) {
        res.push_back(ds);
    }

    if (ind == nums.size() || res.size()>=1) {
        return;
    }

    ds.push_back(nums[ind]);
    helper(ind + 1, nums, sum + nums[ind], alan_sum, ds, res);
    ds.pop_back();
    helper(ind + 1, nums, sum, alan_sum, ds, res);
}

void subsetSums(ll& n, ll& alan_sum, vector<vector<ll>>& res) {
    vector<ll> nums, ds;
    ll sum = 0;
    for (ll i = 1;i <= n;i++) {
        nums.push_back(i);
    }
    helper(0, nums, sum, alan_sum, ds, res);
}

int main() {
    system("cls");
    ios_base::sync_with_stdio(false);    cin.tie(nullptr);     cout.tie(nullptr);
    int tt; cin >> tt;
    int c = 1;
    while (tt--) {
        ll n;
        cin >> n;
        ll x, y;
        cin >> x >> y;

        if ((n * (n + 1) / 2) % (x + y) != 0) {
            cout << "Case #" << c++ << ": " << "IMPOSSIBLE\n";
        }
        else {
            cout << "Case #" << c++ << ": " << "POSSIBLE\n";
            ll alan_sum = x * (n * (n + 1) / 2) / (x + y);
            vector<vector<ll>> ans;
            subsetSums(n, alan_sum, ans);
            cout << ans[0].size() << '\n';
            for (ll i = 0;i < ans[0].size();i++) {
                cout << ans[0][i]<<' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
