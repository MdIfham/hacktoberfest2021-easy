#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    system("cls");
    ios_base::sync_with_stdio(false);    cin.tie(nullptr);     cout.tie(nullptr);
    int tt; cin >> tt;
    int c = 1;
    while (tt--) {
        int n;
        cin >> n;
        vector<char> pass;
        char ch;
        int f = 0, u = 0, l = 0, d = 0, s = 0;

        if (n >= 7) f = 1;
        for (int i = 0;i < n;i++) {
            cin >> ch;
            pass.push_back(ch);

            if (ch >= 65 && ch <= 90) u++;
            else if (ch >= 97 && ch <= 122) l++;
            else if (ch >= 48 && ch <= 57) d++;
            else if (ch == '#' || ch == '@' || ch == '*' || ch == '&') s++;
        }

        if (u == 0) pass.push_back('A');
        if (l == 0) pass.push_back('a');
        if (d == 0) pass.push_back('1');
        if (s == 0) pass.push_back('@');

        while (pass.size() < 7) {
            pass.push_back('i');
        }

        cout << "Case #" << c++ << ": ";
        for (auto it : pass) {
            cout << it;
        }
        cout << "\n";
    }
    return 0;
}