// Name: Katherine Sandoval
// These functions determines if a given matrix representing a relation on a finite set is reflexive and/or irreflexive.

bool isReflexive(int m[n][n]){
   for(int i = 0; i < n; i++)
        if(!m[i][i]) // if m[i][i] (is 1) then 0 return false
            return false;
    return true;
}

bool isIrreflexive(int m[n][n]){
    for(int i = 0; i < n; i++)
        if(m[i][i]) // if m[i][i] is 1 then return false
            return false;
        }
    return true;
}