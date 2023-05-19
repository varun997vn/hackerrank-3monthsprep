#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumPerimeterTriangle' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY sticks as parameter.
 */

vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    int s1=0, s2=0, s3=0; 
    long long maxper=0;
    sort(sticks.begin(), sticks.end(), greater<int>());
    int n=sticks.size();
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                if (((long long)sticks[i] + (long long)sticks[j] + (long long)sticks[k] > maxper) and 
                    // valid triangle
                    (sticks[i] < sticks[j] + sticks[k]) and
                    (sticks[j] < sticks[i] + sticks[k]) and
                    (sticks[k] < sticks[i] + sticks[j])\
                ) {
                    maxper = sticks[i] + sticks[j] + sticks[k];
                    s1 = sticks[i];
                    s2 = sticks[j];
                    s3 = sticks[k];
                }
            }
        }
    }
    if (s1==0 and s2==0 and s3==0) {
        return vector<int> {-1};
    }
    return vector<int> {s3, s2, s1};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string sticks_temp_temp;
    getline(cin, sticks_temp_temp);

    vector<string> sticks_temp = split(rtrim(sticks_temp_temp));

    vector<int> sticks(n);

    for (int i = 0; i < n; i++) {
        int sticks_item = stoi(sticks_temp[i]);

        sticks[i] = sticks_item;
    }

    vector<int> result = maximumPerimeterTriangle(sticks);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
