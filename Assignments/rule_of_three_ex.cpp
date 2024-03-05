#include <iostream>

class IntVec
{
    /*
    Wrtie a vector class that has a contructor, destructor and copy constructor
    Also overload the following operators: assignment (=), addition (+), equality (==), susbcript / array index ([])
    You will also need to implement a public function size() that gives the lenght or size of the vector

    The output of your pgoram should be:
    v1[0] = 0, v2[0] = 0
    v1[1] = 1, v2[1] = 2
    v1[2] = 2, v2[2] = 4
    v1[3] = 3, v2[3] = 6
    v1[4] = 4, v2[4] = 8
    v1[0] = 0, v2[0] = 0
    v1[1] = 2, v2[1] = 2
    v1[2] = 4, v2[2] = 4
    v1[3] = 6, v2[3] = 6
    v1[4] = 8, v2[4] = 8
    V1 is equal to V2
    v1[0] = 0, v2[0] = 0, v3[0] = 0
    v1[1] = 2, v2[1] = 2, v3[1] = 4
    v1[2] = 4, v2[2] = 4, v3[2] = 8
    v1[3] = 6, v2[3] = 6, v3[3] = 12
    v1[4] = 8, v2[4] = 8, v3[4] = 16
    */
};

int main()
{
    IntVec v1(5); // create an IntVec with size 5

    // initialize v1 with some values
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] = i;
    }

    IntVec v2(v1); // create a copy of v1 using the copy constructor

    // modify v2
    for (int i = 0; i < v2.size(); i++)
    {
        v2[i] *= 2;
    }

    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << "v1[" << i << "] = " << v1[i] << ", v2[" << i << "] = " << v2[i] << std::endl;
    }

    v1 = v2; // use the assignment operator to copy v2 back into v1
    // print out v1 and v2 to verify that they have the same values
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << "v1[" << i << "] = " << v1[i] << ", v2[" << i << "] = " << v2[i] << std::endl;
    }

    if (v1 == v2)
    {
        std::cout << "V1 is equal to V2" << std::endl;
    }

    IntVec v3 = v1 + v2;
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << "v1[" << i << "] = " << v1[i] << ", v2[" << i << "] = " << v2[i] << ", v3[" << i << "] = " << v3[i]
                  << std::endl;
    }

    return 0;
}
