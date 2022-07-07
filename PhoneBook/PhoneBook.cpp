#include "PhoneBook.h"

//////////////////////////////////////////////////////////////////////
// Methods and Constructors for class Abonent


Abonent& Abonent::operator=(const Abonent& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	if (FIO) delete FIO;
	if (phone) delete phone;
	if (info) delete info;

	setFIO(obj.FIO);
	setPhone(obj.phone);
	setInfo(obj.info);

	return *this;
}

Abonent::Abonent(const Abonent& obj)
{
	setFIO(obj.FIO);
	setPhone(obj.phone);
	setInfo(obj.info);
}

void Abonent::setFIO()
{
	char buff[80];
	cout << "Enter FIO: ";
	cin.getline(buff, 80);
	setFIO(buff);
}

void Abonent::setFIO(const char* fio)
{
	if (strlen(fio) >= 80)
	{
		cout << "Занадто багато символів, максимум 80!";
		system("pause");
		system("cls");
		return;
	}
	if (FIO)
		delete FIO;
	int len = strlen(fio) + 1;
	FIO = new char[len];
	strcpy_s(FIO, len, fio);
}

void Abonent::setPhone()
{
	char buff[25];
	cout << "Enter Phone: ";
	cin.getline(buff, 25);
	setPhone(buff);
}

void Abonent::setPhone(const char* phone)
{
	if (strlen(phone) >= 25)
	{
		cout << "Занадто багато символів, максимум 25!";
		system("pause");
		system("cls");
		return;
	}
	if (this->phone)
		delete this->phone;
	int len = strlen(phone) + 1;
	this->phone = new char[len];
	strcpy_s(this->phone, len, phone);
}

void Abonent::setInfo()
{
	char buff[250];
	cout << "Enter Info: ";
	cin.getline(buff, 250);
	setInfo(buff);
}

void Abonent::setInfo(const char* info)
{
	if (strlen(info) >= 250)
	{
		cout << "Занадто багато символів, максимум 250!";
		system("pause");
		system("cls");
		return;
	}
	if (this->info)
		delete this->info;
	int len = strlen(info) + 1;
	this->info = new char[len];
	strcpy_s(this->info, len, info);
}

void Abonent::print()
{
	cout << setw(15) << left << FIO << setw(15) << phone << " " << info << endl;
}

string Abonent::toString()
{
	return " | " + (string)FIO + "     " + (string)phone + "     " + (string)info;
}


//////////////////////////////////////////////////////////////////////
// Methods for class PhoneBook

void PhoneBook::menu()
{
	while (true)
	{
		system("cls");

		int c = Menu::select_vertical({ "Додати", "Видалити", "Друк", "Пошук", "Внести у файл", "Зчитати з файлу" , "Вихід"}, HorizontalAlignment::Center, 5);
		switch (c)
		{
		case 0:
			addAbonent();
			
			break;
		case 1:
			delAbonent();
			break;
		case 2:
			print();
			break;
		case 3:
			findAbonent();
			break;
		case 4:
			writeAbonentsToFile();
			break;
		case 5:
			readAbonentsFromFile();
			break;
		case 6:
			exit(0);
		default:
			break;
		}
	}
}

void PhoneBook::print()
{
	system("cls");
	cout << "   ----------------------------------------------------------------------\n";
	cout << "   |                             ВСІ КОНТАКТИ                           |\n";
	cout << "   ----------------------------------------------------------------------\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << "   " << setw(4) << i + 1;
		abonents[i].print();
	}
	system("pause");
}

void PhoneBook::addAbonent()
{
	Abonent abonent;
	abonent.setFIO();
	abonent.setPhone();
	abonent.setInfo();
	addElemArray(abonents, size, abonent);
}

void PhoneBook::delAbonent()
{
	vector<string> delList;
	for (size_t i = 0; i < size; i++)
	{
		delList.push_back(to_string(i + 1) + abonents[i].toString());
	}
	int ind = Menu::select_vertical(delList, HorizontalAlignment::Left, 2);
	delElemArray(abonents, size, ind);
	this->wasDelete = true;
}

void PhoneBook::findAbonent()
{
	char findFio[80];
	cout << "Введіть ПІБ абонента якого треба знайти\n";
	cin.getline(findFio, 80);
	for (size_t i = 0; i < size; i++)
	{

		if (_strnicmp(findFio, abonents[i].FIO, strlen(findFio)) == 0)
		{
			abonents[i].isFind = true;
		}
	}
	for (size_t i = 0; i < size; i++)
	{
		if (abonents[i].isFind)
		{
			break;
		}
		cout << "Користувачів з таким ім'ям немає";
		system("pause");
		system("cls");
		return;
	}
	vector<string> List;
	for (size_t i = 0; i < size; i++)
	{
		if (abonents[i].isFind)
		{
			List.push_back(to_string(i + 1) + abonents[i].toString());
		}
		abonents[i].isFind = false;
	}
	Menu::select_vertical(List, HorizontalAlignment::Left, 2);
}

void PhoneBook::writeAbonentsToFile()
{
	if ((this->wasRead && this->wasDelete) || this->wasRead)
	{
		char nameOfFile[260];
		cout << "Введіть назву файлу який треба створити або знайти та внести в нього телефонну книгу(без \".txt\")\n";
		cin.getline(nameOfFile, 255);
		strcat_s(nameOfFile, ".txt");
		ofstream fout;
		fout.open(nameOfFile);
		for (size_t i = 0; i < size; i++)
		{
			fout << abonents[i].FIO << " ";
			fout << abonents[i].phone << " ";
			fout << abonents[i].info << " |\n";
		}
		fout << '\0';
		fout.close();
		this->wasDelete = false;
	}
	else
	{
		char nameOfFile[260];
		cout << "Введіть назву файлу який треба створити або знайти та внести в нього телефонну книгу(без \".txt\")\n";
		cin.getline(nameOfFile, 255);
		strcat_s(nameOfFile, ".txt");
		ofstream fout;
		fout.open(nameOfFile, ofstream::app);
		for (size_t i = 0; i < size; i++)
		{
			if (!wasRead)
			{
				fout << '\n';
			}
			fout << abonents[i].FIO << " ";
			fout << abonents[i].phone << " ";
			fout << abonents[i].info << " |\n";
		}
		fout << '\0';
		fout.close();
	}
}

void PhoneBook::readAbonentsFromFile()
{
	char nameOfFile[260];
	cout << "Введіть назву файлу який треба створити або знайти та внести в нього телефонну книгу(без \".txt\")\n";
	cin.getline(nameOfFile, 260);
	strcat_s(nameOfFile, ".txt");
	ifstream fin;
	fin.open(nameOfFile);
	if (!fin.is_open())
	{
		cerr << "Файл не был открыт, ошибка!\n";
		system("pause");
		system("cls");
		return;
	}
	else
	{
		while (!fin.eof())
		{
			Abonent abonent;
			char tmp[355];
			char tmp2[355];
			size_t length = 1;
			size_t s = 0;
			bool boolTmp = false;
			for (size_t i = 0; i < length; i++)
			{
				fin >> tmp;
				if (tmp[0] == '\0')
				{
					boolTmp = true;
					break;
				}
				if (tmp[0] == '+' || tmp[0] >= 48 && tmp[0] <= 57)
				{
					length = 1;
					break;
				}
				for (size_t j = 0; j < strlen(tmp); j++)
				{
					tmp2[s] = tmp[j];
					++s;
				}
				tmp2[s++] = ' ';
				++length;
			}
			if (!boolTmp)
			{
				tmp2[s - 1] = '\0';
				abonent.setFIO(tmp2);
				s = 0;
			}


			abonent.setPhone(tmp);

			char tmp3[355];
			for (size_t i = 0; i < length; i++)
			{
				if (boolTmp)
				{
					break;
				}
				fin >> tmp;
				if (tmp[strlen(tmp) - 1] == '|')
				{
					length = 1;
					break;
				}
				for (size_t j = 0; j < strlen(tmp); j++)
				{
					tmp3[s] = tmp[j];
					++s;
				}
				tmp3[s++] = ' ';
				++length;
			}
			if (boolTmp)
			{
				break;
			}
			tmp3[s - 1] = '\0';
			abonent.setInfo(tmp3);
			addElemArray(abonents, size, abonent);
		}
	}
	fin.close();
	this->wasRead = true;
}
