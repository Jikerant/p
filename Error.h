#pragma once
#include <iostream>
using namespace std;
class ErrorBase//�� �� ���� ��� ��� ������ �������(� �� ������ ��� �����)
{
public:

	ErrorBase() { printf("ErrorBase\n"); }

	virtual void Message() { printf("Not same size\n"); }//�� ��� ��� ����������� ���� �� �������� ������ ������
};
class ErrorDerived :public ErrorBase
{
public:

	ErrorDerived() { printf("ErrorDerived\n"); }

	void Message() { printf("Number is out of limits\n"); }//����� �������� �� ������� int
};
class ErrorS :public ErrorBase
{
public:

	ErrorS() { printf("Error\n"); }

	void Message() { printf("not in diaposone\n"); }
};
class ErrorD :public ErrorBase
{
public:

	ErrorD() { printf("Error\n"); }

	void Message() { printf("Empty\n"); }
};
class ErrorO :public ErrorBase
{
public:

	ErrorO() { printf("Error\n"); }

	void Message() { printf("Opening trouble\n"); }
};
class ErrorIn :public ErrorBase
{
public:

	ErrorIn() { printf("Error\n"); }

	void Message() { printf("Init marixes before\n"); }
};
class ErrorInI :public ErrorBase
{
public:

	ErrorInI() { printf("Error\n"); }

	void Message() { printf("Init marixes before m1 first then m2\n"); }
};