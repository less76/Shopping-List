#include "pch.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;
#include "Shoppingdefs.h"

int main()
{
	Shopping foods,foods1;
	char option;
	int n = 0;

	cout << "This is your new shopping list" << endl; 

	while (1) {
		cout << "What is the name of the item" << endl;
		cin >> foods.Entry_t.item;

		cout << "What date this item extire mm/dd/yyyy" << endl;
		cin >> foods.Entry_t.year;

		cout << "What is the price of the item" << endl;
		cin >> foods;

		cout << "This is your shopping list" << endl;
		foods.show_list();
		
		cout << "Your total is $";
		cout << foods1 + foods << endl;
		
		cout << "Press 0 to stop adding to stopping adding to shopping list" << endl;
		cout << "Press d to revove something from the list" << endl;
		option = _getch();

		if (option == '0') {
			break;
		}

		if (option == 'd' || option == 'D') {

			cout << "What would you like to delete" << endl;
			cin >> foods.Entry_t.item;
			foods.removeEntrydescription();
			
			cout << "OK here is your updated shopping list" << endl;
			foods.show_list();

			cout << "Your total is $";
			cout << foods1 - foods << endl;

		}

	}

	return 0;
}