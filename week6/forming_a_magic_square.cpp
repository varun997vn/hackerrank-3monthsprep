#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */
void getAllSquares(int i, vector<vector<int>>& ans, vector<int>& sq, vector<int>& map) {
    for (int j=1; j<=9; j++) {
        if (map[j] == 0) {
            map[j] = 1;
            sq[i] = j;
            if (i==8) {
                ans.push_back(sq);
            }
            else{
                getAllSquares(i+1, ans, sq, map);
            }
            map[j] = 0;
        }
    }

}

bool isMagicSquare(vector<int>& sq) {
    int k = 0;
    vector<vector<int>> matrix (3, vector<int>(3, 0));
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            matrix[i][j] = sq[k++];
        }
    }

    for (auto row: matrix) {
        if (15 != accumulate(row.begin(), row.end(), 0)) {
            return false;
        }
    }

    for (int i=0; i<3; i++) {
        if (matrix[0][i] + matrix[1][i] + matrix[2][i] != 15) {
            return false;
        }
    }

    if (matrix[0][0] + matrix[1][1] + matrix[2][2] != 15) {
        return false;
    }

    if (matrix[0][2] + matrix[1][1] + matrix[2][0] != 15) {
        return false;
    }

    return true;
}


int getCost(vector<vector<int>>& s, vector<int>& sq) {
    int k = 0;
    vector<vector<int>> matrix (3, vector<int>(3, 0));
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            matrix[i][j] = sq[k++];
        }
    }

    int cost=0;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cost+=abs(s[i][j] - matrix[i][j]);
        }
    }

    return cost;
}

int formingMagicSquare(vector<vector<int>> s) {
    vector<vector<int>> ans;
    vector<int> sq(9, 0);
    vector<int> map(10, 0);
    getAllSquares(0, ans, sq, map);

    vector<vector<int>> magicSquares;
    
    for (auto sq: ans) {
        if (isMagicSquare(sq)) {
            magicSquares.push_back(sq);
        }
    }

    int minCost = INT_MAX;

    for (auto sq: magicSquares) {
        minCost = min(minCost, getCost(s, sq));
    }

    return minCost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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
