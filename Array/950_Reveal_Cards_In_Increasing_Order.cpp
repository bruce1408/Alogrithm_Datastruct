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