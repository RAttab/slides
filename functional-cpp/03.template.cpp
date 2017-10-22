/* typedef.cpp
   Rémi Attab (remi.attab@gmail.com), 22 Oct 2017
   FreeBSD-style copyright and disclaimer apply
*/

#include <cstdio>

namespace {


// I
template<typename T>
struct Type
{
    typedef T type;
};

constexpr Type<int>::type a = 10;


// II
template<int V>
struct Value
{
    static constexpr int value = V;
};

constexpr int b = Value<20>::value;


// III
template<typename Type, Type Value>
struct Something
{
    static constexpr Type value = Value;
};

constexpr int c = Something<int, 30>::value;

}

int main(int, const char**)
{
    printf("template.a = %d\n", a);
    printf("template.b = %d\n", b);
    printf("template.c = %d\n", c);
    return 0;
}
