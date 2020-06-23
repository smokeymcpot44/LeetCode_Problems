#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int firstUniqueChar(string s) {
        // unordered_map<char,int> frequencyMap;
        map<char,int> frequencyMap;
        vector<char> singleOccurence;
        //using map
        for(auto c:s) {
            if (frequencyMap.find(c) == frequencyMap.end()) { //if the element is already in the map
                frequencyMap[c] = 1;
            }
            else {
                frequencyMap.find(c)->second += 1;
            }
        }

        for(auto mapElem : frequencyMap) {
            if(mapElem.second == 1) {
                singleOccurence.push_back(mapElem.first);
            }
        }

        int minIndex;
        
        if (singleOccurence.size() == 0) { //if there is no unique char in the string
            minIndex = -1;
        }
        else { //process the chars with only one occurence
            minIndex = (int)(s.find(singleOccurence[0]));
            for_each(singleOccurence.begin() + 1, singleOccurence.end(), [s, &minIndex](char ch) {
                auto it = (int)(s.find(ch));
                if (it < minIndex) {
                    minIndex = it;
                }
            });
        }
        
        return minIndex;
    }
};

int main() {
    Solution s;
    cout << s.firstUniqueChar("kko") << "\n";
}