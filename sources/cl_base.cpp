#include "cl_base.h"
#include <iostream>
#include <vector>
using namespace std;

cl_base::cl_base( cl_base * p_head_object, string s_object_name )
{
	this -> p_head_object = p_head_object; 														// Фиксация наименования созданного объекта
	this -> s_object_name = s_object_name; 														// Фиксация значения указателя на головной объект
	if ( p_head_object ) 																		// Если головной объект существует
	{
		p_head_object -> subordinate_objects.push_back ( this ); 								// Добавление значения указателя на созданный объект в список
																								// указателей на подчиненные объекты головного объекта
	}
}

bool cl_base::change_name ( string s_object_name )
{
	if ( get_head ( ) != nullptr && get_subordinate ( s_object_name ) != nullptr ) 				// Если у объекта есть головной объект
																								// и у головного объекта уже есть подчиненные объекты с таким именем
	{
		return false; 																			// Возвращаем false, т.к. имя не уникально
	}
	this -> s_object_name = s_object_name; 														// Фиксация нового наименования объекта
	return 1; 																					// Возврат успеха операции
}

string cl_base::get_name ( )
{
	return s_object_name; 																		// Возврат наименования текущего объекта
}

cl_base* cl_base::get_head ( )
{
	return p_head_object; 																		// Возврат значения указателя на головной объект текущего объекта
}


void cl_base::print_tree ( )
{
	if ( !subordinate_objects.empty ( ) ) 														// Если есть подчиненные объекты
	{
		cout << endl << this -> get_name ( ); 													// Выводим имя головного объекта
		for (int i = 0;  i < subordinate_objects.size ( ); i++) 								// Проходимся по всему списку указателей
		{
			cout << "  " << subordinate_objects[i] -> get_name ( ); 							// Вывод имени подчиненного объекта
		}
		subordinate_objects[subordinate_objects.size ( ) - 1] -> print_tree ( ); 				// Рекурсивно вызываем метод print_tree() для последнего подчиненного объекта, тем самым строим дерево иерархии
	}
}

cl_base* cl_base::get_subordinate( string s_object_name )
{
	for ( int i = 0; i < subordinate_objects.size ( ); i++ ) 									// Проходимся по всему списку указателей
	{
		if ( subordinate_objects[i] -> s_object_name == s_object_name ) 						// Если имя текущего объекта совпадает с именем объекта, который мы ищем
		{
			return subordinate_objects[i]; 														// Возвращаем указатель на этот объект
		}
	}
	return nullptr; 																			// Если ничего не нашли, то возвращаем нулевой указатель
}

cl_base::~cl_base ( )
{
	for ( int i = 0; i < subordinate_objects.size ( ); i++ )
	{
		delete subordinate_objects[i];
	}
}