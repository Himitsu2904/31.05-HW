#pragma once
class MyString
{
	int length;
	char* str;
public:
	MyString(); //конструктор по умолчанию, позволяющий создать строку длиной 80 символов
	MyString(int _length); //конструктор, позволяющий создавать строку произвольного размера
	MyString(const char* _str); //конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя
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
	void Input(); //метод для ввода строк с клавиатуры
	void Show()const; // вывода строк на экран
	void MyStrcpy(MyString& obj); //копирование строк
	bool MyStrStr(const char* _str);// поиск подстроки в строке
	int  MyChr(char c); // поиск символа в строке (индекс найденного символа, либо -1)
	int MyStrLen();// возвращает длину строки
	void MyStrCat(MyString& b); // объединение строк
	void MyDelChr(char c); // удаляет указанный символ 
	int MyStrCmp(MyString& b); /* сравнение строк 
		-1 – первая строка меньше чем вторая
		1 – первая больше чем вторая
		0 – строки равны!*/
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

