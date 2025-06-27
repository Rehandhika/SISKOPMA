# Sistem Koperasi Mahasiswa (SISKOPMA)

## Deskripsi

**SISKOPMA** adalah sebuah program _Command Line Interface (CLI)_ sederhana yang dibuat menggunakan bahasa pemrograman C. Program ini merupakan simulasi sistem manajemen untuk sebuah koperasi mahasiswa. 

Proyek ini dibuat untuk memenuhi tugas akhir mata kuliah **Algoritma dan Pemrograman**.

## Fitur Utama

Program ini memiliki dua mode pengguna dengan fungsionalitas yang berbeda:

### 1. Admin
- Mengelola data produk (CRUD: Tambah, Lihat, Update, Hapus).
- Mengelola data mahasiswa yang terdaftar (Lihat, Update, Hapus).
- Mengurutkan daftar produk berdasarkan harga atau ID.
- Memerlukan _password_ untuk login.

### 2. Mahasiswa
- Mendaftar akun baru.
- Login menggunakan NIM (Nomor Induk Mahasiswa).
- Melihat daftar produk yang tersedia.
- Melakukan pembelian produk secara tunai (_cash_) atau menggunakan saldo koperasi.
- Menyimpan uang (Top-up saldo).
- Mengecek sisa saldo.
- Mencetak struk sederhana setelah transaksi berhasil.

## Konsep Pemrograman yang Diimplementasikan
Program ini dibangun dengan mengimplementasikan berbagai konsep dasar dalam algoritma dan pemrograman, antara lain:
1.  **Percabangan** (`if-else`, `switch-case`)
2.  **Perulangan** (`while`, `for`)
3.  **Fungsi** (Deklarasi, Definisi, dan Pemanggilan)
4.  **Array** (Termasuk _array of struct_)
5.  **Structure** (`struct`)
6.  **Pointer** (Untuk operasi _file_ dan parameter fungsi)
7.  **Rekursi** (Pada navigasi menu)
8.  **Pencarian** (_Sequential Search_)
9.  **Pengurutan** (_Bubble Sort_)

## Cara Menjalankan Program

1.  **Kompilasi Kode:**
    Pastikan Anda memiliki C _compiler_ (seperti GCC) terinstal di sistem Anda. Buka terminal atau _command prompt_, arahkan ke direktori tempat file ini disimpan, lalu kompilasi dengan perintah:
    ```bash
    gcc siskopma.c -o siskopma
    ```
    *Ganti `siskopma.c` dengan nama file kode C Anda jika berbeda.*

2.  **Jalankan Program:**
    Setelah kompilasi berhasil, jalankan program dengan perintah:
    ```bash
    ./siskopma
    ```
    Untuk pengguna Windows:
    ```bash
    siskopma.exe
    ```

3.  **File Data:**
    Program ini akan secara otomatis membuat dua file `.txt` untuk menyimpan data jika file tersebut belum ada:
    - `produk.txt`: Menyimpan data produk (ID, nama, harga, stok).
    - `mahasiswa.txt`: Menyimpan data pengguna mahasiswa (NIM, nama, saldo).

---
*Dibuat sebagai bagian dari pemenuhan tugas mata kuliah Algoritma dan Pemrograman.*
