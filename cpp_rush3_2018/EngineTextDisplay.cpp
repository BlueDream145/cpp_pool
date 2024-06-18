/*
** EPITECH PROJECT, 2019
** EngineTextDisplay.cpp
** File description:
** EngineTextDisplay
*/

#include <ncurses.h>
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>

#include "EngineInfos.hpp"
#include "Engine.hpp"
#include "EngineUser.hpp"
#include "EngineTextDisplay.hpp"

void basicTemplate(EngineInfos const &infos)
{
    int	i;
    int	xMax;
    int	yMax;
    int	h = 8 + (infos._core.obtainCoreNb() * 2);

    getmaxyx(stdscr, xMax, yMax);
    (void) xMax;
    attron(COLOR_PAIR(3));
    for (i = 0; i < yMax; i++)
        mvprintw(0, i, " ");
    for (i = 0; i < h; i++)
        mvprintw(i, 0, " ");
    for (i = 0; i < h; i++)
        mvprintw(i, yMax - 1, " ");
    for (i = 1; i < h; i++)
        mvprintw(i, 25, " ");
    for (i = 0; i < yMax; i++)
        mvprintw(h, i, " ");
    for (i = 1; i < h; i++)
        mvprintw(i, yMax - 33, " ");
    for (i = 1; i < 25; i++)
        mvprintw(4, i, " ");
    for (i = 1; i < 4; i++)
        mvprintw(i, 12, " ");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(0));
    mvprintw(6, 2, "User Name: ");
    mvprintw(8, 2, "Machine Name: ");
    mvprintw(2, 27, "CPU: ");
    int a = 0;
    while (a < (infos._core.obtainCoreNb() * 2) + 4)
    {
        if (a >= (infos._core.obtainCoreNb() * 2))
            mvprintw(a + 4, 27, "%s[", (a == infos._core.obtainCoreNb() * 2 ? "Ram" : "Swp"));
        else
            mvprintw(a + 4, 27, "%d  [", (a / 2) + 1);
        mvprintw(a + 4, yMax - 35, "]");
        a += 2;
    }
    mvprintw(2, yMax - 31, "Operating System: ");
    mvprintw(4, yMax - 31, "Kernel: ");
    mvprintw(6, yMax - 31, "Core number: ");
    mvprintw(8, yMax - 31, "Active tasks: ");
    mvprintw(10, yMax - 31, "Network :");
    mvprintw(12, yMax - 29, "Up :");
    mvprintw(13, yMax - 29, "Down :");
    attroff(COLOR_PAIR(0));
}

void gauge(EngineInfos const &infos)
{
    int	xMax;
    int	yMax;
    int	i;
    int	a;
    getmaxyx(stdscr, xMax, yMax);
    int	totalLength = yMax - 31 - 35;
    int	length;
    float	*temp;

    (void) xMax;
    attron(COLOR_PAIR(3));
    temp = infos._core.obtainRam();
    length = (int) ((temp[0] * totalLength) / temp[1]);
    for (i = 0; i < length; i++)
        mvprintw(12, i + 31, " ");
    attroff(COLOR_PAIR(3));
    mvprintw(13, yMax - 46, "%.2fG/%.2fG", temp[0], temp[1]);

    attron(COLOR_PAIR(3));
    temp = infos._core.obtainSwap();
    length = (int) ((temp[0] * totalLength) / temp[0]);
    for (i = 0; i < length; i++)
        mvprintw(14, i + 31, " ");
    attroff(COLOR_PAIR(3));
    mvprintw(15, yMax - 46, "%.2fG/%.2fG", temp[0], temp[1]);

    displayCore(infos, 0, 4, yMax);
    displayCore(infos, 1, 6, yMax);
    displayCore(infos, 2, 8, yMax);
    displayCore(infos, 3, 10, yMax);
}

void displayCore(EngineInfos const &infos, int index, int y, int yMax)
{
    std::ostringstream tmp1;
    tmp1 << infos._core.obtainCorePercent()[index] << " %";
    std::string core1(tmp1.str());
    mvprintw(y + 1, yMax - 41, "%.2f %%", infos._core.obtainCorePercent()[index]);
    int length = (int) (infos._core.obtainCorePercent()[index]);
    int i;

    attron(COLOR_PAIR(3));
    for (i = 0; i < length; i++)
        mvprintw(y, i + 31, " ");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(0));
    for (i = length; i < 100; i++)
        mvprintw(y, i + 31, " ");
    attroff(COLOR_PAIR(0));
}

void user(EngineInfos const &infos)
{
    int	xMax;
    int	yMax;

    (void) xMax;
    getmaxyx(stdscr, xMax, yMax);
    attron(COLOR_PAIR(0));
    mvprintw(7, 3, "%s", infos._user.obtainUserName().c_str());
    mvprintw(9, 3, "%s", infos._user.obtainMachineName().c_str());
    mvprintw(2, 2, "%s", infos._user.obtainTime().c_str());
    mvprintw(2, 14, "%s", infos._user.obtainDate().c_str());
    mvprintw(2, yMax - 12, "%s", infos._user.obtainOpSys().c_str());
    mvprintw(4, yMax - 23, "%s", infos._user.obtainKernel().c_str());
    attroff(COLOR_PAIR(0));
}

void core(EngineInfos const &infos)
{
    int xMax;
    int yMax;

    (void) xMax;
    getmaxyx(stdscr, xMax, yMax);
    attron(COLOR_PAIR(0));
    mvprintw(2, 33, "%s", infos._core.obtainCPUModel().c_str());
    mvprintw(6, yMax - 18, "%d", infos._core.obtainCoreNb());
    mvprintw(8, yMax - 17, "%d", infos._core.obtainNbTasks());
    mvprintw(12, yMax - 20, "%db", infos._network.getUp());
    mvprintw(13, yMax - 20, "%db", infos._network.getDown());
    attroff(COLOR_PAIR(0));
}

void textDisplay(EngineInfos &infos)
{
    int size[4];

    size[0] = 0;
    size[1] = 0;
    initscr();
    noecho();
    curs_set(0);
    start_color();
    keypad(stdscr, 1);
    use_default_colors();
    init_pair(0, COLOR_WHITE, -1);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_RED, -1);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    while (true)
    {
        updateInfos(infos);
        getmaxyx(stdscr, size[2], size[3]);
        if (size[2] != size[0] || size[3] != size[1])
        {
            clear();
            basicTemplate(infos);
            size[0] = size[2];
            size[1] = size[3];
        }
        user(infos);
        core(infos);
        gauge(infos);
        refresh();
    }
    curs_set(1);
    endwin();
}