// Name: Katherine Sandoval
// This program displays all the different reflexive and symmetric relations on a set of five elements.

#include <iostream>
#include <fstream>
using namespace std;

bool isSymmetric(int m[5][5]);
bool isReflexive(int m[5][5]);

int main(){
	
	int matrix[5][5];
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			matrix[i][j] = 0;
		}
	}

	ofstream combos;
    combos.open("combos.txt", ios :: app);
    if(!combos)
        cout << "File could not be opened"<<endl;
	
	for(int h = 0; h < 15; ++h){
		for(int i = h; i < 5; ++i){
			for(int j = h; j < 5; ++j){
				matrix[h][j] = 1;
				matrix[j][h] = 1;
				
				matrix[i][j] = 1;
				matrix[j][i] = 1;

				for(int i = 0; i < 5; ++i){
					for(int j = 0; j < 5; ++j){
						matrix[0][0] = 1, matrix[1][1] = 1, matrix[2][2] = 1, matrix[3][3] = 1, matrix[4][4] = 1;
						matrix[i][j] = matrix[i][j];
						if(isReflexive(matrix) && isSymmetric(matrix))
        					combos << matrix[i][j] << " ";
    				}
					combos << endl;  
				}
				combos << endl;
				
				matrix[i][j] = 0;
				matrix[j][i] = 0;
			}
		}	
	}

	combos.close();
	return 0;
}

bool isReflexive(int m[5][5]){
   for(int i = 0; i < 5; i++)
        if(!m[i][i]) // if m[i][i] (is 1) then 0 return false
            return false;
    return true;
}

bool isSymmetric(int m[5][5]){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(m[i][j] && !m[j][i]) // if numbers equal (1 and 0, o would be 1), return false (different numbers)
                return false;
    return true;
}