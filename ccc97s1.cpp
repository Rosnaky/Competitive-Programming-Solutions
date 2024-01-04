#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<string> sentences;

    for (int i = 0; i < n; i++) {
        int s, v, o; cin >> s >> v >> o;

        vector<string> subjects(s);
        vector<string> verbs(v);
        vector<string> objects(o);
        string z;
        getline(cin, z);
        for (int i = 0; i < s; i++) {
            string temp; getline(cin, temp);
            subjects[i] = temp;
        }
        for (int i = 0; i < v; i++) {
            string temp; getline(cin, temp);
            verbs[i] = temp;
        }
        for (int i = 0; i < o; i++) {
            string temp; getline(cin, temp);
            objects[i] = temp;
        }

        for (int i = 0; i < s; i++) {
            for (int j = 0; j < v; j++) {
                for (int k = 0; k < o; k++) {
                    string sentence = subjects[i] + " " + verbs[j] + " " + objects[k] + ".";
                    sentences.push_back(sentence);
                }
            }
        }
    }

    sort(sentences.begin(), sentences.end());
    for (string a : sentences) {
        cout << a << "\n";
    }
}