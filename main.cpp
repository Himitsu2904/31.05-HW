#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString str1("Android");
	cout << "str1.";
	str1.Show();
	cout << endl << endl;

	/*cout << str1 << endl;

	MyString str2;
	cin >> str2; //operation isn't identified, although it is defined
	cout << str2 << endl << endl;*/

	MyString str3;// = 3 + str1;
	str3 = 3 +str1;
	cout << "str3.";
	str3.Show();
	cout << endl << endl;
	
	cout << endl;
}