#include "h.h"

#include <iostream>
#include <set>

#include "conio.h"

using namespace std;

static vector<mus> Mass_mus;
static set<int> Mass_fuu;

void menu() {
	Mass_mus.push_back(mus("Белые розы.mp3", "Ласковый май", 2));                     //
	Mass_mus.push_back(mus("Поговори со мной ольга.mp3", "Ночные снайперы", 1));      //
	Mass_mus.push_back(mus("Орбит без сахара.mp3", "Сплин", 1));                      //

	AudioDevicePtr device = OpenDevice();
	OutputStreamPtr sound = OpenSound(device, Mass_mus[0].get_name_song(), true);

	int i = 0;
	int k = 0;
	char ch = '/';
	cout << "1 - следующий трек \n 2 - предыдущий трек \n 3 - пауза \n 4 - плей \n 5 - дизлайк \n 6 - поставить трек на повтор" << endl;
	while (ch != 27) {
		sound->setRepeat(false);
		ch = _getch();
		switch (ch) {
		case '1':
			i = (i + 1) > Mass_mus.size()-1 ? 0 : i + 1;
			k = i;
			while (Mass_fuu.count(Mass_mus[i].get_genre())) {
				i++;
				if (i > Mass_mus.size()-1) {
					i = 0;
				}
				if (i == k) {
					cout << "В БД нет музыки, которая бы подходила под Ваши вкусовые предпочтения :(" << endl;
					exit(1);
				}
			}
			sound = OpenSound(device, Mass_mus[i].get_name_song(), true);
			sound->play();
			cout << "Сейчас играет: " << Mass_mus[i].get_name_executor() << " - " << Mass_mus[i].get_name_song() << endl;
			break;
		case '2':
			i--;
			sound = OpenSound(device, Mass_mus[i].get_name_song(), true);
			sound->play();
			cout << "Сейчас играет: " << Mass_mus[i].get_name_executor() << " - " << Mass_mus[i].get_name_song() << endl;
			break;
		case '3':
			sound->stop();
			break;
		case '4':
			sound->play();
			cout << "Сейчас играет: " << Mass_mus[i].get_name_executor() << " - " << Mass_mus[i].get_name_song() << endl;
			break;
		case '5':
			Mass_fuu.insert(Mass_mus[i].get_genre());
			i = (i + 1) > Mass_mus.size()-1 ? 0 : i + 1;
			k = i;
			while (Mass_fuu.count(Mass_mus[i].get_genre())) {
				i++;
				if (i > Mass_mus.size()-1) {
					i = 0;
				}
				if (i == k) {
					cout << "В БД нет музыки, которая бы подходила под Ваши вкусовые предпочтения :(" << endl;
					exit(1);
				}
			}
			sound = OpenSound(device, Mass_mus[i].get_name_song(), true);
			sound->play();
			cout << "Сейчас играет: " << Mass_mus[i].get_name_executor() << " - " << Mass_mus[i].get_name_song() << endl;
			break;
		case '6':
			sound->setRepeat(true);
			cout << "Трек стоит на повторе" << endl;
		case 27:
			break;
		}
	}
}