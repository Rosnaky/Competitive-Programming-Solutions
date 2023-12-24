#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> tasks;
    for (int i = 0; i < n; i++) {
        int time, deadline;
        cin >> time >> deadline;
        tasks.push_back({time, deadline});
    }

    sort(tasks.begin(), tasks.end());

    long long ans = 0;
    long long time = 0;

    for (pair<int, int>& task : tasks) {
        auto [dur, dead] = task;

        time += dur;
        ans += dead - time;
    }

    cout << ans;
}