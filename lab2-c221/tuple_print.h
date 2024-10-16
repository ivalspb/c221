#pragma once
#include <tuple>
#include <iostream>

template <typename T, size_t N = std::tuple_size_v<T>>
void printTuple(const T& t)
{
    if constexpr (N > 0)
    {
        std::cout << std::get<N - 1>(t) << " ";
        printTuple<T, N - 1>(t);
    }
}

template<typename... Ts>
std::ostream& operator<<(std::ostream& os, std::tuple<Ts...> const& theTuple)
{
    std::apply
    (
        [&os](Ts const&... tupleArgs)
        {
            os << '[';
            std::size_t n{ 0 };
            ((os << tupleArgs << (++n != sizeof...(Ts) ? ", " : "")), ...);
            os << ']';
        }, theTuple
    );
    return os;
}

template <typename TupleType, size_t... Indexes>
void printTuple_seq(TupleType& t, std::index_sequence<Indexes...>)
{
    ((std::cout << std::get<Indexes>(t) << " "), ...);
}
template <typename TupleType>
void printTuple_s(TupleType& t)
{
    printTuple_seq(t, std::make_index_sequence<std::tuple_size_v<TupleType>>{});
}