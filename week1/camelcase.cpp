#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    string s,output;
    while(getline(cin,s)){
        s.erase(remove(s.begin(), s.end(), '\r'), s.end());
        output="";
        char opr = s[0], typ = s[2];
        for(int i = 4; i<s.size();i++) {
            if(opr=='C'){
                if(i==4 && typ =='C'){
                    output+=toupper(s[i]);
                    continue;
                }
                if(s[i]==' ') continue;
                if(i!=4 && s[i-1]==' '){
                    output+=toupper(s[i]);
                    continue;                    
                }
                output+=s[i];
            } else {
                if(s[i]=='(') break;
                if(isupper(s[i]) && i!=4){
                    output+=" ";
                    output+=(char)(s[i]+32);
                    continue;
                }
                if(typ=='C' && i==4){
                    output+=(char)(s[i]+32);
                    continue;
                }
                output+=s[i];
            }
        }
        if(opr=='C' && typ=='M'){
            cout<<output+"()"<<endl;
        } else {
            cout<<output<<endl;
        }
    } 
    return 0;
}
