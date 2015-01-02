#include <tuple_cast.hpp>
#include <tuple>

#include <stdio.h>

int main(int argc, char *argv[])
{
    auto doubles    = std::make_tuple((double)1.0, (double)2.13, (double)3.14);
    auto floats     = std::tuple_cast<float, float, float>(doubles);
    auto ints       = std::tuple_cast<int, int, int>(doubles);

    fprintf(stdout, "%d, %lf %lf %lf\n", (int)sizeof(std::get<0>(doubles)), std::get<0>(doubles), std::get<1>(doubles), std::get<2>(doubles));
    fprintf(stdout, "%d, %f %f %f\n", (int)sizeof(std::get<0>(floats)), std::get<0>(floats), std::get<1>(floats), std::get<2>(floats));
    fprintf(stdout, "%d, %d %d %d\n", (int)sizeof(std::get<0>(ints)), std::get<0>(ints), std::get<1>(ints), std::get<2>(ints));

    return 0;
}
