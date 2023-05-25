#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sumXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long sumXor(long n) {
    /* Dry run the code for 10. Do the calculation n+x and n^x as shown below;
    It is observed that the 1s in n always gets paired with 0s in x and
    the 0s in n gets paired with either 1 or 0 in x.
    Therefore the total no of possibilities = 2**(no of zeros in  n)
    
    10 + 1 = 1010 + 0001 = 1011
    10 ^ 1 = 1010 ^ 0001 = 1011
    Here the 0 (lsb of 10) is paired with 1 (lsb of 1) and rest are 0s.
    Similarly compute the rest. 
    */
    int zeros = 0;
    while (n > 0) {
        if ((n & 1) == 0) {
            zeros++;
        }
        n = n>>1;
    }
    return pow(2, zeros);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

    fout << result << "\n";

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
