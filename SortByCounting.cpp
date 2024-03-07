#include <iostream>

// Result: the number of elements smaller than a[i]
int countLessThan (int a[], int lenght, int i)
{
    int j, count = 0;

    for (j = 0; j < lenght; j++)
    {
        if (a[j] < a[i] || (a[j] == a[i] && i < j))
        {
            count++;
        }
    }
    return count;
}



/* // Action: sort table a[] using the counting sort algorithm
void sortByCounting(int a[], int lenght)
{
    int i, lessThan;
    int *b = new int[lenght];

    for (i = 0; i < lenght; i++)
    {
        lessThan = countLessThan(a, lenght, i);
        b[lessThan] = a[i];
    }

    for (i = 0; i < lenght; i++)
    {
        a[i] = b[i];
    }
    delete [] b;
}

int main ()
{
    int i, lenght;
    int *a;



    lenght = 6;
    
    // initialize the array a with the values 5, 2, 8, 2, 7, 1
    a = new int[lenght];
    a[0] = 5;
    a[1] = 2;
    a[2] = 8;
    a[3] = 2;
    a[4] = 7;
    a[5] = 1;

    

    sortByCounting(a, lenght);
    std::cout << "The sorted array is: " << std::endl;
    for (i = 0; i < lenght; i++)
    {
        std::cout << a[i] << std::endl;
    }

    return 0;
} */


int main() {
    {
        int a[] = {5, 2, 8, 2, 7, 1};
        int result = countLessThan(a, 6, 1);
        // print result of function:
        std::cout << "Test 1: " << result << "\n";

    }

    
    return 0;
}