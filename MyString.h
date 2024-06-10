#pragma once
class MyString
{
	int length;
	char* str;
public:
	MyString(); //����������� �� ���������, ����������� ������� ������ ������ 80 ��������
	MyString(int _length); //�����������, ����������� ��������� ������ ������������� �������
	MyString(const char* _str); //�����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������
	MyString(const MyString& obj);
	int Get_length()
	{
		return length;
	}
	char* Get_str()
	{
		return str;
	}
	void Set_length(int _length);
	void Set_str(const char* _str);
	void Input(); //����� ��� ����� ����� � ����������
	void Show()const; // ������ ����� �� �����
	void MyStrcpy(MyString& obj); //����������� �����
	bool MyStrStr(const char* _str);// ����� ��������� � ������
	int  MyChr(char c); // ����� ������� � ������ (������ ���������� �������, ���� -1)
	int MyStrLen();// ���������� ����� ������
	void MyStrCat(MyString& b); // ����������� �����
	void MyDelChr(char c); // ������� ��������� ������ 
	int MyStrCmp(MyString& b); /* ��������� ����� 
		-1 � ������ ������ ������ ��� ������
		1 � ������ ������ ��� ������
		0 � ������ �����!*/
	MyString operator +(int a);
	MyString operator +(const char* line);
	MyString operator +(MyString& obj);
	MyString& operator +=(int a);
	MyString& operator +=(const char* line);
	MyString& operator +=(MyString& obj);
	MyString operator -(int a);
	MyString operator -(const char* line);
	MyString operator -(MyString& obj);
	MyString& operator -=(int a);
	MyString& operator -=(const char* line);
	MyString& operator -=(MyString& obj);
	MyString& operator ++();
	MyString operator ++(int);
	MyString& operator --();
	MyString operator --(int);
	MyString operator *(int a);
	MyString& operator *=(int a);
	MyString operator /(int a);
	MyString operator /(char c);
	MyString& operator /=(int a);
	MyString& operator /=(char c);
	MyString operator %(int a);
	MyString operator %(char c);
	MyString& operator %=(int a);
	MyString& operator %=(char c);
	MyString& operator =(MyString& obj);
	operator int();
	operator char* ();
	void operator()();
	~MyString();
};

