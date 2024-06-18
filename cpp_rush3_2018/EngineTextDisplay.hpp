/*
** EPITECH PROJECT, 2019
** EngineTextDisplay.hpp
** File description:
** EngineTextDisplay
*/

#ifndef ENGINETEXTDISPLAY_HPP_
	#define ENGINETEXTDISPLAY_HPP_

    #include "EngineInfos.hpp"

    void updateInfos(EngineInfos &);
    void textDisplay(EngineInfos &);
    void displayCore(EngineInfos const &infos, int index, int y, int yMax);

#endif /* !ENGINETEXTDISPLAY_HPP_ */