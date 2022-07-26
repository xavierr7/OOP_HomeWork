#include "halt.h"

string randomizerOfName();

int main()
{
	u_int averagePassengerArrivalTime;
	u_int averageTimeOfArrivalOfMinibuses;
	u_int maximumNumberOfPeopleAtTheStop;




	return 0;
}

string randomizerOfName()
{
	string listName[20]{"Ivan", "Artem", "Kateryna", "Max", "Tetyana", "Andriy", "Sergiy", "Olga", "Sophia", "Karina", "Dmytro", "Elena", "Eren", "Levi", "Hisoka", "Killua", "Gon", "Hanji", "Kurapika", "Leorio"};
	u_int index = rand() % 20;
	return listName[index];
}
