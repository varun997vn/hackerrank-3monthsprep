#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

/*
This is an inefficient solution that treats the numbers like strings.
string add(string s1, char s2) {
    reverse(s1.begin(), s1.end());
    int carry = 0;
    for (int i=0; i<s1.length(); i++) {
        if (s1[i]-'0' + s2-'0' + carry > 9)  {
            //cout << s1[i]-'0' << "  " << s2-'0' << " " << carry << "\n";
            //cout << s1[i]-'0' + s2-'0' + carry -10 + '0' << "\n";
            s1[i] = char(s1[i]-'0' + s2-'0' + carry - 10 + '0');
            //cout << s1[i] << "**\n";
            carry = 1;
            s2='0';
        }
        else {
            s1[i] = char(s1[i]-'0' + s2-'0' + carry + '0');
            carry = 0;
            break;
        }
    }
    if (carry != 0) {
        s1+="1";
    }
    reverse(s1.begin(), s1.end());
    return s1;
}

string addDigits(string s) {
    string sum="0";
    for (int i=0; i<s.length(); i++) {
        //cout << "Adding " << s[i] << "\n";
        sum=add(sum, s[i]);
        //cout << "Sum: " << sum << "\n";
    }
    if (sum.length() == 1) {
        return sum;
    }
    return addDigits(sum);
}*/

int addDigits(string s) {
    int sum = 0;
    for (auto c: s) {
        sum+=(c-'0');
    }
    if (sum <= 9)
        return sum;
    return addDigits(to_string(sum));
}

int superDigit(string n, int k) {
    /*string p="";
    for (int i=0; i<k; i++) {
        p+=n;
    }
    return stoi(addDigits(p));*/
    int sum = addDigits(n);
    if (sum*k > 9) {
        return addDigits(to_string(sum*k));
    }
    return sum*k;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
