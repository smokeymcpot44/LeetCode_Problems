// all posible substring of a string
//time complexity : n^3
// Brute force
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
    public:
        string findSubstrings(string s) {
            string tempSubstr = "";
            vector<string> substrVec;
            for (int i = 0; i < s.size(); ++i) {
                string addOneSubstr = "";
                addOneSubstr += s[i];
                substrVec.push_back(addOneSubstr);
                addOneSubstr.clear();
                int count = i + 1;
                while (count < s.size()) {
                    tempSubstr.clear();
                    for (int k = i; k <= count; ++k){
                        tempSubstr += s[k];
                    }
                    substrVec.push_back(tempSubstr);
                    ++count;
                }
            }
            //display the substrings
            int maxSubstrLength = 0;
            map<int, string> mapOfMaxLengthSubstrtoTheSubstr = {};
            for(auto& substr : substrVec) {
                // cout << substr << ",";
                auto revStr = substr;
                std::reverse(revStr.begin(), revStr.end());
                if (substr.compare(revStr) == 0) {
                    mapOfMaxLengthSubstrtoTheSubstr.insert(make_pair(revStr.length(),revStr));
                }
            }
            // cout << "\nlongest palindromic substring of string " << s << " is " << mapOfMaxLengthSubstrtoTheSubstr.rbegin()->second;
            return mapOfMaxLengthSubstrtoTheSubstr.rbegin()->second;
        }
};

int main() {
    // cout << Solution().findSubstrings("ratrara");
    // cout << Solution().findSubstrings("cbbd");
    cout << Solution().findSubstrings("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    return 0;
}