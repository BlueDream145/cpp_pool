/*
** EPITECH PROJECT, 2019
** GiftPaper.cpp
** File description:
** @epitech.eu
*/

#include "GiftPaper.hpp"

static const char *giftpaper = "GiftPaper";

GiftPaper::GiftPaper() : Wrap(giftpaper)
{
}

void GiftPaper::closeMe()
{
	this->isOpen = false;
}