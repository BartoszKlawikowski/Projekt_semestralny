#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dane.h"

class zapis
{
private:
	FILE* wskaznik;
public:
	void zapisz(dane &zapisywane_dane);
	dane odczytaj();
};

