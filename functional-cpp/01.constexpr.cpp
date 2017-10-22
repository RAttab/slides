/* constexpr.cpp
   Rémi Attab (remi.attab@gmail.com), 22 Oct 2017
   FreeBSD-style copyright and disclaimer apply

   http://en.cppreference.com/w/cpp/language/constexpr
*/

#include <cstdio>

namespace {

// I
constexpr int a = 10;
constexpr int b = a + 5;

// II
constexpr int fn(int a, int b) { return a * b; }
constexpr int c = fn(a, 20);

// III
#if 0 

int d = 30;
constexpr int e = d + 40;

#endif

}

int main(int, const char**)
{
    printf("constexpr.a = %d\n", a);
    printf("constexpr.b = %d\n", b);
    printf("constexpr.c = %d\n", c);
    return 0;
}
