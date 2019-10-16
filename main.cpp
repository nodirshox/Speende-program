#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
int menu();
double e;
void Main_menu(int x);
class Registration
{
private:
	string name;
	int age;
	double initial_balance = 0;
public:
	void getdata()
	{
		cout << "Enter your personal information : " << endl;
		cout << "Name : ";
		cin >> name;
		while (true)//Error Handling
		{
			cout << "Age : ";
			cin >> age;
			if (cin.good())
			{
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cout << "Try again!(Inter only integer number)" << endl;
			cin.ignore(10, '\n');
		}
		while (true)//Error Handling
		{
			cout << "Initial balance : ";
			ofstream money("money.txt");
			ofstream money2("numbers.txt");
			while (cin >> initial_balance)
			{
				money << "initial_balance " << initial_balance << endl;
				money2 << initial_balance << endl;
				break;
			}
			e = initial_balance;
			if (cin.good())
			{
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cout << "Try again!(Inter only number)" << endl;
			cin.ignore(10, '\n');
		}
	}
	void showdata()
	{
		cout << "Name = " << name << endl;
		cout << "Age = " << age << endl;
		cout << "Initial balance = " << initial_balance << "$" << endl;

	}
};
int main()
{
	//ifstream read("existing.txt");
	//e = mo;
	//getline(read, mo);
	cout << "-----------------------------\n|Welcome to Speende program |\n-----------------------------" << endl;
	ifstream read("information.txt");
	if (!read)
	{
		Main_menu(0);
	}
	int option_main_menu;
	option_main_menu = menu();
	while (option_main_menu != 4)
	{
		switch (option_main_menu){
		case 0:
			Main_menu(0);
		case 1:
			Main_menu(1);
			break;
		case 2:
			Main_menu(2);
			break;
		case 3:
			Main_menu(3);
			break;

		}
		option_main_menu = menu();
	}
	system("pause");
	return 0;
}
//menu function
int menu()
{
	int choice;
	cout << "\n=========================\n";
	cout << "|1 ) Show my balance" << endl;
	cout << "|2 ) Expence(-)" << endl;
	cout << "|3 ) Income(+)" << endl;
	cout << "|4 ) Exit." << endl;
	cout << "=========================\n";
	cin >> choice;
	return choice;
}
//main menu
void Main_menu(int x)
{
	Registration user;
	string name_of_value;
	double money;
	if (x == 0)
	{
		user.getdata();
		ofstream infofile("information.txt");
		infofile.write((char*)(&user), sizeof(user));
		infofile.close();
		cout << "\n---------------------\nYour information:\n" << endl;
		ifstream outfile("information.txt");
		outfile.read((char *)(&user), sizeof(user));
		user.showdata();
		outfile.close();
		cout << "---------------------" << endl;
	}
	if (x == 1)
	{
		ifstream Budjet("money.txt");
		//if (Budjet.good() == 0)//If money.txt does not exist 
		//{
		//	cout << "Your balance is 0$" << endl;
		//	menu();
		//}
		cout << "\n---------------------\nYour balance:\n" << endl;
		while (Budjet >> name_of_value >> money)
		{
			cout << "|" << name_of_value << " <=> " << money << "$" << endl;
		}
		cout << "---------------------" << endl;
		cout << "Existin money: " << e << "$" << endl;
	}
	if (x == 2)
	{
		cout << "Enter your expences (first name of expence then amount of money) : " << endl;
		ofstream Budjet("money.txt", ios::app);
		ofstream Budjet2("numbers.txt", ios::app);
		while (cin >> name_of_value >> money)
		{
			Budjet << name_of_value << " -" << money << endl;
			Budjet2 << "-" << money << endl;
			break;
		}
		e -= money;
	}
	if (x == 3)
	{
		cout << "Enter your income (first name of income then amount of money) : " << endl;
		ofstream Budjet("money.txt", ios::app);
		ofstream Budjet2("numbers.txt", ios::app);
		while (cin >> name_of_value >> money)
		{
			Budjet << name_of_value << " " << money << endl;
			Budjet2 << money << endl;
			break;
		}
		e += money;
	}
}