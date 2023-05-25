#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> bomberMan(int n, vector<string> grid) {
    /* 
    Observations:
    1. N=0 is initial state, (s0).
    2. N=1 is s1
    3. N=3 is s2. However this starts repeating at N=7, 11 and so on.
    4. N=4=6=8=10 and so on. The whole board is filled with bombs.
    5. N=5 is s3. This starts repeating at N=9, 13, 17 and so on.
    
    Therefore compute only till N=5 and use math formulas for any N
    */
    
    if (n == 1) return grid;

    int rows = grid.size();
    int strl = grid[0].length();
    
    //cout << "rows: " << rows << " cols: " << strl << endl;

    vector<string> s0 = grid; 
    vector<string> s1 = grid; 
    vector<string> s2 = vector<string> (rows, string(strl, 'O')); 
    vector<string> s3 = vector<string> (rows, string(strl, 'O'));
    
    /*cout << "s3 before \n";
    for(auto row: s3) {
        cout << row << "\n";
    }
    
    cout << "****\n";*/

    for (int i=0; i<rows; i++) {
        for (int j=0; j<strl; j++) {
            if (s1[i][j] == 'O') {
                if (i-1 >= 0) {
                    s3[i-1][j] = '.';
                }
                if (i+1 < rows) {
                    s3[i+1][j] = '.';
                }
                if (j-1 >= 0) {
                    s3[i][j-1] = '.';
                }
                if (j+1 < strl) {
                    s3[i][j+1] = '.';
                }
                s3[i][j] = '.';
            }
        }
    }
    
    /*cout << "s3 after \n";
    for(auto row: s3) {
        cout << row << "\n";
    }
    
    cout << "***\n"; */

    vector<string> s4 = vector<string> (rows, string(strl, 'O'));
    vector<string> s5 = vector<string> (rows, string(strl, 'O'));

    for (int i=0; i<rows; i++) {
        for (int j=0; j<strl; j++) {
            if (s3[i][j] == 'O') {
                if (i-1 >= 0) {
                    s5[i-1][j] = '.';
                }
                if (i+1 < rows) {
                    s5[i+1][j] = '.';
                }
                if (j-1 >= 0) {
                    s5[i][j-1] = '.';
                }
                if (j+1 < strl) {
                    s5[i][j+1] = '.';
                }
                s5[i][j] = '.';
            }
        }
    }

    if (n % 2 == 0) {
        return s2;
    }

    if ((n-3) % 4 == 0) {
        // cout << "here\n";
        return s3;
    }

    if ((n-5) % 4 == 0) {
        return s5;
    }

    return s0;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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
