#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string ans;
    bool isAM = s.substr(s.length() - 2, 2) == "AM";
    if (isAM and s.substr(0, 2) == "12") {
        ans = "00" + s.substr(2, 6);
    }
    else if (isAM or s.substr(0,2) == "12") {
        ans = s.substr(0, 8);
    }
    else {
        ans = to_string(stoi(s.substr(0, 2)) + 12) + s.substr(2, 6);
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
