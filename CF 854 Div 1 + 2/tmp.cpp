#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string solve(string s) {
    // Count the frequency of each character in the string
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Construct the sorted string in non-increasing order
    string sorted_s = "";
    int max_freq = *max_element(freq, freq + 26);
    for (int f = max_freq; f > 0; f--) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= f) {
                sorted_s += string(f, 'a' + i);
            }
        }
    }

    // Construct the string t by taking alternate characters
    string t = "";
    int i = 0, j = sorted_s.size() - 1;
    while (i <= j) {
        if (i == j) {
            t += sorted_s[i];
        } else {
            t += sorted_s[i] + sorted_s[j];
        }
        i++;
        j--;
    }

    // Construct tmax by taking the lexicographically maximum of t and its reverse
    string tmax = max(t, string(t.rbegin(), t.rend()));

    return tmax;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        cin>>s;
        string result = solve(s);

        cout << result << endl;
    }

    return 0;
}
