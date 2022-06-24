#include <iostream>
#include "lib.hpp"

using namespace Eigen;
using namespace std;

int main(int argc, char* argv[]) {
    std::cout << hello_world() << "\n";
    printf("argc %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("arg %d: %s\n", i, argv[i]);
    }

    Vector2i m1(1, 2);

    int *m1d = m1.data();
    int *m1dp = &m1d[0];

    VectorXi m2(2);
    m2 << 3,4;
    int *m2d = m2.data();

    int *ap = new int[4]{1,2,3,4};
    int arr[4] = {1,2,3,4};
    int *arrp = arr;
    
    return 0;
}