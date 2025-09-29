#include<iostream>
#include<vector>
using namespace std;


// approcah ->hashmap

// time complexity-> O(n)

// space complexity -> auxilary beacuse O(2*26)

bool check(string &s,string &t){
    if(s.length()!=t.length()) return false;


    // vector for stroing frequence of both the string
    vector<int>freq1(26,0);
    vector<int>freq2(26,0);

    for(int i=0;i<s.length();i++){
        // a-a=0 b-a=1 ->char freq store
        freq1[s[i]-'a']++;
        freq2[t[i]-'a']++;
    }

    // checking frequency int the freq vector
    for(int i=0;i<26;i++){
        if(freq1[i]!=freq2[i]) return false;
    }


    return true;


}

int main(){
    string a;
    cout<<"Enter the first string:  ";
    cin>>a;


     string b;
    cout<<"Enter the second string:  ";
    cin>>b;


    if(check(a,b)) cout<<"Yes both are anagram";
    else cout<<"No they are not anagaram";

    return 0;

}