#include <fstream>
#include "Program.h"
using namespace std;
//----------------------------------------------------------------------------------------------
// Геометрическая фигура
//----------------------------------------------------------------------------------------------
shape* shape::in(ifstream &ifst)
{
	shape* sp = NULL;
	int k;
	ifst >> k;
	switch (k)
	{
		case 1:
			sp = new rectangle; 
			break;
		case 2:
			sp = new circle; 
			break;
	}
	sp->inData(ifst);
	return sp;
}
//----------------------------------------------------------------------------------------------
// Прямоугольник
//----------------------------------------------------------------------------------------------
void rectangle::inData(ifstream &ifst) 
{
	ifst >> x >> y;
}
void rectangle::outData(ofstream &ofst) 
{
	ofst << "It is Rectangle: x = " << x << ", y = " << y << endl;
}
//----------------------------------------------------------------------------------------------
// Круг
//----------------------------------------------------------------------------------------------
void circle::inData(ifstream &ifst) 
{
	ifst >> r;
}

void circle::outData(ofstream &ofst) 
{
	ofst << "It is Triangle: r = " << r << endl;
}
//----------------------------------------------------------------------------------------------
// Контейнер - односвязный список
//----------------------------------------------------------------------------------------------
void container::initContainer()
{
	head = NULL;
	last = NULL;
}

void container::inContainer(ifstream &ifst)
{
	while (!ifst.eof())
	{
		node* temp = new node;
		shape* data = shape::in(ifst);
		temp->data = data;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			last = temp;
		}
		else
		{
			last->next = temp;
			last = temp;
		}
	}
}

void container::outContainer(ofstream &ofst)
{
	ofst << "Container contains  elements:" << endl;
	node* current = head;
	if (current == NULL)
		return;
	while (current->next != NULL)
	{
		current->data->outData(ofst);
		current = current->next;
	}
}

void container::clearContainer()
{
	while (head != NULL)
	{
		node* forDelete = head;
		head = head->next;
		delete forDelete;
	}
}