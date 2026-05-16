# include <stdlib.h>
# include <stdio.h>

int dfsUtil(int** mat, int V, int node, int parent, int* visited){
    visited[node] = 1;

    for(int i = 0; i < V; i++){
        if (mat[node][i] == 1){
            if(!visited[i]){
                if(dfsUtil(mat, V, i, node, visited)){
                    return 1;
                }
            } else if (i != parent){
                return 1;
            }
        }
    }
}

int dfs(int** mat, int V){
    if(!mat){
        fprintf(stderr, "Error: Mat error\n");
        return -1;
    }

    int* visited = calloc(V, sizeof(int));
    if(!visited){
        fprintf(stderr, "Error: Visited error\n");
        return -1;
    }

    for (int v = 0; v < V; v++){
        if (!visited[v]){
            if(dfsUtil(mat, V, v, -1, visited)){
                return 1;
            }
        }
    }

    free(visited);
    return 0;
}


int main(){

    int V = 5;
    
    int** mat = malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++){
        mat[i] = calloc(V, sizeof(int));
    }

     // 0-1
    mat[0][1] = 1;
    mat[1][0] = 1;
    
    // 1-3
    mat[1][3] = 1;
    mat[3][1] = 1;
    
    // 0-2
    mat[0][2] = 1;
    mat[2][0] = 1;
    
    // 2-4
    mat[2][4] = 1;
    mat[4][2] = 1;
    
    // 3-4
    mat[3][4] = 1;
    mat[4][3] = 1;

    int res = dfs(mat, V);
    if(res){
        printf("Has cycle\n");
    } else {
        printf("Graph has no cycles\n");
    }

    return 0;
}