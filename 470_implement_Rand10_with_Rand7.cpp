// #include<iostream>
// #include<vector>
// using namespace std;

// // Random Function to that returns 0 or 1 with 
// // equal probability 
// int rand2() 
// { 
// 	// rand() function will generate odd or even 
// 	// number with equal probability. If rand() 
// 	// generates odd number, the function will 
// 	// return 1 else it will return 0. 
// 	return rand() & 1; 
// } 

// // Random Function to that returns 0, 1 or 2 with 
// // equal probability 1 with 75% 
// int rand3() 
// { 
// 	// returns 0, 1, 2 or 3 with 25% probability 
// 	int r = 2 * rand2() + rand2(); 
	
// 	if (r < 3) 
// 		return r; 
	
// 	return rand3(); 
// } 

// // Driver code to test above functions 
// int main() 
// { 
// 	// Intialize random number generator 
// 	srand(time(NULL)); 

// 	for(int i = 0; i < 10; i++) 
// 		cout << rand3()<<endl; 

// 	return 0; 
// } 


// ---------------------------------------------------------------------------------------------
#include<iostream>
using namespace std;
int rand7()
{
 // 产生随机数1--7之间的的数；   
}

int rand10()
{
    int i = rand7()*7+rand7()-7;
    if(i<41) return i % 10 + 1;
    return rand10();
}
int main()
{
    for(int i=0;i<10;i++)
    {
        cout<<rand10()<<endl;
    }
    return 0;
}