#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    int size = 20000000; // 20 juta angka (biar kerasa)
    clock_t mulai, selesai;
    double waktu_total;

    int *data = (int *)malloc(size * sizeof(int));
    
    if (data == NULL) {
        printf("Gagal pesan memori!\n");
        return 1;
    }

    // --- TEST 1: ARRAY INDEXING ---
    mulai = clock();
    for (i = 0; i < size; i++) {
        data[i] = i;
    }
    selesai = clock();

    waktu_total = (double)(selesai - mulai)/ CLOCKS_PER_SEC; 
    printf("Indeks Array: %f detik\n", waktu_total);

    // --- TEST 2: POINTER ARITHMETIC ---
    int *p = data; // Reset pointer ke awal array
    mulai = clock();
    for (i = 0; i < size; i++) {
        *p = i;
        p++; // Geser alamat secara manual
    }
    selesai = clock();

    waktu_total = (double)(selesai - mulai) / CLOCKS_PER_SEC;
    printf("Pointer: %f detik\n", waktu_total);

    // --- TRIK "NIPU" KOMPILER ---
    // Kita print data terakhir supaya loop nggak dianggap "sampah" dan dihapus
    printf("\nCek data terakhir: %d (berhasil diisi)\n", data[size - 1]);

    free(data);

    return 0;
}