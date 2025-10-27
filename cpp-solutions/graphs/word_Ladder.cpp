#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

// approach -> bfs using queue

// time complexity->O(N*M)

//space complexity -> O(N*M)

// this function will return shortest no of steps

int ladderLength(vector<string>&wordList,string beginWord,string endWord){

// create a queue and store the word and steps so queue with pair will be required 
    queue<pair<string,int>>q;

    // create a unordered set and store all the words from the wordList which we need to generate 
    unordered_set<string>st(wordList.begin(),wordList.end());

    // push the starting word and step as 1

    q.push({beginWord,1});

    // now run until queue becomes empty
    while(!q.empty()){

        // take the word and step from queue
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();


        // if the word and endword matches return the steps
        if(word==endWord) return steps;
        // traverse through each char of word
        for(int i=0;i<word.size();i++){
            
            // store the orignal one and later on will change it to match with words present in the set
            char orignal=word[i];

            // check all the possibilties by changing it with all 26 chars
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                // once find the word push it to the queue and delete it from set because later on it is gurraentee if we get the word step will be higher
                if(st.find(word)!=st.end()){
                    q.push({word,steps+1});
                    st.erase(word);
                }

            }

            // give back the orignal char to the word for later on matching
            word[i]=orignal;

        }


    }

    // if it doesnt match with endword return 0
    return 0;


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
