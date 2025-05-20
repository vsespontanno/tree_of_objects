#include "cl_application.h"
#include <string>
#include <iostream>
using namespace std;

cl_application::cl_application (cl_base* p_head_object ) : cl_base ( p_head_object ){} 										// Вызываем конструктор базового класса,
																				//параметры - указатель на головной объект
void cl_application::build_tree_objects ( )
{
	string p_head_name, sub_name; 																// Имя корневого и имя подчиненных
	cl_base * p_head_object = this; 															// Текущий объект назначается корневым
	cl_base * subordinate_object = nullptr; 														// Указатель на подчиненный объект не инициализирован
	cin >> p_head_name; 																	// Вводим имя корневого объекта
	this -> change_name ( p_head_name ); 															// Текущему корневому оъекту присваивается введенное имя
	while(true)
	{
		cin >> p_head_name >> sub_name; 														// Вводим имя головного и подчиненного ему объекта
		if ( p_head_name == sub_name ) {break;} 													// Если имя корневого объекта равно имени подчиненного, то завершаем построение дерева
		if ( subordinate_object != nullptr &&
			p_head_name			== subordinate_object -> get_name ( ) ) 								// Если подчиненный объект уже существует
																				//  и его имя совпадает с введенным именем головного
		{
			p_head_object = subordinate_object; 													// Присваем головному объекту имя этого подчиненного
		}
		if ( p_head_object -> get_subordinate ( sub_name ) == nullptr && 										// Если у головного объекта нет подчиненного с таким именем
			p_head_name == p_head_object -> get_name ( ) ) 												// и введенное имя корневого объекта совпадает с именем текущего корневого объекта
		{
			subordinate_object = new cl_obj ( p_head_object, sub_name ); 										// Создаем новый подчиненный объект
		}
	}
}

int cl_application::exec_app ( )
{
	cout << get_name ( ); 																	// Вывод имени корневого объекта
	print_tree ( ); 																	// Вывод дерева иерархии объектов
	return 0;
}
