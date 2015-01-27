// Name: Katherine Sandoval
// These functions determines if a given matrix representing a relation on a finite set is symmetric and/or antisymmetric.

bool isSymmetric(int m[n][n]){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(m[i][j] && !m[j][i]) // if numbers equal (1 and 0, o would be 1), return false (different numbers)
                return false;
    return true;
}

bool isAntisymmetric(int m[n][n]){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(m[i][j] && m[j][i] && (i != j)) // if 1 and 1 and 1 != 0 return false
                return false;
    return true;
}