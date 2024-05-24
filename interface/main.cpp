#include "LIB.h"

using namespace sf;

int main()
{
    int i = 0;
    int k = 0;
    int count = 0;

    Clock clock;

    sf::RenderWindow window(sf::VideoMode(1300, 850), "ComRadeMusic");

    // МУЗЫКА

    Music music;
    music.openFromFile("Song.ogg"); // Сюда самая первая музыка из бд должна встать
    Time currentTime = clock.getElapsedTime();
    Time newPos = currentTime;
    auto last_time = newPos;

    music.setVolume(1);

    //КНОПКА ДАЛЕЕ
    ConvexShape Next;
    Next.setPointCount(7);
    Next.setPoint(0, Vector2f(550, 450));
    Next.setPoint(1, Vector2f(550, 500));
    Next.setPoint(2, Vector2f(580, 475));
    Next.setPoint(3, Vector2f(580, 500));
    Next.setPoint(4, Vector2f(610, 475));
    Next.setPoint(5, Vector2f(580, 450));
    Next.setPoint(6, Vector2f(580, 475));
    Next.setFillColor(Color::Black);

    //КНОПКА НАЗАД
    ConvexShape Backstep;
    Backstep.setPointCount(7);
    Backstep.setPoint(0, Vector2f(370, 450));
    Backstep.setPoint(1, Vector2f(370, 500));
    Backstep.setPoint(2, Vector2f(340, 475));
    Backstep.setPoint(3, Vector2f(340, 500));
    Backstep.setPoint(4, Vector2f(300, 475));
    Backstep.setPoint(5, Vector2f(340, 450));
    Backstep.setPoint(6, Vector2f(340, 475));
    Backstep.setFillColor(Color::Black);

    //КНОПКА ПЛЕЙ

    CircleShape push_start(30.f);
    push_start.setPosition(485, 445);
    //push_start.setOrigin(225,270);
    push_start.setFillColor(Color::Black);
    push_start.setPointCount(3);
    push_start.setRotation(90);

    //DISLIKE
    CircleShape triangle(25, 3);
    triangle.setPosition(350, 425);
    triangle.setFillColor(Color::Red);
    triangle.setRotation(180);

    CircleShape triangle1(15, 3);
    triangle1.setPosition(320, 365);
    triangle1.setFillColor(Color::Red);

    CircleShape triangle2(15, 3);
    triangle2.setPosition(300, 365);
    triangle2.setFillColor(Color::Red);

    RectangleShape line(Vector2f(60, 3));
    line.rotate(135);
    line.setPosition(Vector2f(350, 370));
    line.setFillColor(Color::Black);



    //ГЛАВНОЕ ОКНО

    RectangleShape mainwindow;
    mainwindow.setSize(Vector2f(450, 300));
    mainwindow.setPosition(225, 225);
    mainwindow.setOutlineThickness(4);
    mainwindow.setOutlineColor(Color::Black);

    //РЕКОМЕНДАЦИ СЛЕВА

    /*RectangleShape recom;
    recom.setSize(Vector2f(300, 700));
    recom.setPosition(10, 70);
    recom.setOutlineThickness(4);
    recom.setOutlineColor(Color::Black);*/

    //NETX SONG

    RectangleShape next_play;
    next_play.setSize(Vector2f(300, 100));
    next_play.setPosition(900, 350);
    next_play.setOutlineThickness(5);
    next_play.setOutlineColor(Color::Black);


    //RectangleShape recomaround1;
    //recomaround1.setSize(Vector2f(300, 100));
    //recomaround1.setPosition(10, 70);
    //recomaround1.setOutlineThickness(2);
    //recomaround1.setOutlineColor(Color::Black);

    //RectangleShape recomaround2;
    //recomaround2.setSize(Vector2f(300, 100));
    //recomaround2.setPosition(10, 170);
    //recomaround2.setOutlineThickness(2);
    //recomaround2.setOutlineColor(Color::Black);

    //RectangleShape recomaround3;
    //recomaround3.setSize(Vector2f(300, 100));
    //recomaround3.setPosition(10, 270);
    //recomaround3.setOutlineThickness(2);
    //recomaround3.setOutlineColor(Color::Black);

    //RectangleShape recomaround4;
    //recomaround4.setSize(Vector2f(300, 100));
    //recomaround4.setPosition(10, 370);
    //recomaround4.setOutlineThickness(2);
    //recomaround4.setOutlineColor(Color::Black);

    //RectangleShape recomaround5;
    //recomaround5.setSize(Vector2f(300, 100));
    //recomaround5.setPosition(10, 470);
    //recomaround5.setOutlineThickness(2);
    //recomaround5.setOutlineColor(Color::Black);

    //RectangleShape recomaround6;
    //recomaround6.setSize(Vector2f(300, 100));
    //recomaround6.setPosition(10, 570);
    //recomaround6.setOutlineThickness(2);
    //recomaround6.setOutlineColor(Color::Black);



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
                        music.openFromFile("song2.ogg");// Сюда идёт следующая песня из бд
                        count = 0;
                        //music.play();
                        /*i = (i + 1) > Mass_mus.size() - 1 ? 0 : i + 1;
                        //k = i;
                        //while (Mass_fuu.count(Mass_mus[i].get_genre())) {
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
                        push_start.setFillColor(Color::Black);
                        music.openFromFile("Song.ogg");
                        count = 0;
                    }
                    else if ((triangle.getGlobalBounds().contains(mousepoz.x, mousepoz.y) || (triangle1.getGlobalBounds().contains(mousepoz.x, mousepoz.y)) || (triangle2.getGlobalBounds().contains(mousepoz.x, mousepoz.y)) || (line.getGlobalBounds().contains(mousepoz.x, mousepoz.y))))
                    {

                    }
                }
        }



        window.clear(Color::White);

        

        window.draw(mainwindow);
        //window.draw(recom);
        window.draw(Next);
        window.draw(Backstep);
        window.draw(push_start);
        /*window.draw(recomaround1);
        window.draw(recomaround2);
        window.draw(recomaround3);
        window.draw(recomaround4);
        window.draw(recomaround5);
        window.draw(recomaround6);*/
        window.draw(next_play);
        window.draw(triangle);
        window.draw(triangle1);
        window.draw(triangle2);
        window.draw(line);
        window.display();
    }

    return 0;
}