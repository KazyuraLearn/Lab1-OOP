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

void shape::getColor(int colorNumber)
{
	switch (colorNumber)
	{
		case 1:
			c = color::RED;
			break;
		case 2:
			c = color::ORANGE;
			break;
		case 3:
			c = color::YELLOW;
			break;
		case 4:
			c = color::GREEN;
			break;
		case 5:
			c = color::BLUE;
			break;
		case 6:
			c = color::DARKBLUE;
			break;
		case 7:
			c = color::PURPLE;
			break;
	}
}

void shape::outColor(ofstream &ofst)
{
	switch (c)
	{
		case color::RED:
			ofst << "RED" << endl;
			break;
		case color::ORANGE:
			ofst << "ORANGE" << endl;
			break;
		case color::YELLOW:
			ofst << "YELLOW" << endl;
			break;
		case color::GREEN:
			ofst << "GREEN" << endl;
			break;
		case color::BLUE:
			ofst << "BLUE" << endl;
			break;
		case color::DARKBLUE:
			ofst << "DARKBLUE" << endl;
			break;
		case color::PURPLE:
			ofst << "PURPLE" << endl;
			break;
	}
}
//----------------------------------------------------------------------------------------------
// Прямоугольник
//----------------------------------------------------------------------------------------------
void rectangle::inData(ifstream &ifst) 
{
	int temp;
	ifst >> x >> y >> temp;
	getColor(temp);
}
void rectangle::outData(ofstream &ofst) 
{
	ofst << "It is Rectangle: x = " << x << ", y = " << y << " color: ";
	outColor(ofst);
}
//----------------------------------------------------------------------------------------------
// Круг
//----------------------------------------------------------------------------------------------
void circle::inData(ifstream &ifst) 
{
	int temp;
	ifst >> r >> temp;
	getColor(temp);
}

void circle::outData(ofstream &ofst) 
{
	ofst << "It is Triangle: r = " << r << " color: ";
	outColor(ofst);
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
	while (current != NULL)
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