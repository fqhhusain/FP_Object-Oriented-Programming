# FP_Object-Oriented-Programming
Program ini dibuat dalam rangka penugasan mata kuliah Struktur Data dan Pemrograman Berorientasi Objek 

## Anggota Kelompok
- Riskiyatul Nur Oktarani 5027231013
- Muhammad Faqih Husain 5027231023

## Deskripsi
Program ini menerapkan konsep OOP dan konsep graph untuk mengimplementasikan Aplikasi kesehatan yang memiliki fitur utama untuk mengetahui layanan apa saja yang terdapat pada suatu fasilitas kesehatan serta dapat mengetahui lokasi fasilitas kesehatan terdekat dari suatu bangunan. Program ini dibuat dalam bentuk sebuah peta bangunan beserta jaraknya pada suatu daerah yang diimplementasikan dengan edge list. Graph yang diterapkan untuk mengimplementasikan jalan berupa weighted undirected grah. Jarak ke fasilitas kesehatan terdekat didapaktakn dengan algoritma shortest path yaitu dijkstra.

Program ini menggunakan pendekatan OOP dengan fitur sebagai berikut:

1. Class & Object

Class adalah sebuah tipe data yang terdiri dari satu atau lebih data dan satu atau lebih fungsi. Sebuah class dapat diakses ketika class tersebut dipanggil dan dibuat dalam bentuk instance dari class tersebut.

- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/3b8d00ce-e8f3-4951-bf79-c4935e07b345)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/368867de-f1d4-48cf-a853-76b63a5b540c)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/40efbbdd-2f70-496b-9317-7d6af86baac3)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/572e02ad-f1cc-43e1-aa74-a8aeb0fdb586)

Object adalah instance dari suatu class. Saat sebuah object dibuat, memory baru akan dialokasikan. Untuk setiap object, memiliki atribut, sifat, dan perilaku.

- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/4a1069de-6adb-40ac-9c8a-d26959fc211d)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/75f20380-d241-48c3-8ea2-91b6e5819073)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/88e32b04-2b4c-4e4b-bf17-96b7fcb7ee9b)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/f04d7179-7f55-4c1a-8d1d-941d8d96c530)

2. Attribute, Property & Method, Behavior

Attribute/Property adalah anggota variabel data yang berada dalam sebuah class yang mewakili suatu fitur tertentu. Attribute/Property juga dapat disebut sebagai karakteristik class yang dapat diakses dari object lain atau membedakan suatu class dengan class lainnya.

- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/328fcea6-ec2c-42a5-8e34-ec0fbae5526c)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/b80c1d76-e498-43c7-a5aa-12a181f77349)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/70ddc308-c9c8-457c-9b78-8c791580d8e7)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/a0ea13ac-f7d3-492c-bf3d-601e538053c4)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/194c0047-c413-4d70-b163-a66e2606db7d)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/f5ab4da2-f3d8-4acc-b6c6-534837b7b0fc)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/cb3b81c4-07da-4445-ba83-affaffa13faa)

Method/Behavior adalah fungsi yang terdapat dalam sebuah class. Method/Behavior dapat menggunakan suatu parameter dan menerima argumen yang nantinya dapat dimanipulasi untuk menghasilkan sebuah output sesuai tujuan dibuatnya Method/Behavior tersebut.

contohnya pada class Graph memiliki method sebagai berikut 
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/07eded57-e757-4569-878a-e3b4112b5c96)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/ac434e84-0de3-4947-80c6-e3598c3b4ba4)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/ad345903-1e48-4fa5-99ac-1520c371d21a)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/3a98f95e-9f0e-4d57-a99e-3cc86304cc28)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/09426641-08ab-4101-b37d-adbf78e8cffd)


3. Constructor

Constructor adalah metode khusus dalam sebuah kelas yang dipanggil secara otomatis ketika sebuah objek dari kelas tersebut dibuat. Constructor digunakan untuk menginisialisasi data anggota dari sebuah kelas. Constructor memiliki nama yang sama dengan nama kelas dan tidak memiliki tipe pengembalian, termasuk void.

Dalam program terdapat penggunaan Parameterized Constructor. Constructor ini digunakan ketika kita ingin menginisialisasi data anggota dengan nilai tertentu pada saat pembuatan objek.

- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/ba0e1ecb-19fc-43e7-aae4-b7cd18c92159)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/057d5cbf-5cd9-4c01-bdfa-0bf710ead4c4)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/49b15c94-8a30-49a5-93b0-b4596e6b166b)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/cb0983ed-f880-4260-92ed-cdff6fb8722c)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/19a898a6-b522-4ca8-b0e9-20f3c30a38fd)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/4a315a68-6755-4225-9c59-cf11dfc5d633)

4. Setter & Getter

Dalam pemrograman berorientasi objek (OOP), setter dan getter adalah metode yang digunakan untuk mengakses dan memodifikasi data anggota (member data) dari sebuah kelas. Ini membantu dalam mengontrol akses ke data dan menjaga enkapsulasi.Setter adalah Metode yang digunakan untuk mengatur nilai anggota data. Getter adalah Metode yang digunakan untuk mendapatkan nilai anggota data.

- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/ebb82e10-213d-4705-8bae-73d2147af883)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/e241129e-f7ed-41f8-9dbe-d8116124720a)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/d9cb22e3-faa0-45cb-86c9-b3aad362ea16)

5. Encapsulation

Encapsulation dalam pemrograman berorientasi objek (OOP) adalah konsep untuk mengemas data bersama dengan metode yang beroperasi pada data tersebut dalam sebuah class. Ini berarti bahwa data (variabel) bersama dengan operasi (metode atau fungsi) yang bekerja pada data itu, dikemas bersama dalam satu unit yang disebut objek.

![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/030232f8-9ac3-466a-a372-490bef15ed07)

6. Inheritance

Inheritance adalah suatu fitur atau proses dimana class baru dibuat dari class yang sudah ada. Kelas baru yang dibuat disebut “derived class” atau “child class” dan class yang sudah ada disebut “base class” atau “parent class”.

- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/5d67115b-b0ae-40ee-96f8-f8d1b22117b3)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/0d3f51f8-db38-4b9d-8c15-5e5eb83cc1d2)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/2279f922-7c0e-4fa0-9463-c573c54f9d07)

7. Overriding

Overriding adalah sebuah method dari superclass (kelas induk) yang ditulis kembali pada subclass (kelas anak). Karena sering kali terdapat sebuah method dari superclass (kelas induk) yang aksi pada methodnya tidak sesuai jika diterapkan pada subclass (kelas anak).

- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/d3aca27e-5ad9-4e48-857e-8ccafec3a070)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/7074c6f2-0416-43d2-a1f1-045ff1ac56a6)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/cce2a8d1-2315-42d1-bda6-ce975364da79)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/967ee528-f11a-4690-b09a-19fc704ec042)

8. Access Modifier, Visibility

Konsep "Access Modifier" atau "Visibility" adalah bagian penting dari pemrograman berorientasi objek karena membantu mengatur akses terhadap properti dan metode dari suatu kelas. Access Modifier terbagi menjadi publik, private, dan protected.

Contoh penerapan pada program adalah sebagai berikut :

- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/a47ea3e3-fd65-4a70-a21f-45216947cf44)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/e0a0846b-691d-4179-bddf-0c1127d2f2c1)
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/af0f05e2-3ca2-4662-a064-77e403eeb2c8)

9. Abstraction

Pada Class HealthcareFacility:
- Mendeklarasikan metode virtual murni provideService, yang harus diimplementasikan oleh kelas turunannya.
- Menyembunyikan detail implementasi dari bagaimana layanan disediakan, dan hanya menyediakan antarmuka dasar (getName, getType).
- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/0a937ba2-aa48-4ef6-8caa-8f8487ae6454)


10. Polymorphism

Kata “polymorphism” berarti memiliki banyak bentuk. Dengan kata sederhana, kita dapat mendefinisikan polymorphism sebagai kemampuan sebuah pesan untuk ditampilkan dalam lebih dari satu bentuk. Contoh nyata dari polymorphism adalah seseorang yang pada saat yang sama dapat memiliki karakteristik yang berbeda. Seorang pria pada saat yang sama adalah seorang ayah, suami, dan karyawan. Jadi orang yang sama menunjukkan perilaku yang berbeda dalam situasi yang berbeda. Ini disebut polymorphism. Polymorphism dianggap sebagai salah satu fitur penting dari Pemrograman Berorientasi Objek.

Runtime polymorphism dicapai dengan Penimpaan Fungsi. Pengikatan akhir dan polimorfisme dinamis adalah nama lain dari polymorphism runtime. Pemanggilan fungsi diselesaikan pada saat runtime dalam polymorphism runtime. Sebaliknya, dengan polymorphism waktu kompilasi, kompiler menentukan pemanggilan fungsi mana yang akan diikat ke objek setelah menyimpulkannya pada saat runtime.

Virtual function adalah fungsi anggota yang dideklarasikan di kelas dasar menggunakan kata kunci virtual dan didefinisikan ulang (override) di kelas turunan.

- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/cf918870-e209-48da-9233-ef7e964f2ef5)

- ![image](https://github.com/fqhhusain/FP_Object-Oriented-Programming/assets/88548292/493f79c2-65ca-44b6-bc7a-95d7c4b557ce)

