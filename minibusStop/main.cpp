#include "halt.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	size_t average_Passenger_ArrivalTime = 2; // повинно бути не менше 2
	size_t average_TimeOfArrival_OfMinibuses = 20; // повинно бути не менше 2
	size_t maximum_NumberOfPeople_AtTheStop_AtOneMoment = 5;

	Halt halt(average_Passenger_ArrivalTime, average_TimeOfArrival_OfMinibuses, maximum_NumberOfPeople_AtTheStop_AtOneMoment);
	halt.process();


	return 0;
}