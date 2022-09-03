#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<pair<string, string>> nonRepet;
    map<string, int> m;
    map<string, int> repotCount;
    map<string, int> res;

    for(int i=0; i<id_list.size(); i++){
        repotCount[id_list[i]] = 0;
        res[id_list[i]] = 0;
    }

    //중복 없애기
    for(int i=0; i<report.size(); i++){
        m[report[i]] = 0;
    }
   
    
    for(int i=0; i<report.size(); i++){
        string input = report[i];
        stringstream ss(input);
        string f, s;
        ss>>f>>s;
        pair<string, string> p = make_pair(f,s);
        if(m[report[i]]==0){
            nonRepet.push_back(make_pair(f, s));   
            m[report[i]] = 1; 
        }
    }

    for(int i=0; i<nonRepet.size(); i++){
        m[nonRepet[i].second]++;
    }

    for(int i=0; i<id_list.size(); i++){
        if(m[id_list[i]]>=k){
            for(int j=0; j<nonRepet.size(); j++){
                if(id_list[i] == nonRepet[j].second){
                    res[nonRepet[j].first]++;
                }
            }
        }
    }

    for(int i=0; i<id_list.size(); i++){
        answer.push_back(res[id_list[i]]);
    }


    return answer;
}

int main(){
    vector<int> res;
    vector<string> id_list;
    vector<string> report;
    int k = 2;

    id_list.push_back("muzi");
    id_list.push_back("frodo");
    id_list.push_back("apeach");
    id_list.push_back("neo");
    
    report.push_back("muzi frodo");
    report.push_back("apeach frodo");
    report.push_back("frodo neo");
    report.push_back("muzi neo");
    report.push_back("apeach muzi");
/*
    id_list.push_back("con");
    id_list.push_back("ryan");

    report.push_back("ryan con");
    report.push_back("ryan con");
    report.push_back("ryan con");
    report.push_back("ryan con");
*/
    res = solution(id_list, report, k);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

    return 0;
}