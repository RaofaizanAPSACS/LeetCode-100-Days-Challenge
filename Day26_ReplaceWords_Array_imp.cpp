/*
Problem link: 
https://leetcode.com/problems/replace-words/

Problem:
In English, we have a concept called root, which can be followed by some other word to form another longer
 word - let's call this word successor. For example, when the root "an" is followed by the successor word 
 "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces,
 replace all the successors in the sentence with the root forming it. If a successor can be replaced 
 by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.
*/
#include<bits/stdc++.h>
using namespace std;

string replaceWords(vector<string>& dictionary, string sentence) {
    istringstream s(sentence);
    string word;
    sentence = "";
    while(s>>word){
        for(int i=0;i<dictionary.size();i++){
            if(word.size() > dictionary[i].size()){
                if(dictionary[i] == word.substr(0,dictionary[i].size())){
                    word = dictionary[i];
                }
            }
        }
        sentence += word;
        sentence += " ";
    }
    sentence.pop_back();
    return sentence;
}

int main(){   
    vector<string> dict{"a","b","c"};
    string s = "aadsfasf absbs bbab cadsfafs";
    cout<<replaceWords(dict,s);
	return 0;
}