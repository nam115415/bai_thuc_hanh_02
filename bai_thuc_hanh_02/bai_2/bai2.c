#include <stdio.h>
#include <stdlib.h>

int main() {
    int h, c;
    printf("Nhap so hang va so cot: ");
    scanf("%d%d", &h, &c);
    
    float **ma = (float **)malloc(h * sizeof(float *));
    if (ma == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }

    for (int i = 0; i < h; i++) {
        ma[i] = (float *)malloc(c * sizeof(float));
        if (ma[i] == NULL) {
            printf("Khong du bo nho tai dong %d!\n", i);
            return 1;
        }
    }
    //nhap dl
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%f", &ma[i][j]);
        }
    }

    //in ra
    printf("Ma tran %dx%d vua tao:\n", h, c);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < c; j++) {
            printf("%.2f\t", ma[i][j]);
        }
        printf("\n");
    }

    //giai phong ma tran
    for (int i = 0; i < h; i++) {
        free(ma[i]);
    }
    free(ma);

    return 0;
}