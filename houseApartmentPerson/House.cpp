#include "House.h"

uint16_t House::countOfPeople = 0;

/////////////////////////////////
//Tenants


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

Apartment::Apartment(const Apartment& apartment)
{	
	tenants = new Tenants[size];
	this->size = apartment.size;
	for (size_t i = 0; i < size; i++)
	{
		tenants[i] = apartment.tenants[i];
	}
}

Apartment& Apartment::operator=(const Apartment& apartment)
{
	if (this == &apartment)
	{
		return *this;
	}
	if (tenants)
	{
		delete[] tenants;
	}
	tenants = new Tenants[size];
	this->size = apartment.size;
	for (size_t i = 0; i < size; i++)
	{
		tenants[i] = apartment.tenants[i];
	}

	return *this;
}

void Apartment::menu()
{
	bool tmp = false;
	while (true)
	{
		system("cls");

		int c = Menu::select_vertical({ "Add tenant", "Delete tenant", "Show all tenants of this apartment", "Exit" }, HorizontalAlignment::Center, 5);
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

string Apartment::toString()
{
	return  " <- number of apartment";
}

void Apartment::print()
{
	system("cls");
	cout << "   ----------------------------------------------------------------------\n";
	cout << "   |                              ALL TENANTS                           |\n";
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
	House::countOfPeople++;
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
	House::countOfPeople--;
}

/////////////////////////////////////////////
//House 

House::House(const House& house)
{
	size = house.size;
	apartments = new Apartment[size];
	for (size_t i = 0; i < size; i++)
	{
		apartments[i] = house.apartments[i];
	}
	size_t len = strlen(house.address) + 1;
	address = new char[len];
	strcpy_s(address, len, house.address);
	elevator = house.elevator;
	countOfFloors = house.countOfFloors;

}

House& House::operator=(const House& house)
{
	if (this == &house)
	{
		return *this;
	}
	if (apartments)
	{
		delete[] apartments;
	}
	if (address)
	{
		delete address;
	}
	size = house.size;
	apartments = new Apartment[size];
	for (size_t i = 0; i < size; i++)
	{
		apartments[i] = house.apartments[i];
	}

	size_t len = strlen(house.address) + 1;
	address = new char[len];
	strcpy_s(address, len, house.address);
	countOfFloors = house.countOfFloors;
	elevator = house.elevator;

	return *this;
}

void House::menu()
{
	while (true)
	{
		system("cls");

		int c = Menu::select_vertical({ "Show info about House", "Work with apartment", "Exit" }, HorizontalAlignment::Center, 5);
		switch (c)
		{
		case 0:
			showInfo();
			break;
		case 1:
			workWithApartment();
			break;
		case 2:
			exit(0);
			break;
		}
	}
}

void House::setInfo()
{
	apartments = new Apartment[size];
	cout << "Enter the address: \n";
	char buff[120];
	cin.getline(buff, 120);
	size_t len = strlen(buff) + 1;
	address = new char[len];
	strcpy_s(address, len, buff);
	system("pause");
	system("cls");

	uint16_t tmp;
	while (true)
	{
		cout << "Enter the count of floors: \n";
		cin >> tmp;
		cin.ignore();
		if (tmp <= 0)
		{
			cout << "it`s impossible :/\n";
			system("pause");
			system("cls");
		}
		else
		{
			this->countOfFloors = tmp;
			system("cls");
			break;
		}
	}

	cout << "Is there an elevator and does it work?\n";
	int ind = Menu::select_vertical({ "Yes", "No " }, HorizontalAlignment::Left, 2);
	if (ind == 0)
	{
		elevator = true;
	}
	else
	{
		elevator = false;
	}
}

void House::showInfo()
{
	system("cls");
	cout << "Address of the house: " << address << endl << endl;
	cout << "Number of residents: " << countOfPeople << endl << endl;
	cout << "Number of floors in the house: " << countOfFloors << endl << endl;
	cout << "Number of apartments in the house: " << size << endl << endl;
	cout << "Is there an elevator and does it work: ";
	if (elevator == true)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	system("pause");
}

void House::workWithApartment()
{
	vector<string> List;
	for (size_t i = 0; i < size; i++)
	{
		List.push_back(to_string(i + 1) + apartments[i].toString());
	}
	int ind = Menu::select_vertical(List, HorizontalAlignment::Left, 2);
	apartments[ind].menu();
}
