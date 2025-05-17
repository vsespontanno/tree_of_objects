#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <string>
#include <vector>
using namespace std;

class cl_base
{
	string s_object_name; 																// Имя текущего объекта
	cl_base * p_head_object; 															// Указатель на головной объект
	vector<cl_base*> subordinate_objects; 												// Указатели на подчиненные объекты
	public:
		cl_base ( cl_base * p_head_object, string s_object_name = "Base_object" );		// Конструктор создает объект с указанием на головной объект и именем объекта
		~cl_base ( ); 																	// Деструктор по умолчанию
		bool change_name ( string s_object_name ); 										// Изменяет имя объекта (false, если имя уже занято)
		string get_name ( ); 															// Возвращает имя текущего объекта
		cl_base * get_head ( ); 														// Возвращает указатель на головной объект
		void print_tree ( ); 															// Выводит дерево иерархии объектов
		cl_base * get_subordinate ( string s_object_name ); 							// Возвращает указатель на подчиняемый объект
};

#endif
