#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include <string>
#include "cl_base.h"
#include "cl_obj.h"
using namespace std;

class cl_application : public cl_base 							  // Наследуем метода базового класса
{
	public:
		cl_application ( cl_base * p_head_object ); 			// Конструктор создает корневой объект
		void build_tree_objects ( ); 						        	// Построение дерева иерархии объектов
		int exec_app ( ); 									            	// Запуск алгоритма (вывод дерева)
};

#endif
