// #include<iostream>
// #include<vector>
// using namespace std;


// int max_difference(vector<int>& a){
//     int len=a.size();
//     if(len<2){
//         return 0;
//     }

//     int minnum = min(a[0], a[1]);
//     int max_diff = a[1] - a[0];
//     for(int i=2; i<len; i++){
//         if(a[i] - minnum > max_diff){
//             max_diff=a[i]-minnum;
//         }
//         if(a[i] < minnum){
//             minnum=a[i];
//         }
//     }
//     return max_diff;
// }

// int main()
// {
//     vector<int> a = {6,3,4,5,6};
//     cout<<max_difference(a)<<endl;

//     // string s1 = "abcd";
//     // string s2 = "defcd";
//     // if(s1==s2) cout<<"yes"<<endl;
//     // else cout<<"no"<<endl;

// }

#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;
int main()
{
    set<std::string> myset1{"i am wang","i am wu","i am a", "i am kai"};
    unordered_map<string, set<string>>temp;
    set<string> myset2{"i am wang","i am wu","i am a", "i am kai"};
    set<string>::iterator setIter1 = myset2.begin();
    temp.insert(pair<string, set<string>>("hello", {"1"}));
    temp.insert(pair<string, set<string>>("h1", {}));
    temp.insert(pair<string, set<string>>("h2", {"1,4,5"}));

    unordered_map<string, set<string>>::iterator iter = temp.begin();
    unordered_map<string, set<string>>::iterator ite1r = temp.find("h1");

    if (ite1r == temp.end())
    {
        cout<<"no h1 key in set"<<endl;
    }
    else{
        cout<<"has h1 key in set"<<endl;
        ite1r->second.insert(myset1.begin(), myset1.end());
    }

    for(; iter != temp.end(); iter ++)
    {
        cout<<iter->second.size()<<": size"<<endl;   
    }


    for (; setIter1 != myset2.end(); setIter1++)
    {
        cout << "myset2----- :" << *setIter1 << endl;
    }
    myset2.insert(myset1.begin(), myset1.end());

    cout << "myset2 size: " << myset2.size() << endl;
    set<string>::iterator setIter = myset2.begin();
    for (; setIter != myset2.end(); setIter++)
    {
        cout << "myset2 :" << *setIter << endl;
    }
};