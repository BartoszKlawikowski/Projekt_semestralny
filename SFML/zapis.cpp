#include "zapis.h"

void zapis::zapisz(dane &zapisywane_dane)
{
	wskaznik = fopen("dane.dat", "wb");
	fwrite(&zapisywane_dane, sizeof(zapisywane_dane), 1, wskaznik);
	fclose(wskaznik);
}

dane zapis::odczytaj()
{
	dane temp;
	wskaznik = fopen("dane.dat", "rb");
	fread(&temp, sizeof(dane), 1, wskaznik);
	fclose(wskaznik);

	return temp;
}