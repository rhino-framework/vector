#include "vector.hpp"

int main(int argc, char const *argv[])
{
    RHino::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    auto back = v1.back();

    return 0;
}
