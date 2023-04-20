#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void ShowMatrix(int row,int column,int matrix[row][column])
{
    int i,j;
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
}



void AddMatrix(int row,int column,int matrix1[row][column],int matrix2[row][column])
{
    int i,j;
    int matrixResult[row][column];
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            matrixResult[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }

    ShowMatrix(row,column,matrixResult);
}



void SubstractMatrix(int row,int column,int matrix1[row][column],int matrix2[row][column])
{
    int i,j;
    int matrixResult[row][column];
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            matrixResult[i][j]=matrix1[i][j]-matrix2[i][j];
        }
    }

    ShowMatrix(row,column,matrixResult);
}


void ScalarMatrix(int row,int column,int matrix1[row][column])
{
    int i,j;
    int matrixResult[row][column];
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            matrixResult[i][j]=matrix1[i][j]*2;
        }
    }

    ShowMatrix(row,column,matrixResult);
}


//0 0
void matrixMultipication(int row,int column,int matrix1[row][column],int matrix2[row][column])
{
    int i,j,sum=0,k;
    int matrixResult[row][column];

    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            sum=0;
            for(k=0;k<row;k++)
            {
                sum+=matrix1[i][k]*matrix2[k][j];
            }

            matrixResult[i][j]=sum;
        }
    }

    ShowMatrix(row,column,matrixResult);
}



bool AreIdentical(int row,int column,int matrix1[row][column],int matrix2[row][column])
{
    int i,j;
    bool Identical=true;
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            if(matrix1[i][j]!=matrix2[i][j])
            {
                Identical=false;
                break;
            }
        }
    }

    if(Identical)
        return true;
    return false;
}



int SumMainDiagonal(int row,int column,int matrix[row][column])
{
    int i,j,sum=0;
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            if(i==j)
                sum+=matrix[i][j];
        }
    }
    return sum;
}


//0 3
//1 2
//2 1
//3 0
int SumMinorDiagonal(int row,int column,int matrix[row][column])
{
    int i,j,sum=0;
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            if(j==row-i-1)
                sum+=matrix[i][j];
        }
    }
    return sum;
}



void printEachRowEachColumnSum(int n,int matrix[n][n])
{
    int i,j,rowSum=0,columnSum=0;
    for(i=0;i<n;i++)
    {
        rowSum=0;
        columnSum=0;
        for(j=0;j<n;j++)
        {
            rowSum+=matrix[i][j];
            columnSum+=matrix[j][i];
        }
        printf("%d. row  => sum  : %d\n",i+1,rowSum);
        printf("%d. column => sum : %d\n",i+1,columnSum);
    }
}


// 0 0 ||  0 2
// 1 1 ||  1 1
// 2 0 ||  2 2
void interChangeDioganals(int n,int matrix[n][n])
{
    int i,j,temp;
    int matrixResult[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            temp=matrix[i][i];
            matrix[i][i]=matrix[i][n-i-1];
            matrix[i][n-i-1]=temp;
        }
    }

    ShowMatrix(n,n,matrix);
}




int IsUpperTriangleSum(int n,int matrix[n][n])
{
    int i,j,sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j>i)
            {
                sum+=matrix[i][j];
            }
        }
    }
    return sum;
}



int IsLowerTriangleSum(int n,int matrix[n][n])
{
    int i,j,sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>j)
            {
                sum+=matrix[i][j];
            }
        }
    }
    return sum;
}



//3 x 3  1 0 2 0 2 1
//4 x 4  1 0 2 0 2 1 3 0 3 1 3 2
bool IsUpperTriangularMatrix(int n,int matrix[n][n])
{
    int i,j;
    bool isUpper=true;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>j && matrix[i][j]!=0)
            {
                isUpper=false;
                break;
            }
        }
    }

    if(isUpper)
        return true;
    return false;
}




// 4 x 4
//1 2 1 3 1 4
//2 3 2 4
//3 4
bool IsLowerTriangularMatrix(int n,int matrix[n][n])
{
    int i,j;
    bool isLower=true;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j>i && matrix[i][j]!=0)
            {
                isLower=false;
                break;
            }
        }
    }

    if(isLower)
        return true;
    return false;
}


// 0 0 0 0
// 0 1 1 0
// 0 2 2 0
// 1 0 0 1
// 1 1 1 1
// 1 2 2 1
void transposeMatrix(int n,int matrix[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",matrix[j][i]);
        }
    }
}

//2x2
int determinantMatrix2x2(int n,int mat[n][n])
{
    int det=(mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
    return det;
}


//3x3
int determinantMatrix3x3(int n,int mat[n][n])
{
    int a,b,c,d,e,f,g,h,i;

    a=mat[0][0];
    b=mat[0][1];
    c=mat[0][2];
    d=mat[1][0];
    e=mat[1][1];
    f=mat[1][2];
    g=mat[2][0];
    h=mat[2][1];
    i=mat[2][2];

    int det=a*(e*i-f*h)-b*(d*i-f*g)+c*(d*h-e*g);
    return det;
}



bool IsIdentity(int n,int matrix[n][n])
{
    int i,j;
    bool Identity=true;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j && matrix[i][j]!=1)
            {
                Identity=false;
            }
            else if(i!=j && matrix[i][j]!=0)
            {
                Identity=false;
            }
        }
    }

    if(Identity)
        return true;
    return false;
}



bool IsSparseMatrix(int n,int matrix[n][n])
{
    int i,j,zeros=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
                zeros++;
        }
    }

    if(zeros>=n*n/2)
        return true;
    return false;
}



bool IsSymmetricMatrix(int n,int matrix[n][n])
{
    int i,j;
    bool isSymetric=true;
    int matrixResult[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            matrixResult[j][i]=matrix[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrixResult[i][j]!=matrix[i][j])
                isSymetric=false;
        }
    }

    if(isSymetric)
        return true;
    return false;
}



int main()
{
    int matrix1[3][3]={{1,2,-1},
                       {2,1,3},
                       {-1,3,0}
                      };


    printf("%d",IsSymmetricMatrix(3,matrix1));
    return 0;
}
