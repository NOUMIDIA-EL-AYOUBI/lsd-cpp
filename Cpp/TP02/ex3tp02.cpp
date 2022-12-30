#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>
#include <ctime>

using namespace std;

template<typename type>
void generateRandomMatrix(int n, vector<vector<type>> &matrix)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
       matrix[i][j] =  rand()%10;
    }
}

template<typename type>
vector<vector<type>> matrixMultiply(int n, vector<vector<type>> &A, vector<vector<type>> &B)
{
  vector<vector<type>> result(n, vector<type>(n));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
      result[i][j] = 0;
      for(int k = 0; k < n; k++)
        result[i][j] += A[i][k] * B[k][j];
    }

  return result;
}

template<typename type>
vector<vector<type>> powr(int n, vector<vector<type>> &A)
{
  vector<vector<type>> result(n, vector<type>(n));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
      result[i][j] = 0;
      for(int k = 0; k < n; k++)
        result[i][j] += A[i][k] * A[k][j];
    }

  return result;
}

template<typename type>
void showMatrix(int n, vector<vector<type>> &matrix)
{
  for (size_t i = 0; i < n; i++) {
    if (i == 0) printf(" [ ");
    else printf("[ ");
    for (size_t j = 0; j < n; j++) {
      printf(" %d ", matrix[i][j]);
    }
    printf(" ]\n ");
  }
}

/*template<typename type>
vector<vector<type>> powrec(vector<vector<type>> &a, int p, int n)
{
  if (p == 1)
    return a;
  if (p % 2 == 0)
    return powrec(powr(n, a), p / 2, n);
  else
    return matrixMultiply(n, powrec(powr(n, a), (p - 1) / 2, n), a);
}*/

template<typename type>
vector<vector<type>> powrec(vector<vector<type>> &a, int p, int n)
{
if (p == 1)
return a;
vector<vector<type>> temp = powr(n, a); 
if (p % 2 == 0)
return powrec(temp, p / 2, n);
else{
   vector<vector<type>> temp1 = powrec(temp, (p - 1) / 2, n); 
   return matrixMultiply(n, temp1, a);
    }
}



template<typename type>
vector<vector<type>> pownaive(vector<vector<type>> &a, int p, int n)
{
  if (p == 1)
    return a;
  vector<vector<type>> result(n, vector<type>(n));
  result = a;
  for (int i = 0; i < p-1; i++)
  {
    result = matrixMultiply(n,result, a);
    
  }
  return result;
}

int main()
{
    int n=3;
    int p=3;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    generateRandomMatrix/*<int ***/(n,a);
    cout<<"\n result of multiplication ="<<endl;
    //showMatrix( n, a);
    std::vector<std::vector<int>> b(n, std::vector<int>(n));
    b=powrec(a,p,n);
    std::vector<std::vector<int>> c(n, std::vector<int>(n));
    c=pownaive(a,p,n);
    cout<<"\n generated matrix a ="<<endl;
    showMatrix( n, a);
    cout<<"\n powrec ="<<endl;
    showMatrix( n, b);
    cout<<"\n pownaive ="<<endl;
    showMatrix( n, c);

}
