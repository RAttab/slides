/* typedef.cpp
   Rémi Attab (remi.attab@gmail.com), 22 Oct 2017
   FreeBSD-style copyright and disclaimer apply

   http://en.cppreference.com/w/cpp/language/typedef
*/

#include <cstdio>

namespace {

// I
typedef int A;
A a = 10;

typedef A B;
B b = 20;


// II
struct Struct
{
    typedef int type;
};
constexpr Struct::type s = 30;


// III
template<typename T>
struct Template
{
    typedef typename T::type type;
};
constexpr Template<Struct>::type t = 40;

}

int main(int, const char**)
{
    printf("typedef.a = %d\n", a);
    printf("typedef.b = %d\n", b);
    printf("typedef.s = %d\n", s);
    printf("typedef.t = %d\n", t);
    return 0;
}
