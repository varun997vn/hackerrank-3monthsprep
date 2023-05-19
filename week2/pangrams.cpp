#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    vector<int> alph (26, 0);
    for (auto c: s) {
        if (tolower(c)-97 >=0 and tolower(c)-97 < 26) {
            alph[tolower(c)-97]++;
        }
    }
    for (auto n: alph) {
        if (n == 0) return "not pangram";
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
