#include<iostream>
#include<vector>
#include<set>
using namespace std;



int ladderLength(vector<string>&wordList,string beginWord,string endWord){
    

}







int main(){

    // these are the given data we will stop once we reach the end word and return the steps
    vector<string>wordList={"hot","dot","dog","lot","log","cog"};

    string beginWord="hit";
    string endWord="cog";

    int ans=ladderLength(wordList,beginWord,endWord);

    if(ans==0){
        cout<<"It is not possible to reach the end word";
    }
    else{
        cout<<"The shortest transformation sequence is: "<<ans;
    }

    return 0;


}
