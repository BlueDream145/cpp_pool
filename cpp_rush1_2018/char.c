/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** char
*/

#include <string.h>
#include "new.h"
#include "char.h"

#define KEY (1 + 9 + 1)

enum Operations {
    ADD, SUB, MULT, DIV, EQ, SUP, GT, LT
};

typedef struct
{
    Class base;
    char data;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!(this) || !(args))
        raise("Wrong pointer");
    this->data = (char)(va_arg(*args, int));
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static const char *Char_str(CharClass *this)
{
    static char res[KEY] = { 0 };

    if (!(this))
        raise("Wrong pointer");
    snprintf(res, KEY, "<Char (%c)>", this->data);
    return (strdup(res));
}

static char process_op(CharClass *this, CharClass *obj, int op)
{
    switch (op) {
    case (ADD):
        return (this->data + obj->data);
    case (SUB):
        return (this->data - obj->data);
    case (MULT):
        return (this->data * obj->data);
    case (DIV):
        return (obj->data ? this->data / obj->data : 0);
    }
    return (0);
}

static Object *Char_operate(const Object *this, const Object *obj, int op)
{
    CharClass *_this = (CharClass *)(this);
    CharClass *_obj = (CharClass *)(obj);

    if (!(this) || !(obj))
        raise("Wrong pointer");
    return (new(Char, process_op(_this, _obj, op)));
}

static char process_compare(CharClass *this, CharClass *obj, int op)
{
    switch (op) {
    case (EQ):
        return (this->data == obj->data);
    case (GT):
        return (this->data > obj->data);
    case (LT):
        return (this->data < obj->data);
    }
    return (false);
}

static bool Char_compare(const Object *this, const Object *obj, int op)
{
    CharClass *_this = (CharClass *)(this);
    CharClass *_obj = (CharClass *)(obj);

    if (!(_this) || !(_obj))
        raise("Wrong pointer");
    return (process_compare(_this, _obj, op));
}

static Object *Char_add(const Object *this, const Object *obj)
{
    return (Char_operate(this, obj, ADD));
}

static Object *Char_sub(const Object *this, const Object *obj)
{
    return (Char_operate(this, obj, SUB));
}

static Object *Char_mult(const Object *this, const Object *obj)
{
    return (Char_operate(this, obj, MULT));
}

static Object *Char_div(const Object *this, const Object *obj)
{
    return (Char_operate(this, obj, DIV));
}

static bool Char_eq(const Object *this, const Object *obj)
{
    return (Char_compare(this, obj, EQ));
}

static bool Char_gt(const Object *this, const Object *obj)
{
    return (Char_compare(this, obj, GT));
}

static bool Char_lt(const Object *this, const Object *obj)
{
    return (Char_compare(this, obj, LT));
}

static CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mult,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .data = 0
};

Class *Char = (Class *)&_description;
