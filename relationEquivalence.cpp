// Name: Katherine Sandoval
// This program displays all the equivalence relations on a set of seven elements.

#include <iostream>
#include <fstream>
using namespace std;

bool isSymmetric(int m[7][7]);
bool isReflexive(int m[7][7]);
int transitiveClosure(int graph[7][7]);
bool isTransitive(int graph[7][7]);
int original[4][4];

int main(){
	
	int matrix[7][7];
	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 7; ++j){
			matrix[i][j] = 0;
		}
	}

	ofstream combos;
    combos.open("com.txt", ios :: app);
    if(!combos)
        cout << "File could not be opened"<<endl;
	
	for(int h = 0; h < 28; ++h){
		for(int i = h; i < 7; ++i){
			for(int j = h; j < 7; ++j){
				matrix[h][j] = 1;
				matrix[j][h] = 1;
				
				matrix[i][j] = 1;
				matrix[j][i] = 1;

				for(int i = 0; i < 7; ++i){
					for(int j = 0; j < 7; ++j){
						matrix[0][0] = 1, matrix[1][1] = 1, matrix[2][2] = 1, matrix[3][3] = 1, matrix[4][4] = 1;
						matrix[i][j] = matrix[i][j];
						if(isReflexive(matrix) && isSymmetric(matrix) && isTransitive(matrix))
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

bool isReflexive(int m[7][7]){
   for(int i = 0; i < 7; i++)
        if(!m[i][i]) // if m[i][i] (is 1) then 0 return false
            return false;
    return true;
}

bool isSymmetric(int m[7][7]){
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
            if(m[i][j] && !m[j][i]) // if numbers equal (1 and 0, o would be 1), return false (different numbers)
                return false;
    return true;
}

int transitiveClosure(int graph[7][7])
{
    int sum = 0;

    for (int k = 0; k < 7; k++){
        for (int i = 0; i < 7; i++){
            for (int j = 0; j < 7; j++){
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
    
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
         sum = graph[i][j] ;
      
    return sum;
}

bool isTransitive(int graph[7][7]){
    
    int k = 0;
    
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            original[i][j] = graph[i][j];
    
    transitiveClosure(graph);
    
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            if(original[i][j] == graph[i][j])
                k++;
    
    if(k == 49)
        return true;
    else
        return false;
}