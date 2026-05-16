# include <stdio.h>
# include <stdlib.h>

void dfs (int** image, int rows, int cols, int r, int c, int ogColor, int color){
    // Boundary checks
    if (r < 0 || r >= rows || c < 0 || c >= cols) return;

    // Color check
    if (image[r][c] != ogColor) return;

    // Fill the color of that cell r, c
    image[r][c] = color;

    // dfs on all the cells neighbouring r, c
    dfs(image, rows, cols, r - 1, c, ogColor, color); // Up 
    dfs(image, rows, cols, r + 1, c, ogColor, color); // down
    dfs(image, rows, cols, r, c - 1, ogColor, color); // Left
    dfs(image, rows, cols, r, c + 1, ogColor, color); // Right
}

int** floodFill (int** image, int sr, int sc, int color){
    
}