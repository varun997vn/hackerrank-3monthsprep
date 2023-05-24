#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

long findNextPowerOf2(long n) {
    for (int i=0; i<64; i++) {
        if (((long)1)<<i > n) {
            return (long )1 << (i-1);
        } 
    }
    return 1;
}

string counterGame(long n) {
    bool player=0;
    if (n==1) return "Richard";

    while (n > 1) {
        if ((n&(n-1)) == 0) {
            n = n/2;
        }
        else {
            long pow2 = findNextPowerOf2(n);
            n = n-pow2;
            cout << "new n*" << n << "\n";
        }
        if (n == 1) {
            break;
        }
        player = !player;
    }

    return (player) ? "Richard": "Louise";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        unsigned long n = stoll(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
