#include "Menu.h"

using namespace sf;
using namespace std;

static vector<mus> Mass_mus;
static set<int> Mass_fuu;

static ConvexShape Next;
static ConvexShape Backstep;
static CircleShape push_start(30.f);
static CircleShape triangle(25, 3);
static CircleShape triangle1(15, 3);
static CircleShape triangle2(15, 3);
static RectangleShape line(Vector2f(60, 3));
static RectangleShape mainwindow;
static RectangleShape next_play;

static sf::RenderWindow window(sf::VideoMode(1300, 850), "ComRadeMusic");

void create() {

	Next.setPointCount(7);
	Next.setPoint(0, Vector2f(550, 450));
	Next.setPoint(1, Vector2f(550, 500));
	Next.setPoint(2, Vector2f(580, 475));
	Next.setPoint(3, Vector2f(580, 500));
	Next.setPoint(4, Vector2f(610, 475));
	Next.setPoint(5, Vector2f(580, 450));
	Next.setPoint(6, Vector2f(580, 475));
	Next.setFillColor(Color::Black);

	Backstep.setPointCount(7);
	Backstep.setPoint(0, Vector2f(370, 450));
	Backstep.setPoint(1, Vector2f(370, 500));
	Backstep.setPoint(2, Vector2f(340, 475));
	Backstep.setPoint(3, Vector2f(340, 500));
	Backstep.setPoint(4, Vector2f(300, 475));
	Backstep.setPoint(5, Vector2f(340, 450));
	Backstep.setPoint(6, Vector2f(340, 475));
	Backstep.setFillColor(Color::Black);

	push_start.setPosition(485, 445);
	push_start.setFillColor(Color::Black);
	push_start.setPointCount(3);
	push_start.setRotation(90);

	triangle.setPosition(350, 425);
	triangle.setFillColor(Color::Red);
	triangle.setRotation(180);

	triangle1.setPosition(320, 365);
	triangle1.setFillColor(Color::Red);

	triangle2.setPosition(300, 365);
	triangle2.setFillColor(Color::Red);

	line.rotate(135);
	line.setPosition(Vector2f(350, 370));
	line.setFillColor(Color::Black);

	mainwindow.setSize(Vector2f(450, 300));
	mainwindow.setPosition(225, 225);
	mainwindow.setOutlineThickness(4);
	mainwindow.setOutlineColor(Color::Black);

	next_play.setSize(Vector2f(300, 100));
	next_play.setPosition(900, 350);
	next_play.setOutlineThickness(5);
	next_play.setOutlineColor(Color::Black);
}

void draw() {
	window.clear(Color::White);
	window.draw(mainwindow);
	window.draw(Next);
	window.draw(Backstep);
	window.draw(push_start);
	window.draw(next_play);
	window.draw(triangle);
	window.draw(triangle1);
	window.draw(triangle2);
	window.draw(line);
	window.display();
}

int mus_next(int i, int y) {
	int k = i;
	if (y) i = i + 1 >= Mass_mus.size() ? i = 0 : i + 1;
	else i = i - 1 < 0 ? i = Mass_mus.size() - 1 : i - 1;
	while (Mass_fuu.count(Mass_mus[i].get_genre())) {
		i += y;
		if (y && i > Mass_mus.size() - 1) i = 0;
		else if (!y && i < 0) i = Mass_mus.size() - 1;

		if (i == k) {
			std::cout << "End of BD" << endl;
			return -1;
		}
	}
	return i;
}

int main()
{
	int i = 0;
	int k = 0;
	int count = 0;

	Mass_mus.push_back(mus("Song.ogg", "Jakone & Сирена", 2));
	Mass_mus.push_back(mus("song2.ogg", "Makan", 2));
	Mass_mus.push_back(mus("rock1.ogg", "Три дня дождя", 1));

	Clock clock;

	Music music;
	music.openFromFile(Mass_mus[i].get_name_song());
	Time currentTime = clock.getElapsedTime();
	Time newPos = currentTime;
	auto last_time = newPos;

	music.setVolume(10);

	create();

	while (window.isOpen())
	{
		Vector2i mousepoz = Mouse::getPosition(window);

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();



			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left) {
					if (push_start.getGlobalBounds().contains(mousepoz.x, mousepoz.y))
					{
						count++;
						if (count == 1)
						{

							std::cout << "Done!\n";
							push_start.setFillColor(Color::Red);

							music.play();
							clock.restart();
							Time currentTime = clock.getElapsedTime();
						}

						currentTime = clock.getElapsedTime();
						newPos = currentTime;
						if (count == 2)
						{
							last_time += newPos;
							std::cout << newPos.asSeconds() << std::endl;
							push_start.setFillColor(Color::Black);
							count = 0;
							music.pause();
							music.setPlayingOffset(last_time);
						}
					}
					else if ((Next.getGlobalBounds().contains(mousepoz.x, mousepoz.y)))
					{
						push_start.setFillColor(Color::Black);
						i = mus_next(i, 1);
						if (i < 0) return 0;
						count = 0;
						music.openFromFile(Mass_mus[i].get_name_song());
						music.play();

					}
					else if ((Backstep.getGlobalBounds().contains(mousepoz.x, mousepoz.y)))
					{
						push_start.setFillColor(Color::Black);
						i = mus_next(i, -1);
						if (i < 0) return 0;
						music.openFromFile(Mass_mus[i].get_name_song());
						music.play();
						count = 0;
					}
					else if ((triangle.getGlobalBounds().contains(mousepoz.x, mousepoz.y) || (triangle1.getGlobalBounds().contains(mousepoz.x, mousepoz.y)) || (triangle2.getGlobalBounds().contains(mousepoz.x, mousepoz.y)) || (line.getGlobalBounds().contains(mousepoz.x, mousepoz.y))))
					{
						Mass_fuu.insert(Mass_mus[i].get_genre());
						i = mus_next(i, 1);
						if (i < 0) return 0;
						music.openFromFile(Mass_mus[i].get_name_song());
						music.play();
					}
				}
		}

		draw();

	}

	return 0;
}