#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gamingArray' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

string gamingArray(vector<int> arr) {
    /* Inefficient Solution
    auto it=arr.end();
    bool player=0; // "BOB";
    // O(N)
    while (it != arr.begin()) {
        // O(N)
        it = max_element(arr.begin(), it);
        if (it == arr.begin()) {
            break;
            }
        player = !player;
    }
    return (player) ? "ANDY" : "BOB";
    */
    
    /* This logic is awesome
    So the idea is that the last player will always end up removing the first element.
    Therefore, we need to see how many maxes can be computed from the beginning.
    For example, [2,3,5,4,1] is an array. The first max is 2, replaced by 3 and then by 5.
    If we count the number of maxes, it is 3. The last max must be removed by the winning player. 
    In this case, 1st max (5) is removed by Bob, 2nd max (3) is removed by Andy and then
    3rd max (2) is removed by Bob. Therefore he wins the game.
    */ 
    int maxElem = INT_MIN;
    int c = 0;
    for (auto& a: arr) {
        if (a > maxElem) {
            maxElem = a;
            c++;
        }
    }
    return (c % 2 == 0) ? "ANDY" : "BOB";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string arr_count_temp;
        getline(cin, arr_count_temp);

        int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(arr_count);

        for (int i = 0; i < arr_count; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = gamingArray(arr);

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
