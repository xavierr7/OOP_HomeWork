#include "House.h"

/////////////////////////////////
//Person


Tenants::Tenants(const Tenants& tenant)
{
	setFIO(tenant.FIO);
	this->age = tenant.age;
}

Tenants& Tenants::operator=(const Tenants& tenant)
{
	if (this == &tenant)
	{
		return *this;
	}
	if (FIO)
	{
		delete FIO;
	}
	setFIO(tenant.FIO);
	this->age = tenant.age;

	return *this;
}

void Tenants::setFIO()
{
	char buff[85];
	cout << "Enter FIO: ";
	cin.getline(buff, 85);
	setFIO(buff);
}

void Tenants::setFIO(const char* fio)
{
	if (strlen(fio) >= 80)
	{
		cout << "Too many symbols!";
		system("pause");
		system("cls");
		return;
	}
	if (FIO)
		delete FIO;
	size_t len = strlen(fio) + 1;
	FIO = new char[len];
	strcpy_s(FIO, len, fio);
}

void Tenants::setAge()
{
	uint16_t tmp;
	while (true)
	{
		cout << "Enter age: ";
		cin >> tmp;
		cin.ignore();
		if (tmp > 130)
		{
			cout << "You probably dead now :/\n";
			system("pause");
			system("cls");
		}
		else if (tmp <= 0)
		{
			cout << "You weren't born yet :/\n";
			system("pause");
			system("cls");
		}
		else
		{
			this->age = tmp;
			break;
		}
	}
	 
}

void Tenants::print()
{
	cout << setw(15) << left << FIO << setw(15) << age << endl;
}

string Tenants::toString()
{
	return " | " + (string)FIO + "   " + (string)to_string(age);
}

////////////////////////////////
//Apartment



void Apartment::menu()
{
	bool tmp = false;
	while (true)
	{
		system("cls");

		int c = Menu::select_vertical({ "Додати мешканця", "Видалити мешканця", "Показати усіх машканців квартири", "Вихід" }, HorizontalAlignment::Center, 5);
		switch (c)
		{
		case 0:
			addTenants();
			break;
		case 1:
			delTenants();
			break;
		case 2:
			print();
			break;
		case 3:
			tmp = true;
			break;
		}
		if (tmp)
		{
			system("cls");
			break;
		}
	}
}

void Apartment::print()
{
	system("cls");
	cout << "   ----------------------------------------------------------------------\n";
	cout << "   |                             ВСІ МЕШКАНЦІ                           |\n";
	cout << "   ----------------------------------------------------------------------\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << "   " << setw(4) << i + 1;
		tenants[i].print();
	}
	system("pause");
}

void Apartment::addTenants()
{
	Tenants tenant;
	tenant.setFIO();
	tenant.setAge();
	addElemArray(tenants, size, tenant);
}

void Apartment::delTenants()
{
	if (size == 0)
	{
		return;
	}
	vector<string> delList;
	for (size_t i = 0; i < size; i++)
	{
		delList.push_back(to_string(i + 1) + tenants[i].toString());
	}
	int ind = Menu::select_vertical(delList, HorizontalAlignment::Left, 2);
	delElemArray(tenants, size, ind);
}
