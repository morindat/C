# include <stdio.h>
# include <stdlib.h>

int* bfs(int** mat, int n, int src){
    if(!mat){
        fprintf(stderr, "Error: Mat error\n");
        return NULL;
    }

    int* res = malloc(n * sizeof(int));
    int* que = malloc(n * sizeof(int));

    if(!res || !que){
        fprintf(stderr, "Error: res error or que error\n");
        free(que);
        free(res);
        return NULL;
    }

    int* visited = calloc(n, sizeof(int));
    if (!visited){
        fprintf(stderr, "Error: Visited error\n");
    }

    int rear = 0, front = 0;
    que[rear++] = src;
    visited[src] = 1;
    int indx = 0;

    while (front < rear){
        int node = que[front++];
        res[indx] = node;

        for(int v = 0; v < n; v++){
            if (mat[node][v] == 1 && !visited[v]){
                visited[v] = 1;
                que[rear++] = v;
            }
        }

        indx ++;
    }

    return res;

}

int shorterstPath(int** mat, int n, int start, int finish){
    if(!mat){
        fprintf(stderr, "Error: Mat error\n");
        return -1;
    }

    int* distances = malloc(n * sizeof(int));
    if(!distances){
        fprintf(stderr, "Error: Mat error\n");
        return -1;
    }

    int* q = malloc(n * sizeof(int));
    if(!q){
        fprintf(stderr, "Error: malloc error on q\n");
        return -1;
    }

    for(int i = 0; i < n; i++) distances[i] = -1;
    int rear = 0, front = 0;
    distances[start] = 0;
    q[rear++] = start;

    if (start == finish) return 0;

    while(front < rear){
        int current = q[front++];

        for(int i = 0; i < n; i++){
            if(mat[current][i] == 1 && distances[i] == -1){
                distances[i] = distances[current] + 1;
                if(i == finish){
                    return distances[i];
                }
            }
            q[rear++] = i;
        }
    }

    return -1;

}

int main(){
    int n = 5;

    int** mat = malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        mat[i] = calloc(n, sizeof(int));
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

    int* res = bfs(mat, n, 3);
    if(res){
        printf("BFS: ");
        for (int i = 0; i < n; i++){
            printf("%d ", res[i]);
        }
        printf("\n");
    } else {
        printf("Nothing in the res array!");
    }

    printf("Shortest path from 0 to 4 is %d units long\n", shorterstPath(mat, n, 0, 4));

    return 0;
}