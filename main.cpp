#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString str1("Android");
	cout << "str1."; str1.Show();
	cout << endl << endl;

	MyString str2;// = 3 + str1;
	str2 = 3 + str1;
	cout << "str2."; str2.Show();
	cout << endl << endl;
	
	cout << endl;
}