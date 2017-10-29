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
#if 0 

int c = 30;
constexpr int d = d + 40;

#endif

}

int main(int, const char**)
{
    printf("constexpr.a = %d\n", a);
    printf("constexpr.b = %d\n", b);
    return 0;
}
