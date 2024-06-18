/*
** EPITECH PROJECT, 2019
** EngineDisplay.hpp
** File description:
** EngineDisplay
*/

#ifndef ENGINEDISPLAY_HPP_
	#define ENGINEDISPLAY_HPP_

    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>

    #include "EngineInfos.hpp"

    // Functions
    void graphDisplay(EngineInfos &);
    void updateInfos(EngineInfos &);

    // Main Display Methods
    void display_name(sf::RenderWindow *);
    void display_graphCPU4(sf::RenderWindow *, EngineInfos const &);
    void display_graphCPU3(sf::RenderWindow *, EngineInfos const &);
    void display_graphCPU2(sf::RenderWindow *, EngineInfos const &);
    void display_graphCPU1(sf::RenderWindow *, EngineInfos const &);
    void display_graphCPU(sf::RenderWindow *, EngineInfos const &);
    void display_data(sf::RenderWindow *, EngineInfos const &);
    void display_kernel(sf::RenderWindow *, EngineInfos const &);
    void display_cpu(sf::RenderWindow *, EngineInfos const &);
    void display_user(sf::RenderWindow *, EngineInfos const &);

    // Display Elements
    void display_shape(sf::RenderWindow *, int, int, int);
    void display_title(sf::RenderWindow *, std::string, int, int);
    void display_text(sf::RenderWindow *, std::string, int, int);
    void display_shape2(sf::RenderWindow *, int, int, int, int, int);
    void display_title2(sf::RenderWindow *, std::string, int, int);
    void display_text2(sf::RenderWindow *, std::string, int, int, int);

#endif /* !ENGINEDISPLAY_HPP_ */