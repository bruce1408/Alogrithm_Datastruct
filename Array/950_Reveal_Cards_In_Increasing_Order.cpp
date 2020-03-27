#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * In a deck of cards, every card has a unique integer.  You can order the deck in any order you want.
 * Initially, all the cards start face down (unrevealed) in one deck.
 * Now, you do the following steps repeatedly, until all cards are revealed:
 * Take the top card of the deck, reveal it, and take it out of the deck.
 * If there are still cards in the deck, put the next top card of the deck at the bottom of the deck.
 * If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
 * Return an ordering of the deck that would reveal the cards in increasing order.
 * The first entry in the answer is considered to be the top of the deck.
 * 
 * Input: [17,13,11,2,3,5,7]
 * Output: [2,13,3,11,5,17,7]
*/

/**
 * 方法1，使用队列，就是先把这个数组排序，然后排序之后我们就要放进结果res中
 * 但是要按照要求的话，可能需要有点技巧，就是我们需要按照index下标来做，这个下标我们
 * 事先保存在temp中，这个是队列，每次我们取下标队列中的top元素，把排序好的数赋值给这个
 * 位置的元素，然后这个值在去除，下一个值我们放到队尾即可；依次循环
*/
vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    sort(deck.begin(), deck.end());
    vector<int> result(deck.size());
    queue<int> temp;
    for (int i = 0; i < deck.size(); i++)
        temp.push(i);
    for (int i = 0; i < deck.size(); i++)
    {
        result[temp.front()] = deck[i];
        temp.pop();
        int val = temp.front();
        temp.pop();
        temp.push(val);
    }
    return result;
}

int main()
{
    vector<int> res = {17, 13, 11, 2, 3, 5, 7};
    for (auto i : deckRevealedIncreasing(res))
    {
        cout << i << " ";
    }
}