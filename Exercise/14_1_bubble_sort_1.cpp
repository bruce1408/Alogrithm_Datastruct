#include<iostream>
#include<vector>
using namespace std;


void bubblesort(vector<int>&res){
    if(res.size() <= 1) return ;

    for(int i = 0; i<res.size();i++){
        for(int j = i+1; j<res.size();j++)
        {
            if(res[i] > res[j])
            {
                swap(res[i], res[j]);
            }
        }
    }
}


int main()
{
    vector<int>res = {2,3,4,1,5,6};
    bubblesort(res);
    for(auto x: res){
        cout<<x<<endl;
    }
}
