/*
** EPITECH PROJECT, 2019
** ex00.c
** File description:
** @epitech.eu
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this)
{
    const char *build = "Building Cthulhu";
    const char *str = "Cthulhu";
    const char *separator = "----";

	printf("%s\n", separator);
	this->m_name = malloc(8);
	strcpy(this->m_name, str);
	this->m_power = 42;
	printf("%s\n", build);
}

static void koala_initializer(koala_t *this, char *name, char legend)
{
    const char *building = "Building %s\n";

	cthulhu_initializer(&this->m_parent);
	this->m_parent.m_name = name;
	this->m_parent.m_power = (legend ? 42 : 0);
	this->m_is_a_legend = legend;
	printf(building, this->m_parent.m_name);
}

cthulhu_t *new_cthulhu()
{
	cthulhu_t *obj = malloc(sizeof(cthulhu_t));

	cthulhu_initializer(obj);
	return(obj);
}

void print_power(cthulhu_t *this)
{
    const char *power = "Power => %i\n";

	printf(power, this->m_power);
}

void attack(cthulhu_t *this)
{
    const char *attack = "%s attacks and destroys the city\n";
    const char *enoughPower = "%s can't attack, he doesn't have enough power\n";

	if (this->m_power >= 42) {
		this->m_power -= 42;
		printf(attack, this->m_name);
	} else
		printf(enoughPower, this->m_name);
}

void sleeping(cthulhu_t *this)
{
    const char *sleep = "%s sleeps\n";

	this->m_power += 42000;
	printf(sleep, this->m_name);
}

koala_t *new_koala(char *name, char legend)
{
	koala_t *obj = malloc(sizeof(koala_t));

	koala_initializer(obj, name, legend);
	return(obj);
}

void eat(koala_t *this)
{
    const char *eats = "%s eats\n";

	this->m_parent.m_power += 42;
	printf(eats, this->m_parent.m_name);
}
