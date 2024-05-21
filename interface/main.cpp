#include "LIB.h"

using namespace sf;

int main()
{
    int i = 0;
    int k = 0;
    int count = 0;

    Clock clock;

    //Time currentTime = clock.getElapsedTime();

    sf::RenderWindow window(sf::VideoMode(1300, 850), "ComRadeMusic");

    // МУЗЫКА

    Music music;
    music.openFromFile("Song.ogg"); // Сюда самая первая музыка из бд должна встать
    //auto newPos = music.getPlayingOffset();
    Time currentTime = clock.getElapsedTime();
    Time newPos = currentTime;
    auto last_time = clock.getElapsedTime();


    //КНОПКА ДАЛЕЕ
    ConvexShape Next;
    Next.setPointCount(7);
    Next.setPoint(0, Vector2f(750, 450));
    Next.setPoint(1, Vector2f(750, 500));
    Next.setPoint(2, Vector2f(780, 475));
    Next.setPoint(3, Vector2f(780, 500));
    Next.setPoint(4, Vector2f(810, 475));
    Next.setPoint(5, Vector2f(780, 450));
    Next.setPoint(6, Vector2f(780, 475));
    Next.setFillColor(Color::Black);

    //КНОПКА НАЗАД
    ConvexShape Backstep;
    Backstep.setPointCount(7);
    Backstep.setPoint(0, Vector2f(570, 450));
    Backstep.setPoint(1, Vector2f(570, 500));
    Backstep.setPoint(2, Vector2f(540, 475));
    Backstep.setPoint(3, Vector2f(540, 500));
    Backstep.setPoint(4, Vector2f(500, 475));
    Backstep.setPoint(5, Vector2f(540, 450));
    Backstep.setPoint(6, Vector2f(540, 475));
    Backstep.setFillColor(Color::Black);

    //КНОПКА ПЛЕЙ

    CircleShape push_start(30.f);
    push_start.setPosition(685, 445);
    //push_start.setOrigin(225,270);
    push_start.setFillColor(Color::Black);
    push_start.setPointCount(3);
    push_start.setRotation(90);

    //ГЛАВНОЕ ОКНО

    RectangleShape mainwindow;
    mainwindow.setSize(Vector2f(450, 300));
    mainwindow.setPosition(425, 225);
    mainwindow.setOutlineThickness(4);
    mainwindow.setOutlineColor(Color::Black);

    //РЕКОМЕНДАЦИ СЛЕВА

    RectangleShape recom;
    recom.setSize(Vector2f(300, 700));
    recom.setPosition(10, 70);
    recom.setOutlineThickness(4);
    recom.setOutlineColor(Color::Black);

    //РАМКИ ПЕСЕН СЛЕВА





    while (window.isOpen())
    {
        Vector2i mousepoz = Mouse::getPosition(window);

        //clock.restart(); //перезагружает время
       

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
                            //music.openFromFile(music_right_now);
                            //music.setPlayingOffset(newPos);

                            music.play();
                            clock.restart();
                            Time currentTime = clock.getElapsedTime();
                            std::cout << currentTime.asSeconds() << std::endl;
                            std::cout << music.getDuration().asSeconds() << std::endl;
                        }

                       // music.

                        
                        //music.setPlayingOffset(newpos);
                        currentTime = clock.getElapsedTime();
                        newPos = currentTime;
                        if (count == 2)
                        {
                            
                            //newPos = currentTime;
                            last_time = music.getDuration() - (music.getDuration() - newPos);
                            std::cout << newPos.asSeconds() << std::endl;
                            push_start.setFillColor(Color::Black);
                            count = 0;
                            music.pause();
                            music.setPlayingOffset(last_time);

                            //music.setPlayingOffset(newpos.asSeconds());
                            //std::cout << newpos << std::endl;
                            
                        }
                    }
                    else if ((Next.getGlobalBounds().contains(mousepoz.x, mousepoz.y)))
                    {
                        //count++;
                        music.pause();
                        push_start.setFillColor(Color::Black);
                        music.openFromFile("song2.ogg"); // Сюда идёт следующая песня из бд
                        //music.play();
                        /*i = (i + 1) > Mass_mus.size() - 1 ? 0 : i + 1;
                        k = i;
                        while (Mass_fuu.count(Mass_mus[i].get_genre())) {
                            i++;
                            if (i > Mass_mus.size() - 1) {
                                i = 0;
                            }
                            if (i == k) {
                                std::cout << "Надо обновить БД" << endl;
                                exit(1);*/

                    }
                    else if ((Backstep.getGlobalBounds().contains(mousepoz.x, mousepoz.y)))
                    {
                        //count++;
                        music.pause();
                        push_start.setFillColor(Color::Black);
                        music.openFromFile("Song.ogg");
                    }
                }
        }



        window.clear(Color::White);

        

        window.draw(mainwindow);
        window.draw(recom);
        window.draw(Next);
        window.draw(Backstep);
        window.draw(push_start);
        window.display();
    }

    return 0;
}