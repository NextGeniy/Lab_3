#include <iostream>
#include <thread>
#include <iomanip>             
#include <Windows.h>
#include <ctime>
using namespace std;
void printMatrix(int**, int, bool = 1);
void printMatrix(int** matrix, int N, bool zero)
{
    if (zero) system("cls");
    for (int** elemJ = matrix, **lastJ = elemJ + N - 1; elemJ <= lastJ; elemJ++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N - 1; elemI <= lastI; elemI++)
        {
            cout << setw(3) << *elemI;
            if (elemI != lastI) cout << " ";
        }
        cout << "\n";
    }
    std::this_thread::sleep_for(0.1s);
}
void zeroMatrix(int** matrix, int N) {
    for (int** elemJ = matrix, **lastJ = elemJ + N - 1; elemJ <= lastJ; elemJ++) 
    {
        for (int* elemI = *elemJ, *lastI = elemI + N - 1; elemI <= lastI; elemI++) 
        {
            *elemI = 0;
        }
    }
}

void snakeMatrix(int** matrix, int N) {
    printMatrix(matrix, N);
    for (int lineNum = 0; lineNum < N / 2; ++lineNum) {
        for (int** elemJ = matrix, **lastJ = matrix + N - 1; elemJ <= lastJ; elemJ++) 
        {
            *(*elemJ + lineNum * 2) = rand() % 101;
            printMatrix(matrix, N);
        }
        for (int** elemJ = matrix + N - 1, **lastJ = matrix; elemJ >= lastJ; elemJ--) 
        {
            *(*elemJ + lineNum * 2 + 1) = rand() % 101;
            printMatrix(matrix, N);
        }
    }
}
void rotateMatrix(int** matrix, int N) {
    int** a = new int* [N / 2], ** b = new int* [N / 2], ** c = new int* [N / 2], ** d = new int* [N / 2], *** arr = new int** [4];
    arr[0] = a; arr[1] = b; arr[2] = c; arr[3] = d;
    for (int*** i = arr, ***ilast = arr + 3; i <= ilast; i++)
    {
        for (int** elem = *i, **last = elem + N / 2 - 1; elem <= last; elem++)
        {
            *elem = new int[N / 2];
        }
    }

    for (int** elemJ = matrix, **lastJ = elemJ + N / 2 - 1, **elemArray = a; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemArrayJ = *elemI;
        }
    }

    for (int** elemJ = matrix, **lastJ = elemJ + N / 2 - 1, **elemArray = b; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ + N / 2, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemArrayJ = *elemI;
        }
    }

    for (int** elemJ = matrix + N / 2, **lastJ = elemJ + N / 2 - 1, **elemArray = c; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemArrayJ = *elemI;
        }
    }

    for (int** elemJ = matrix + N / 2, **lastJ = elemJ + N / 2 - 1, **elemArray = d; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ + N / 2, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemArrayJ = *elemI;
        }
    }

    int** pa, ** pb, ** pc, ** pd;
    pa = c; pb = d; pc = a; pd = b;

    for (int** elemJ = matrix, **lastJ = elemJ + N / 2 - 1, **elemArray = pa; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemI = *elemArrayJ;
        }
    }

    for (int** elemJ = matrix, **lastJ = elemJ + N / 2 - 1, **elemArray = pb; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ + N / 2, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemI = *elemArrayJ;
        }
    }

    for (int** elemJ = matrix + N / 2, **lastJ = elemJ + N / 2 - 1, **elemArray = pc; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemI = *elemArrayJ;
        }
    }

    for (int** elemJ = matrix + N / 2, **lastJ = elemJ + N / 2 - 1, **elemArray = pd; elemJ <= lastJ; elemJ++, elemArray++)
    {
        for (int* elemI = *elemJ + N / 2, *lastI = elemI + N / 2 - 1, *elemArrayJ = *elemArray; elemI <= lastI; elemI++, elemArrayJ++)
        {
            *elemI = *elemArrayJ;
        }
    }


    printMatrix(matrix, N, 0);
}
void sortMatrix(int** matrix, int N) {
    int* arr = new int[N * N];
    int i = 0;
    for (int** elemJ = matrix, **lastJ = elemJ + N - 1; elemJ <= lastJ; elemJ++) 
    {
        for (int* elemI = *elemJ, *lastI = elemI + N - 1; elemI <= lastI; elemI++) 
        {
            *(arr + i) = *elemI;
            i++;
        }
    }
    bool reverse = 1;
    while (reverse) {
        reverse = 0;
        for (int* j = arr, *jlast = j + (N * N) - 2; j <= jlast; j++) 
        {
            if (*j > *(j + 1)) 
            {
                reverse = 1;
                int t = *(j + 1);
                *(j + 1) = *j;
                *j = t;
            }
        }
    }

    i = 0;
    for (int** elemJ = matrix, **lastJ = elemJ + N - 1; elemJ <= lastJ; elemJ++) 
    {
        for (int* elemI = *elemJ, *lastI = elemI + N - 1; elemI <= lastI; elemI++) 
        {
            *elemI = *(arr + i);
            i++;
        }
    }
    printMatrix(matrix, N, 0);
}
void increaseMatrix(int** matrix, int N, int k) {
    for (int** elemJ = matrix, **lastJ = elemJ + N - 1; elemJ <= lastJ; elemJ++)
    {
        for (int* elemI = *elemJ, *lastI = elemI + N - 1; elemI <= lastI; elemI++)
        {
            *elemI *= k;
        }
    }
    printMatrix(matrix, N, 0);
}

int main()
{
    srand(time(NULL));
    int N;
    cout << "Enter N(6, 8 or 10):" << "\n";
    cin >> N;
    while (N != 6 && N != 8 && N != 10) {
        cout << "Wrong N value, try again" << "\n";
        cin >> N;
    }
    int** matrix = new int* [N];
    for (int** elem = matrix, **last = elem + N - 1; elem <= last; elem++)
    {
        *elem = new int[N];
    }
    zeroMatrix(matrix, N);
    snakeMatrix(matrix, N);
    cout << "Rotated matrix: " << '\n';
    rotateMatrix(matrix, N);
    cout << '\n' << "Sorted matrix: " << '\n';
    sortMatrix(matrix, N);
    cout << '\n' << "Enter a value to increase matrix elements: ";
    int k;
    cin >> k;
    increaseMatrix(matrix, N, k);
}
