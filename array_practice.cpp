/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    // Btw you can initialize variables like this:
    bool aa = false, bb = true;
    int az = 10, at = 20;
    //int **table = new * int [rows];

    //int * table = new int [cols];

    int My_Array[5] = {1, 2, 1000, 4, 5};
    int * a = My_Array;
    int ** c = &a;
    //cout << (*c)[2] << endl;
    cout << My_Array << endl; //  Note: The address of the first element of an array is the address of entire array it self
    cout << &My_Array[0] << endl;
    int my_cols = 4;
    int my_rows = 5;
    //So when can do something like this
    int * ptr = new int [my_cols];
    //The pointer is basically holding the first element address of the array
    //So when we do this:
    int ** my_table = new int *[my_rows];
    //We are storing the address of the first array(which is the address of the entire arrays) in the double pointer.
    //By typing new int*[rows], we are saying that we have a pointer that holds the number of arrays created with "rows" and the double pointer just stores all the arrays by accessing the first array element of the single pointer
    //Another of thinking about this is that when we create a dynamic array like this int * ptr = new int [cols],  we use a pointer to store that array. So, with this idea, if we wanted to create like 4 more arrays, we would have to create 4 more pointers that points to the arrays. However, for example, if we use int ** table = new int* [rows], "new int* [rows]" is the array created, but like the other example, since we are creating multiple arrays that each have pointers we have to indicate this by using this single pointer for new int[]

    cout << a[3] << endl;
    cout << *(a +3) << endl;

    int cols = 5;
    int rows = 6;
    int * b = new int[cols];
    //this is a pointer that holds the memory of an array that has a dynamic size
    int * x = new int[cols];

    //If we do this, we create a double pointer to a pointer that holds the dynamic memory of arrays.
    //new int * [cols] just holds the memory of the arrays just like int *x = new int[cols]
    //Since we are storing it in a double pointer, we can make y[i] = new int [rows], which iniliazes all the arrays to a specific siz
    //It intitalizes it to a specific size just like int * x = new int [cols], but this time the specific pointer to the sized array is store in a double pointer which lests just define the number of arrays
    int **z = new int*[rows];


    int **y = new int *[cols];
    for(int i = 0; i < cols; i++){
        y[i] = new int [rows];
    }
    return 0;
}
