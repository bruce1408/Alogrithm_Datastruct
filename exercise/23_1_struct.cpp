#include<iostream>
#include<string>
#include<vector>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int num;

struct cord
{
    int x;
    float y;
    string s;
};

const int N = 10010;
// cord res[N];

bool cmp(cord n1, cord n2)
{
    return n1.x < n2.x;
}

int main()
{
    cout<<"请输入一个数字："<<endl;
    cin>>num;
    vector<cord>res(num);
    for(int i=0; i<num; i++)
    {
        cin>>res[i].x>>res[i].y>>res[i].s;
    }
    // sort(res, res+num, cmp);
    sort(res.begin(), res.end(), cmp);
    for(int i=0;i<num;i++)
    {
        printf("%d %.2f %s\n",res[i].x, res[i].y, res[i].s.c_str());
    }    
}

// 方法 二，使用pair来做
map<int,pair<float,string>> data;

int main()
{
    int i = 0, n = 0; 
    double f;
    string s;
    cin >> i;

    for(int j = 0; j < i;j++){
        cin >> n;
        cin >> f;
        cin >> s;
        pair<double,string> p(f,s);
        data[n] = p;
    }


    for(auto& e:data){
        cout  << e.first << " "<< e.second.first<<" " << e.second.second << endl;;
    }


    return 0;
}
