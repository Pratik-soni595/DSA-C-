#include <iostream>
#include <vector>

using namespace std;
void keypadCombinations(string st, string ans = "", int position = 0){
    int length = st.length();
    if(position == length) {
        cout<<ans<<endl;
        return;
    }
    vector<vector<char>> mapping = {
        {},
        {},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };
    
    vector<char> letters = mapping[st[position]-'0'];

    for(int i=0; i<letters.size(); i++){
        keypadCombinations(st, ans+letters[i], position+1);
    }
    
}

int main(){
    string st = "98";
    keypadCombinations(st);
}