#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;




vector<vector<string>>groupAnagrams(vector<string>&strs){
    vector<vector<string>>ans;
    unordered_map<string,vector<string>>mp;
    for(auto &str:strs){
        string word=str;
        sort(str.begin(),str.end());
        mp[str].push_back(word);

    }
    for(auto it:mp){
        ans.push_back(it.second);
    }

    return ans;


}




int main(){
    vector<string>strs={"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>>ans=groupAnagrams(strs);
    for (const auto &group : ans) {
        for (const auto &word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
    
        

}