#include "h.h"

#include <iostream>
#include <set>

#include "conio.h"

using namespace std;

static vector<mus> Mass_mus;
static set<int> Mass_fuu;

void menu() {
	Mass_mus.push_back(mus("����� ����.mp3", "�������� ���", 2));                     //
	Mass_mus.push_back(mus("�������� �� ���� �����.mp3", "������ ��������", 1));      //
	Mass_mus.push_back(mus("����� ��� ������.mp3", "�����", 1));                      //

	AudioDevicePtr device = OpenDevice();
	OutputStreamPtr sound = OpenSound(device, Mass_mus[0].get_name_song(), true);

	int i = 0;
	int k = 0;
	char ch = '/';
	cout << "1 - ��������� ���� \n 2 - ���������� ���� \n 3 - ����� \n 4 - ���� \n 5 - ������� \n 6 - ��������� ���� �� ������" << endl;
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
					cout << "� �� ��� ������, ������� �� ��������� ��� ���� �������� ������������ :(" << endl;
					exit(1);
				}
			}
			sound = OpenSound(device, Mass_mus[i].get_name_song(), true);
			sound->play();
			cout << "������ ������: " << Mass_mus[i].get_name_executor() << " - " << Mass_mus[i].get_name_song() << endl;
			break;
		case '2':
			i--;
			sound = OpenSound(device, Mass_mus[i].get_name_song(), true);
			sound->play();
			cout << "������ ������: " << Mass_mus[i].get_name_executor() << " - " << Mass_mus[i].get_name_song() << endl;
			break;
		case '3':
			sound->stop();
			break;
		case '4':
			sound->play();
			cout << "������ ������: " << Mass_mus[i].get_name_executor() << " - " << Mass_mus[i].get_name_song() << endl;
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
					cout << "� �� ��� ������, ������� �� ��������� ��� ���� �������� ������������ :(" << endl;
					exit(1);
				}
			}
			sound = OpenSound(device, Mass_mus[i].get_name_song(), true);
			sound->play();
			cout << "������ ������: " << Mass_mus[i].get_name_executor() << " - " << Mass_mus[i].get_name_song() << endl;
			break;
		case '6':
			sound->setRepeat(true);
			cout << "���� ����� �� �������" << endl;
		case 27:
			break;
		}
	}
}