#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 理解错了题目
*/
int countCharacters(vector<string> &words, string chars)
{
    int countSum = 0;
    for (int i = 0; i < words.size(); i++)
    {
        int singleWord = 0;
        int len = words[i].size();
        for (auto j : words[i])
        {
            if (chars.find(j) != chars.npos)
            {
                singleWord += 1;
            }
        }
        if (singleWord == len) countSum += len;
    }
    return countSum;
}



class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        vector<int> seen(26, 0);

        for (char &c : chars)
            seen[c - 'a']++;

        for (auto &word : words) {
            vector<int> cur(26, 0);
            for (char &c : word)
                cur[c - 'a']++;

            bool flag = true;
            for (int i = 0; i < 26; i++)
                if (cur[i] > seen[i])
                    flag = false;

            if (flag)
                ans += word.length();

        }

        return ans;
    }
};

int main()
{
    vector<string> res = {"dyiclysmffuhibgfvapygkorkqllqlvokosagyelotobicwcmebnpznjbirzrzsrtzjxhsfpiwyfhzyonmuabtlwin","ndqeyhhcquplmznwslewjzuyfgklssvkqxmqjpwhrshycmvrb","ulrrbpspyudncdlbkxkrqpivfftrggemkpyjl","boygirdlggnh","xmqohbyqwagkjzpyawsydmdaattthmuvjbzwpyopyafphx","nulvimegcsiwvhwuiyednoxpugfeimnnyeoczuzxgxbqjvegcxeqnjbwnbvowastqhojepisusvsidhqmszbrnynkyop","hiefuovybkpgzygprmndrkyspoiyapdwkxebgsmodhzpx","juldqdzeskpffaoqcyyxiqqowsalqumddcufhouhrskozhlmobiwzxnhdkidr","lnnvsdcrvzfmrvurucrzlfyigcycffpiuoo","oxgaskztzroxuntiwlfyufddl","tfspedteabxatkaypitjfkhkkigdwdkctqbczcugripkgcyfezpuklfqfcsccboarbfbjfrkxp","qnagrpfzlyrouolqquytwnwnsqnmuzphne","eeilfdaookieawrrbvtnqfzcricvhpiv","sisvsjzyrbdsjcwwygdnxcjhzhsxhpceqz","yhouqhjevqxtecomahbwoptzlkyvjexhzcbccusbjjdgcfzlkoqwiwue","hwxxighzvceaplsycajkhynkhzkwkouszwaiuzqcleyflqrxgjsvlegvupzqijbornbfwpefhxekgpuvgiyeudhncv","cpwcjwgbcquirnsazumgjjcltitmeyfaudbnbqhflvecjsupjmgwfbjo","teyygdmmyadppuopvqdodaczob","qaeowuwqsqffvibrtxnjnzvzuuonrkwpysyxvkijemmpdmtnqxwekbpfzs","qqxpxpmemkldghbmbyxpkwgkaykaerhmwwjonrhcsubchs"};
    string chars = "usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp";
    Solution s;

    cout << s.countCharacters(res, chars) << endl;
}