#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString str1;
	cout << "str1."; str1.Show();
	cout << endl << endl;

	MyString str2(5);
	cout << "str2."; str2.Show();
	cout << endl << endl;

	MyString str3("Android");
	cout << "str3."; str3.Show();
	cout << endl << endl;

	MyString str4;
	str4.Input();
	cout << endl << "str4 (Input).\n"; str4.Show();
	cout << endl << endl;

	MyString str5; str5.MyStrcpy(str3);
	cout << "str5 (MyStrcpy str1).\n"; str5.Show();
	cout << endl << endl;

	cout << "str5 (MyStrStr \"Andi\").";
	if (str5.MyStrStr("Andi")) cout<<" Substr is in str.";
	else cout << " Substr is NOT in str.";
	cout << endl << endl;

	
	cout << "str5 (Chr 'd').\n"; 
	int b = str5.MyChr('d');
	if (b == -1) cout << "No location found.";
	cout << "\nstr5 (Chr 'm').\n";
	b = str5.MyChr('m');
	if (b == -1) cout << "No location found.";
	cout << endl << endl;

	cout << "str5 (StrLen).\t";
	cout << "Length = " << str5.MyStrLen();
	cout << endl << endl;

	MyString str6("Sad"), str7("dest");
	cout << "str6 (StrCat str7).\t";
	str6.MyStrCat(str7);
	cout << endl; str6.Show();
	cout << endl << endl;

	cout << "str6 (StrDelChr 'd').\n";
	str6.MyDelChr('d');
	str6.Show(); cout << endl << endl;

	cout << "str5 (StrCmp str6).\n";
	int a = str5.MyStrCmp(str6);
	if (a) cout << "str5 is longer than str6.";
	else if (!a) cout << "str5 and str6 lengths are equal.";
	else cout << "str5 is shorter than str6.";
	cout << endl << "\t------------------------------------Overloaded operations------------------------------------" << endl;

	cout << "str6 (operator += 5).\n";
	str6 += 5;
	str6.Show(); cout << endl << endl;

	MyString str8 = str5 + 5;
	cout << "str8 (operator str5 + 5).\n";
	str8.Show(); cout << endl << endl;

	MyString str9 = str8 + str6;
	cout << "str9 (operator str8 + str6).\n";
	str9.Show(); cout << endl << endl;

	MyString str10 = str9 + "Time";
	cout << "str10 (operator str9 + \"Time\").\n";
	str10.Show(); cout << endl << endl;

	str10 += " loop";
	cout << "str10 (operator += \" loop\").\n";
	str10.Show(); cout << endl << endl;

	str10 += str4;
	cout << "str10 (operator += str4).\n";
	str10.Show(); cout << endl << endl;

	str10 -= 4;
	cout << "str10 (operator -= 4).\n";
	str10.Show(); cout << endl << endl;

	MyString str11 = str8 - 6;
	//str10 = str8 - 6; //why in this case error occurs?
	cout << "str11 (operator str8 - 6).\n";
	str11.Show(); cout << endl << endl;

	MyString str12("---Android--Android_And");
	cout << "str12.\t";
	str12.Show(); cout << endl;
	MyString str13 = str12 - "Android";
	cout << "str13 (operator str12 - \"Android\").\n";
	str13.Show(); cout << endl;

	MyString str14 = str10 - str5;
	cout << "str14 (operator str10 - str5).\n";
	str14.Show(); cout << endl << endl;

	str14 -= "Time";
	cout << "str14 (operator -= \"Time\").\n";
	str14.Show(); cout << endl << endl;

	str14 -= str6;
	cout << "str14 (operator -= str6).\n";
	str14.Show(); cout << endl << endl;

	++str14;
	cout << "str14 (operator ++a).\n";
	str14.Show(); cout << endl << endl;

	MyString str15 = str14++;
	cout << "str15 (operator a++).\n";
	str15.Show(); cout << endl << "str14.\t";
	str14.Show(); cout << endl << endl;

	--str14;
	cout << "str14 (operator --a).\n";
	str14.Show(); cout << endl << endl;

	MyString str16 = str14--;
	cout << "str16 (operator a--).\n";
	str16.Show(); cout << endl << "str14.\t";
	str14.Show(); cout << endl << endl;

	MyString str17 = str6 * 3;
	cout << "str17 (operator str6 * 3).\n";
	str17.Show(); cout << endl << endl;

	str5 *= 5;
	cout << "str5 (operator *= 5).\n";
	str5.Show(); cout << endl << endl;

	MyString str18 = str17 / 3;
	cout << "str18 (operator str17 / 3).\n";
	str18.Show(); cout << endl << endl;

	str5 /= 5;
	cout << "str5 (operator /= 5).\n";
	str5.Show(); cout << endl << endl;

	MyString str19 = str5 / 'r';
	cout << "str19 (operator str5 / 'r').\n";
	str19.Show(); cout << endl << endl;

	str18 /= '-';
	cout << "str18 (operator /= '-').\n";
	str18.Show(); cout << endl << endl;

	MyString str20 = str5 % 3;
	cout << "str20 (operator str5 % 3).\n";
	str20.Show(); cout << endl << endl;

	MyString str21 = str18 % 'e';
	cout << "str21 (operator str18 % 'e').\n";
	str21.Show(); cout << endl << endl;

	str5 %= 2;
	cout << "str5 (operator %= 2).\n";
	str5.Show(); cout << endl << endl;

	str5 %= 'o';
	cout << "str5 (operator %= 'o').\n";
	str5.Show(); cout << endl << endl;

	MyString str22;
	cout << "str22 ().\n";
	str22.Show(); cout << endl;
	str22 = str18;
	cout << "str22 (operator = str18).\n";
	str22.Show(); cout << endl << endl;

	int n = (int)str22;
	cout << "n = (int)str22 = " << n << endl << endl;

	char* s = (char*)str22;
	cout << "s = (char*)str22 = " << s << endl << endl;

	cout << "str20 (operator ())." << endl;
	str20(); cout << endl << endl;
	
	cout << endl;
}