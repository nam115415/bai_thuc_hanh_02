#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char  hoTen[30];
    int   maSV;
    float diem1, diem2, diem3;
} SinhVien;
void xoaBoDem(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void nhapSinhVien(SinhVien *sv) {
    printf("  Nhap ma sinh vien: ");
    scanf("%d", &(sv->maSV));
    xoaBoDem();
    printf("  Nhap ho ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = '\0'; 
    printf("  Nhap diem mon 1: ");
    scanf("%f", &(sv->diem1));
    printf("  Nhap diem mon 2: ");
    scanf("%f", &(sv->diem2));
    printf("  Nhap diem mon 3: ");
    scanf("%f", &(sv->diem3));
    xoaBoDem();
}
void inSinhVien(const SinhVien *sv) {
    printf("Ma SV: %-5d | Ho ten: %-20s | Diem: %.2f, %.2f, %.2f\n",
           sv->maSV, sv->hoTen, sv->diem1, sv->diem2, sv->diem3);
}
int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    xoaBoDem();
    SinhVien *danhSach = (SinhVien *)malloc(n * sizeof(SinhVien));
    if (danhSach == NULL) {
        printf("Khong du bo nho de cap phat.");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("thong tin sinh vien thu %d: ", i + 1);
        nhapSinhVien(danhSach + i);
    }
    printf("\ndanh sach\n");
    for (int i = 0; i < n; i++) {
        printf("%2d. ", i + 1);
        inSinhVien(danhSach + i);
    }
    printf("\n");
    free(danhSach);
    return 0;
}