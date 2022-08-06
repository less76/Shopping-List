#pragma once

class Shopping{
	private:
			std::string *description[3];
			int description_size;
			std::string remove;

	public:
		Shopping();
		~Shopping();
		void set_description_size(int);
		int get_description_size();
		void set_removal(std::string);
		std::string get_removal();

		struct Entry {
			std::string item;
			std::string total;
			std::string year;
		}Entry_t;

		void addEntrydescription();
		void removeEntrydescription();
		void addYear();
		void addPrice();
		void show_list();

		Shopping operator +(const Shopping& plus);
		Shopping operator -(const Shopping& minus);

	friend ostream& operator << (ostream& os, const Shopping& output);
	friend istream& operator >> (istream& is, Shopping& input);

};
