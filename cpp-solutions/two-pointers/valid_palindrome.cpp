#include<iostream>
#include<string>
#include<algorithm>
using namespace std;







bool isPalindrome(string &s){

    // take two pinters left and right point left to start and right to the last
    int left=0;
    int right=s.length()-1;



    while(left<right){


        // condition check for space 
       while(left<right && ! isalnum(s[left])) left++;
       while(left<right && ! isalnum(s[right])) right--;

       // if after both case dissatisfies and conversion of both letters to lowercase mismatches return false immediatly
            if(tolower(s[left])!=tolower(s[right])){
                return false;
              }

              left++;
              right--;

            }

            // return true at last
            return true;


}

int main(){
    string s ="A man, a plan, a canal: Panama";

    bool ans=isPalindrome(s);

    if(ans){
        cout<<"Yes the given string is palindrome ";
    }
    else{
        "the given string is not palindrome ";
    }

    return 0;
}