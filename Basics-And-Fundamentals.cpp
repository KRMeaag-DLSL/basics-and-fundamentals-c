#include <iostream>

using namespace std;

int main(void)
{
    // Variable Declaration
    int *firstArray = NULL;
    int *secondArray = NULL;
    int firstSize;
    int secondSize;

    const int MAX_SIZE = 10;

    // Asking Size from User

    cout << "\nThe max size of each array is " << MAX_SIZE << endl;
    do
    { 
        cout << "\nSize of first array: ";
        cin >> firstSize;
        cout << "Size of second array: ";
        cin >> secondSize;

        if (firstSize < 0 || secondSize < 0 || firstSize > MAX_SIZE || secondSize > MAX_SIZE)
        {
            cout << "\nOne or both of the variables is either more than ten or a negative number. Try again!" << endl;
        }

    } while (firstSize < 0 || secondSize < 0 || firstSize > MAX_SIZE || secondSize > MAX_SIZE);
    
    // Declaring of Dynamic Arrays using Malloc
    firstArray = new int(firstSize);
    secondArray = new int(secondSize);

    // Creating Total Array using Malloc
    int totalSize = firstSize + secondSize;
    int *totalArray = new int(firstSize + secondSize);

    // Asking Numbers from User
    int num;

    // For First Array
    for (int i = 0; i < firstSize; i++)
    {
        cout << "\nFirst Array, Number " << i + 1 << ": ";
        cin >> num;
        firstArray[i] = num;
    }

    // For Second Array
    for (int i = 0; i < secondSize; i++)
    {
        cout << "\nSecond Array, Number " << i + 1 << ": ";
        cin >> num;
        secondArray[i] = num;
    }

    // Combining Arrays

    // Insert First Array
    for (int j = 0; j < firstSize; j++)
    {
        totalArray[j] = firstArray[j];
    }

    // Insert Second Array
    for (int j = 0; j < secondSize; j++)
    {
        totalArray[firstSize + j] = secondArray[j];
    }

    // Sorting Total Array Using Selection Sort
    for (int i = 0; i < totalSize; i++)
    {
        int biggestNum = totalArray[i];
        int biggestNumIndex = i;

        // Find Biggest Num
        for (int j = 0 + i; j < totalSize; j++)
        {
            if (biggestNum < totalArray[j])
            {
                biggestNum = totalArray[j];
                biggestNumIndex = j;
            }
        }

        int tempVal = totalArray[i];
        totalArray[i] = biggestNum;
        totalArray[biggestNumIndex] = tempVal;
    }

    cout << "\nSorted Array: ";

    // Printing Arrays in Descending Order
    for (int i = 0; i < totalSize; i++)
        cout << totalArray[i] << "  ";

    cout << endl;

    free(firstArray);
    free(secondArray);
    free(totalArray);
}
