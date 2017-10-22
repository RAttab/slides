/* baby.cpp                                 -*- C++ -*-
   Rémi Attab (remi.attab@gmail.com), 22 Oct 2017
   FreeBSD-style copyright and disclaimer apply

   https://en.wikipedia.org/wiki/PID_controller
   http://en.cppreference.com/w/cpp/language/template_specialization
*/

#include <cstdio>

namespace {

// I
template<int A, int B>
struct Sum
{
    static constexpr int value = A + B;
};

constexpr int sum = Sum<10, Sum<20, 30>::value>::value;


// II

constexpr long Kp = 1000;
constexpr long Ki = 1000;
constexpr long Kd = 10;

struct Nil
{
    static constexpr long error = 0;
    static constexpr long integral = 0;
    static constexpr long value = 0;
};

template<typename Prev, long Target, long Value, long Delta = 1>
struct Pid
{
    static constexpr long error = Target - Value;
    static constexpr long integral = Prev::integral + error * Delta;
    static constexpr long derivative = (error - Prev::error) / Delta;

    static constexpr long value = Kp * error + Ki * integral + Kd * derivative;
};

constexpr long pid = Pid<Nil, 100, 0>::value;


// III - IV

template<long Value>
struct Transition
{
    static constexpr long value = Value / 1723;
};

template<int N, typename State, long Target>
struct Loop
{
    typedef Pid<State, Target, Transition<State::value>::value> step;

    static constexpr long value = Loop<N - 1, step, Target>::value;
};


// IV

template<typename State, long Target>
struct Loop<0, State, Target>
{
    static constexpr long value = Transition<State::value>::value;
};

}


int main(int, const char**)
{
    printf("baby.sum = %d\n", sum);
    printf("baby.pid = %ld\n", pid);

    printf("baby.pid.Loop<  1, 1000000> = %ld\n", Loop<1, Nil, 1000000>::value);
    printf("baby.pid.Loop<  2, 1000000> = %ld\n", Loop<2, Nil, 1000000>::value);
    printf("baby.pid.Loop<  4, 1000000> = %ld\n", Loop<4, Nil, 1000000>::value);
    printf("baby.pid.Loop<  8, 1000000> = %ld\n", Loop<8, Nil, 1000000>::value);
    printf("baby.pid.Loop< 16, 1000000> = %ld\n", Loop<16, Nil, 1000000>::value);
    printf("baby.pid.Loop< 32, 1000000> = %ld\n", Loop<32, Nil, 1000000>::value);
    printf("baby.pid.Loop< 64, 1000000> = %ld\n", Loop<64, Nil, 1000000>::value);
    printf("baby.pid.Loop<128, 1000000> = %ld\n", Loop<128, Nil, 1000000>::value);

    return 0;
}
