// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}

//Exercise 2.1: 
//Size: Amount of elements stored in vector.
//Capacity: Number of elements that vector can currently accomodate without expansion (capacity >= size).
//Capacity expansion: Generally doubles (though 1.5 multiplication offers better efficiency) - based on tradeoff between time taken to copy elements to newly assigned memory block vs time taken to insert new elements in available capacity.