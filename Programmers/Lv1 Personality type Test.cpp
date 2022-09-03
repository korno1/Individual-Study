#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int score[7] = {3, 2, 1, 0, 1, 2, 3};
    int nature[8] = {0,};
    char type[8] = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    map<char, int> m;
    
    for(int i=0; i<8; i++){
        m[type[i]] = i;
    }

    for(int i=0; i<survey.size(); i++){
        int t = m[survey[i][0]];
        if(t%2==0){
            if(choices[i]<4) nature[t] += score[choices[i]-1];
            else nature[t+1] += score[choices[i]-1]; 
        }
        else{
            if(choices[i]<4) nature[t] += score[choices[i]-1];
            else nature[t-1] += score[choices[i]-1];
        } 
        
    }

    for(int i=0; i<8; i+=2){
        if(nature[i] < nature[i+1]) answer += type[i+1];
        else answer += type[i];
        
    }

    return answer;
}

int main(){
    vector<string> survey;
    vector<int> choices;
    string res;

    survey.push_back("AN");
    survey.push_back("CF");
    survey.push_back("MJ");
    survey.push_back("RT");
    survey.push_back("NA");

    choices.push_back(5);
    choices.push_back(3);
    choices.push_back(2);
    choices.push_back(7);
    choices.push_back(5);

    cout<<solution(survey, choices)<<endl;

    return 0;
}