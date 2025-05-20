#include "cl_obj.h"
#include <iostream>
using namespace std;

cl_obj::cl_obj ( cl_base * p_head_object, string S_object_name ) :
	cl_base ( p_head_object, S_object_name ){} 							// Вызываем конструктор базового класса,
																		//параметры - указатель на головной объект и имя объекта
