/*
Реализовать класс Бинарное дерево поиска (упорядоченное дерево) на базе динамической организации.
Структура записи: целочисленное поле данных (ключ), указатели на левый и правый дочерние элементы.

Основные операции:
1 вставка узла;
2 удаление узла;
3 поиск элемента по значению ключа;
4 вычисление глубины дерева;
9 уничтожение дерева;
10 проверка пустоты дерева.
11 Вывод линейных списков, соответствующих всем обходам дерева (осуществлять в одном пункте меню).

5 прямой обход дерева;
6 симметричный обход дерева;
7 обратный обход дерева;
8 обход дерева по ширине;

12 Дополнительные операции: формирование дерева из линейного списка (из файла), вывод всех обходов дерева в файл.
*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include "bst.h"
#include <string>


using namespace std;
void output(int);


int main()
{

	bst tree;

	bst::iterator itr;

	cout << "|--------------------------------------------------------------------------|" << endl;
	cout << "|                                   MAIN MENU                              |" << endl;
	cout << "|--------------------------------------------------------------------------|" << endl;
	cout << "| 1) Insert node                                                           |" << endl;
	cout << "| 2) Node removal                                                          |" << endl;
	cout << "| 3) Search item by key value                                              |" << endl;
	cout << "| 4) Calculation depth of the tree                                         |" << endl;
	cout << "| 5) Destruction of a tree                                                 |" << endl;
	cout << "| 6) Check the emptiness of the tree                                       |" << endl;
	cout << "| 7) Displays linear lists                                                 |" << endl;
	cout << "| 8) Clear screen                                                          |" << endl;
	cout << "| 9) Exit                                                                  |" << endl;
	cout << "|--------------------------------------------------------------------------|" << endl;
	string trigger = "8";


	while (!(trigger == "9")) {

		cout << "your command.....";
		cin >> trigger;

		switch (trigger[0]) {

		case '9':
		{
			break;
		}

		case '8':
		{
			system("cls");
			cout << "|--------------------------------------------------------------------------|" << endl;
			cout << "| 1) Insert node                                                           |" << endl;
			cout << "| 2) Node removal                                                          |" << endl;
			cout << "| 3) Search item by key value                                              |" << endl;
			cout << "| 4) Calculation depth of the tree                                         |" << endl;
			cout << "| 5) Destruction of a tree                                                 |" << endl;
			cout << "| 6) Check the emptiness of the tree                                       |" << endl;
			cout << "| 7) Displays linear lists                                                 |" << endl;
			cout << "| 8) Clear screen                                                          |" << endl;
			cout << "| 9) Exit                                                                  |" << endl;
			cout << "|--------------------------------------------------------------------------|" << endl;
			break;
		}

		case '7':
		{
			if (!tree.isempty()) {
				cout << "NLR" << endl;
				tree.NLR(output); cout << endl;
				cout << "LNR" << endl;
				tree.LNR(output); cout << endl;
				cout << "LRN" << endl;
				tree.LRN(output); cout << endl;
				cout << "width" << endl;
				tree.width(output); cout << endl;
			}
			break;
		}

		case '6':
		{
			if (tree.isempty())
				cout << "empty" << endl;
			else
				cout << "not empty" << endl;
			break;
		}

		case '5':
		{
			if (!tree.isempty())
				tree.destruct();
			break;
		}

		case '4':
		{
			
			if (!tree.isempty()) {
				int depth;
				depth = tree.dark_deep_tree(tree.get_root());
				cout << "depth = " << depth << endl;
			}
			else
				cout << "depth = 0"<< endl;
			break;
		}

		case '3':
		{
			int searching;
			cout << "Insert the searching value ... ";
			cin >> searching;
			cout << endl;
			if (tree.search(searching))
				cout << "Tree have such element" << endl;
			else
				cout << "NO such elements in tree" << endl;
			break;
		}

		case '2':
		{
			int rem;
			cout << "DELETE THIS ... ";
			cin >> rem;
			cout << endl;
			if (!tree.isempty()) {
				tree.delete_by_value(rem);
				cout << "DELETED" << endl;
			}
			break;
		}


		case '1':
		{
			int added;
			cout << "add element ... ";
			cin >> added;
			cout << endl;
			tree.add(added);
			break;
		}



		default:
		{
			trigger = "8";
			cout << ".....wrong command....."; cout << endl;
			break;
		}

		}
	}

	return 0;
}

void output(int data) {
	cout << data << " ";
}

