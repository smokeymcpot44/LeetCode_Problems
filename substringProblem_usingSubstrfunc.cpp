// all posible substring of a string
//time complexity : n^2
//Bruet force
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Solution {
    public:
    string findSubstrings(string s) {
        if(s == "")
            return s;
        set<string> substringSet; //store all the substrings
        map<int,string> palindromeMap; //store the palindromes
        for (int i = 0; i < s.size(); ++i) {
            for (int charcount = 1; charcount <= s.size()-i ; ++charcount) {
                substringSet.insert(s.substr(i,charcount));
            }
        }
        for(auto str : substringSet) {
            auto revStr = str; //string copy
            reverse(revStr.begin(), revStr.end());
            if (str.compare(revStr) == 0) {
                palindromeMap.insert(make_pair(str.length(), str));
            }
        }
        return palindromeMap.rbegin()->second; //return the last element as it will be the maximum
    }
};

int main() {
    // cout << Solution().findSubstrings("ratrara");
    // Solution().findSubstrings("ratrara");
    // cout << Solution().findSubstrings("cbbd");
    // cout << Solution().findSubstrings("abcb");
    cout << Solution().findSubstrings("");
    // cout << Solution().findSubstrings(" ");
    // cout << Solution().findSubstrings("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    return 0;
}