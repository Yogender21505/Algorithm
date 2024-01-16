// if t= AAB
// Then all possible substring that has the AB in string count those string ammong them .
// such that there are 8 posiblities:
// A, B, AA, AB, AAB, ABA, BAA, BA
// so the AB is in {AB, AAB,ABA}



#include <bits/stdc++.h>
using namespace std;

int c = 0;
char PREV_CHAR;

void solve(string t, int &count, int i) {
    count++;
    for (int x = i; x < t.size(); x++) {
        if (x != i && t[x] == t[i]) continue;
        if (x == 0) {
            PREV_CHAR = t[0];
        }
        if (t[x] == 'B' && PREV_CHAR == 'A') c++;
        else { PREV_CHAR = t[x]; }

        swap(t[x], t[i]);
        solve(t, count, i + 1);
    }
}

int main() {
    string t;
    cin >> t;
    sort(t.begin(), t.end());
    int i = 0;
    int count = -1;
    solve(t, count, i);
    cout << c << endl;
    return count;
}
