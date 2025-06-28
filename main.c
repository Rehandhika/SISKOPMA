/*
Program ini disusun oleh :
Kelompok 1 - 1KS2
1.	Athaya Daffa Winata (222413514)
2.	Defila Cahyati (222413540)
3.	Rehandhika Arya Pratama (222413752)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Implementasi Struct
typedef struct
{
    char nim[15];
    char nama[50];
    int saldo;
} Mahasiswa;

typedef struct
{
    int id;
    char nama[50];
    int harga;
    int stok;
} Produk;

//Implementasi Subprogram(Fungsi)
void lihatbarang();
void tambahbarang();
void updatebarang();
void hapusbarang();
void lihatmahasiswa();
void updatemahasiswa();
void hapusmahasiswa();
void admin();
void daftar();
void updateSaldoMahasiswa(Mahasiswa mhs);
void beli(Mahasiswa *mhs);
void menumhs(Mahasiswa *mhs);
void simpanuang(Mahasiswa *mhs);
void login();
void mhs();
void urutbarang();

int main()
{
    int mode, password;

    printf("\n==========================================\n");
    printf("   SISTEM KOPERASI MAHASISWA       \n");
    printf("==========================================\n");
    printf("Login sebagai:\n");
    printf("1. Mahasiswa\n");
    printf("2. Admin\n");
    printf("3. Keluar\n");
    printf("\n>> Masukkan pilihan Anda: ");
    scanf("%d", &mode);

    //Implementasi Percabangan (Switch)
    switch (mode)
    {
    case 1:
        printf("\n-- Ke Menu Mahasiswa --\n");
        mhs();
        break;

    case 2:
        printf("\n-- Login Admin --\n");
        printf("btw passwordnya 12345 \n ");
        printf("Masukkan Password : ");
        scanf("%d", &password);

        //Implementasi Percabangan (If else)
        if (password == 12345)
        {
            admin();
        }
        else
        {
            printf("\n[SALAH] Hmm... Anda bukan atmin.\n\n");
            main();
        }
        break;

    case 3:
        printf("\nTerima kasih telah menggunakan SISKOPMA.\n");
        return 0;

    default:
        printf("\n[ERROR] Pilihan tidak ada.\n\n");
        main();
        break;
    }
}

void lihatbarang()
{
    Produk p;

    //Implementasi Pointer
    FILE *file = fopen("produk.txt", "r");
    printf("\n=========================================================\n");
    printf("                    DAFTAR PRODUK SISKOPMA                  \n");
    printf("=========================================================\n");
    printf("%-5s | %-20s | %-15s | %-10s\n", "ID", "Nama Produk", "Harga", "Stok");
    printf("---------------------------------------------------------\n");

    //Implementasi Perulangan (while)
    while (fscanf(file, "%d %s %d %d", &p.id, p.nama, &p.harga, &p.stok) != EOF)
    {
        printf("%-5d | %-20s | Rp %-12d | %-10d\n", p.id, p.nama, p.harga, p.stok);
    }
    printf("=========================================================\n\n");
    fclose(file);
}

void tambahbarang()
{
    //Implementasi tipe data Structure
    Produk p;

    //Implementasi Pointer
    FILE *file = fopen("produk.txt", "a");
    printf("\n---[ Tambah Produk Baru ]---\n");
    printf("ID Barang   : ");
    scanf("%d", &p.id);
    printf("Nama Barang : ");
    getchar();
    fgets(p.nama, sizeof(p.nama), stdin);
    p.nama[strcspn(p.nama, "\n")] = '\0';
    printf("Harga       : ");
    scanf("%d", &p.harga);
    printf("Stok        : ");
    scanf("%d", &p.stok);
    fprintf(file, "%d %s %d %d\n", p.id, p.nama, p.harga, p.stok);
    fclose(file);
    printf("\n[SUKSES] Produk sudah masuk etalase.\n\n");
}

void updatebarang()
{
    //Implementasi pemanggilan fungsi
    lihatbarang();
    int id, ditemukan = 0;
    Produk p, baris[100];
    int k = 0;
    FILE *file = fopen("produk.txt", "r");
    while (fscanf(file, "%d %s %d %d", &baris[k].id, baris[k].nama, &baris[k].harga, &baris[k].stok) != EOF)
    {
        k++;
    }
    fclose(file);

    printf("\n---[ Update Data Produk ]---\n");
    printf("Masukkan ID barang yang ingin diapdet: ");
    scanf("%d", &id);

    //Implementasi Perulangan(For)
    for (int i = 0; i < k; i++)
    {
        //Implementasi Percabangan (If)
        if (baris[i].id == id)
        {
            ditemukan = 1;
            printf(" -> Nama Barang Baru: ");
            getchar();
            fgets(baris[i].nama, sizeof(baris[i].nama), stdin);
            baris[i].nama[strcspn(baris[i].nama, "\n")] = '\0';
            printf(" -> Harga Baru      : ");
            scanf("%d", &baris[i].harga);
            printf(" -> Stok Baru       : ");
            scanf("%d", &baris[i].stok);
            break;
        }
    }

    //Implementasi Percabangan (If else)
    if (ditemukan)
    {
        file = fopen("produk.txt", "w");
        for (int i = 0; i < k; i++)
        {
            fprintf(file, "%d %s %d %d\n", baris[i].id, baris[i].nama, baris[i].harga, baris[i].stok);
        }
        fclose(file);
        printf("\n[SUKSES] Produk berhasil diapdet.\n\n");
    }
    else
    {
        printf("\n[ERROR] Produk gada.\n\n");
    }
}

void hapusbarang()
{
    lihatbarang();
    int id, ditemukan = 0, k = 0;
    //Implementasi Structure(Array of Structure)
    Produk p, baris[100];

    //Implementasi pointer
    FILE *file = fopen("produk.txt", "r");
    while (fscanf(file, "%d %s %d %d", &baris[k].id, baris[k].nama, &baris[k].harga, &baris[k].stok) != EOF)
    {
        k++;
    }
    fclose(file);


    printf("\n---[ Hapus Produk ]---\n");
    printf("Masukkan ID barang yang ingin dihapus: ");
    scanf("%d", &id);
    file = fopen("produk.txt", "w");
    for (int i = 0; i < k; i++)
    {
        if (baris[i].id != id)
        {
            fprintf(file, "%d %s %d %d\n", baris[i].id, baris[i].nama, baris[i].harga, baris[i].stok);
        }
        else
        {
            ditemukan = 1;
        }
    }
    fclose(file);

    //Implementasi Percabangan (For)
    if (ditemukan)
    {
        printf("\n[SUKSES] Produk sudah see you on top.\n\n");
    }
    else
    {
        printf("\n[ERROR] Produk gada.\n\n");
    }

    lihatbarang();
}

void lihatmahasiswa()
{
    Mahasiswa mhs;
    FILE *file = fopen("mahasiswa.txt", "r");
    printf("\n======================================================\n");
    printf("                 DAFTAR DATA MAHASISWA                \n");
    printf("======================================================\n");
    printf("%-15s | %-20s | %-15s\n", "NIM", "Nama Mahasiswa", "Saldo");
    printf("------------------------------------------------------\n");
    while (fscanf(file, "%s %s %d", mhs.nim, mhs.nama, &mhs.saldo) != EOF)
    {
        printf("%-15s | %-20s | Rp %-12d\n", mhs.nim, mhs.nama, mhs.saldo);
    }
    printf("======================================================\n\n");
    fclose(file);
}

void updatemahasiswa()
{
    lihatmahasiswa();
    char id[15];
    int ditemukan = 0;

    //Implementasi Array of Structures
    Mahasiswa mhs, baris[100];
    int k = 0;
    FILE *file = fopen("mahasiswa.txt", "r");
    while (fscanf(file, "%s %s %d", &baris[k].nim, &baris[k].nama, &baris[k].saldo) != EOF)
    {
        k++;
    }
    fclose(file);

    printf("\n---[ Apdet Data Mahasiswa ]---\n");
    printf("Masukkan NIM yang ingin diapdet: ");
    getchar();
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    for (int i = 0; i < k; i++)
    {
        if (strcmp(baris[i].nim, id) == 0)
        {
            ditemukan = 1;
            printf(" -> Nama Mahasiswa Baru : ");
            fgets(baris[i].nama, sizeof(baris[i].nama), stdin);
            baris[i].nama[strcspn(baris[i].nama, "\n")] = '\0';
            printf(" -> Saldo Baru          : ");
            scanf("%d", &baris[i].saldo);
            break;
        }
    }

    if (ditemukan)
    {
        file = fopen("mahasiswa.txt", "w");
        
        //Implementasi Pengulangan (For)
        for (int i = 0; i < k; i++)
        {
            fprintf(file, "%s %s %d\n", baris[i].nim, baris[i].nama, baris[i].saldo);
        }
        fclose(file);
        printf("\n[SUKSES] Mahasiswa berhasil diupdate.\n\n");
    }
    else
    {
        printf("\n[ERROR] Mahasiswa tidak ditemukan.\n\n");
    }
}

void hapusmahasiswa()
{
    lihatmahasiswa();
    char nim[15];
    int ditemukan = 0, k = 0;
    Mahasiswa mhs, baris[100];

    FILE *file = fopen("mahasiswa.txt", "r");
    while (fscanf(file, "%s %s %d", &baris[k].nim, &baris[k].nama, &baris[k].saldo) != EOF)
    {
        k++;
    }
    fclose(file);

    printf("\n---[ Hapus Data Mahasiswa ]---\n");
    printf("Masukkan NIM mahasiswa yang ingin dihapus: ");
    getchar();
    fgets(nim, sizeof(nim), stdin);
    nim[strcspn(nim, "\n")] = '\0';
    file = fopen("mahasiswa.txt", "w");
    for (int i = 0; i < k; i++)
    {
        if (strcmp(baris[i].nim, nim) != 0)
        {
            fprintf(file, "%s %s %d\n", baris[i].nim, baris[i].nama, baris[i].saldo);
        }
        else
        {
            ditemukan = 1;
        }
    }
    fclose(file);

    if (ditemukan)
    {
        printf("\n[SUKSES] Mahasiswa berhasil see you on top.\n\n");
    }
    else
    {
        printf("\n[ERROR] Mahasiswa tidak ditemukan.\n\n");
    }
}

void admin()
{
    int pilih;
    printf("\n========================================\n");
    printf("             DASHBOARD ADMIN            \n");
    printf("========================================\n");
    printf("1. Lihat Produk\n");
    printf("2. Tambah Produk\n");
    printf("3. Update Data Produk\n");
    printf("4. Hapus Produk\n");
    printf("5. Lihat Daftar Mahasiswa\n");
    printf("6. Update Data Mahasiswa\n");
    printf("7. Hapus Mahasiswa\n");
    printf("8. Urutkan Tampilan Produk\n");
    printf("9. Kembali ke Menu Utama\n");
    printf("\n>> Masukkan pilihan Anda: ");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
        lihatbarang();
        admin();
        break;

    case 2:
        tambahbarang();
        admin();
        break;

    case 3:
        updatebarang();
        admin();
        break;

    case 4:
        hapusbarang();
        admin();
        break;

    case 5:
        lihatmahasiswa();
        admin();
        break;

    case 6:
        updatemahasiswa();
        admin();
        break;

    case 7:
        hapusmahasiswa();
        admin();
        break;

    case 8:
        urutbarang();
        admin();
        break;

    case 9:
        //Implementasi Rekursi (Fungsi Main-Admin-Main)
        main();
        break;

    default:
        printf("\n[ERROR] Pilih yang benar.\n\n");
        admin();
        break;
    }
}

void daftar()
{
    Mahasiswa mhs;
    FILE *file = fopen("mahasiswa.txt", "a");
    printf("\n---[ Pendaftaran Akun Mahasiswa ]---\n");
    printf("NIM  : ");
    scanf("%s", mhs.nim);
    getchar();
    printf("Nama : ");
    fgets(mhs.nama, sizeof(mhs.nama), stdin);
    mhs.nama[strcspn(mhs.nama, "\n")] = '\0';
    mhs.saldo = 0;
    fprintf(file, "%s %s %d\n", mhs.nim, mhs.nama, mhs.saldo);
    fclose(file);
    printf("\n[SUKSES] Pendaftaran berhasil! Silakan login.\n\n");
}

void updateSaldoMahasiswa(Mahasiswa mhs)
{
    FILE *file = fopen("mahasiswa.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Mahasiswa tempMhs;

    while (fscanf(file, "%s %s %d", tempMhs.nim, tempMhs.nama, &tempMhs.saldo) != EOF)
    {
        if (strcmp(mhs.nim, tempMhs.nim) == 0)
        {
            fprintf(temp, "%s %s %d\n", mhs.nim, mhs.nama, mhs.saldo);
        }
        else
        {
            fprintf(temp, "%s %s %d\n", tempMhs.nim, tempMhs.nama, tempMhs.saldo);
        }
    }
    fclose(file);
    fclose(temp);
    remove("mahasiswa.txt");
    rename("temp.txt", "mahasiswa.txt");
}

void beli(Mahasiswa *mhs)
{
    lihatbarang();
    Produk baris[100];
    int k = 0, id, banyak;

    struct
    {
        Produk p;
        int banyak;
    } keranjang[10];

    int jumlahBelanja = 0;

    FILE *file = fopen("produk.txt", "r");
    while (fscanf(file, "%d %s %d %d", &baris[k].id, baris[k].nama, &baris[k].harga, &baris[k].stok) != EOF)
        k++;
    fclose(file);

    int total = 0;
    printf("\n---[ Mulai Belanja ]---\n");
    while (1)
    {
        printf("Masukkan ID Produk (ketik 0 untuk selesai): ");
        scanf("%d", &id);
        if (id == 0)
        {
            break;
        }
        int index = -1;

        // Implementasi Pencarian(Sequential search)
        for (int i = 0; i < k; i++)
            if (baris[i].id == id)
                index = i;

        if (index == -1)
        {
            printf("[ERROR] Produk tidak ada!\n");
            continue;
        }

        printf(" -> Jumlah Beli: ");
        scanf("%d", &banyak);
        if (banyak <= 0 || banyak > baris[index].stok)
        {
            printf("[ERROR] Jumlah tidak valid atau stok tidak mencukupi!\n");
            continue;
        }

        total += baris[index].harga * banyak;
        baris[index].stok -= banyak;

        keranjang[jumlahBelanja].p = baris[index];
        keranjang[jumlahBelanja].banyak = banyak;
        jumlahBelanja++;
    }

    if (total == 0)
    {
        printf("\n[INFO] Tidak ada produk yang dibeli.\n");
        return;
    }

    int bayar;
    printf("\n---[ Proses Pembayaran ]---\n");
    printf("Total Belanja Anda: Rp %d\n", total);
    printf("Bayar pakai? (1.Cash / 2.Saldo): ");
    scanf("%d", &bayar);

    if (bayar == 2)
    {
        if (mhs->saldo < total)
        {
            printf("\n[ERROR] Saldo tidak mencukupi!\n");
            return;
        }
        mhs->saldo -= total;
        updateSaldoMahasiswa(*mhs);
    }

    // Update stok ke file
    file = fopen("produk.txt", "w");
    for (int i = 0; i < k; i++)
    {
        fprintf(file, "%d %s %d %d\n", baris[i].id, baris[i].nama, baris[i].harga, baris[i].stok);
    }
    fclose(file);

    printf("\n\n=======================================================\n");
    printf("                  STRUK PEMBELIAN KOPMA                \n");
    printf("=======================================================\n");
    printf("Nama Pelanggan : %s\n", mhs->nama);
    printf("NIM            : %s\n", mhs->nim);
    printf("-------------------------------------------------------\n");
    printf("%-3s | %-15s | %-7s | %-10s | %-10s\n", "No", "Nama Produk", "Jumlah", "Harga", "Subtotal");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < jumlahBelanja; i++)
    {
        printf("%-3d | %-15s | %-7d | %-10d | %-10d\n",
               i + 1,
               keranjang[i].p.nama,
               keranjang[i].banyak,
               keranjang[i].p.harga,
               keranjang[i].p.harga * keranjang[i].banyak);
    }
    printf("-------------------------------------------------------\n");
    printf("                                  Total : Rp %-10d\n", total);
    printf("-------------------------------------------------------\n");
    if (bayar == 1)
    {
        printf("Metode Pembayaran : Cash\n");
    }
    else
    {
        printf("Metode Pembayaran : Saldo Kopma\n");
        printf("Sisa Saldo        : Rp %d\n", mhs->saldo);
    }
    printf("=======================================================\n");
    printf("          Terima kasih sudah berbelanja!             \n\n");

    menumhs(mhs);
}

void menumhs(Mahasiswa *mhs)
{
    int pilih;
    printf("\n========================================\n");
    printf("     Selamat Datang, %s!              \n", mhs->nama);
    printf("========================================\n");
    printf("1. Beli Barang\n");
    printf("2. Simpan Uang\n");
    printf("3. Cek Saldo\n");
    printf("4. Logout\n");
    printf("\n>> Masukkan pilihan Anda: ");
    scanf("%d", &pilih);

    //Implementasi Percabanagn (Switch)
    switch (pilih)
    {
    case 1:
        beli(mhs);
        break;

    case 2:
        simpanuang(mhs);
        break;

    case 3:
        printf("\n[INFO] Saldo Anda saat ini adalah: Rp %d\n", mhs->saldo);
        menumhs(mhs);
        break;

    case 4:
        main();
        break;

    default:
        printf("\n[ERROR] Pilih yang betul.\n\n");
        menumhs(mhs);
        break;
    }
}

void simpanuang(Mahasiswa *mhs)
{
    int jumlah;
    printf("\n---[ Simpan Uang ]---\n");
    printf("Masukkan jumlah uang yang ingin disimpan: ");
    scanf("%d", &jumlah);
    if (jumlah < 0)
    {
        printf("\n[ERROR] Jumlah tidak boleh negatif.\n");
        return;
    }
    mhs->saldo += jumlah;
    updateSaldoMahasiswa(*mhs);
    printf("\n[SUKSES] Saldo berhasil ditambahkan. Saldo Anda sekarang: Rp %d\n", mhs->saldo);
    menumhs(mhs);
}

void login()
{
    Mahasiswa mhs;
    char nimInput[15];
    FILE *file = fopen("mahasiswa.txt", "r");
    printf("\n---[ Login Mahasiswa ]---\n");
    printf("Masukkan NIM Anda: ");
    scanf("%s", nimInput);

    // 8. Implementasi Pencarian (Sequential Search), Membaca file baris per baris untuk menemukan NIM yang cocok.
    while (fscanf(file, "%s %s %d", &mhs.nim, &mhs.nama, &mhs.saldo) != EOF)
    {
        if (strcmp(nimInput, mhs.nim) == 0)
        {
            fclose(file);
            menumhs(&mhs);
            break;
        }
    }

    printf("\n[ERROR] Login gagal, NIM tidak ditemukan.\n\n");
    fclose(file);
}

void mhs()
{
    int pilih;
    printf("\n---[ Menu Mahasiswa ]---\n");
    printf("Sudah punya akun?\n");
    printf("1. Daftar (kalau belum)\n");
    printf("2. Login (kalau sudah)\n");
    printf("3. Kembali\n");
    printf("\n>> Masukkan pilihan Anda: ");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
        daftar();
        mhs();
        break;

    case 2:
        login();
        mhs();
        break;

    case 3:
        main();
        break;

    default:
        printf("\n[ERROR] Pilihan gada.\n\n");
        mhs();
        break;
    }
}

void urutbarang()
{
    Produk baris[100];
    Produk temp;
    int k = 0;
    int pilih;

    FILE *file = fopen("produk.txt", "r");
    while (fscanf(file, "%d %s %d %d", &baris[k].id, baris[k].nama, &baris[k].harga, &baris[k].stok) != EOF)
    {
        k++;
    }
    fclose(file);

    printf("\n---[ Urutkan Tampilan Produk ]---\n");
    printf("Urutkan berdasarkan:\n");
    printf("1. Harga (Termurah ke Termahal)\n");
    printf("2. ID (Terkecil ke Terbesar)\n");
    printf("\n>> Masukkan pilihan Anda: ");
    scanf("%d", &pilih);
    

    //Implementasi Pengurutan (Bubble Sort), Algoritma Bubble Sort digunakan untuk mengurutkan array produk.
    switch (pilih)
    {
    case 1: // Urutkan berdasarkan HARGA
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = 0; j < k - i - 1; j++)
            {
                if (baris[j].harga > baris[j + 1].harga)
                {
                    temp = baris[j];
                    baris[j] = baris[j + 1];
                    baris[j + 1] = temp;
                }
            }
        }
        printf("\n[INFO] Produk berhasil diurutkan berdasarkan HARGA.\n");
        break;

    case 2: // Urutkan berdasarkan ID
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = 0; j < k - i - 1; j++)
            {
                if (baris[j].id > baris[j + 1].id)
                {
                    temp = baris[j];
                    baris[j] = baris[j + 1];
                    baris[j + 1] = temp;
                }
            }
        }
        printf("\n[INFO] Produk berhasil diurutkan berdasarkan ID.\n");
        break;

    default:
        printf("\n[ERROR] Pilihan tidak valid.\n");
        return;
    }

    printf("\n=========================================================\n");
    printf("                DAFTAR PRODUK (TERURUT)                  \n");
    printf("=========================================================\n");
    printf("%-5s | %-20s | %-15s | %-10s\n", "ID", "Nama Produk", "Harga", "Stok");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < k; i++)
    {
        printf("%-5d | %-20s | Rp %-12d | %-10d\n", baris[i].id, baris[i].nama, baris[i].harga, baris[i].stok);
    }
    printf("=========================================================\n\n");
}
