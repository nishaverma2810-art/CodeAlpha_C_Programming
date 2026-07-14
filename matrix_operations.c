

#include <stdio.h>

void inputMatrix(int a[10][10], int row, int col)
{
    int i, j;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void displayMatrix(int a[10][10], int row, int col)
{
    int i, j;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[10][10], int b[10][10], int row, int col)
{
    int c[10][10], i, j;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nMatrix Addition:\n");
    displayMatrix(c, row, col);
}

void transposeMatrix(int a[10][10], int row, int col)
{
    int t[10][10], i, j;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            t[j][i] = a[i][j];
        }
    }

    printf("\nTranspose Matrix:\n");
    displayMatrix(t, col, row);
}

void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int c2)
{
    int c[10][10], i, j, k;

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for(k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication:\n");
    displayMatrix(c, r1, c2);
}

int main()
{
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &r2, &c2);

    printf("\nEnter elements of Matrix A:\n");
    inputMatrix(a, r1, c1);

    printf("\nEnter elements of Matrix B:\n");
    inputMatrix(b, r2, c2);

    if(r1 == r2 && c1 == c2)
    {
        addMatrix(a, b, r1, c1);
    }
    else
    {
        printf("\nMatrix Addition is not possible.\n");
    }

    transposeMatrix(a, r1, c1);

    if(c1 == r2)
    {
        multiplyMatrix(a, b, r1, c1, c2);
    }
    else
    {
        printf("\nMatrix Multiplication is not possible.\n");
    }

    return 0;
}
