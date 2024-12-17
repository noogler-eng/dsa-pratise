
#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        
        unordered_map<string, vector<pair<string, double>>> day1;
        unordered_map<string, vector<pair<string, double>>> day2;

        for(int i=0; i<pairs1.size(); i++){
            string u = pairs1[i][0];
            string v = pairs1[i][1];
            double rate = rates1[i];
            day1[u].push_back({v, rate});
            day1[v].push_back({u, 1 / rate});
        }

        for(int i=0; i<pairs2.size(); i++){
            string u = pairs2[i][0];
            string v = pairs2[i][1];
            double rate = rates2[i];
            day2[v].push_back({u, rate});
            day2[u].push_back({v, 1 / rate});
        }

        // day1 calculation
        unordered_map<string, double> maxAmount;
        queue<string> q;
        maxAmount[initialCurrency] = 1;
        q.push(initialCurrency);
        while(!q.empty()){
            string currency = q.front();
            q.pop();

            for(auto i: day1[currency]){
                string new_currency = i.first;
                double rate = i.second;
                if(maxAmount[new_currency] < rate * maxAmount[currency]){
                    maxAmount[new_currency] = rate * maxAmount[currency];
                    q.push(new_currency);
                }
            }
        }

        // calculation on day2
        unordered_map<string, double> maxConversion;
        maxConversion[initialCurrency] = 1;
        q.push(initialCurrency);
        double res = 0.0;
        while(!q.empty()){
            string currency = q.front();
            q.pop();

            res = max(res, maxConversion[currency] * maxAmount[currency]);

            for(auto i: day2[currency]){
                string new_currency = i.first;
                double rate = i.second;
                if(maxConversion[new_currency] < rate * maxConversion[currency]){
                    maxConversion[new_currency] = rate * maxConversion[currency];
                    q.push(new_currency);
                }
            }
        }

        return res;
    }
};