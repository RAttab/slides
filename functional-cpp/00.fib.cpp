/* fib.cpp
   Rémi Attab (remi.attab@gmail.com), 22 Oct 2017
   FreeBSD-style copyright and disclaimer apply

   https://en.wikipedia.org/wiki/Fibonacci_number
*/

#include <cstdio>

namespace {

template<long N>
struct Fib
{
    static constexpr long value = Fib<N-1>::value + Fib<N-2>::value;
};

template<> struct Fib<2> { static constexpr long value = 1; };
template<> struct Fib<1> { static constexpr long value = 1; };
template<> struct Fib<0> { static constexpr long value = 0; };


template<long N>
struct FibFn
{
    static long step()
    {
        return FibFn<N - 1>::step() + FibFn<N - 2>::step();
    }
};


}

int main(int, const char**)
{
    printf("fib.10 = %ld\n", Fib<10>::value);
    printf("fib.50 = %ld\n", Fib<50>::value);

    printf("fib.fn.10 = %ld\n", Fib<10>::value);
    printf("fib.fn.50 = %ld\n", Fib<50>::value);
    return 0;
}
