#include<iostream>
#include<stack>
#include<string>

using namespace std;


// time complexity -> O(N)

// space complexity-> O(N)



bool isValid(string &s){

    // declare a stack it follows lifo principle
    stack<char>st;

    // traverse through the string charactes
    for(auto ch:s){
        // push all the openning brackets to the stack
        if(ch=='('|| ch=='{'||ch=='[') st.push(ch);
        else{
        // incase the stack is empty
        if(st.empty()) return false;

        // take the top element
        char top=st.top();

        // match  the closing brackets  with the top elemnt of stack and pop if it matches 

        if(ch==')' &&top=='(' || ch==']' && top=='[' || ch=='}' &&top=='{'){
                st.pop();
            }
            // immediatly return false if not matching
            else{
                return false;
            }



    }

    }

    // if all matches are successfull  then stack would be empty and function will return true
    return st.empty();
    





}





int main(){

    // input
    string s ="()[]{}";


    // logging the output wrt the bool function 
    if(isValid(s)){
        cout<<"yes input is valid";
    }
    else{
        cout<<"not valid";
    }

    return 0;
}