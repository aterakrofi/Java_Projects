/*Java program to implement Quick Sort on 100000 floating point arrays*/
import java.io.*;
import java.util.Arrays;
import java.util.Random;


public class QuickSort {
	
public static void main(String[] args) {
		
System.out.println("\nBefore Sorting");
	
//Randomly Generated Floating Point Array 
float minX = 0.0f;
float maxX = 100000.0f;
        
float [] array = new float [100000];
Random num = new Random();

    for(int i = 0; i< array.length; i++) {
         array[i]=num.nextFloat()* (maxX - minX) + minX;;
      
        System.out.print(array[i] + "  ");
     }
 
int low = 0;
int high = array.length - 1;
 
quickSort(array, low, high);

//Sorted Array
System.out.println("\n\nSorted Array");
System.out.println(Arrays.toString(array));
	}
 
//Method to sort array
public static void quickSort(float[] arr, int low, int high) {
		if (arr == null || arr.length == 0)
			return;
 
		if (low >= high)
			return;
 
		// pick the pivot
		int middle = low + (high - low) / 2;
		float pivot = arr[middle];
 
		// make left < pivot and right > pivot
		int i = low, j = high;
		while (i <= j) {
			while (arr[i] < pivot) {
				i++;
			}
 
			while (arr[j] > pivot) {
				j--;
			}
 
			if (i <= j) {
				float temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++;
				j--;
			}
		}
 
		// recursively sort two sub parts
		if (low < j)
			quickSort(arr, low, j);
 
		if (high > i)
			quickSort(arr, i, high);
	}
}

