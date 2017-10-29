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

struct Nil;

template<typename X, typename Y> struct Cons;


typedef Cons<Constant<int, 10>,
        Cons<Constant<int, 20>,
        Cons<Constant<int, 30>, Nil> > > list;


// II

template<typename Cons> struct Car;

template<typename X, typename Y>
struct Car<Cons<X, Y> >
{
    typedef X type;
};

template<typename Cons> struct Cdr;

template<typename X, typename Y>
struct Cdr<Cons<X, Y> >
{
    typedef Y type;
};


// III

template<typename Cons>
struct Print
{
    static void print()
    {
        printf("(%d, ", Car<Cons>::type::value);
        Print<typename Cdr<Cons>::type>::print();
        printf(")");
    }
};

template<>
struct Print<Nil>
{
    static void print() { printf("nil"); }
};


// IV

template<int Factor>
struct Mul
{
    template<typename Value>
    auto apply(Value*) -> Constant<int, Value::value * Factor> {}
};

template<typename Fn, typename Arg>
struct Apply
{
    typedef decltype(((Fn *) nullptr)->apply((Arg *) nullptr)) type;
};

template<typename Fn, typename List>
struct Map
{
    typedef Cons<
        typename Apply<Fn, typename Car<List>::type>::type,
        typename Map<Fn, typename Cdr<List>::type>::type> type;
};

template<typename Fn>
struct Map<Fn, Nil>
{
    typedef Nil type;
};

}

int main(int, const char**)
{
    printf("list.print = ");
    Print<list>::print();
    printf("\n");

    printf("list.mul = ");
    Print<typename Map<Mul<20>, list>::type>::print();
    printf("\n");

    return 0;
}
