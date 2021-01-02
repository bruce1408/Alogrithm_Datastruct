#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * O(NK), N : number of words, K : number of words in each temp string
 * S(1) if  output is not considerated as extra space
*/

/**
 * 方法 1，按照三种情况讨论即可
 * 1、如果是最后一行，只实现左对齐，每个单词中间插入一个空格，行尾插入空格使其长度达到length
 * 2、如这一行只有一个单词，直接在行尾补上空格即可。
 * 3、如果是其他情况，需要统计多少空格，且空格基本均匀分配
*/
vector<string> fullJustify1(vector<string> &words, int maxWidth)
{
    vector<string> result;
    int start = 0;
    while (start < words.size())
    {
        int end = start;
        int local_len_sum = 0; // sum of length of words

        while ((end < words.size()) && (local_len_sum + words[end].size() + (end - start) <= maxWidth))
            local_len_sum += words[end++].size(); // add one word, move end to next idx
        string temp = "";
        int num_words = end - start; // words[start, start+1, ..., end - 1] , (end-1)-start + 1
        if (end == words.size() || num_words == 1)
        {
            for (int i = start; i < end - 1; ++i)
                temp += words[i] + " ";
            temp += words[end - 1] + string(maxWidth - local_len_sum - (num_words - 1), ' ');
        }
        else
        {
            int must_have_space = num_words - 1; // i.e., slots between words, 3 words, 2 slots
            int total_space = maxWidth - local_len_sum;
            int extra_space = total_space - must_have_space;

            bool even_extra = (extra_space % (num_words - 1) == 0);
            int avg_extra = extra_space / (num_words - 1);
            int left_extra = extra_space % (num_words - 1);

            for (int i = start; i < end - 1; ++i)
            {
                temp += words[i] + ' '; // must_have space
                if (even_extra)
                    // can evenly allocate extra space for each slot
                    temp += string(avg_extra, ' ');
                else
                {
                    // can't evenly allocate extra space for each slot
                    if (avg_extra > 0)
                    {
                        // each slot has at least one extra space
                        if (i < start + left_extra)
                            temp += string(left_extra, ' ');
                        temp += string(avg_extra, ' ');
                    }
                    else
                    {
                        if (i < start + left_extra)
                            temp += string(1, ' ');
                    }
                }
            }
            temp += words[end - 1];
        }
        result.push_back(temp);
        start = end;
    }
    return result;
}

/**
 * 方法 2，思路都是一样的，但是写法略不同
*/

string space(int x)
{
    string res;
    while (x--)
        res += ' ';
    return res;
}

vector<string> fullJustify2(vector<string> &words, int maxWidth)
{
    vector<string> res;
    for (int i = 0; i < words.size();) // i表示单词的起始位置，j表示单词的结束位置
    {
        int j = i + 1, s = words[i].size(), rs = words[i].size();
        while (j < words.size() && s + 1 + words[j].size() <= maxWidth)
        {
            s += 1 + words[j].size();
            rs += words[j].size();
            j++;
        }
        rs = maxWidth - rs;     // 空格数
        string line = words[i]; // 当前单词是哪个
        if (j == words.size())  // 如果是最后一行，每个单词一空格且左对齐即可
        {
            for (i++; i < j; i++)
                line += ' ' + words[i];
            while (line.size() < maxWidth)
                line += ' ';
        }
        else if (j - i == 1) // 如果是当前行只有一个单词的情况
            line += space(rs);
        else // 其他情况
        {
            int base = rs / (j - i - 1);
            int rem = rs % (j - i - 1);
            i++;
            for (int k = 0; i < j; i++, k++)
                line += space(base + (k < rem)) + words[i];
        }
        i = j;
        res.push_back(line);
    }
    return res;
}

int main()
{
    vector<string> res = {"this", "is", "an", "example", "of", "text", "justification."};
    int n = 16;
    fullJustify2(res, n);
}