#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int* p = new int[26];
        for (int i = 0; i < 26; ++i)
            p[i] = 0;
        for (int i = 0; i < s.length(); ++i)
            p[s.at(i) - 'a'] += 1;
        for (int i = 0; i < s.length(); ++i) {
            if (p[s.at(i) - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
int main() {
    string s = "leetcode";
    Solution s1;
    cout << s1.firstUniqChar(s) << endl;
    return 0;
}
