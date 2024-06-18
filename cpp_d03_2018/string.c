/*
** EPITECH PROJECT, 2019
** String.c
** File description:
** @epitech.eu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string.h"

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_s = &insert_s;
    this->insert_c = &insert_c;
    this->to_int = &to_int;
    this->split_s = &split_s;
    this->split_c = &split_c;
    this->aff = &aff;
}

void string_destroy(string_t *this)
{
    if (!this || !this->str)
        return;
    free(this->str);
}

void assign_s(string_t *this, const string_t *str)
{
    if (!this || !str || !this->str)
        return;
    string_destroy(this);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (!this || !s || !this->str)
        return;
    string_destroy(this);
    this->str = strdup(s);
}

void append_s(string_t *this, const string_t *ap)
{
    append_c(this, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    char *tmp;
    char *strr;

    if (!ap || !this || !this->str)
        return;
    tmp = malloc(sizeof(char) * (strlen(this->str) + strlen(ap) + 1));
    strr = strdup(this->str);
    tmp[0] = '\0';
    if (!tmp || !strr)
        return;
    if (this->str != NULL) {
        tmp = strcat(tmp, strr);
        tmp = strcat(tmp, ap);
    }
    this->str = tmp;
}

char at(const string_t *this, size_t pos)
{
    unsigned int size;
    
    if (!this || !this->str)
        return(-1);
    size = strlen(this->str) - 1;
    if (pos <= size)
        return(this->str[pos]);
    else
        return(-1);
}

void clear(string_t *this)
{
    memset(this->str, 0, 0);
}

int size(const string_t *this)
{
    int size;
    
    if (!this || !this->str)
        return(-1);
    size = strlen(this->str);
    return(size);
}

int compare_s(const string_t *this, const string_t *str)
{
    return(compare_c(this, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (!this || !this->str || !str)
        return(-1);
    return(strcmp(this->str, str));
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t len;
    size_t index = 0;

    if (!this || !this->str || !s)
       return(0);
    len = strlen(this->str);
    for (unsigned int i = 0; i < len; i++)
    {
        if (i == pos)
        {
            for (;(i < len) && (index < n) && s; i++)
                s[index++] = this->str[i];
            s[index] = '\0';
        }
        i++;
    }
   return(index);
}

const char *c_str(const string_t *this)
{
    if (!this || !this->str)
       return(NULL);
    else
       return(this->str);
}

int empty(const string_t *this)
{
    if (this && this->str && this->str[0] == '\0')
        return(1);
    else
        return(-1);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return (find_c(this, str->str, pos));
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    int str_len;
    unsigned int this_len;
    int j;
    int n;

    if (!this || !this->str || !str)
        return(-1);
    str_len = strlen(str);
    this_len = strlen(this->str);
    for (unsigned int i = 0;
        i < this_len && this->str[i] != '\0'; i++) {
        if (i == pos)
            for (; i < this_len && this->str[i] != '\0'; i++) {
                j = 0;
                if (this->str[i] == str[j]) {
                    n = i;
                    while (j < str_len && str[j] != '\0')
                        if (str[j] == this->str[i++])
                            j++;
                        else
                            break;
                    if (str[j] == '\0')
                        return(n);
                }
            }
    }
    return(n);
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *tmp;
    unsigned int i = 0;
    int ct;
    int len;

    if (!this || !this->str || !str)
        return;
    len = strlen(this->str) + strlen(str) + 1;
    tmp = malloc(sizeof(char) * len);
    if (tmp == NULL)
        return;
    for (; i < pos && this->str[i] != '\0'; i++)
        tmp[i] = this->str[i];
    ct = i;
    for (int j = 0; str[j] != 0; j++)
        tmp[i++] = '\0';
    if (this->str[ct] == '\0') {
        this->assign_c(this, tmp);
        return;
    } else
        while (this->str[ct] != '\0')
            tmp[i++] = this->str[ct++];
    tmp[i] = '\0';
    this->assign_c(this, tmp);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    insert_c(this, pos, str->str);
}

int to_int(const string_t *this)
{
    if (!this || !this->str)
        return(0);
    else
        return(atoi(this->str));
}

string_t **split_s(const string_t *this, char separator)
{
    if (this || separator)
        return(NULL);
    return(NULL);
}

char **split_c(const string_t *this, char separator)
{
    if (this || separator)
        return(NULL);
    return(NULL);
}

void aff(const string_t *this)
{
    for (int i = 0; this->str[i]; i++)
        printf("%c", this->str[i]);
}