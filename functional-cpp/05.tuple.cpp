/* tuple.cpp                                 -*- C++ -*-
   Rémi Attab (remi.attab@gmail.com), 22 Oct 2017
   FreeBSD-style copyright and disclaimer apply

   http://en.cppreference.com/w/cpp/language/parameter_pack
*/

#include <cstdio>

namespace {

template<typename Type, Type Value>
struct Constant
{
    static constexpr Type value = Value;
};


// I

template<typename... Types> struct Tuple;

struct Alice;
typedef Tuple<Alice, Constant<int, 10> > alice;

struct Bob;
typedef Tuple<Bob, Constant<bool, true>, Constant<long, 200> > bob;


// II

template<typename Tuple>
struct IsBob
{
    static constexpr bool value = false;
};

template<typename... Rest>
struct IsBob< Tuple<Bob, Rest...> >
{
    static constexpr bool value = true;
};

static constexpr bool alice_is_bob = IsBob<alice>::value;
static constexpr bool bob_is_bob = IsBob<bob>::value;


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

static constexpr long get = Get<2, bob>::type::value;

}

int main(int, const char**)
{
    printf("tuple.isbob.alice = %d\n", alice_is_bob);
    printf("tuple.isbob.bob = %d\n", bob_is_bob);
    printf("tuple.get.2 = %ld\n", get);
    return 0;
}
