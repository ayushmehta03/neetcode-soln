#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;




vector<vector<string>>groupAnagrams(vector<string>&strs){
    // 2d vector for stroing the groups which match
    vector<vector<string>>ans;
    // unordered-map for storing the same type
    unordered_map<string,vector<string>>mp;
    for(auto &str:strs){
        string word=str;
        // sort the word what this will do is 
        // suppose we have eat and ate so for both sorted order will be aet

        sort(str.begin(),str.end());
        
        // now aet will contain ->eat and ate both

        mp[str].push_back(word);

    }

    // iterate through the map and push it to 2d vector answer
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