#include <iostream>

using namespace std;

int main(){

    const int row1 = 2;
    const int row2 = 2;
    
    const int col1 = 2;
    const int col2 = 2;

    if(col1 != row2){
        
        cout << "Can't multiply these matricies. Try again with different dimensions." << endl;
        return 1; // exit code 1 for dimension error.

    }

    const int row3 = row1;
    const int col3 = col2;

    cout << "Multiplying a " << row1 << "x" << col1 << " matrix by a " << row2 << "x" << col2 << " matrix, resulting in a " << row3 << "x" << col3 << " matrix." << endl << endl;

    int matrix1[row1][col1];
    int matrix2[row2][col2];
    int matrix3[row3][col3];

    // taking in vals for matrix 1
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++){
            
            int temp;
            
            cout << "Enter the integer at (" << (i + 1) << ", " << (j + 1) << ") in the first matrix: ";
            cin >> temp;

            matrix1[i][j] = temp;

        }
    }

    cout << endl;

    // taking in the vals for matrix 2
    for(int i = 0; i < row2; i++){
        
        for(int j = 0; j < col2; j++){
            
            int temp;
            
            cout << "Enter the integer at (" << (i + 1) << ", " << (j + 1) << ") in the second matrix: ";
            cin >> temp;

            matrix2[i][j] = temp;

        }

    }

    cout << endl << "Matrix 1: " << endl;

    for(int i = 0; i < row1; i++){
        
        for(int j = 0; j < col1; j++){

            cout << matrix1[i][j] << " ";
        
        }

        cout << endl;
    }

    cout << endl << "Matrix 2: " << endl;

    for(int i = 0; i < row2; i++){
        
        for(int j = 0; j < col2; j++){

            cout << matrix2[i][j] << " ";
        
        }

        cout << endl;
    }

    cout << endl << "Result: " << endl;

    for(int targetRow = 0; targetRow < row3; targetRow++){

        for(int targetCol = 0; targetCol < col3; targetCol++){

            int temp = 0;

            for(int i = 0; i < col1; i++){
                
                temp += matrix1[targetRow][i] * matrix2[i][targetCol];
                
            }

            matrix3[targetRow][targetCol] = temp;

            cout << temp << " ";

        }

        cout << endl;
    }

    return 0;
}
