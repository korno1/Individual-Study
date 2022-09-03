#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<pair<string, string>, int> mc;
    map<string, int> m;
    map<string, int> res;
    map<string, int> repet;
    vector<string> first;
    vector<string> second;
    
    for(int i=0; i<report.size(); i++){
        string input = report[i];
        stringstream ss(input);
        string f, s;
        ss>>f>>s;
        first.push_back(f);
        second.push_back(s);
        mc[make_pair(first[i], second[i])] = 0;
    }

    for(int i=0; i<id_list.size(); i++){
        m[id_list[i]] = 0;
        res[id_list[i]] = 0;
        repet[id_list[i]] = 0;
    }

    for(int i=0; i<report.size(); i++){
        if(mc[make_pair(first[i], second[i])] == 0){
            m[second[i]]++;
            mc[make_pair(first[i], second[i])] = 1;
        }
        //cout<<second[i]<<" "<<m[second[i]]<<endl;
    }

    for(int i=0; i<id_list.size(); i++){
        if(m[id_list[i]] >= k){
            for(int j=0; j<report.size(); j++){
                if(id_list[i] == second[j]){
                    if(mc[make_pair(first[j], second[j])]!=2){
                        res[first[j]]++;
                        mc[make_pair(first[j], second[j])]=2;
                    }
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
/*
    id_list.push_back("muzi");
    id_list.push_back("frodo");
    id_list.push_back("apeach");
    id_list.push_back("neo");
    
    report.push_back("muzi frodo");
    report.push_back("apeach frodo");
    report.push_back("frodo neo");
    report.push_back("muzi neo");
    report.push_back("apeach muzi");
*/
    id_list.push_back("con");
    id_list.push_back("ryan");

    report.push_back("ryan con");
    report.push_back("ryan con");
    report.push_back("ryan con");
    report.push_back("ryan con");

    res = solution(id_list, report, k);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

    return 0;
}