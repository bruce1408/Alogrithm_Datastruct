#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

// 超级经典的题
class Solution
{
    public:
    // typedef vector<string> VS; // typedef 新的定义
    string numberToWords(int num)
    {
        string res = convertHundred(num%1000);
        vector<string> v = {"Thousand", "Million", "Billion"};
        for(int i=0;i<3;i++)
        {
            num/=1000;
            res = num%1000 ? convertHundred(num%1000)+" " + v[i]+" " + res:res;
        }
        while(res.back()==' ')res.pop_back(); // 123000 比如后面都是0删除 ' '
        return res.empty()? "Zero":res;
    }
    string convertHundred(int num)
    {
        vector<string> v1 = {"","One","Two", "Three", "Four", "Five", 
        "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", 
        "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        vector<string> v2 = {"","","Twenty", "Thirty", "Forty", "Fifty", "Sixty",
        "Seventy", "Eighty", "Ninety"};
    
        string res;
        int a = num/100, b = num%100, c=num%10;
        res = b<20 ? v1[b] : v2[b/10] + ( c? " " + v1[c]:"");
        if(a>0) res = v1[a] + " Hundred" +(b ? " "+res:"");
        return res;
    }
};


// class Solution
// {
//     public:
//     typedef vector<string> VS;
//     string numberToWords(int num)
//     {
//         string res = convertHundred(num%1000);
//         VS v = {"Thousand", "Million", "Billion"};
//         for(int i=0;i<3;i++)
//         {
//             num/=1000;
//             res = num%1000 ? convertHundred(num%1000)+" " + v[i]+" " + res:res;
//         }
//         while(res.back()==' ')res.pop_back(); // 123000 比如后面都是0删除 ' '
//         return res.empty()? "Zero":res;
//     }

//     string convertHundred(int num)
//     {
//         VS v1 = {"","One","Two", "Three", "Four", "Five", 
//         "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", 
//         "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

//         VS v2 = {"","","Twenty", "Thirty", "Forty", "Fifty", "Sixty",
//         "Seventy", "Eighty", "Ninety"};
    
//         string res;
//         int a = num/100, b = num%100, c=num%10;
//         res = b<20 ? v1[b] : v2[b/10] + ( c? " " + v1[c]:"");
//         if(a>0) res = v1[a] + " Hundred" +(b ? " "+res:"");
//         return res;
//     }
// };


int main()
{
    Solution s;
    cout<<s.numberToWords(294564)<<endl;
}

// 方法二。
// class Solution2 
// {
//     int findPlace (int placeNum)
//     {
//         if (placeNum % 3 == 0)
//             return 100;
//         else if ((placeNum+1) % 3 == 0)
//             return 10;
//         else
//             return 1;
//     }
//     string findOnes(char digit)
//     {
//         switch(digit)
//         {
//             case '9':
//                 return "Nine ";
//             case '8':
//                 return "Eight ";
//             case '7':
//                 return "Seven ";
//             case '6':
//                 return "Six ";
//             case '5':
//                 return "Five ";
//             case '4':
//                 return "Four ";
//             case '3':
//                 return "Three ";
//             case '2':
//                 return "Two ";
//             case '1':
//                 return "One ";
//         }
//     }
//     string findTens(char digit)
//     {
//         switch(digit){
//             case '9':
//                 return "Ninety ";
//             case '8':
//                 return "Eighty ";
//             case '7':
//                 return "Seventy ";
//             case '6':
//                 return "Sixty ";
//             case '5':
//                 return "Fifty ";
//             case '4':
//                 return "Forty ";
//             case '3':
//                 return "Thirty ";
//             case '2':
//                 return "Twenty ";
//         }
//     }
//     string findSpecialTens(char digit)
//     {
//         switch(digit)
//         {
//             case '9':
//                 return "Nineteen ";
//             case '8':
//                 return "Eighteen ";
//             case '7':
//                 return "Seventeen ";
//             case '6':
//                 return "Sixteen ";
//             case '5':
//                 return "Fifteen ";
//             case '4':
//                 return "Fourteen ";
//             case '3':
//                 return "Thirteen ";
//             case '2':
//                 return "Twelve ";
//             case '1':
//                     return "Eleven ";
//             case '0':
//                     return "Ten ";
//         }   
//     }
// public:
//     string numberToWords(int num) 
//     {
//         if(num == 0)
//             return "Zero";
//         char lastNum = '0';
//         string result = "";
//         string number = to_string(num);
//         int place = number.size();
//         for(int i = 0; i < number.size(); i++)
//         {
//             if(number[i] != '0')
//             {
//                 lastNum = number[i];
//                 int subPlace = (findPlace(place));
//                 switch(subPlace)
//                 {
//                     case 100:
//                         result += findOnes(number[i]) + "Hundred ";
//                         break;
//                     case 10:
//                         if(number[i] == '1'){
//                             ++i;
//                             place--;
//                             result += findSpecialTens(number[i]);                    
//                         }                  
//                         else
//                             result += findTens(number[i]);
//                         break;
//                     case 1:
//                         result += findOnes(number[i]);
//                     default:
//                         break;
//                 }
//             }
//             if(place == 4 || place == 7 || place == 10)
//             {
//                 if(lastNum != '0')
//                 {
//                     if(place == 4)
//                         result += "Thousand ";
//                     if(place == 7 )
//                         result += "Million ";
//                     if(place == 10)
//                         result += "Billion ";
//                     lastNum = '0';
//                 }
//             }
//             --place;
//         }
//         return result.substr(0, result.size()-1);
//     }
// };
