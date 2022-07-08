#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int step = 0;
char TenFile[50];
FILE *fp;
FILE *fp2;

void INFORMATION_GROUP();   // Thong tin thanh vien nhom.
void INFORMATION_PROJECT(); // Ten De Tai.
void INTRO();
void MENU();
void READ_FILE(float A[MAX][MAX], int *n, char TenFile[10], FILE *fp); // Doc ma tran tu file.
void WRITE_FILE(char TenFile[10], FILE *fp2, float d);                 // Ghi ket qua vao file.
void ENTER_MANUALLY(float A[MAX][MAX], int *n);                        // Nhap ma tran tu ban phim.
void DISPLAY_MATRIX(float A[MAX][MAX], int n);                         // Xuat ma tran ban dau.
void DISPLAY_MATRIX_CHILD(float B[MAX][MAX], int n, float A1i, int i); // In tung buoc tinh dinh thuc
float DETERMINANT_MATRIX(float A[MAX][MAX], int n);                    // Tinh Dinh Thuc.

int main()
{
    // Khai bao du lieu
    float A[MAX][MAX];
    int n, choose;
    float d; // ket qua dinh thuc;
    char tt;

    INFORMATION_GROUP();
    printf("\n");

    INFORMATION_PROJECT();
    printf("\n");

    INTRO();
    printf("\n");

    do
    {
        MENU();
        printf("\n");

    ChucNang:
        printf("Nhap chuc nang: ");
        scanf("%d", &choose);
        system("cls");

        switch (choose)
        {

        case 1:
            printf("\n1.1 Nhap tu ban phim.\n");
            printf("\n1.2 Doc tu file.");
            int temp;
            printf("\nNhap lua chon : ");
            scanf("%d", &temp);
            if (temp == 1)
            {
                printf("\nNhap cap cua ma tran: ");
                scanf("%d", &n);
                ENTER_MANUALLY(A, &n);
            }
            else if (temp == 2)
            {
                READ_FILE(A, &n, TenFile, fp);
            }
            MENU();
            printf("\n");
            goto ChucNang;
            break;

        case 2:
            printf("\n Ma Tran Can Tinh Dinh Thuc La : \n");
            DISPLAY_MATRIX(A, n);
            MENU();
            printf("\n");
            goto ChucNang;
            break;

        case 3:
            DISPLAY_MATRIX(A, n);
            if (n == 1)
            {
                printf("Dinh thuc la phan tu duy nhat cua ma tran ! |A| = %.2lf\n", A[1][1]);
                d = A[1][1];
            }
            else if (n == 2)
            {
                printf("Dinh thuc cua ma tran bang : %.2lf * %.2lf - %.2lf * %.2lf", A[1][1], A[2][2], A[2][1], A[1][2]);
                d = A[1][1] * A[2][2] - A[2][1] * A[1][2];
            }
            else if (n >= 3)
            {
                printf("\nQua Trinh Tinh Dinh Thuc :\n");
                d = DETERMINANT_MATRIX(A, n);
            }
            MENU();
            printf("\n");
            goto ChucNang;
            break;

        case 4:
            printf("4.1 In Ket Qua Ra Man Hinh\n");
            printf("4.2 Ghi Ket Qua Vao File.\n");
            int temp1;
            printf("Nhap lua chon :");
            scanf("%d", &temp1);
            if (temp1 == 1)
            {
                printf("Dinh Thuc Cua Ma Tran La : | A | = %.2f", d);
                printf("\n");
            }
            else if (temp1 == 2)
            {
                WRITE_FILE(TenFile, fp2, d);
            }
            MENU();
            printf("\n");
            goto ChucNang;
            break;

        case 0:
            break;

        default:
            printf("Sai Cu Phap !!, Vui Long Nhap Lai !\n");
            MENU();
            printf("\n");
            goto ChucNang;
        }

        printf("\nBan co muon tinh dinh thuc ma tran moi khong(c/k)?  : ");
        fflush(stdin);
        scanf("%c", &tt);
        if (tt != 'c')
        {
            break;
        }
        else
        {
            step = 0;
        }

    } while (tt);
    return 0;
}
void INFORMATION_GROUP()
{
    printf("\n\t\t\t\t|************************************************************|");
    printf("\n\t\t\t\t|                           GROUP_6                          |");
    printf("\n\t\t\t\t|************************************************************|");
    printf("\n\t\t\t\t|     Ho va Ten           ||      Lop        ||   MSSV       |");
    printf("\n\t\t\t\t|************************************************************|");
    printf("\n\t\t\t\t| 1.NGUYEN DUONG BAO NHAT ||   21TCLC_DT4    ||  102210268   |");
    printf("\n\t\t\t\t| 2.LE TAT TUAN           ||   21TCLC_DT4    ||  102210285   |");
    printf("\n\t\t\t\t|                         ||                 ||              |");
    printf("\n\t\t\t\t|************************************************************|");
}

void INFORMATION_PROJECT()
{
    printf("\n|*****************************************************************************************************************************|");
    printf("\n|                                              INFORMATION OF PROJECT: 107                                                    |");
    printf("\n|                                                                                                                             |");
    printf("\n|1. Tinh dinh thuc cua ma tran vuong cap n                                                                                    |");
    printf("\n|                                                                                                                             |");
    printf("\n|2.Khai Bao Du Lieu: Mang 2 chieu cho ma tran A vuong can tinh dinh thuc gom n hang va n cot                                  |");
    printf("\n|                                                                                                                             |");
    printf("\n|3.Yeu Cau                                                                                                                    |");
    printf("\n|+ 3.1: Dung ky thuat de quy bang cach khai trien theo mot hang hoac mot cot de ha cap dinh thuc                              |");
    printf("\n|+ 3.2: Doc n va ma tran A tu file *.INP hoac tao ngau nhien                                                                  |");
    printf("\n|+ 3.3: Ghi ket qua so d la dinh thuc cua ma tran A ra file *.OUT hoac ra man hinh                                            |");
    printf("\n|                                                                                                                             |");
    printf("\n|*****************************************************************************************************************************|");
}

void INTRO()
{
    printf("\n\t\t\t\t+------------------------------------------------+\n");
    printf("\t\t\t\t|            Matrix determinant                  |\n");
    printf("\t\t\t\t|                                                |\n");
    printf("\t\t\t\t|            Dinh thuc ma tran                   |\n");
    printf("\t\t\t\t+------------------------------------------------+\n");
}

void MENU()
{
    printf("\n|*********************************************************************|");
    printf("\n|                             CHUC NANG                               |");
    printf("\n|                                                                     |");
    printf("\n|   1: Nhap Du Lieu Cua Ma Tran Vuong Cap n.                          |");
    printf("\n|   2: Hien Thi Ma Tran Can Tinh Dinh Thuc.                           |");
    printf("\n|   3: Thuc Hien Tinh Dinh Thuc                                       |");
    printf("\n|   4: Ghi Ket Qua.                                                   |");
    printf("\n|   0: Thoat Khoi MENU.                                               |");
    printf("\n|*********************************************************************|");
}

void READ_FILE(float A[MAX][MAX], int *n, char TenFile[50], FILE *fp)
{
TryAgain1:
    printf("Moi ban nhap ten file : ");
    fflush(stdin);
    gets(TenFile);
    fp = fopen(TenFile, "r");
    if (fp == NULL)
    {
        printf("Error!!!\n");
        goto TryAgain1;
    }
    fscanf(fp, "%d\n", &(*n));

    for (int i = 1; i <= *n; i++)
    {
        for (int j = 1; j <= *n; j++)
        {
            fscanf(fp, "%f\n", &A[i][j]);
        }
    }
    printf("=> Doc file thanh cong!!!\n");
    fclose(fp);
}

void WRITE_FILE(char TenFile[50], FILE *fp2, float d)
{
TryAgain2:
    printf("Nhap Ten File (Luu Ket Qua): ");
    fflush(stdin);
    gets(TenFile);
    fp2 = fopen(TenFile, "a+");
    if (fp2 == NULL)
    {
        printf("File Khong Ton Tai.Vui Long Nhap Lai Ten File\n");
        goto TryAgain2;
    }
    fprintf(fp2, "\nDinh Thuc Cua Ma Tran : |A| = %.2f", d);
    printf("=> Da Luu Ket Qua Vao File\n");
    fclose(fp2);
}

void ENTER_MANUALLY(float A[MAX][MAX], int *n)
{
    for (int i = 1; i <= (*n); i++)
    {
        for (int j = 1; j <= (*n); j++)
        {
            scanf("%f", &A[i][j]);
        }
    }
}

void DISPLAY_MATRIX(float A[MAX][MAX], int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("\t\t\t\t                         | ");
        for (int j = 1; j <= n; j++)
        {
            printf("%.2f ", A[i][j]);
        }
        printf("| \n");
    }
    printf(" \n\t\t\t\t                           \n");
}

void DISPLAY_MATRIX_CHILD(float B[MAX][MAX], int n, float A1i, int i)
{
    printf("\t\tStep %d:\n", ++step);
    printf("\t\t\t\t                         %.2f * %.0f * \n", A1i, pow(-1, i + 1));
    DISPLAY_MATRIX(B, n);
    system("pause");
}

float DETERMINANT_MATRIX(float A[MAX][MAX], int n)
{
    float detnxn = 0;
    if (n == 1)
        return A[1][1];
    if (n == 2)
        return A[1][1] * A[2][2] - A[2][1] * A[1][2];
    for (int i = 1; i <= n; i++)
    {
        float B[MAX][MAX];

        for (int j = 1; j <= n - 1; j++)
        {
            for (int k = 1; k <= n - 1; k++)
            {
                if (k < i)
                    B[j][k] = A[j + 1][k];
                else
                    B[j][k] = A[j + 1][k + 1];
            }
        }
        DISPLAY_MATRIX_CHILD(B, n - 1, A[1][i], i);
        detnxn += pow(-1, i + 1) * A[1][i] * DETERMINANT_MATRIX(B, n - 1);
    }
    return detnxn;
}
