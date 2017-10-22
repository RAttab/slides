/* tuple.cpp                                 -*- C++ -*-
   Rémi Attab (remi.attab@gmail.com), 22 Oct 2017
   FreeBSD-style copyright and disclaimer apply

   http://en.cppreference.com/w/cpp/language/parameter_pack
*/

#include <cstdio>

namespace {


// I

template<typename... Types> struct Tuple;

struct A; struct B; struct C;
typedef Tuple<A, int, B, C> tuple;


// II

template<typename Tuple>
struct Test
{
    static constexpr bool value = false;
};

template<typename X, typename Y, typename Z>
struct Test< Tuple<X, int, Y, Z> >
{
    static constexpr bool value = true;
};

constexpr bool passed = Test<Tuple<A, int, B, C> >::value;
constexpr bool failed = Test<Tuple<A, long, B, C> >::value;


// III

template<int N, typename Tuple> struct Get {};

template<typename Head, typename... Rest>
struct Get<0, Tuple<Head, Rest...>>
{
    typedef Head type;
};

template<int N, typename Head, typename... Rest>
struct Get<N, Tuple<Head, Rest...> >
{
    typedef typename Get<N - 1, Tuple<Rest...> >::type type;
};

Get<1, Tuple<A, int, B, C> >::type get = 10;


// IV

template<typename Type, Type Value>
struct Constant
{
    static constexpr Type value = Value;
};

constexpr int constant = Get<1, Tuple<long, Constant<int, 20> > >::type::value;

}

int main(int, const char**)
{
    printf("tuple.test.pass = %d\n", passed);
    printf("tuple.test.fail = %d\n", failed);
    printf("tuple.get.1 = %d\n", get);
    printf("tuple.constant = %d\n", constant);
    return 0;
}
