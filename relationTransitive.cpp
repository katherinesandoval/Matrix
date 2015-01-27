// Name: Katherine Sandoval
// These functions determines if a given matrix representing a relation on a finite set is transitive.

int transitiveClosure(int graph[V][V])
{
    int sum = 0;

    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
         sum = graph[i][j] ;
      
    return sum;
}

bool isTransitive(int graph[V][V]){
    
    int k = 0;
    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            original[i][j] = graph[i][j];
    
    transitiveClosure(graph);
    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if(original[i][j] == graph[i][j])
                k++;
    
    if(k == (V*V))
        return true;
    else
        return false;
}