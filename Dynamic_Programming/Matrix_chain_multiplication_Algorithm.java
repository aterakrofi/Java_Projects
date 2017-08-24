// Dynamic Programming:Java implementation of Matrix
// Chain Multiplication.

 
import java.util.Scanner;

public class Matrix{
    private int[][] m;
    private int[][] s;
    private int     n;
 
public Matrix(int[] p) {
    n = p.length - 1; // No. of matrices in the chain

 // over allocating m without index 0
    m = new int[n + 1][n + 1];
                                   
    s = new int[n + 1][n + 1]; // same for s
    matrixChainOrder(p); // run the dynamic-programming algorithm
    }
 
 private void matrixChainOrder(int[] p){
        // Initializing the cost for the empty sub problems.
    for (int i = 1; i <= n; i++)
      m[i][i] = 0;

        // Solve for chains of increasing length l.
    for (int l = 2; l <= n; l++){
    for (int i = 1; i <= n - l + 1; i++){
         int j = i + l - 1;
       m[i][j] = Integer.MAX_VALUE;

             // Checking for optimization 
    for (int k = i; k < j; k++){
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
    if (q < m[i][j]){
//Optimized order q is the best
        m[i][j] = q;
        s[i][j] = k;
                    }
                }
            }
        }
    }
 
 private String printOptimalParens(int i, int j){
      
    if (i == j)
         return "A[" + i + "]";
    else
         return "(" + printOptimalParens(i, s[i][j])
                    + printOptimalParens(s[i][j] + 1, j) + ")";
    }
 
  public String toString(){
     return printOptimalParens(1, n);
    }
 
   
/*Dimension of matrix follows the structure p[i-1] x p[i] for i = 1..n*/
  static int Matrix_Order(int p[], int n)
 	{
 		/*  Allocating one extra row and one extra column in m[][]. 0th row and 0th column of m[][] are not used */
     int m[][] = new int[n][n];

     int i, j, k, L, q;

 		/* m[i,j] = Optimal number of multiplications needed
 		to compute the matrix */

 		// cost is zero when multiplying one matrix.
     for (i = 1; i < n; i++)
 			m[i][i] = 0;

 		// Length of chain L
     for (L=2; L<n; L++){
     for (i=1; i<n-L+1; i++){
 	    j = i+L-1;
     if(j == n) continue;
 	    m[i][j] = Integer.MAX_VALUE;
 	for (k=i; k<=j-1; k++){
//q represents optimal solution
 		q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
 	if (q < m[i][j])
 		m[i][j] = q;

 				}
 			}
 		}

 		return m[1][n-1];
 	}

 	// Driver program to test above function
 public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
        /* System.out .println("Input the array p[], which represents the chain of matrices ");*/
    System.out.println("Enter the the size of Chain Matrix: ");
    int n = sc.nextInt();
    int arr[] = new int[n];
    System.out.println("Enter the Matrix dimensions: ");
 for (int i = 0; i < n; i++)
      arr[i] = sc.nextInt();
         
      Matrix Order = new Matrix(
                 arr);
     System.out.println("Matrices are of order: ");
 for (int i = 1; i < arr.length; i++){
     System.out.println("A" + i + "-->" + arr[i - 1] + "x" + arr[i]);
         }
      System.out.println(Order.toString());
         sc.close();
 	    
       int size = arr.length;

       System.out.println("Order of Optimal Association is "+
 						Matrix_Order(arr, size));
 	}
 }
