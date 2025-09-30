#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


// approach->string manipulation
// time complexity-> O(N)
// space complexiy O(N)



// function for encoding the string 

string encode(vector<string>&strs){
   // declare a temp string
    string encoded;
    // iterate through every elemnt in the string array
    
    for(auto &s:strs){

        // while encoding add the length of first elemnt then hashtag and the charcters of string 

        // if the string is neet-> it goes like 4 ->length and the # and the neet -> 4#neet

        encoded+=to_string(s.size()) +"#"+s;
    }

    // return the encoded string
    return encoded;
}


// function for decoding the string

vector<string>decode(string s){

    // declare the vector to return the decoded parts
    vector<string>result;

    // pointer i at the beggining
    int i=0;

    //iterate through each character in string
    while(i<s.size()){

    // remeber the order is length+#+actual word

    // lets take the j pointer to #
    int j=i;

    while(s[j]!='#'){
        j++;
    }

    // stoi->convert string to ineteger
    //  j is pointing to #  and according to the order 
    // before # there was length so i->j-1 -> will give the length
  
    int length=stoi(s.substr(i,j-i));

    // grab the actual word after # there was actual word so start from j+1 to the length and store it in a string word
    string word=s.substr(j+1,length);

    // push the word in the result array
    result.push_back(word);



    // move the i pointer to the next encoded word
    // remeber j was at hasthag and the next char is actual word part so moving i to j+1+lenght will take us to the next encoded part
    i=j+1+length;

    }


    // return the string vector
    return result;


}



int main(){
  vector<string> input = {"neet", "code", "love", "you"};


  // calling encoded function
  string encoded=encode(input);

  cout<<"Encoded part: "<<encoded;
    cout<<endl;
    // calling decoded function
    vector<string>decoded=decode(encoded);


    // printing the decoded part
    cout<<"Decoded string: ";
    for(auto &w:decoded) cout<<w<<" ";
    cout<<endl;

    return 0;
  


}