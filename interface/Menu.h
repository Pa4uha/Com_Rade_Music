#include "LIB.h"

//void menu();


class mus {
	char name_song[30];
	char name_executor[30];
	int genre; //1-ðîê, 2-ïîï, 3-ðåï

public:
	mus(const char* name1, const char* name2, int g) {
		strcpy_s(name_song, name1);
		strcpy_s(name_executor, name2);
		genre = g;
	}
	int get_genre() { return genre; }
	void set_genre(int g1) { genre = g1; }

	char* get_name_song() { return name_song; }
	void set_name_song(char n1[30]) { strcpy_s(name_song, n1); }

	char* get_name_executor() { return name_executor; }
	void set_name_executor(char n1[30]) { strcpy_s(name_executor, n1); }

};