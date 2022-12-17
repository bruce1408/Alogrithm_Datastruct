// #include<iostream>
// #include<vector>


// using namespace std;

// int main()
// {
	
	
	// vector<int> res ;
	// int a;
	// int n=0;
	// int count;
	// cout<<"plea input the count :"<<endl;
	// cin>>count;
	// while(n<count)
	// {
		// cin>>a;
		// res.push_back(a);
		// n++;
	// }
	// for(auto i:res)
		// cout<<i<<" ";
	
	
	
	
	// return 0;
// }




// int main()
// {
    // int i;
    // cout<<"please put number in it:"<<endl;
    // int a[10];    /* i是随机值*/
    // for(i = 0; i < 10; i++)
    // {
        // cin>>a[i];
    // }
    // for(int n = 0; n < i; n++) {
        // cout<<a[n]<<" ";
    // }
    // return 0;
// }




// int main()
// {
	// int n;
	// cout<<"plea input a arrary size:"<<endl;
    // cin>>n; 
    // int *arr=new int[n];
    // cout<<"plae input array num:"<<endl;
    // for(int i=0;i<n;i++)
        // cin>>arr[i];
    // for(int i=0;i<n;i++)
       // cout<<arr[i]<<" ";
    // //释放arr数组 
    // delete[] arr;
    // return 0;
	
	
	
// }



// void main()
// {
	// int i,j,m=30,n=80;
	// bool word[30][80];
	// for (i=0;i<m;i++)

// {

// for (j=0;j<n;j++)

// {

// if ((i-m/2)*(i-m/2)*6+(j-n/2)*(j-n/2)<800&&(i-m/2)*(i-m/2)*6+(j-n/2)*(j-n/2)>550)

// word[i][j]=true;

// else 

// word[i][j]=false;

// }

// }

// for (i=0;i<m;i++)

// {

// for (j=0;j<n;j++)

// {

// if (word[i][j])

// printf("*");

// else 

// printf(" ");

// }

// printf("\n");

// }

// system("pause"); 

// }


#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

// // ======================================================================================

// // Helper function to read the provided font from a file.  The format
// // of the font file is described in comments below.  The width,
// // height, and bitmap_letters variables are set by this function.
// void ReadFont(const string &font_file, int &width, int &height, vector<vector<string> > &bitmap_letters)
// {
  // // open the font file for reading
  // ifstream istr(font_file.c_str());
  // if (!istr) { 
    // cerr << "ERROR: cannot open font file " << font_file << endl;
	// close(1);
  // }
  // // read in the width & height for every character in the file
  // istr >> width >> height;
  // assert (width >= 1);
  // assert (height >= 1);
  // // Create a vector to store all 256 ASCII characters of the
  // // characters.  Each character is represented as a vector of
  // // <height> strings that are each <width> wide.  Initially the
  // // characters are unknown (represented with the '?' character).
  // bitmap_letters = vector<vector<string> > 
    // ( 256, vector<string> ( height, string(width, '?')));

  // // read in all the characters
  // // output_type is the ascii integer representation of the character
  // int ascii;
  // while (istr >> ascii) 
  // {
    // assert (ascii >= 0 && ascii < 256);
    // // next the character is printed in single quotes
    // char c;
    // istr >> c;
    // assert (c == '\'');
    // // use std::noskipws to make sure we can read the space character correctly
    // istr >> noskipws >> c;
    // // verify that the ascii code matches the character
    // assert (c == (char)ascii);
    // // switch back to std::skipws mode
    // istr >> skipws >> c;
    // assert (c == '\'');
    // // read in the letter
    // vector<std::string> bitmap;
    // string tmp;
    // for (int i = 0; i < height; i++) {
      // istr >> tmp;
      // assert ((int)tmp.size() == width);
      // // make sure the letter uses only '#' and '.' characters
      // for (unsigned int j = 0; j < tmp.size(); j++) { 
        // assert (tmp[j] == '.' || tmp[j] == '#'); 
      // }
      // bitmap.push_back(tmp);
    // }
    // // overwrite the initially unknown letter in the vector
    // bitmap_letters[ascii] = bitmap;
  // }
// }
// // ======================================================================================
// char find_characters(std::string &read_file_line, char &foreground_character, char &background_character )
// {
  // int array[255] = {0}; // initialize all elements to 0
  // vector<char> str;
  // // Add all characters from the user-entered ASCII file to an array
  // for(int a=0; a<read_file_line.size(); a++){
    // str.push_back(2);
    // str[a] = read_file_line[a];
  // }
  // int i, max_similar_character_count;
  // // Count the occurance of every character in user-eneted ASCII file
  // for(i = 0; str[i] != 0; i++)
  // {
     // ++array[str[i]];
  // }
  // // Find the character that was most frequent and set as the background character 
  // // and find the second most frequently used character and set as the foreground character
  // max_similar_character_count = array[0];
  // foreground_character = 0;
  // for(i = 0; str[i] != 0; i++){
    // if( array[str[i]] > max_similar_character_count){
	  // max_similar_character_count = array[str[i]];
	  // background_character = str[i];
	// }else{
	  // if(background_character != str[i]){
	  // foreground_character = str[i];
	  // }
	// }
  // }
// }
// // =======================================================================================
// string display(string bitmap_file, string input, char foreground_character, char background_character){
  // string return_string = "";
  // int width = 6;
  // int height = 7;
  // vector<vector<string> > bitmap_letters;
  // ReadFont(bitmap_file, width, height, bitmap_letters);
  // int letter_index = 0;
  // //START create the ASCII code for each letter.
  // for(int row=0;row<7;row++){
    // letter_index = 0;
    // //START convert simple_font format to user-entered format.
    // for(string::iterator it = input.begin(); it != input.end(); ++it) {
      // for (int letter_character_index = 0; letter_character_index < 7; ++letter_character_index){
        // if (bitmap_letters[input[letter_index]][row][letter_character_index] == '#')
          // bitmap_letters[input[letter_index]][row][letter_character_index] = foreground_character;
        // if (bitmap_letters[input[letter_index]][row][letter_character_index] == '.')
          // bitmap_letters[input[letter_index]][row][letter_character_index] = background_character;
      // }
      // return_string = return_string + bitmap_letters[input[letter_index]][row] + background_character;
      // letter_index++;
    // }
    // //END convert simple_font format to user-entered format.
    // if(row <6){
      // return_string = return_string + "\n";
    // }
  // }
  // //END create ASCII code.
  // return return_string;
// }
// // ======================================================================================
// string read(string bitmap_file, char* read_file){
  // string return_string = "";
  // vector<vector<string> > bitmap_letters;
  // int width=6;
  // int height=7;
  // ReadFont(bitmap_file, width, height, bitmap_letters);
  // vector<vector<string> > read_letters(200);
  // ifstream fin(read_file);
  // string read_file_line;
  // int letter_row = 0;
  // int letter_index = 0;
  // char foreground_character;
  // char background_character;
  // //START break file sentence into letters, convert into simple_font format, and save each letter into its own array. 
  // while(getline(fin, read_file_line) && letter_index < 7) {  
    // letter_row = 0;
	// // Find and set the foreground and background characters
    // if(letter_index == 0){
      // find_characters(read_file_line, foreground_character, background_character);
    // }
    // read_letters[letter_index].resize(read_file_line.length()/7);
    // while(letter_row < read_file_line.length()/7){
	  // // Breaking file rows down into letters and saving them into a vector
      // read_letters[letter_index][letter_row] =  read_file_line.substr (letter_row*7,7);
      // for(string::iterator it = read_letters[letter_index][letter_row].begin(); it != read_letters[letter_index][letter_row].end(); ++it) {
        // for (int letter_row_index = 0; letter_row_index < 7; ++letter_row_index) {
		  // // Convert user-seleted file format to the ASCII format for proper comparison
          // if (read_letters[letter_index][letter_row][letter_row_index] == foreground_character){
            // read_letters[letter_index][letter_row][letter_row_index] = '#';
		  // }
          // if (read_letters[letter_index][letter_row][letter_row_index] == background_character){
            // read_letters[letter_index][letter_row][letter_row_index] = '.';
		  // }
        // }
      // }
      // letter_row++;
    // }
    // letter_index++;
  // }
  // //END saving letters into array
  // int character_ascii_number=32;
  // int character_row=0;
  // letter_row=0;
  // letter_index=0;
  // int same=0;
  // string string_comparison1 = "";
  // string string_comparison2 = "";
  // //START check though each bitmap letter for each file letter to see if they are the same
  // while(letter_row < read_letters[0].size()){ 
    // letter_index=0;
    // character_ascii_number=0;
	// // Runs a loop for every possible ASCII character
    // while ( character_ascii_number < 127){
	  // same=0;
	  // //Create ASCII character from integer
      // char character = character_ascii_number;
      // character_row=0;
	  // letter_index=0;
      // while(character_row < 7){
	      // string_comparison1 = read_letters[letter_index][letter_row];
		  // string_comparison2 = bitmap_letters[character][character_row];
		  // // Checking that each row are the same for each letter
          // if(string_comparison1.substr (0,6) == string_comparison2){
		    // same++;
			// letter_index++;
			// }else{
			// break;
			// }
	      // character_row++;
	    // }
		// // If every row for a letter is the same as in the file then they must be the same letter and I store that letter
		// if(same == 7){
		  // return_string = return_string + character;
		// }
	  // character_ascii_number++;
    // }
    // letter_row++;
  // }
  // //END check through letters
  // return return_string;
// }
// // ======================================================================================
// int main(int argc, char* argv[]){
  // string output_type = argv[1];
  // //if user wants to convert an ASCII art file to text run the read function
  // if (output_type == "read"){
    // if(argc != 4){
      // cerr << "Please enter only 4 parameters";
      // exit(1);
    // }
    // string output_string = read(string(argv[2]), argv[3]);
    // cout << output_string;
  // }else if(output_type=="display"){
    // // If user wants to display ASCII art run the display function
    // if(argc != 6){
      // cerr << "Please enter only 6 parameters";
      // exit(1);
    // }
    // string output_string = display(string(argv[2]),string(argv[3]),char(argv[4][0]),char(argv[5][0]));
    // cout << output_string;
  // }else{
    // cerr << "Your first parameter must be either read or display";
  // }
// }

//----------------------------------- 活字印刷解法----------------------------------------------


// void print_one(int** res, int n)
// {
	// for(int i=0;i<8;i++)
		// res[i][3] = n;
	
	// for(int i=0;i<8;i++)
	// {
		// for(int j=0;j<8;j++)
			// cout<<res[i][j]<<" ";
		// cout<<endl;
	// }
// }


void print_num(string res[8][8])
{
	cout<<endl;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

}


void print_one(string res[8][8])
{
	for(int i=1;i<8;i++)
	{
		res[i][4] = to_string(1);
	}
}

void print_two(string res[8][8])
{
	int i = 0;
	while(i<8)
	{
		if(i==0)
		{
			res[i][3] = to_string(2);
			res[i][4] = to_string(2);
			i++;
		}
		if(i==1)
		{
			res[i][2] = to_string(2);
			res[i][6] = to_string(2);
			i++;
		}
		if(i==2)
		{
			res[i][1] = to_string(2);
			res[i][6] = to_string(2);
			i++;
		}
		if(i==3)
		{
			res[i][6] = to_string(2);
			i++;
		}
		if(i==4)
		{
			res[i][5] = to_string(2);
			i++;
		}
		if(i==5)
		{
			res[i][3] = to_string(2);
			i++;
		}
		if(i==6)
		{
			// res[i][1] = to_string(2);
			res[i][2] = to_string(2);
			i++;
		}
		if(i==7)
		{
			for(int j=1;j<7;j++)
				res[i][j] = to_string(2);
			i++;
		}

	}
}



void print_three(string res[8][8])
{
	int i = 0;
	while(i<8)
	{
		if(i==0)
		{
			res[i][3] = to_string(2);
			res[i][4] = to_string(2);
			i++;
		}
		if(i==1)
		{
			res[i][2] = to_string(2);
			res[i][6] = to_string(2);
			i++;
		}
		if(i==2)
		{
			// res[i][1] = to_string(2);
			res[i][5] = to_string(2);
			i++;
		}
		if(i==3)
		{
			res[i][4] = to_string(2);
			i++;
		}
		if(i==4)
		{
			res[i][3] = to_string(2);
			i++;
		}
		if(i==5)
		{
			res[i][6] = to_string(2);
			i++;
		}
		if(i==6)
		{
			// res[i][1] = to_string(2);
			res[i][5] = to_string(2);
			i++;
		}
		if(i==7)
		{

			res[i][3] = to_string(2);
			res[i][4] = to_string(2);
			i++;
		}

	}
}


void print_four(string res[8][8])
{
	for(int i=0;i<8;i++)
	{
		res[i][4] = to_string(1);
	}
}



void print_six(string res[8][8])
{
	for(int i=0;i<8;i++)
	{
		res[i][4] = to_string(1);
	}
}



int main()
{
	// string res[8][8]={" "};
	

	
	// print_three(res);
	// print_num(res);
	// print_two(res);
	// print_num(res);
	int a;
	vector<int> res;
	while(cin>>a)
	{
		res.push_back(a);
	}
	for(auto i:res)
		cout<<i<<" ";
	
	
	return 0;
	
	
}







































