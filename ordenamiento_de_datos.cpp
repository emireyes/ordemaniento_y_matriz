#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find(int b[], int l, int *index, int mode) {
    int a;
    int i;
    
    if (mode == 0) {
        a = 1000000;
        *index = -1;
        
        for (i = 0; i < l; i++) {
            if (b[i] < a) {
                a = b[i];
                *index = i;
            }
        }
    } else if (mode == 1) {
        a = -1000000;
        *index = -1;
        
        for (i = 0; i < l; i++) {
            if (b[i] > a) {
                a = b[i];
                *index = i;
            }
        }
    }
    return a;
}

void insertionSort(int arr[], int n) {
    int key;
    int j;
    int i;
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

float calculateMean(int arr[], int l) {
    float sum = 0;
    int i;
    
    for (i = 0; i < l; i++) {
        sum += arr[i];
    }
    return sum / l;
}

int calculateMode(int arr[], int l) {
    int maxCount = 0;
    int mode = -1;
    int count;
    int i;
    int j;
    
    for (i = 0; i < l; i++) {
        count = 0;
        for (j = 0; j < l; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    return mode;
}

float calculateMedian(int arr[], int l) {
    if (l % 2 != 0) {
        return (float)arr[l / 2];
    } else {
        return (float)(arr[(l - 1) / 2] + arr[l / 2]) / 2.0;
    }
}

void generateHistogram(int arr[], int l) {
    printf("\n\nHistograma:\n");
    int i;
    int j;
    
    for (i = 1; i <= 30; i++) {
        int frequency = 0;
        
        for (j = 0; j < l; j++) {
            if (arr[j] == i) {
                frequency++;
            }
        }
        float percentage = 100 * ((float)frequency / l);
        
        if (percentage > 0) {
            printf("%2d: ", i);
            
            for (int k = 0; k < (int)percentage; k++) {
                printf("*");
            }
            printf(" \n");
        }
    }
}

int main() {
    srand(time(NULL));
    
    int l;
    printf("Numero de elementos a ordenar: ");
    scanf("%d", &l);

    int b[l];

    printf("Lista sin ordenar: ");
    int i;
    
    for (i = 0; i < l; i++) {
        b[i] = rand() % 30 + 1;
        printf("%d, ", b[i]);
    }

    insertionSort(b, l);

    int minIndex, maxIndex;
    int minValue = find(b, l, &minIndex, 0);
    int maxValue = find(b, l, &maxIndex, 1);

    printf("\n\nLista ordenada: ");
    for (i = 0; i < l; i++) {
        printf("%d, ", b[i]);
    }

    printf("\n\nMin value: %d (Index: %d)", minValue, minIndex);
    printf("\nMax value: %d (Index: %d)", maxValue, maxIndex);
    
    float mean = calculateMean(b, l);
    printf("\nMean: %.2f", mean);

    int mode = calculateMode(b, l);
    printf("\nMode: %d", mode);

    float median = calculateMedian(b, l);
    printf("\nMedian: %.2f\n", median);

    generateHistogram(b, l);

    return 0;
}
