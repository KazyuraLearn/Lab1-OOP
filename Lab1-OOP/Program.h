#ifndef PROGRAM_H
#define PROGRAM_H
#include <fstream>
using namespace std;
//----------------------------------------------------------------------------------------------
// Геометрическая фигура
//----------------------------------------------------------------------------------------------
class shape
{
	private:
		enum color { RED, ORANGE, YELLOW, GREEN, BLUE, DARKBLUE, PURPLE };			
	protected:		
		color c;
		void getColor(int colorNumber);
		void outColor(ofstream &ofst);
	public:
		shape() {};
		static shape* in(ifstream &ifst); 
		virtual void inData(ifstream &ifst) = 0;
		virtual void outData(ofstream &ofst) = 0;
};
//----------------------------------------------------------------------------------------------
// Прямоугольник
//----------------------------------------------------------------------------------------------
class rectangle : public shape
{
	private:
		int x, y;
	public:
		void inData(ifstream &ifst); 
		void outData(ofstream &ofst); 
		rectangle() {};
};
//----------------------------------------------------------------------------------------------
// Круг
//----------------------------------------------------------------------------------------------
class circle : public shape
{
	private:
		int r;
	public:
		void inData(ifstream &ifst);
		void outData(ofstream &ofst);
		circle() {};
};
//----------------------------------------------------------------------------------------------
// Элемент контейнера - односвязного списка
//----------------------------------------------------------------------------------------------
class node
{		
	public:		
		shape* data;
		node* next;
		node(shape* data, node* next);
};
//----------------------------------------------------------------------------------------------
// Контейнер - односвязный список
//----------------------------------------------------------------------------------------------
class container
{
	private:
		node* head;
		node* last;
	public:
		container() { head = NULL; last = NULL; }
		void initContainer();
		void inContainer(ifstream &ifst);
		void outContainer(ofstream &ofst);
		void clearContainer();
		~container() { clearContainer(); } 
};
#endif