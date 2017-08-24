/*Java program to IMPLEMENT Heapsort*/

import java.util.Scanner;
import java.util.Random;
 
 public class Sort_Heap {	
public static void main(String args[]) {

//	Randomly Generated Floating Point Array       
float minX = 0.0f;
float maxX = 10.0f;
   
float [] arr = new float [100000];

Random num = new Random();
System.out.println("\n\nGENERATED ARRAY");

     for(int i = 0; i< arr.length; i++) {
         arr[i]=num.nextFloat()* (maxX - minX) + minX;;
     
	System.out.print(arr[i] + "  ");
		}
	//sorting of Array 
		for(int i=arr.length; i>1; i--) {
			
			HeapSort(arr, i - 1);
		}
		
		System.out.println("\n\nSorted Array");
 
		for(int i=0; i<arr.length; i++) {
			
			System.out.print(" " + arr[i]);
		}	
	}
 
//Method to heapsort array
	private static void HeapSort(float arr[], int bound) {
		int left, right, middle, root;
		float temp;
		root = (bound-1) / 2;
		
		for(int i=root; i>=0; i--) {
			
			for(int j=root; j>=0; j--) {	
				left = (2*j) + 1;
				right = (2*j) + 2;
			
				if((left <= bound) && (right <= bound)) {
					
					if(arr[right] >= arr[left])
						middle = right;
					else
						middle = left;
				}
				else {
					
					if(right > bound)
						middle = left;
					else
						middle = right;
				}
 
				if(arr[j] < arr[middle]) {
					
					temp = arr[j];
					arr[j] = arr[middle];
					arr[middle] = temp;
				}
			}
		}
		temp = arr[0];
		arr[0] = arr[bound];
		arr[bound] = temp;
	}
}
