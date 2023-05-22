#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int chars=6, digit=1, lowercase=1, uppercase=1, specialchar=1;
    for (auto c : password) {
        chars--;
        if (isalpha(c) and isupper(c)) uppercase--;
        else if (isalpha(c) and islower(c)) lowercase--;
        else if (isdigit(c)) digit--;
        else if (
            c=='!' or c=='@' or c=='#' or c=='$' or c=='%' or c=='^' or
            c=='&' or c=='*' or c=='(' or c==')' or c=='-' or c=='+'
        ) specialchar--;
    }
    
    int total = 0;
    if (digit > 0) { total+=digit; chars--; }
    if (lowercase > 0) { total+=lowercase; chars--; }
    if (uppercase > 0) { total+=uppercase; chars--; }
    if (specialchar > 0) { total+= specialchar; chars--; }
    
    if (chars > 0) total+=chars;
    
    return total; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
