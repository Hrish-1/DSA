#include<bits/stdc++.h>
using namespace std;
int main(){
    map<char,int> m;
    set<char> s;
    string str;
    cin>>str;
    for(int i = 0; i < str.length(); i++){
        m[str[i]]++;
        if(m[str[i]] > 1){
            s.insert(str[i]);
        }
    }
    set<char>::iterator it;
    for(it = s.begin(); it!=s.end();it++){
        cout<<*it;
    }
return 0;
}
