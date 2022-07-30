#pragma once
#include "halt.h"

std::string randomizerOfName()
{
	std::string listName[20]{ "Ivan", "Artem", "Kateryna", "Max", "Tetyana", "Andriy", "Sergiy", "Olga", "Sophia",
		"Karina", "Dmytro", "Elena", "Eren", "Levi", "Hisoka", "Killua", "Gon", "Erwin", "Kurapika", "Leorio" };
	size_t index = rand() % 20;
	return listName[index];
}

std::string randomizerOfBrand()
{
	std::string listName[13]{ "ANKAI", "HIGER", "HYUNDAI", "IKARUS", "IRIZAR", "IVECO", "KIA", "NEOPLAN", "OTOKAR",
		"SCANIA", "SETRA", "TEMSA", "YUTONG" };
	size_t index = rand() % 13;
	return listName[index];
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}