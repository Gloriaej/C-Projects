



#include<iostream>  //for input and output services(cin, cout and the likes)
#include<fstream>  // library for inuput & output file streams
#include<cassert>  //This helps to ensure files were read correctly


using namespace std;

//Function Prototypes
int * shrinkArray(int firstArray[], int size);

double calcAvg(int *newArray, int size);

//The main Function
int main()
{
        int value;    //A variable that holds the numbers being read from the file
        int initialSize; //A variable that holds the first number in the file(the initial size)
        ifstream myIn;   // input file stream variable
        ofstream myOut;  //output file stream variable
        myIn.open("nums.txt"); // This line opens the data file nums.txt for processing
        assert(myIn);          //checks to make sure the file was read correctly


        myOut.open("out.txt");  //To open the output file out.txt ready to receive

        myIn >> initialSize;    // reads in the first line which is the initial size of the array


        int     *firstArray = new int[initialSize];  //dynamic memory allocation
        int actualSize = 0;                                             //variable to hold the count of array elements

        while(myIn >> value) //This while loop reads in the remaining values from the file and puts them in the array
        {

                        firstArray[actualSize] = value;

                         actualSize++;  //increments the size as it goes
        }

        int *lastArray = shrinkArray(firstArray, actualSize);//Function call to shrinkArray

        double avg = calcAvg(lastArray, actualSize); //Function call for calcAvg function

        //This lines prints results to stdout and writes to the output files
        cout<<initialSize<<endl;
        myOut<< initialSize<<endl;
        cout<<actualSize<<" ";
        myOut << actualSize<<" ";
        cout<< avg<<endl;

        myOut<< avg<<endl;

        myIn.close();   //Closing the files after use
        myOut.close();

        delete [] firstArray;    //Deallocating memory
        firstArray = nullptr;
return 0;
}


//Function definitions

//This function ShrinkArray takes in an array that is possibly not filled to capacity
//Then shrinks the array to the actual size of elements that are in the array and returns
//a pointer to the new perfectly sized array.

int * shrinkArray(int firstArray[], int size)
{
        int *newArray = new int[size];       //dynamic memory allocation


        for(int i = 0; i < size; i++)     //This for loop that copies all the elements of the bigger array to the new array
                {
                newArray[i] = firstArray[i];
                }

                delete [] firstArray; //Deallocating memory
                firstArray = nullptr;
        return newArray;                      //returns a pointer to the new array.
}

//This function calcAvg takes in a pointer to an array, sums its elements
//calculates the average and returns the calculated average.

double calcAvg(int *newArray, int size)
{


        double sum = 0;

        for( int i = 0; i< size; i++)//This for loops goes through the array
        {
                sum += newArray[i];     // adds each element to the sum

        }

        return   sum / size;  // returns calculated average


}
