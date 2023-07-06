#include "stdio.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

class MyClass
{
int length{};
int *ptr;
public:
	MyClass(int val):length{val}
	{
		printf("MyClass  param constructor called.%d \n",val);
		ptr=new int[length];
	}
	MyClass(const MyClass &obj);
	MyClass& operator=(const MyClass &obj);
	~MyClass()
	{
		cout<<"Destrcutor Called."<<endl;
		delete[]ptr;
	}
	int getData()
	{
		return *ptr;
	}

};

MyClass::MyClass(const MyClass &obj)
{
	if(this==&obj)return;
	length=obj.length;
	ptr=new int[length];
	for(int i=0;i<length;i++)ptr[i]=obj.ptr[i];
	printf("MyClass  copy constructor called.%d \n",length);
}

MyClass& MyClass::operator=(const MyClass &obj)
{
	if(this==&obj)return *this;
	delete []ptr;
	length=obj.length;
	ptr=new int[length];
	for(int i=0;i<length;i++)ptr[i]=obj.ptr[i];
	printf("MyClass  assignment operator called.%d \n",length);
	return *this;
}

void print(const MyClass &obj)
{
	cout<<"Show data:"<<obj.getData()<<endl;
}

int main()
{
	char *array=(char *)malloc(20*sizeof(char));
	//int *array=(int *)malloc(20*sizeof(int));
	cout<<"Main Started"<<endl;
	cout<<"Main Started1"<<endl;
	MyClass *ptr=new(&array[4]) MyClass(25);//placement of new opertor
	MyClass *ptr1=new MyClass(30);
	MyClass abc(10);
	MyClass xyz=abc;
	MyClass pqr(20);
	pqr=xyz;
	delete ptr1;
	delete ptr;//This will crash app
	ptr->~MyClass();
	delete []array;
	cout<<"New Line Added"<<endl;
	cout<<"Main Exit"<<endl;
	cout<<"Main Exit1"<<endl;
}
