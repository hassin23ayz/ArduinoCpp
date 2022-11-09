// https://www.programiz.com/cpp-programming/library-function/iostream/cin
// https://www.programiz.com/cpp-programming/vectors 
// https://cplusplus.com/reference/vector/vector/
// https://www.geeksforgeeks.org/passing-vector-function-cpp/

#include <iostream>
#include <vector>
using namespace std;

void show_elems(vector<int>& mVect ) // pass by reference 
{
    // iterate over the vector and print the elems 
    vector<int>::iterator iV;

    // The end() function points to the theoretical element that comes after the final element of the vector.
    for(iV = mVect.begin(); iV < mVect.end(); iV++)
    {
        cout << *iV << " ";
    }
    cout << "\n";
}

void erase_an_elem(vector<int>& mVect, int pos)
{
    mVect.erase(mVect.begin() + pos);
}

int main()
{

    int nOfElems;
    cout << "Enter how many elems you want to store ";
    cin  >> nOfElems;

    // dynamically filling up the vector 
    vector<int> mVect; 
    for(int i=0; i<nOfElems; i++)
    {
        int userIn;
        cin >> userIn;
        mVect.push_back(userIn);
    }

    // let's see the elems stored
    show_elems(mVect);

    // let's delete an element 3rd poisition
    erase_an_elem(mVect, 3);

    // let's see the elems stored
    show_elems(mVect);     

    return 0;
}
