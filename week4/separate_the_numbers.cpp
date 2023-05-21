#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

bool find(string s1, string s2) {
    if (s1.length() > s2.length()) return false;
    int l = s1.length();
    for (int i=0; i<l; i++) {
        if(s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

string addOne(string s) {
    reverse(s.begin(), s.end());
    bool added = false;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '9') {
            s[i] = '0';
        }
        else {
            s[i] = s[i]+1;
            added = true;
            break;
        }
    }
    if (!added) {
        s += "1";
    }
    
    reverse(s.begin(), s.end());
    //cout << "add 1 string: "<< s << "\n";
    return s;
}

bool match(string s1, string s2) {
    //cout << "s1: " << s1 << " s2: " << s2 << "\n";
    if (s1.length() > 0 and s1[0] == '0') return false;
    if (s2.length() > 0 and s2[0] == '0') return false;
    if (s2 == "") {
        //cout << "returning true\n";
        return true;
    }
    string a1 = addOne(s1);
    if (find(a1, s2)) { //s2.rfind(a1) == 0) {
        //cout << "here";
        return match(a1, s2.substr(a1.length()));
    }
    /*else {
        cout << "couldnt find " << a1 << " in " << s2 << "\n";
    }*/
    return false;
}
 
void separateNumbers(string s) {
    for (int i=1; i<=s.length()-1; i++) {
        //cout << i << "\n";
        if (match(s.substr(0, i), s.substr(i))) {
            cout << "YES "<< s.substr(0, i) << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
