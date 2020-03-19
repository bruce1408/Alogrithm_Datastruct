#include<iostream>
#include<vector>
using namespace std;

bool binary_search(int a[], int left, int right, int tag)
{
    while(left<=right)
    {
        int mid = (left + right)>>1; // 相当于除以2
        if(a[mid]==tag)
        {
            return true;
        }
        else
        {
            a[mid]<tag ? left = mid+1:right = mid-1;
        }
    }
    return false;
}

int main()
{
    int a[] = {1,2,2,3,4,5,6,8};
    cout<<binary_search(a, 0, 7, 2)<<endl;
}


// #include <iostream>

// using namespace std;

// // 二分查找求下界
// int lowerBound(int *a, int lef, int righ, int v) {
//     int middle;
//     while(lef < righ) {
//         // 取中值
//         middle = lef + (righ - lef) / 2;
//         if(v <= a[middle]) {
//             righ = middle;
//         } else {
//             lef = middle + 1;
//         }
//     }
//     return lef;
// }

// // 二分查找求上界
// int upperBound(int *a, int lef, int righ, int v) {
//     int middle;
//     while(lef < righ) {
//         // 取中值
//         middle = lef + (righ - lef) / 2;
//         if(v >= a[middle]) {
//             lef = middle + 1;
//         } else {
//             righ = middle;
//         }
//     }
//     return lef;
// }

// int main() {
//     int a[] = {-10, -5, 0, 0, 1, 3, 3, 3, 5, 10};
//     int n = 10;
//     int v = -100;
//     cout << "元素" << v << "在a中的下界位置是：" << lowerBound(a, 0, n, v) << endl;
//     v = -10;
//     cout << "元素" << v << "在a中的下界位置是：" << lowerBound(a, 0, n, v) << endl;
//     v = 0;
//     cout << "元素" << v << "在a中的下界位置是：" << lowerBound(a, 0, n, v) << endl;
//     v = 3;
//     cout << "元素" << v << "在a中的下界位置是：" << lowerBound(a, 0, n, v) << endl;
//     v = 10;
//     cout << "元素" << v << "在a中的下界位置是：" << lowerBound(a, 0, n, v) << endl;
//     v = 100;
//     cout << "元素" << v << "在a中的下界位置是：" << lowerBound(a, 0, n, v) << endl;

//     cout << endl << endl;

//     v = -100;
//     cout << "元素" << v << "在a中的上界位置是：" << upperBound(a, 0, n, v) << endl;
//     v = -10;
//     cout << "元素" << v << "在a中的上界位置是：" << upperBound(a, 0, n, v) << endl;
//     v = 0;
//     cout << "元素" << v << "在a中的上界位置是：" << upperBound(a, 0, n, v) << endl;
//     v = 3;
//     cout << "元素" << v << "在a中的上界位置是：" << upperBound(a, 0, n, v) << endl;
//     v = 10;
//     cout << "元素" << v << "在a中的上界位置是：" << upperBound(a, 0, n, v) << endl;
//     v = 100;
//     cout << "元素" << v << "在a中的上界位置是：" << upperBound(a, 0, n, v) << endl;

//     return 0;
// }