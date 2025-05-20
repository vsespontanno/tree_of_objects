#ifndef __CL_OBJ__H
#define __CL_OBJ__H
#include "cl_base.h"
#include <iostream>
using namespace std;

class cl_obj : public cl_base{ 										             	// Наследуем метода базового класса
	public:
		cl_obj ( cl_base * p_head_object, string S_object_name );						// Конструктор создает корневой объект
};

#endif
