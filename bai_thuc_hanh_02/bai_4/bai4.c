#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char  hoten[30];
    int   masv;
    float d1, d2, d3;
} Data;

typedef struct tagNode {
    Data infor;
    struct tagNode *link;
} Node;

typedef struct {
    Node *pHead;
    Node *pTail;
    int   spt;
} LList;

void xoaBoDem(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void initList(LList *L) {
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}

int emptyList(LList L) {
    return (L.spt == 0);
}

Node *makeNode(Data x) {
    Node *pp = (Node *)malloc(sizeof(Node));
    if (pp != NULL) {
        pp->infor = x;
        pp->link = NULL;
    }
    return pp;
}

int insert_Head(LList *L, Data x) {
    Node *pp = makeNode(x);
    if (pp == NULL) return 0;
    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        pp->link = L->pHead;
        L->pHead = pp;
    }
    L->spt++;
    return 1;
}

int insert_Tail(LList *L, Data x) {
    Node *pp = makeNode(x);
    if (pp == NULL) return 0;
    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pTail->link = pp;
        L->pTail = pp;
    }
    L->spt++;
    return 1;
}

Node *timNut(LList L, int ma) {
    Node *pp = L.pHead;
    while (pp != NULL && pp->infor.masv != ma)
        pp = pp->link;
    return pp;
}

int insert_After(LList *L, Node *q, Data x) {
    Node *pp = makeNode(x);
    if (pp == NULL) return 0;
    pp->link = q->link;
    q->link = pp;
    if (q == L->pTail)
        L->pTail = pp;
    L->spt++;
    return 1;
}

void freeList(LList *L) {
    Node *pp = L->pHead, *tmp;
    while (pp != NULL) {
        tmp = pp;
        pp = pp->link;
        free(tmp);
    }
    initList(L);
}

void nhap(Data *x) {
    printf("Nhap ma sv (<= 0 de huy): ");
    scanf("%d", &(x->masv));
    xoaBoDem();
    if (x->masv > 0) {
        printf("Nhap ho ten: ");
        fgets(x->hoten, sizeof(x->hoten), stdin);
        x->hoten[strcspn(x->hoten, "\n")] = '\0';
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
        xoaBoDem();
    }
}

void in(Data x) {
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n",
           x.hoten, x.masv, x.d1, x.d2, x.d3);
}

void processList(LList L) {
    Node *pp = L.pHead;
    if (emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }
    while (pp != NULL) {
        in(pp->infor);
        pp = pp->link;
    }
}

int main() {
    LList L;
    int kt = 0, chon, ma;
    Data x;
    Node *q;

    initList(&L);
    do {
        printf("\nChuong trinh lam viec voi DSLK don SV\n");
        printf("\n1: Them nut vao dau danh sach");
        printf("\n2: Them nut vao cuoi danh sach");
        printf("\n3: Them nut vao sau mot nut khac trong danh sach");
        printf("\n9: Duyet ds");
        printf("\n0: Thoat");
        printf("\nMoi ban chon: ");
        scanf("%d", &chon);
        xoaBoDem();

        switch (chon) {
        case 1:
            nhap(&x);
            if (x.masv > 0 && !insert_Head(&L, x))
                printf("Khong du bo nho!\n");
            break;
        case 2:
            nhap(&x);
            if (x.masv > 0 && !insert_Tail(&L, x))
                printf("Khong du bo nho!\n");
            break;
        case 3:
            printf("Nhap ma sv cua nut can them phia sau: ");
            scanf("%d", &ma);
            xoaBoDem();
            q = timNut(L, ma);
            if (q == NULL) {
                printf("Khong tim thay sv co ma %d!\n", ma);
            } else {
                nhap(&x);
                if (x.masv > 0 && !insert_After(&L, q, x))
                    printf("Khong du bo nho!\n");
            }
            break;
        case 9:
            processList(L);
            break;
        case 0:
            printf("Bye bye\n");
            kt = 1;
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (kt == 0);

    freeList(&L);
    return 0;
}