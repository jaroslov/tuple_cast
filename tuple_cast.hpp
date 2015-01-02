#ifndef TUPLE_CAST_HPP
#define TUPLE_CAST_HPP

#include <tuple>

namespace std
{

namespace
{

template <typename T, typename U>
void tuple_cast_at_recursive(T& t, U const& u)
{
}

template <typename Head, typename... Len, typename T, typename U>
void tuple_cast_at_recursive(T& t, U const& u)
{
    constexpr size_t index  = (size_t)tuple_size<U>::value - (size_t)tuple_size<tuple<Len...>>::value - (size_t)1;
    get<index>(t)   = get<index>(u);
    tuple_cast_at_recursive<Len...>(t, u);
}

}// end anonmyous namespace.

template <typename... Ts, typename... Us>
tuple<Ts...> tuple_cast(tuple<Us...> const& u)
{
    static_assert(tuple_size<tuple<Ts...>>::value == tuple_size<tuple<Us...>>::value, "Tuple cast must perserve arity.");
    tuple<Ts...> t;
    tuple_cast_at_recursive<Ts...>(t, u);
    return t;
}

}// end namespace std.

#endif//TUPLE_CAST_HPP
