#include <iostream>
using namespace std;

int main (void)
{
    int height = 0;
    cout << "Height: ";
    cin >> height;

    cout << endl;

    for (int i = 1; i <= height; i++) 
    { 
        int starCount = (i * 2) - 1;
        int spaceCount = height - i + 1;

        for (int j = 0; j < spaceCount; j++)
          cout << " ";

        for (int j = 0; j < starCount; j++)
          cout << "*";

        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0;  j < height; j++)
          cout << " ";

        cout << "*";
        cout << endl;
    }
    return 0;
}
//      *
//     ***
//    *****
//   *******
//  *********
//      *
//      *