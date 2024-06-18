/*
** EPITECH PROJECT, 2019
** EngineDisplay.cpp
** File description:
** EngineDisplay
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <sstream>

#include "EngineDisplay.hpp"

static const char *global_font = "champagne.ttf";
static const char *window_name = "Rush3";

static void print(sf::RenderWindow & window, EngineInfos & infos)
{
    display_user(&window, infos);
    display_cpu(&window, infos);
    display_kernel(&window, infos);
    display_data(&window, infos);
    display_graphCPU(&window, infos);
    display_graphCPU1(&window, infos);
    display_graphCPU2(&window, infos);
    display_graphCPU3(&window, infos);
    display_graphCPU4(&window, infos);
    display_name(&window);
}

void graphDisplay(EngineInfos &infos)
{
    sf::RenderWindow window(sf::VideoMode(810, 600), window_name);

    while (window.isOpen())
    {
        updateInfos(infos);
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear(sf::Color::White);

        sf::Texture texture;
        texture.loadFromFile("background.jpeg");
        sf::Sprite background(texture);
        window.draw(background);

        print(window, infos);

        sf::Texture texture2;
        texture2.loadFromFile("ram.png");
        sf::Sprite logo(texture2);
        logo.setPosition(345, 80);
        window.draw(logo);

        window.display();
    }
}

void display_name(sf::RenderWindow *window)
{
    display_text2(window, window_name, 10, 330, 65);
    display_text2(window, "Gkrellm, C++ monitoring program", 470, 110, 40);
    display_text2(window, "Alexandre - Jesuyon - Sofiane - Vincent", 550, 50, 20);
}

void display_graphCPU4(sf::RenderWindow *window, EngineInfos const & infos)
{
    float val = infos._core.obtainCorePercent()[3];
    int size = int(val + 0.5) * 4;
    
    display_shape2(window, 396, 400, 39, 400, 0);
    display_shape2(window, 397, 400, 37, size, size / 4);
}

void display_graphCPU3(sf::RenderWindow *window, EngineInfos const & infos)
{
    float val = infos._core.obtainCorePercent()[2];
    int size = int(val + 0.5) * 4;
  
    display_shape2(window, 351, 400, 39, 400, 0);
    display_shape2(window, 352, 400, 37, size, size / 4);
}

void display_graphCPU2(sf::RenderWindow *window, EngineInfos const & infos)
{
    float val = infos._core.obtainCorePercent()[1];
    int size = int(val + 0.5) * 4;
  
    display_shape2(window, 306, 400, 39, 400, 0);
    display_shape2(window, 307, 400, 37, size, size / 4);
}

void display_graphCPU1(sf::RenderWindow *window, EngineInfos const & infos)
{
    float val = infos._core.obtainCorePercent()[0];
    int size = int(val + 0.5) * 4;
  
    display_shape2(window, 261, 400, 39, 400, 0);
    display_shape2(window, 262, 400 , 37 , size, size / 4);
}

void display_graphCPU(sf::RenderWindow *window, EngineInfos const & infos)
{
    float val = (((infos._core.obtainCorePercent()[0]) + (infos._core.obtainCorePercent()[1]) +
        (infos._core.obtainCorePercent()[2]) + (infos._core.obtainCorePercent()[3])) / 4);
    int size = int(val + 0.5) * 4;
  
    display_shape2(window, 215, 400, 39, 400, 0);
    display_shape2(window, 216, 400 , 37 , size, size / 4);
}

void display_data(sf::RenderWindow *window, EngineInfos const & infos)
{
    const char *up = "Up : ";
    const char *down = "  |   Down : ";
    const char *network = "Network :";
    std::ostringstream tmp;
    tmp << up <<infos._network.getUp() << down << infos._network.getDown();
    std::string str(tmp.str());

    display_shape(window, 10, 710, 50);
    display_title(window, network, 150/2.0f, 720);
    display_text(window, str, 200/2.0f, 740);
}

void display_kernel(sf::RenderWindow *window, EngineInfos const & infos)
{
    const char *ram = "Random Access Memory :";
    const char *os = "Operating System :";
    const char *kernel = "Kernel :";
    const char *g = "G  |  ";
    std::ostringstream tmp;
    tmp << infos._core.obtainRam()[0] << g << infos._core.obtainRam()[1] << "G";
    std::string str(tmp.str());

    display_shape(window, 520, 15, 180);
    display_title(window, ram, 1150/2.0f, 25);
    display_text(window, str, 1200/2.0f, 45);

    display_shape(window, 520, 57, 50);
    display_title(window, os, 1150/2.0f, 70);
    display_text(window, infos._user.obtainOpSys(), 1200/2.0f, 90);

    display_shape(window, 520, 102, 50);
    display_title(window, kernel, 1150/2.0f, 115);
    display_text(window, infos._user.obtainKernel(), 1200/2.0f, 135);
}

void display_cpu(sf::RenderWindow *window, EngineInfos const & infos)
{
    const char *core = "Central Processing Unit :";
    std::ostringstream tmp1;
    tmp1 << infos._core.obtainCorePercent()[0] << " %";
    std::string core1(tmp1.str());
    std::ostringstream tmp2;
    tmp2 << infos._core.obtainCorePercent()[1] << " %";
    std::string core2(tmp2.str());
    std::ostringstream tmp3;
    tmp3 << infos._core.obtainCorePercent()[2] << " %";
    std::string core3(tmp3.str());
    std::ostringstream tmp4;
    tmp4 << infos._core.obtainCorePercent()[3] << " %";
    std::string core4(tmp4.str());

    display_shape(window, 10, 215, 225);
    display_title(window, core, 150/2.0f, 225);
    display_text(window, infos._core.obtainCPUModel(), 200/2.0f, 245);
    display_shape(window, 10, 257, 1);
    display_title(window, "Central Processing Unit 1 :", 150/2.0f, 270);
    display_text(window, core1, 200/2.0f, 290);
    display_shape(window, 10, 302, 1);
    display_title(window, "Central Processing Unit 2 :", 150/2.0f, 315);
    display_text(window, core2, 200/2.0f, 335);
    display_shape(window, 10, 347, 1);
    display_title(window, "Central Processing Unit 3 :", 150/2.0f, 360);
    display_text(window, core3, 200/2.0f, 380);
    display_shape(window, 10, 392, 1);
    display_title(window, "Central Processing Unit 4 :", 150/2.0f, 410);
    display_text(window, core4, 200/2.0f, 430);
}

void display_user(sf::RenderWindow *window, EngineInfos const & infos)
{
    const char *machineName = "Machine Name :";
    const char *userName = "User Name :";
    const char *date = "Date :";
    const char *timeStr = "Time :";

    display_shape(window, 10, 15, 180);
    display_title(window, machineName, 150/2.0f, 25);
    display_text(window, infos._user.obtainMachineName(), 200/2.0f, 45);
    display_shape(window, 10, 57, 1);
    display_title(window, userName, 150/2.0f, 70);
    display_text(window, infos._user.obtainUserName(), 200/2.0f, 90);
    display_shape(window, 10, 102, 1);
    display_title(window, date, 150/2.0f, 115);
    display_text(window, infos._user.obtainDate(), 200/2.0f, 135);
    display_shape(window, 10, 147, 1);
    display_title(window, timeStr, 150/2.0f, 160);
    display_text(window, infos._user.obtainTime(), 200/2.0f, 180);
}

void display_shape(sf::RenderWindow *window, int _x, int _y, int _size)
{
    sf::RectangleShape rect;

    rect.setSize(sf::Vector2f(280, _size));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(3);
    rect.setPosition(_x, _y);
    window->draw(rect);
}

void display_title(sf::RenderWindow *window, std::string _text, int _x, int _y)
{
    sf::Font font;
    sf::Text text;
    sf::FloatRect textRect = text.getLocalBounds();

    font.loadFromFile(global_font);
    text.setFont(font);
    text.setString(_text);
    text.setCharacterSize(14);
    text.setColor(sf::Color::Blue);
    text.setOrigin(textRect.left + textRect.width/2.0f,
        textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(_x, _y - 4));
    window->draw(text);
}

void display_text(sf::RenderWindow *window, std::string _text, int _x, int _y)
{
    sf::Font font;
    sf::Text text;
    sf::FloatRect textRect = text.getLocalBounds();

    font.loadFromFile(global_font);
    text.setFont(font);
    text.setString(_text);
    text.setCharacterSize(12);
    text.setColor(sf::Color::Black);
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(_x, _y - 5));
    window->draw(text);
}

void display_shape2(sf::RenderWindow *window, int _x, int _y, int _sizex, int _sizey, int value)
{
    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(_sizey, _sizex));
    rectangle.setOutlineColor(sf::Color::Black);
    if (value == 0)
        rectangle.setFillColor(sf::Color::White);
    else if (value <= 10 && value != 0)
        rectangle.setFillColor(sf::Color::Blue);
    else if (value <= 25 && value > 10)
        rectangle.setFillColor(sf::Color::Green);
    else if (value < 50 && value > 25)
        rectangle.setFillColor(sf::Color::Yellow);
    else
        rectangle.setFillColor(sf::Color::Red);
    rectangle.setOutlineThickness(3);
    rectangle.setPosition(_y, _x);
    window->draw(rectangle);
}

void display_title2(sf::RenderWindow *window, std::string _text, int _x, int _y)
{
    sf::Font font;
    sf::Text text;

    font.loadFromFile(global_font);
    text.setFont(font);
    text.setString(_text);
    text.setCharacterSize(25);
    text.setColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(_y, _x);
    window->draw(text);
}

void display_text2(sf::RenderWindow *window, std::string _text, int _x, int _y, int size)
{
    sf::Font font;
    sf::Text text;

    font.loadFromFile(global_font);
    text.setFont(font);
    text.setString(_text);
    text.setCharacterSize(size);
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(_y, _x);
    window->draw(text);
}
