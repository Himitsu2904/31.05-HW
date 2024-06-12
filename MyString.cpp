#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <string>
#include <iostream>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length + 1];
	for (int i = 0; i < length; i++) str[i] = '-';
	str[length] = '\0';
}

MyString::MyString(int _length)
{
	length = _length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++) str[i] = '-';
	str[length] = '\0';
}

MyString::MyString(const char* _str)
{
	length = strlen(_str);
	str = new char[length + 1];
	strcpy(str, _str);
}

MyString::MyString(const MyString& obj)
{
	length = obj.length;
	if (str != nullptr) delete[] str;
	str = new char[obj.length + 1];
	strcpy(str, obj.str);
}

void MyString::Set_length(int _length)
{
	char* _str = new char[length + 1];
	strcpy(_str, str);
	delete[] str;
	str = new char[_length + 1];
	for (int i = 0; i < _length; i++) str[i] = _str[i];
	if (_length > length)
	{
		for (int i = length; i < _length; i++) str[i] = '-';
	}
	str[_length] = '\0';
	length = _length;
	delete[] _str;
}

void MyString::Set_str(const char* _str)
{
	length = strlen(_str);
	if (str!=nullptr) delete[] str;
	str = new char[length + 1];
	strcpy(str, _str);
}

void MyString::Input()
{
	char buff[100]; int choice;
	if (str != nullptr) delete[] str;
	cout << "You want to enter the string itself (1) or it's length (2)? "; cin >> choice;
	cin.ignore();
	switch (choice)
	{
	case 1:
		cout << "Enter string: "; gets_s(buff, 100);
		length = strlen(buff);
		str = new char[length + 1];
		strcpy(str, buff);
		break;
	case 2:
		cout << "Enter the length of string: "; cin >> length;
		str = new char[length + 1];
		for (int i = 0; i < length; i++) str[i] = '-';
		str[length] = '\0';
		break;
	}
}

void MyString::Show()const
{
	cout << "\tData about MyString object:";
	cout << "\nLength: " << length;
	cout << "\nStr: " << str;
}

void MyString::MyStrcpy(MyString& obj)
{
	length = obj.length;
	if (str != nullptr) delete[] str;
	str = new char[length + 1];
	strcpy(str, obj.str);
}

bool MyString::MyStrStr(const char* _str)
{
	int _length = strlen(_str);
	if (_length > strlen(str)) return false;
	char* __str = new char[_length + 1];
	strcpy(__str, _str);
	int ind = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == __str[0])
		{
			for (int j = 0; j < _length; j++)
			{
				if (str[i + j] != __str[j])
				{
					delete[] __str;
					return false;
				}
			}
		}
	}
	delete[] __str;
	return true;
}

int MyString::MyChr(char c)
{
	int n = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c) n++;
	} 
	if (n == 0) return -1;
	int* index = new int[n];
	int ind = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			index[ind] = i;
			ind++;
		}
	}
	cout << "All numbers of location: ";
	for (int i = 0; i < n; i++)
	{
		cout << index[i] + 1 << "\t";
	}
	cout << endl << "Index of first location: " <<index[0];
	return index[0];
}

int MyString::MyStrLen()
{
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	int _length = length;
	char* _str = new char[_length + 1];
	strcpy(_str, str);
	length += b.length;
	if (str != nullptr) delete[] str;
	str = new char[length + 1];
	strcpy(str, _str);
	for (int i = _length, j = 0; i < length; i++, j++)
	{
		str[i] = b.str[j];
	}
	str[length] = '\0';
	delete[] _str;
}

void MyString::MyDelChr(char c)
{
	int n = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] != c) n++;
	}
	char* _str = new char[length + 1];
	strcpy(_str, str);
	delete[] str;
	str = new char[n + 1];
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (_str[i] != c) {str[j] = _str[i]; j++;}
	}
	str[n] = '\0';
	length = n;
	delete[] _str;
}

int MyString::MyStrCmp(MyString& b)
{
	if (length > b.length) return 1;
	else if (length == b.length) return 0;
	else return - 1;
}

MyString MyString::operator+(int a)
{
	MyString obj;
	int _length = length + a;
	char* _str = new char[_length];
	strcpy(_str, str);
	for (int i = length; i < _length; i++) _str[i] = '-';
	_str[_length] = '\0';
	obj.Set_str(_str);
	return obj;
}

MyString MyString::operator+(const char* line)
{
	MyString rez;
	int size = strlen(line);
	int _length = length + size;
	char* _str = new char[_length + 1];
	strcpy(_str, str);
	for (int i = length, j = 0; i < _length; i++, j++) _str[i] = line[j];
	_str[_length] = '\0';
	rez.Set_str(_str);
	delete[] _str;
	return rez;
}

MyString MyString::operator+(MyString& obj)
{
	MyString rez;
	int _length = length + obj.length;
	char* _str = new char[_length + 1];
	strcpy(_str, str);
	for (int i = length, j = 0; i < _length; i++, j++) _str[i] = obj.str[j];
	_str[_length] = '\0';
	rez.Set_str(_str);
	delete[] _str;
	return rez;
}

MyString& MyString::operator+=(int a)
{
	int _length = length;
	char* _str = new char[_length + 1];
	strcpy(_str, str);
	if (str != nullptr) delete[] str;
	length += a;
	str = new char[length + 1];
	strcpy(str, _str);
	for (int i = _length; i < length; i++) str[i] = '-';
	str[length] = '\0';
	delete[] _str;
	return *this;
}

MyString& MyString::operator+=(const char* line)
{
	int _length = length;
	length = _length + strlen(line);
	char* _str = new char[_length + 1];
	strcpy(_str, str);
	delete[] str;
	str = new char[length + 1];
	strcpy(str, _str);
	for (int i = _length, j = 0; i < length; i++, j++) str[i] = line[j];
	str[length] = '\0';
	delete[] _str;
	return *this;
}

MyString& MyString::operator+=(MyString& obj)
{
	int _length = length;
	length = _length + obj.length;
	char* _str = new char[_length + 1];
	strcpy(_str, str);
	delete[] str;
	str = new char[length + 1];
	strcpy(str, _str);
	for (int i = _length, j = 0; i < length; i++, j++) str[i] = obj.str[j];
	str[length] = '\0';
	delete[] _str;
	return *this;
}

MyString MyString::operator-(int a)
{
	MyString obj;
	int _length = length - a;
	char* _str = new char[_length + 1];
	for (int i = 0; i < _length; i++) _str[i] = str[i];
	_str[_length] = '\0';
	obj.Set_str(_str);
	delete[] _str;
	return obj;
}

MyString MyString::operator-(const char* line)
{
	MyString obj;
	int size = strlen(line);
	if (size > length)
	{
		cout << "Method cannot function." << endl;
		return obj;
	}
	int n = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == line[0]) n++;
	}
	int* start = new int[n];
	bool* detect = new bool[n];
	int a = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == line[0])
		{
			int b = 0;
			start[a] = i;
			detect[a] = true;
			for (int ind = i, j = 0; j < size && ind < length; ind++, j++)
			{
				if (str[ind] == line[j]) b++;
				else
				{
					detect[a] = false;
					break;
				}
			}
			if (b != size) detect[a] = false;
			a++;
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++) if (detect[i] == true) c++;
	int _length = length - c * size;
	char* _str = new char[_length + 1];
	for (int i = 0, j = 0, k = 0; i < length; i++, k++)
	{
		if (i == start[j] && detect[j] == true)
		{
			i += size;
			j++;
		}
		_str[k] = str[i];
	}
	_str[_length] = '\0';
	obj.Set_str(_str);
	cout << endl;
	delete[] start; delete[] detect; delete[] _str;
	return obj;
}

MyString MyString::operator-(MyString& obj)
{
	MyString rez;
	int size = obj.length;
	if (size > length)
	{
		cout << "Method cannot function." << endl;
		return rez;
	}
	int n = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == obj.str[0]) n++;
	}
	int* start = new int[n];
	bool* detect = new bool[n];
	int a = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == obj.str[0])
		{
			int b = 0;
			start[a] = i;
			detect[a] = true;
			for (int ind = i, j = 0; j < size && ind < length; ind++, j++)
			{
				if (str[ind] == obj.str[j]) b++;
				else
				{
					detect[a] = false;
					break;
				}
			}
			if (b != size) detect[a] = false;
			a++;
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++) if (detect[i] == true) c++;
	int _length = length - c * size;
	char* _str = new char[_length + 1];
	for (int i = 0, j = 0, k = 0; i < length; i++, k++)
	{
		if (i == start[j] && detect[j] == true)
		{
			i += size;
			j++;
		}
		_str[k] = str[i];
	}
	_str[_length] = '\0';
	rez.Set_str(_str);
	cout << endl;
	delete[] start; delete[] detect; delete[] _str;
	return rez;
}

MyString& MyString::operator-=(int a)
{
	int _length = length;
	length -= a;
	char* _str = new char[_length + 1];
	strcpy(_str, str);
	delete[] str;
	str = new char[length + 1];
	for (int i = 0; i < length; i++) str[i] = _str[i];
	str[length] = '\0';
	delete[] _str;
	return *this;
}

MyString& MyString::operator-=(const char* line)
{
	int size = strlen(line);
	if (size > length)
	{
		cout << "Method cannot function." << endl;
		return *this;
	}
	int n = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == line[0]) n++;
	}
	int* start = new int[n];
	bool* detect = new bool[n];
	int a = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == line[0])
		{
			int b = 0;
			start[a] = i;
			detect[a] = true;
			for (int ind = i, j = 0; j < size && ind < length; ind++, j++)
			{
				if (str[ind] == line[j]) b++;
				else
				{
					detect[a] = false;
					break;
				}
			}
			if (b != size) detect[a] = false;
			a++;
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++) if (detect[i] == true) c++;
	int _length = length - c * size;
	char* _str = new char[_length + 1];
	for (int i = 0, j = 0, k = 0; i < length; i++, k++)
	{
		if (i == start[j] && detect[j] == true)
		{
			i += size;
			j++;
		}
		_str[k] = str[i];
	}
	_str[_length] = '\0';
	Set_str(_str);
	cout << endl;
	delete[] start; delete[] detect; delete[] _str;
	return *this;
}

MyString& MyString::operator-=(MyString& obj)
{
	int size = obj.length;
	if (size > length)
	{
		cout << "Method cannot function." << endl;
		return *this;
	}
	int n = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == obj.str[0]) n++;
	}
	int* start = new int[n];
	bool* detect = new bool[n];
	int a = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == obj.str[0])
		{
			int b = 0;
			start[a] = i;
			detect[a] = true;
			for (int ind = i, j = 0; j < size && ind < length; ind++, j++)
			{
				if (str[ind] == obj.str[j]) b++;
				else
				{
					detect[a] = false;
					break;
				}
			}
			if (b != size) detect[a] = false;
			a++;
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++) if (detect[i] == true) c++;
	int _length = length - c * size;
	char* _str = new char[_length + 1];
	for (int i = 0, j = 0, k = 0; i < length; i++, k++)
	{
		if (i == start[j] && detect[j] == true)
		{
			i += size;
			j++;
		}
		_str[k] = str[i];
	}
	_str[_length] = '\0';
	Set_str(_str);
	cout << endl;
	delete[] start; delete[] detect; delete[] _str;
	return *this;
}

MyString& MyString::operator++()
{
	char* _str = new char[length + 1];
	strcpy(_str, str);
	delete[] str;
	length++;
	str = new char[length + 1];
	strcpy(str, _str);
	str[length - 1] = '-';
	str[length] = '\0';
	delete[] _str;
	return *this;
}

MyString MyString::operator++(int)
{
	MyString obj(str);
	char* _str = new char[length + 1];
	strcpy(_str, str);
	delete[] str;
	length++;
	str = new char[length + 1];
	strcpy(str, _str);
	str[length - 1] = '-';
	str[length] = '\0';
	delete[] _str;
	return obj;
}

MyString& MyString::operator--()
{
	char* _str = new char[length + 1];
	strcpy(_str, str);
	delete[] str;
	length--;
	str = new char[length + 1];
	for (int i = 0; i < length; i++) str[i] = _str[i];
	str[length] = '\0';
	delete[] _str;
	return *this;
}

MyString MyString::operator--(int)
{
	MyString obj(str);
	char* _str = new char[length + 1];
	strcpy(_str, str);
	delete[] str;
	length--;
	str = new char[length + 1];
	for (int i = 0; i < length; i++) str[i] = _str[i];
	str[length] = '\0';
	delete[] _str;
	return obj;
}

MyString MyString::operator*(int a)
{
	MyString obj;
	int _length = length * a;
	char* _str = new char[_length + 1];
	int k = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < length; j++)
		{
			_str[k] = str[j];
			k++;
		}
	}
	_str[_length] = '\0';
	obj.Set_str(_str);
	delete[] _str;
	return obj;
}

MyString& MyString::operator*=(int a)
{
	int _length = length * a;
	char* _str = new char[_length + 1];
	int k = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < length; j++)
		{
			_str[k] = str[j];
			k++;
		}
	}
	_str[_length] = '\0';
	delete[] str;
	str = new char[_length + 1];
	strcpy(str, _str);
	length = _length;
	delete[] _str;
	return *this;
}

MyString MyString::operator/(int a)
{
	MyString obj;
	int _length = length / a;
	char* _str = new char[_length + 1];
	for (int i = 0; i < _length; i++) _str[i] = str[i];
	_str[_length] = '\0';
	obj.Set_str(_str);
	delete[] _str;
	return obj;
}

MyString MyString::operator/(char c)
{
	MyString obj;
	int ind = -1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c) { ind = i; break; }
	}
	if (ind == -1)
	{
		cout << "Character not found." << endl;
		return MyString();
	}
	int _length = ind + 1;
	char* _str = new char[_length + 1];
	for (int i = 0; i < _length; i++)
	{
		_str[i] = str[i];
	}
	_str[_length] = '\0';
	obj.Set_str(_str);
	return obj;
}

MyString& MyString::operator/=(int a)
{
	int _length = length / a;
	char* _str = new char[_length + 1];
	for (int i = 0; i < _length; i++) _str[i] = str[i];
	_str[_length] = '\0';
	delete[] str;
	str = new char[_length + 1];
	strcpy(str, _str);
	length = _length;
	delete[] _str;
	return *this;
}

MyString& MyString::operator/=(char c)
{
	int ind = -1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c) { ind = i; break; }
	}
	if (ind == -1)
	{
		cout << "Character not found." << endl;
		return *this;
	}
	int _length = ind + 1;
	char* _str = new char[_length + 1];
	for (int i = 0; i < _length; i++)
	{
		_str[i] = str[i];
	}
	_str[_length] = '\0';
	delete[] str;
	str = new char[_length + 1];
	strcpy(str, _str);
	length = _length;
	return *this;
}

MyString MyString::operator%(int a)
{
	MyString obj;
	int ind = a - 1;
	int _length = length - a;
	char* _str = new char[_length + 1];
	for (int i = ind + 1, j = 0; i < length; i++, j++) _str[j] = str[i];
	_str[_length] = '\0';
	obj.Set_str(_str);
	delete[] _str;
	return obj;
}

MyString MyString::operator%(char c)
{
	MyString obj;
	int ind = -1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			ind = i;
			break;
		}
	}
	if (ind == -1)
	{
		cout << "Character not found." << endl;
		return obj;
	}
	int _length = length - ind - 1;
	char* _str = new char[_length + 1];
	for (int i = ind + 1, j = 0; i < length; i++, j++) _str[j] = str[i];
	_str[_length] = '\0';
	obj.Set_str(_str);
	delete[] _str;
	return obj;
}

MyString& MyString::operator%=(int a)
{
	int ind = a - 1;
	int _length = length - a;
	char* _str = new char[_length + 1];
	for (int i = ind + 1, j = 0; i < length; i++, j++) _str[j] = str[i];
	_str[_length] = '\0';
	delete[] str;
	str = new char[_length + 1];
	strcpy(str, _str);
	delete[] _str;
	length = _length;
	return *this;
}

MyString& MyString::operator%=(char c)
{
	int ind = -1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			ind = i;
			break;
		}
	}
	if (ind == -1)
	{
		cout << "Character not found." << endl;
		return *this;
	}
	int _length = length - ind - 1;
	char* _str = new char[_length + 1];
	for (int i = ind + 1, j = 0; i < length; i++, j++) _str[j] = str[i];
	_str[_length] = '\0';
	delete[] str;
	str = new char[_length + 1];
	strcpy(str, _str);
	delete[] _str;
	length = _length;
	return *this;
}

MyString& MyString::operator=(MyString& obj)
{
	if (this == &obj) return *this;
	if (str != nullptr) delete str;
	length = obj.length;
	str = new char[length + 1];
	strcpy(str, obj.str);
	return *this;
}

//MyString& MyString::operator=(int a)
//{
//	if (str != nullptr) delete[] str;
//	int _length = a;
//	str = new char[_length + 1 ];
//	for (int i = 0; i < a; i++)
//	{
//		str[i] = '-';
//	}
//	str[_length] = '\0';
//	return *this;
//}

MyString::operator int()
{
	return length;
}

MyString::operator char* ()
{
	char* _str = new char[length + 1];
	strcpy(_str, str);
	return _str;
}

void MyString::operator ()()
{
	Show();
}

MyString::~MyString()
{
	delete[] str;
}

//-------------------------------------------------------------------------

MyString operator+(int a, MyString& obj)
{
	MyString rez;
	int _length = a + obj.Get_length();
	char* _str = new char[_length + 1];
	for (int i = 0; i < a; i++)
	{
		_str[i] = '-';
	}
	//strcat(_str, obj.Get_str());
	char* __str = obj.Get_str();
	cout << "__str: " << __str << endl;
	for (int i = a, j = 0; i < _length; i++, j++)
	{
		_str[i] = __str[j];
	}
	_str[_length] = '\0';
	cout << "_str: " << _str << endl;
	rez.Set_str(_str);
	rez.Set_length(_length);
	return rez;
}