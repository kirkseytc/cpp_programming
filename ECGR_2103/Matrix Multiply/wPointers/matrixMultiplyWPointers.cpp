#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int r1, r2, r3, c1, c2, c3;

    cout << "Please enter the amount rows of the first matrix : ";
    cin >> r1;

    cout << "Please enter the amount columns of the first matrix : ";
    cin >> c1;

    cout << endl;

    cout << "Please enter the amount rows of the second matrix : ";
    cin >> r2;

    cout << "Please enter the amount columns of the second matrix : ";
    cin >> c2;

    if(r2 != c1){
        cout << "Cannot multiply these matricies, try again with different dimensions." << endl;
        exit(1);
    }

    r3 = r1;
    c3 = c2;

    cout << endl << "Multiplying a " << r1 << "x" << c1 << " matrix by a " << r2 << "x" << c2 << " matrix, resulting in a " << r3 << "x" << c3 << " matrix." << endl << endl;

    int *matrix1 = (int *)malloc(sizeof(int) * r1 * c1);
    int *matrix2 = (int *)malloc(sizeof(int) * r2 * c1);
    int *matrix3 = (int *)malloc(sizeof(int) * r3 * c3);

    if(matrix1 == NULL || matrix2 == NULL || matrix3 == NULL){
        cout << "Malloc Fail. Aborting." << endl;
        exit(1);
    }

    // taking in vals for matrix 1
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            
            int temp;
            
            cout << "Enter the integer at (" << (i + 1) << ", " << (j + 1) << ") in the first matrix: ";
            cin >> temp;

            matrix1[c1 * i + j] = temp;

        }
    }

    cout << endl;

    // taking in the vals for matrix 2
    for(int i = 0; i < r2; i++){
        for(int j = 0; j < c2; j++){
            
            int temp;
            
            cout << "Enter the integer at (" << (i + 1) << ", " << (j + 1) << ") in the second matrix: ";
            cin >> temp;

            matrix2[c2 * i + j] = temp;

        }
    }

    cout << endl << "Matrix 1: " << endl;

    for(int i = 0; i < r1 * c1; i++){
        cout << matrix1[i] << " ";

        if(i % c1 == c1 - 1){
            cout << endl;
        }
    }

    cout << endl << "Matrix 2: " << endl;

    for(int i = 0; i < r2 * c2; i++){
        cout << matrix2[i] << " ";

        if(i % c2 == c2 - 1){
            cout << endl;
        }
    }

    cout << endl << "Result: " << endl;

    for(int i = 0; i < r3; i++){

        for(int j = 0; j < c3; j++){

            int temp = 0;

            for(int k = 0; k < c1; k++){
                
                temp += matrix1[k * r1 + j] * matrix2[i * r2 + k];
                
            }

            matrix3[r3 * i + j] = temp;

            cout << matrix3[r3 * i + j] << " ";

        }

        cout << endl;
    }

    free(matrix1);
    matrix1 = NULL;

    free(matrix2);
    matrix2 = NULL;

    free(matrix3);
    matrix3 = NULL;

    return 0;
}