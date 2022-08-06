#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Shopping.h"

Shopping::Shopping()
{
	description_size = 0;

	for (int i = 0; i < 3; i++)
		description[i] = NULL;
}

Shopping::~Shopping()
{
	
	for (int i = 0; i < 3; i++)
	delete[]description[i];
}

void Shopping::set_description_size(int description_size) {
	this->description_size = description_size;
}

int Shopping::get_description_size() {
	return description_size;
}

void Shopping::set_removal(std::string remove) {
	this->remove = remove;
}

std::string Shopping::get_removal() {
	return this->remove;
}

void Shopping::addEntrydescription(){

	std::string *new_array = new std::string[get_description_size() + 1];

	if (get_description_size() == 0) {
		*new_array = this->Entry_t.item;
		description[0] = new_array;
	}

	else {

		for (int i = 0; i < get_description_size(); i++) {
			*new_array++ = *description[0]++;
		}

		*new_array = this->Entry_t.item;
		new_array -= get_description_size();

		description[0] = new_array;

	}

}

void Shopping::removeEntrydescription() {

	int found = 0;

	std::string** new_array = new std::string*[3];
	for (int i = 0; i < 3; i++)
		new_array[i] = new std::string[get_description_size()];

	for (int i = 0; i < get_description_size() - 1; i++) {

		for (int j = 0; j < 3; j++) {
			*new_array[j] = *description[j]++;
		}

		if (*new_array[0] == this->Entry_t.item) {
			remove = *new_array[2];

			for (int j = 0; j < 3; j++) {
				*new_array[j] = *description[j]++;
			}


			found = 1;
		}

		for (int j = 0; j < 3; j++) {
			*new_array[j]++;
		}

	}

	if (found == 0) {
		cout << "Can not find string in list" << endl;

		description[0] -= get_description_size() - 1;

	}

	else {

		for (int j = 0; j < 3; j++) {
			new_array[j] -= get_description_size() - 1;
		}

		for (int j = 0; j < 3; j++) {
			description[j] = new_array[j];
		}

		description_size--;

	}
}

void Shopping::addYear() {

	int check = 0;

	for (int i = 0; i < 2; i++) {
		if ((this->Entry_t.year[i] < '0' || this->Entry_t.year[i] > '9' ) || (this->Entry_t.year[i + 3] < '0' || this->Entry_t.year[i + 3] > '9')) {
			cout << "Wrong format" << endl;
			check = 1;
			break;
		}
	}

	if (this->Entry_t.year[2] != '/' || this->Entry_t.year[5] != '/') {
		cout << "Wrong format" << endl;
		check = 1;
	}

	for (int i = 6; i < 9; i++) {
		if (this->Entry_t.year[i] < '0' || this->Entry_t.year[i] > '9') {
			cout << "Wrong year" << endl;
			check = 1;
			break;
		}
	}

	if (check == 0) {

		std::string *new_array = new std::string[get_description_size() + 1];

		if (get_description_size() == 0) {
			*new_array = this->Entry_t.year;
			description[1] = new_array;
		}

		else {

			for (int i = 0; i < get_description_size(); i++) {
				*new_array++ = *description[1]++;
			}

			*new_array = this->Entry_t.year;
			new_array -= get_description_size();

			description[1] = new_array;
		}

	}

}

void Shopping::addPrice() {

	std::string *new_array = new std::string[get_description_size() + 1];

	if (get_description_size() == 0) {
		*new_array = this->Entry_t.total;
		description[2] = new_array;
	}

	else {

		for (int i = 0; i < get_description_size(); i++) {
			*new_array++ = *description[2]++;
		}

		*new_array = this->Entry_t.total;
		new_array -= get_description_size();

		description[2] = new_array;

	}

	description_size++;

}

void Shopping::show_list() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < get_description_size(); j++) {
			if (i == 2) {
				cout << "$";
			}
			cout << *description[i]++;
			cout << "   ";
		}

		description[i] -= get_description_size();
		cout << " " << endl;
	}
}

istream& operator >> (istream& is, Shopping& input) {
	is >> input.Entry_t.total;
	input.addEntrydescription();
	input.addYear();
	input.addPrice();
	return is;
}

ostream& operator << (ostream& os, const Shopping& output) {
	os << output.Entry_t.total;
	return os;
}

Shopping Shopping::operator+(const Shopping& plus) {
	Shopping temp;

	double number1 = atof(this->Entry_t.total.c_str());
	double number2 = atof(plus.Entry_t.total.c_str());
	double number3 = number1 + number2;

	auto num_str = std::to_string(number3);
	this->Entry_t.total = num_str;
	temp.Entry_t.total = num_str;

	return temp;
}

Shopping Shopping::operator-(const Shopping& minus) {
	Shopping temp;
	
	double number1 = atof(this->Entry_t.total.c_str());
	double number2 = atof(minus.remove.c_str());
	double number3 = number1 - number2;

	auto num_str = std::to_string(number3);
	this->Entry_t.total = num_str;
	temp.Entry_t.total = num_str;

	return temp;
}
