#include <time.h>
#include "stdio.h"
#include "stdlib.h"

int compares[6] = {0, 0, 0, 0, 0, 0}, permutations[6] = {0, 0, 0, 0, 0, 0};
double times[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

void print_menu_0()
{
	printf("0. Enter array\n");
    printf("1. Sort array\n");
    printf("2. Find an element in array\n");
    printf("3. Show time, quantity of compares and permutations\n");
	printf("4. Exit\n");
    
}

void print_menu_1() {
    printf("0. Enter your array\n");
	printf("1. Enter random array\n");
}

void print_menu_2() {
	printf("0. Selection sort\n");
	printf("1. Bubble sort\n");
    printf("2. Insertion sort\n");
    printf("3. Merge sort\n");
}

void print_menu_3() {
    printf("0. Linear search\n");
    printf("1. Binary search\n");
}

void print_menu_4() {
	printf("0. Selection sort\n");
	printf("1. Bubble sort\n");
    printf("2. Insertion sort\n");
    printf("3. Merge sort\n");
    printf("4. Linear search\n");
    printf("5. Binary search\n");
}

void fill(int array[], int len, int digit) {
    int i = 0;
    for(i; i < len; i++) {
        array[i] = digit;
    }
}

int max(int a, int b) {
    if (a >= b){
        return a;
    }
    return b;
}

int max_of_array(int array[], int len) {
    int max = array[0];
    int i = 1;
    for(i; i < len; i++) {
        if (max < array[i])
            max = array[i];
    }
    return max;
}

int min_of_array(int array[], int len) {
    int min = array[0];
    int i = 1;
    for(i; i < len; i++) {
        if (min > array[i])
            min = array[i];
    }
    return min;
}

void copy_array(int array[], int copy[], int len) {
    for(int i = 0; i < len; i++) {
        copy[i] = array[i];
    }
}

void random_array(int array[], int len, int a, int b) {
    for(int i = 0; i < len; ++i) 
        array[i] = rand()%(b-a) + a;
}

void enter_array(int array[], int len) {
    printf("Enter array: ");
    int temp;
    for(int i = 0; i < len; i++) {
        scanf("%d", &temp);
        array[i] = temp;
    }
}

void print_array(int array[], int len) {
    int i = 0;
    for(i; i < len; i++) {
        printf("%d" " ", array[i]);
    }

}

void selection_sort(int array[], int len) {
    int sorted = 0;
    int min_index = 0;
    int temp;
    int i;
    while(sorted < len) {
        i = sorted;
        for(i; i < len-1; i++) {
            compares[0] += 1;
            if (array[min_index] > array[i+1]) {
                min_index = i+1;
            }
        }
        permutations[0] += 1;
        temp = array[min_index];
        array[min_index] = array[sorted];
        array[sorted] = temp;
        sorted += 1;
        min_index = sorted;
    }
}

void insertion_sort(int array[], int len) {
    int temp;
    for(int i = 1; i < len; i++) {
        for(int j = i; j > 0; j--) {
            compares[2] += 1;
            if (array[j] < array[j-1]) {
                permutations[2] += 1;
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
            else {
                break;
            }
        }
    }
}

void buble_sort(int array[], int len) {
    int right = len - 1;
    int left = 0;
    while(right >= left) {
        int i;
        int temp;
        for(i = 1; i <= right; i++) {
            compares[1] += 1;
            if (array[i-1] > array[i]) {
                permutations[1] += 1;
                temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
            }
        }
        right -= 1;
        for(i = left; i > 0; i--) {
            compares[1] += 1;
            if (array[i-1] > array[i]) {
                permutations[1] += 1;
                temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
            }
        }
        left += 1;
    }    
}

void merge(int array[], int left, int right) {
    int middle = (right + left)/2;
    int i = left, j = middle + 1, k = left;
    int c[right - left + 1];
    while(i <= middle && j <= right) {
        compares[3] += 1;
        if (array[i] <= array[j]) {
            c[k-left] = array[i];
            i += 1;
            k += 1;
        }
        else {
            permutations[3] += 1;
            c[k-left] = array[j];
            j += 1;
            k += 1;
        }
    }
    while (i <= middle) {
        c[k-left] = array[i];
        i += 1;
        k += 1;
    }
    while(j <= right) {
        c[k-left] = array[j];
        j += 1;
        k += 1;
    }
    for(i = left; i <= right; i++) {
        array[i] = c[i-left];
    }
}

void merge_sort(int array[], int left, int right) {
    if (left < right) {
        merge_sort(array, left, (left + right)/2);
        merge_sort(array, (left + right)/2+1, right);
        merge(array, left, right);
    }
}

int linear_search(int array[], int len, int to_find) {
    int temp;
    for(int i = 0; i < len; i++) {
        compares[4] += 1;
        if (array[i] == to_find) {
            printf("Index of element to find is: %d\n", i);
            return i;
        }
    }
    printf("No such element in array!\n\n");
    return 0;
}

int binary_search(int array[], int len, int to_find) {
    int temp, right = len - 1, left = 0, middle, index;
    for(int i  = 0; i < len; i++) {
        middle = (left + right)/2;
        compares[5] += 1;
        if (array[middle] == to_find) {
            index = middle;
            printf("Index of element to find is: %d\n", index);
            return index;
        }
        else if(left == right) {
            printf("No such element in array!\n\n");
            return 0;
        }
        else if(array[middle] > to_find) {
            right = middle - 1;
        }
        else if(array[middle] < to_find) {
            left = middle + 1;
        }
    }
}

int main() {
    clock_t t;
	int choice_0 = 1488, choice_1 = 1488, choice_2 = 1488, choice_3 = 1488, choice_4 = 1488, status = 0;
    int len;
    int to_find, index;
    int left, right;
    int array[10000], copy[10000];
	while(choice_0 != 4) {
		print_menu_0();
		scanf("%d", &choice_0);
		switch (choice_0) {
		case 0: 
            print_menu_1();
            scanf("%d", &choice_1);
            printf("Enter length of array: ");
            scanf("%d", &len);
            if (len <= 0 || len > 10000) {
                printf("Length of array must be in range from 1 to 10000!\n\n");
                break;
            }
            switch (choice_1) {
                case 0:
                    enter_array(array, len);
                    copy_array(array, copy, len);
                    status = 1;
                    break;
                case 1:
                    printf("Enter left boarder for digits in array: ");
                    scanf("%d", &left);
                    printf("Enter right boarder for digits in array: ");
                    scanf("%d", &right);
                    random_array(array, len, left, right);
                    copy_array(array, copy, len);
                    status = 1;
                    break;
                default: 
                    printf("\n Enter 0 or 1! \n\n");
                    break;
            }
            break;
        case 1:
            copy_array(copy, array, len);
            print_menu_2();
            scanf("%d", &choice_2);
            switch (choice_2) {
            case 0:
                if (status > 0) {
                    times[0] = 0.0;
                    compares[0] = 0;
                    permutations[0] = 0;
                    printf("Your array before sort: ");
                    print_array(array, len);
                    printf("\n");
                    t = clock();
                    selection_sort(array, len);
                    t = clock() - t;
                    times[0] = t;
                    printf("Your array after sort: ");
                    print_array(array, len);
                    printf("\n");
                    status = 2;
                    
                }
                else {
                    printf("\nYou should enter array before sorting it!\n\n");
                }
                break;
            case 1: 
                if (status > 0) {
                    times[1] = 0.0;
                    compares[1] = 0;
                    permutations[1] = 0;
                    printf("Your array before sort: ");
                    print_array(array, len);
                    printf("\n");
                    t = clock();
                    buble_sort(array, len);
                    t = clock() - t;
                    times[1] = t;
                    printf("Your array after sort: ");
                    print_array(array, len);
                    printf("\n");
                    status = 2;
                }
                else {
                    printf("\nYou should enter array before sorting it!\n\n");
                }
                break;
            case 2: 
                if (status > 0) {
                    times[2] = 0.0;
                    compares[2] = 0;
                    permutations[2] = 0;
                    printf("Your array before sort: ");
                    print_array(array, len);
                    printf("\n");
                    t = clock();
                    insertion_sort(array, len);
                    t = clock() - t;
                    times[2] = t;
                    printf("Your array after sort: ");
                    print_array(array, len);
                    printf("\n");
                    status = 2;
                }
                else {
                    printf("\nYou should enter array before sorting it\n\n!");
                }
                break;
            case 3: 
                if (status > 0) {
                    times[3] = 0.0;
                    compares[3] = 0;
                    permutations[3] = 0;
                    printf("Your array before sort: ");
                    print_array(array, len);
                    printf("\n");
                    t = clock();
                    merge_sort(array, 0, len);
                    t = clock() - t;
                    times[3] = t;
                    printf("Your array after sort: ");
                    print_array(array, len);
                    printf("\n");
                    status = 2;
                }
                else {
                    printf("\nYou should enter array before sorting it!\n\n");
                }
                break; 
            default: 
                printf("Enter digit in range from 0 to 3! \n\n");
                break;
            }
            break;
        case 2:
            print_menu_3();
            scanf("%d", &choice_3);
            printf("Enter element to find: ");
            scanf("%d", &to_find);
            switch (choice_3) {
                case 0:
                    if (status > 0) {
                        times[4] = 0.0;
                        compares[4] = 0;
                        t = clock();
                        linear_search(array, len, to_find);
                        t = clock() - t;
                        times[4] = t;
                        printf("\n");
                    }
                    else {
                        printf("\nEnter array before searching elements in it!\n\n");
                    }
                    break;
                case 1:
                    if (status == 2) {
                        times[5] = 0.0;
                        compares[5] = 0;
                        t = clock();
                        binary_search(array, len, to_find);
                        t = clock() - t;
                        times[5] = t;
                        printf("\n");
                    }
                    else if (status == 1) {
                        printf("\nArray must be sorted to use binary search!\n\n");
                    }
                    else {
                        printf("\nEnter array before searching elements in it!\n\n");
                    }
                    break;
                default:
                    printf("\nEnter 0 or 1!\n\n");
                    break;

            }
            break;
        case 3:
            print_menu_4();
            scanf("%d", &choice_4);
            switch (choice_4)
            {
                case 0: 
                    printf("Selection sort's time, compares, permutations : %f, %d, %d\n", (float)times[0]/CLOCKS_PER_SEC, compares[0], permutations[0]);
                    break;
                case 1:
                    printf("Bubble sort's time, compares, permutations : %f, %d, %d\n", (float)times[1]/CLOCKS_PER_SEC, compares[1], permutations[1]);
                    break;
                case 2: 
                    printf("Insertion sort's time, compares, permutations : %f, %d, %d\n", (float)times[2]/CLOCKS_PER_SEC, compares[2], permutations[2]);
                    break;
                case 3:
                    printf("Merge sort's time, compares, permutations : %f, %d, %d\n", (float)times[3]/CLOCKS_PER_SEC, compares[3], permutations[3]);
                    break;
                case 4: 
                    printf("Lineary search's time, compares : %f, %d\n", (float)times[4]/CLOCKS_PER_SEC, compares[4]);
                    break;
                case 5:
                    printf("Binary search's time, compares : %f, %d\n", (float)times[5]/CLOCKS_PER_SEC, compares[5]);
                    break;
                default: 
                    printf("Enter digit in range from 0 to 5!\n\n");
                    break;
            }
            break;  
        default:
            printf("\nEnter digit in range from 0 to 4!\n\n");
            break;        

            
        }
}
}