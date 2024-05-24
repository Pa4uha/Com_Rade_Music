#include "Menu.h"

#include <iostream>
#include <set>

#include "conio.h"

using namespace std;

static vector<mus> Mass_mus;
static set<int> Mass_fuu;

void menu() {
	Mass_mus.push_back(mus("Áåëûå ðîçû.mp3", "Ëàñêîâûé ìàé", 2));
	Mass_mus.push_back(mus("Ïîãîâîðè ñî ìíîé îëüãà.mp3", "Íî÷íûå ñíàéïåðû", 1));
	Mass_mus.push_back(mus("Îðáèò áåç ñàõàðà.mp3", "Ñïëèí", 1));

	/*AudioDevicePtr device = OpenDevice();
	OutputStreamPtr sound = OpenSound(device, Mass_mus[0].get_name_song(), true);*/

	int i = 0;
	int k = 0;
	//char ch = '/';
	cout << "1 - ñëåäóþùèé òðåê \n 2 - ïðåäûäóùèé òðåê \n 3 - ïàóçà \n 4 - ïëåé \n 5 - äèçëàéê" << endl;
	while (ch != 27) {
		ch = _getch();
		switch (ch) {
		case '1':
			i = (i + 1) > Mass_mus.size() - 1 ? 0 : i + 1;
			k = i;
			while (Mass_fuu.count(Mass_mus[i].get_genre())) {
				i++;
				if (i > Mass_mus.size() - 1) {
					i = 0;
				}
				if (i == k) {
					cout << "Â ÁÄ íåò ìóçûêè, êîòîðàÿ áû ïîäõîäèëà ïîä Âàøè âêóñîâûå ïðåäïî÷òåíèÿ :(" << endl;
					exit(1);
				}
			}
			sound = OpenSound(device, Mass_mus[i].get_name_song(), true);
			sound->play();
			break;
		case '2':
			i--;
			sound = OpenSound(device, Mass_mus[i].get_name_song(), true);
			sound->play();
			break;
		case '3':
			sound->stop();
			break;
		case '4':
			sound->play();
			break;
		case '5':
			Mass_fuu.insert(Mass_mus[i].get_genre());
			i = (i + 1) > Mass_mus.size() - 1 ? 0 : i + 1;
			k = i;
			while (Mass_fuu.count(Mass_mus[i].get_genre())) {
				i++;
				if (i > Mass_mus.size() - 1) {
					i = 0;
				}
				if (i == k) {
					cout << "Â ÁÄ íåò ìóçûêè, êîòîðàÿ áû ïîäõîäèëà ïîä Âàøè âêóñîâûå ïðåäïî÷òåíèÿ :(" << endl;
					exit(1);
				}
			}
			sound = OpenSound(device, Mass_mus[i].get_name_song(), true);
			sound->play();
			break;
		case 27:
			break;
		}
	}
}