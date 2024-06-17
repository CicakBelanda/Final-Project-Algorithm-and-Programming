#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define BOLD "\x1b[1m"
#define ITALIC "\x1b[3m"
#define MAX_DATA 1000

// Struct untuk tanggal transaksi
struct TanggalTransaksi {
    int tanggalTransaksi;
    int bulanTransaksi;
    int tahunTransaksi;
};

// Struct untuk data penjualan
struct DataPenjualan {
    struct TanggalTransaksi tanggalTransaksiInfo;
    char namaPelanggan[50];
    char jenisProduk[50];
    char namaProduk[50];
    int jumlahProduk;
    double hargaProduk;
    double totalPembayaran;
};

// Mencetak page introduction
void intro(){
    system("cls");
    printf(BOLD "Welcome to Clothing Management App" RESET "\n\n");
    printf(BOLD "Developed by " GREEN ITALIC "Cina Arab Jawa" RESET "\n");
    Sleep(5000);

    system("cls");
    printf(BOLD "Final Project Lab: Algorithm and Programming" RESET "\n");
    printf(BOLD "Case Study M - Clothing" RESET "\n\n");
    printf(BOLD "Our Team:" RESET "\n");
    printf("Kevin Joseph Handoyo - 2702355302 \n");
    printf("Hasan Fadlullah - 2702357011\n");
    printf("Fulvian Rayhan Renanda Putra - 2702354256\n");
    Sleep(5000);
}

// Validasi input dari user
void typeValidation(int *opt, int lower, int upper) {
    while (*opt < lower || *opt > upper) {
        printf("Invalid answer!!!\n");
        printf("Select type >> ");
        scanf("%d", opt);
    }
    printf("\n");
}

// Validasi input dari user
void menuValidation(int *opt, int lower, int upper) {
    while (*opt < lower || *opt > upper) {
        printf("Invalid answer!!!\n");
        printf("Select menu >> ");
        scanf("%d", opt);
    }
    printf("\n");
}

// Validasi input dari user
void decisionValidation(char *decision) {
    while (*decision != 'y' && *decision != 'Y' && *decision != 'n' && *decision != 'N') {
        printf("Invalid answer!!!\n");
        printf("Answer >> ");
        scanf(" %c", decision);
    }
}

// Display menu aplikasi
void display(int *option) {
    system("cls");

    // Print the menu
    printf("================================\n");
    printf("|       Application Menu       |\n");
    printf("================================\n");
    printf("| 1. Input data                |\n");
    printf("| 2. Display data              |\n");
    printf("| 3. Sort data                 |\n");
    printf("| 4. Search data               |\n");
    printf("| 5. Export data               |\n");
    printf("| 6. Manage data               |\n");
    printf("| 7. Exit                      |\n");
    printf("================================\n");
    printf("Select menu >> "); scanf("%d", option);

    menuValidation(option, 1, 7);
}

// Display jenis produk
void productType(int *optionType, struct DataPenjualan *data) {
    printf("Product Type:\n");
    printf("1. Casual Wear\n");
    printf("2. Formal Wear\n");
    printf("3. Sports Wear\n");
    printf("4. Traditional Wear\n");
    printf("5. Swim Wear\n");
    printf("6. Outdoor Wear\n");
    printf("Select type >> "); 
    scanf("%d", optionType);
    
    typeValidation(optionType, 1, 6);

    if (*optionType == 1) strcpy(data->jenisProduk, "Casual Wear");
    else if (*optionType == 2) strcpy(data->jenisProduk, "Formal Wear");
    else if (*optionType == 3) strcpy(data->jenisProduk, "Sports Wear");
    else if (*optionType == 4) strcpy(data->jenisProduk, "Traditional Wear");
    else if (*optionType == 5) strcpy(data->jenisProduk, "Swim Wear");
    else if (*optionType == 6) strcpy(data->jenisProduk, "Outdoor Wear");
}

// Display nama produk
void productName1(struct DataPenjualan *data) {
    int optionName;
    printf("Casual Wear:\n");
    printf("1. T-Shirt - Rp85.000\n");
    printf("2. Jeans - Rp150.000\n");
    printf("3. Hoodie - Rp200.000\n");
    printf("4. Sweater - Rp175.000\n");
    printf("5. Shorts - Rp125.000\n");
    printf("Select type >> "); 
    scanf("%d", &optionName);

    typeValidation(&optionName, 1, 5);

    if (optionName == 1) {
        strcpy(data->namaProduk, "T-Shirt");
        data->hargaProduk = 85000;
    } else if (optionName == 2) {
        strcpy(data->namaProduk, "Jeans");
        data->hargaProduk = 150000;
    } else if (optionName == 3) {
        strcpy(data->namaProduk, "Hoodie");
        data->hargaProduk = 200000;
    } else if (optionName == 4) {
        strcpy(data->namaProduk, "Sweater");
        data->hargaProduk = 175000;
     }else if (optionName == 5) {
        strcpy(data->namaProduk, "Shorts");
        data->hargaProduk = 125000;
    }
}

// Display nama produk
void productName2(struct DataPenjualan *data) {
    int optionName;
    printf("Formal Wear:\n");
    printf("1. Blazer - Rp300.000\n");
    printf("2. Shirt - Rp250.000\n");
    printf("3. Suits - Rp275.000\n");
    printf("4. Long Skirts - Rp150.000\n");
    printf("5. Dress - Rp175.000\n");
    printf("Select type >> "); 
    scanf("%d", &optionName);

    typeValidation(&optionName, 1, 5);

    if(optionName == 1) {
        strcpy(data->namaProduk, "Blazer");
        data->hargaProduk = 300000;
    } else if(optionName == 2) {
        strcpy(data->namaProduk, "Shirt");
        data->hargaProduk = 250000;
    } else if(optionName == 3) {
        strcpy(data->namaProduk, "Suits");
        data->hargaProduk = 275000;
    } else if(optionName == 4) {
        strcpy(data->namaProduk, "Long Skirts");
        data->hargaProduk = 150000;
    } else if(optionName == 5) {
        strcpy(data->namaProduk, "Dress");
        data->hargaProduk = 175000;
    }
}

// Display nama produk
void productName3(struct DataPenjualan *data) {
    int optionName;
    printf("Sports Wear:\n");
    printf("1. Sports T-Shirt - Rp100.000\n");
    printf("2. Sports Shorts - Rp125.000\n");
    printf("3. Running Shoes - Rp300.000\n");
    printf("4. Windproof Jacket - Rp350.000\n");
    printf("5. Sports Leggings - Rp100.000\n");
    printf("Select type >> "); 
    scanf("%d", &optionName);

    typeValidation(&optionName, 1, 5);

    if(optionName == 1) {
        strcpy(data->namaProduk, "Sports T-Shirt");
        data->hargaProduk = 100000;
    } else if(optionName == 2) { 
        strcpy(data->namaProduk, "Sports Shorts");
        data->hargaProduk = 125000;
    } else if(optionName == 3) {
        strcpy(data->namaProduk, "Running Shoes");
        data->hargaProduk = 300000;
    } else if(optionName == 4) {
        strcpy(data->namaProduk, "Windproof Jacket");
        data->hargaProduk = 350000;
    } else if(optionName == 5) {
        strcpy(data->namaProduk, "Sports Leggings");
        data->hargaProduk = 100000;
    }
}

// Display nama produk
void productName4(struct DataPenjualan *data) {
    int optionName;
    printf("Traditional Wear:\n");
    printf("1. Kimono - Rp250.000\n");
    printf("2. Kebaya - Rp200.000\n");
    printf("3. Koteka - Rp15.000\n");
    printf("Select type >> "); 
    scanf("%d", &optionName);

    typeValidation(&optionName, 1, 3);

    if(optionName == 1) {
        strcpy(data->namaProduk, "Kimono");
        data->hargaProduk = 250000;
    } else if(optionName == 2) {
        strcpy(data->namaProduk, "Kebaya");
        data->hargaProduk = 200000;
    } else if(optionName == 3) {
        strcpy(data->namaProduk, "Koteka");
        data->hargaProduk = 15000;
    }
}

// Display nama produk
void productName5(struct DataPenjualan *data) {
    int optionName;
    printf("Swim Wear:\n");
    printf("1. Swimshorts - Rp75.000\n");
    printf("2. Women's Swimsuit - Rp150.000\n");
    printf("3. Rash Guard - Rp175.000\n");
    printf("Select type >> "); 
    scanf("%d", &optionName);

    typeValidation(&optionName, 1, 3);

    if(optionName == 1) { 
        strcpy(data->namaProduk, "Swimshorts");
        data->hargaProduk = 75000;
    } else if(optionName == 2) { 
        strcpy(data->namaProduk, "Women's Swimsuit");
        data->hargaProduk = 150000;
    } else if(optionName == 3) {
        strcpy(data->namaProduk, "Rash Guard");
        data->hargaProduk = 175000;
    }
}

// Display nama produk
void productName6(struct DataPenjualan *data) {
    int optionName;
    printf("Outdoor Wear:\n");
    printf("1. Hiking Jacket - Rp200.000\n");
    printf("2. Hiking Pants - Rp175.000\n");
    printf("3. Hiking Shoes - Rp300.000\n");
    printf("4. Waterproof Jacket - Rp350.000\n");
    printf("Select type >> "); 
    scanf("%d", &optionName);

    typeValidation(&optionName, 1, 4);

    if(optionName == 1) { 
        strcpy(data->namaProduk, "Hiking Jacket");
        data->hargaProduk = 200000;
    } else if(optionName == 2) { 
        strcpy(data->namaProduk, "Hiking Pants");
        data->hargaProduk = 175000;
    } else if(optionName == 3) {
        strcpy(data->namaProduk, "Hiking Shoes");
        data->hargaProduk = 300000;
    } else if(optionName == 4) {
        strcpy(data->namaProduk, "Waterproof Jacket");
        data->hargaProduk = 350000;
    }
}

// Input data ke dalam file
void inputData(struct DataPenjualan data[], int *count) {
    int optionType;

    if (*count >= MAX_DATA) {
        printf("Data capacity exceeded. Cannot input more data.\n");
        system("pause");
        return;
    }

    system("cls");
    do {
        printf("Transaction Date (DD MM YYYY): ");
        if (scanf("%d %d %d", &data[*count].tanggalTransaksiInfo.tanggalTransaksi,
                  &data[*count].tanggalTransaksiInfo.bulanTransaksi,
                  &data[*count].tanggalTransaksiInfo.tahunTransaksi) != 3 ||
            data[*count].tanggalTransaksiInfo.tanggalTransaksi < 1 ||
            data[*count].tanggalTransaksiInfo.tanggalTransaksi > 31 ||
            data[*count].tanggalTransaksiInfo.bulanTransaksi < 1 ||
            data[*count].tanggalTransaksiInfo.bulanTransaksi > 12 ||
            data[*count].tanggalTransaksiInfo.tahunTransaksi < 1900 ||
            data[*count].tanggalTransaksiInfo.tahunTransaksi > 2100) {
            
            printf("Invalid date! Please enter a valid date.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);
    printf("\n");

    printf("Customer Name: ");
    scanf(" %[^\n]", data[*count].namaPelanggan);
    printf("\n");

    productType(&optionType, &data[*count]);

    if(optionType == 1) productName1(&data[*count]);
    else if(optionType == 2) productName2(&data[*count]);
    else if(optionType == 3) productName3(&data[*count]);
    else if(optionType == 4) productName4(&data[*count]);
    else if(optionType == 5) productName5(&data[*count]);
    else if(optionType == 6) productName6(&data[*count]);

    printf("Quantity: ");
    scanf("%d", &data[*count].jumlahProduk);
    printf("\n");

    data[*count].totalPembayaran = data[*count].jumlahProduk * data[*count].hargaProduk;

    FILE *sales = fopen("sales.txt", "a");
    if (sales == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(sales, "%d,%d,%d,%s,%s,%s,%d,%.2lf,%.2lf\n",
            data[*count].tanggalTransaksiInfo.tanggalTransaksi,
            data[*count].tanggalTransaksiInfo.bulanTransaksi,
            data[*count].tanggalTransaksiInfo.tahunTransaksi,
            data[*count].namaPelanggan,
            data[*count].jenisProduk,
            data[*count].namaProduk,
            data[*count].jumlahProduk,
            data[*count].hargaProduk,
            data[*count].totalPembayaran);

    fclose(sales);

    (*count)++;

    printf("Data added successfully.\n\n");

    // Fungsi rekursi untuk input data
    char decision;
    printf("Do you want to input more data? (y/n): "); scanf(" %c", &decision);
    decisionValidation(&decision);
    if (decision == 'y' || decision == 'Y') {
        inputData(data, count);
    } else {
        printf("\n");
        system("pause");
    }
}

// Cetak data dari file
void printFile(struct DataPenjualan data[], int row) {
    system("cls");
    printf("Displaying %d rows of data\n\n", row);

    // Cetak header tabel
    printf("==========================================================================================================================\n");
    printf("| %-3s | %-12s %-20s %-20s %-18s %-5s %-15s %-16s |\n", 
           "No", "Date", "Customer Name", "Product Type", "Product Name", 
           "Qty", "Price", "Total Price");
    printf("==========================================================================================================================\n");

    // Cetak data
    for (int i = 0; i < row; i++) {
        printf("| %-3d | %-2d/%-2d/%-6d %-20s %-20s %-18s %-5d Rp%-13.2lf Rp%-14.2lf |\n",
               i+1,
               data[i].tanggalTransaksiInfo.tanggalTransaksi,
               data[i].tanggalTransaksiInfo.bulanTransaksi,
               data[i].tanggalTransaksiInfo.tahunTransaksi,
               data[i].namaPelanggan,
               data[i].jenisProduk,
               data[i].namaProduk,
               data[i].jumlahProduk,
               data[i].hargaProduk,
               data[i].totalPembayaran);
    }
        
    printf("==========================================================================================================================\n\n");
}

// Cetak data dari file
void displayData(struct DataPenjualan data[]) {
    int totalRow = 0, row;
    char line[MAX_DATA];
    
    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL) {
        printf("Error opening file.\n");
        system("pause");
        return;
    }

    // Ambil data dari file
    while (fgets(line, sizeof(line), sales) != NULL) {
        sscanf(line, "%d,%d,%d,%[^,],%[^,],%[^,],%d,%lf,%lf\n",
               &data[totalRow].tanggalTransaksiInfo.tanggalTransaksi,
               &data[totalRow].tanggalTransaksiInfo.bulanTransaksi,
               &data[totalRow].tanggalTransaksiInfo.tahunTransaksi,
               data[totalRow].namaPelanggan,
               data[totalRow].jenisProduk,
               data[totalRow].namaProduk,
               &data[totalRow].jumlahProduk,
               &data[totalRow].hargaProduk,
               &data[totalRow].totalPembayaran);
        totalRow++;
    }

    if(totalRow > 0) {
        printf("Enter number of rows: "); scanf("%d", &row);
        if(row > totalRow) printFile(data, totalRow);
        else printFile(data, row);
    } else {
        printf("Data is still empty!!!\n");
    }
    
    fclose(sales);

    system("pause");
}

// Export data ke file baru
void exportData(struct DataPenjualan data[]) {
    int totalRow = 0;
    char filename[20];
    char line[MAX_DATA];
    system("cls");
    printf("Enter file name: "); scanf(" %[^\n]", filename);

    FILE *export = fopen(strcat(filename, ".txt"), "w");
    if (export == NULL) {
        printf("Error opening file.\n");
        system("pause");
        return;
    }

    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL) {
        printf("Error opening file.\n");
        system("pause");
        return;
    }

    // Copy dari file lama dan paste di file baru
    while (fgets(line, sizeof(line), sales) != NULL) {
        sscanf(line, "%d,%d,%d,%[^,],%[^,],%[^,],%d,%lf,%lf\n",
               &data[totalRow].tanggalTransaksiInfo.tanggalTransaksi,
               &data[totalRow].tanggalTransaksiInfo.bulanTransaksi,
               &data[totalRow].tanggalTransaksiInfo.tahunTransaksi,
               data[totalRow].namaPelanggan,
               data[totalRow].jenisProduk,
               data[totalRow].namaProduk,
               &data[totalRow].jumlahProduk,
               &data[totalRow].hargaProduk,
               &data[totalRow].totalPembayaran);

        fprintf(export, "%d,%d,%d,%s,%s,%s,%d,%.2lf,%.2lf\n",
                data[totalRow].tanggalTransaksiInfo.tanggalTransaksi,
                data[totalRow].tanggalTransaksiInfo.bulanTransaksi,
                data[totalRow].tanggalTransaksiInfo.tahunTransaksi,
                data[totalRow].namaPelanggan,
                data[totalRow].jenisProduk,
                data[totalRow].namaProduk,
                data[totalRow].jumlahProduk,
                data[totalRow].hargaProduk,
                data[totalRow].totalPembayaran);

        totalRow++;
    }

    fclose(export);
    fclose(sales);

    printf("Data successfully written to file %s!\n\n", filename);
    system("pause");
}

// Mneghitung total baris di file
int totalRowCount() {
    int count = 0;
    char line[MAX_DATA];
    
    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL) {
        printf("Error opening file.\n");
        system("pause");
        return 0;
    }

    while (fgets(line, sizeof(line), sales) != NULL) {
        count++;
    }

    fclose(sales);

    return count;
}

// Mengubah string ke huruf kecil
void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Fungsi membandingkan 2 tanggal
int compareDates(const void *a, const void *b) {
    const struct DataPenjualan *dateA = (const struct DataPenjualan *)a;
    const struct DataPenjualan *dateB = (const struct DataPenjualan *)b;

    int dateAValue = dateA->tanggalTransaksiInfo.tahunTransaksi * 10000 +
                     dateA->tanggalTransaksiInfo.bulanTransaksi * 100 +
                     dateA->tanggalTransaksiInfo.tanggalTransaksi;

    int dateBValue = dateB->tanggalTransaksiInfo.tahunTransaksi * 10000 +
                     dateB->tanggalTransaksiInfo.bulanTransaksi * 100 +
                     dateB->tanggalTransaksiInfo.tanggalTransaksi;

    return dateAValue - dateBValue;
}

// Fungsi membandingkan 2 nama
int compareNames(const void *a, const void *b) {
    const struct DataPenjualan *dataA = (const struct DataPenjualan *)a;
    const struct DataPenjualan *dataB = (const struct DataPenjualan *)b;

    char nameA[50], nameB[50];
    strcpy(nameA, dataA->namaPelanggan);
    strcpy(nameB, dataB->namaPelanggan);
    toLowercase(nameA);
    toLowercase(nameB);

    return strcmp(nameA, nameB);
}

// Fungsi membandingkan 2 tipe produk
int comparePrTypes(const void *a, const void *b) {
    const struct DataPenjualan *dataA = (const struct DataPenjualan *)a;
    const struct DataPenjualan *dataB = (const struct DataPenjualan *)b;

    char nameA[50], nameB[50];
    strcpy(nameA, dataA->jenisProduk);
    strcpy(nameB, dataB->jenisProduk);
    toLowercase(nameA);
    toLowercase(nameB);

    return strcmp(nameA, nameB);
}

// Fungsi membandingkan 2 nama produk
int comparePrName(const void *a, const void *b) {
    const struct DataPenjualan *dataA = (const struct DataPenjualan *)a;
    const struct DataPenjualan *dataB = (const struct DataPenjualan *)b;

    char nameA[50], nameB[50];
    strcpy(nameA, dataA->namaProduk);
    strcpy(nameB, dataB->namaProduk);
    toLowercase(nameA);
    toLowercase(nameB);

    return strcmp(nameA, nameB);
}

// Fungsi membandingkan 2 jumlah produk
int compareQty(const void *a, const void *b) {
    const struct DataPenjualan *dataA = (const struct DataPenjualan *)a;
    const struct DataPenjualan *dataB = (const struct DataPenjualan *)b;

    return dataA->jumlahProduk - dataB->jumlahProduk;
}

// Fungsi membandingkan 2 harga
int comparePrice(const void *a, const void *b) {
    const struct DataPenjualan *dataA = (const struct DataPenjualan *)a;
    const struct DataPenjualan *dataB = (const struct DataPenjualan *)b;

    return dataA->hargaProduk - dataB->hargaProduk;
}

// Fungsi membandingkan 2 total harga
int compareTotal(const void *a, const void *b) {
    const struct DataPenjualan *dataA = (const struct DataPenjualan *)a;
    const struct DataPenjualan *dataB = (const struct DataPenjualan *)b;

    return dataA->totalPembayaran - dataB->totalPembayaran;
}

// Membaca data dari file
void readData(struct DataPenjualan data[], int *totalRow) {
    char line[MAX_DATA];
    FILE *sales = fopen("sales.txt", "r");
    if (sales == NULL) {
        printf("Error opening file.\n");
        system("pause");
        return;
    }

    *totalRow = 0; 

    while (fgets(line, sizeof(line), sales) != NULL) {
        sscanf(line, "%d,%d,%d,%[^,],%[^,],%[^,],%d,%lf,%lf\n",
               &data[*totalRow].tanggalTransaksiInfo.tanggalTransaksi,
               &data[*totalRow].tanggalTransaksiInfo.bulanTransaksi,
               &data[*totalRow].tanggalTransaksiInfo.tahunTransaksi,
               data[*totalRow].namaPelanggan,
               data[*totalRow].jenisProduk,
               data[*totalRow].namaProduk,
               &data[*totalRow].jumlahProduk,
               &data[*totalRow].hargaProduk,
               &data[*totalRow].totalPembayaran);
        (*totalRow)++;
    }

    fclose(sales);
}

// Print data yang sudah di sort
void printSorted(struct DataPenjualan data[], int totalRow, int sortType) {
    if (sortType == 2) {
        // Reverse array jika opsi descending
        for (int i = 0; i < totalRow / 2; i++) {
            struct DataPenjualan temp = data[i];
            data[i] = data[totalRow - 1 - i];
            data[totalRow - 1 - i] = temp;
        }
    }

    int row;
    printf("Enter number of rows: "); scanf("%d", &row);
    if(row > totalRow) printFile(data, totalRow);
    else printFile(data, row);

    system("pause");
}

// Fungsi sort berdasarkan tanggal
void sortByDate(struct DataPenjualan data[], int totalRow, int sortType) {
    readData(data, &totalRow);
    qsort(data, totalRow, sizeof(struct DataPenjualan), compareDates);
    printSorted(data, totalRow, sortType);
}

// Fungsi sort berdasarkan nama
void sortByName(struct DataPenjualan data[], int totalRow, int sortType) {
    readData(data, &totalRow);
    qsort(data, totalRow, sizeof(struct DataPenjualan), compareNames);
    printSorted(data, totalRow, sortType);
}

// Fungsi sort berdasarkan jenis produk
void sortByPrType(struct DataPenjualan data[], int totalRow, int sortType) {
    readData(data, &totalRow);
    qsort(data, totalRow, sizeof(struct DataPenjualan), comparePrTypes);
    printSorted(data, totalRow, sortType);
}

// Fungsi sort berdasarkan nama produk
void sortByPrName(struct DataPenjualan data[], int totalRow, int sortType) {
    readData(data, &totalRow);
    qsort(data, totalRow, sizeof(struct DataPenjualan), comparePrName);
    printSorted(data, totalRow, sortType);
}

// Fungsi sort berdasarkan jumlah produk
void sortByQty(struct DataPenjualan data[], int totalRow, int sortType) {
    readData(data, &totalRow);
    qsort(data, totalRow, sizeof(struct DataPenjualan), compareQty);
    printSorted(data, totalRow, sortType);
}

// Fungsi sort berdasarkan harga
void sortByPrice(struct DataPenjualan data[], int totalRow, int sortType) {
    readData(data, &totalRow);
    qsort(data, totalRow, sizeof(struct DataPenjualan), comparePrice);
    printSorted(data, totalRow, sortType);
}

// Fungsi sort berdasarkan total harga
void sortByTotal(struct DataPenjualan data[], int totalRow, int sortType) {
    readData(data, &totalRow);
    qsort(data, totalRow, sizeof(struct DataPenjualan), compareTotal);
    printSorted(data, totalRow, sortType);
}

// Sort Data 
void sortData(struct DataPenjualan data[]) {
    int optionSort, sortType;
    system("cls");
    printf("============================\n");
    printf("|      Sort Data Menu      |\n");
    printf("============================\n"); 
    printf("| 1. Sort by date          |\n");
    printf("| 2. Sort by name          |\n");
    printf("| 3. Sort by product type  |\n");
    printf("| 4. Sort by product name  |\n");
    printf("| 5. Sort by quantity      |\n");
    printf("| 6. Sort by price         |\n");
    printf("| 7. Sort by total price   |\n");
    printf("| 8. Go back               |\n");
    printf("============================\n");
    printf("Select menu >> "); 
    scanf("%d", &optionSort);
    
    menuValidation(&optionSort, 1, 8);

    if(optionSort == 8) return;

    printf("\nSort Ascending or Descending?\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Select menu >> ");
    scanf("%d", &sortType);

    menuValidation(&sortType, 1, 2);

    int totalRow = totalRowCount();

    if(totalRow < 1) {
        printf("Data is still empty!!!\n");
        system("pause");
        return;
    }

    if (optionSort == 1) {
        sortByDate(data, totalRow, sortType);
    } else if (optionSort == 2) {
        sortByName(data, totalRow, sortType);
    } else if (optionSort == 3) {
        sortByPrType(data, totalRow, sortType);
    } else if (optionSort == 4) {
        sortByPrName(data, totalRow, sortType);
    } else if (optionSort == 5) {
        sortByQty(data, totalRow, sortType);
    } else if (optionSort == 6) {
        sortByPrice(data, totalRow, sortType);
    } else if (optionSort == 7) {
        sortByTotal(data, totalRow, sortType);
    }
}

// Print data yang dicari
void printSearch(struct DataPenjualan data[], int foundAt[], int j) {
    printf("==========================================================================================================================\n");
    printf("| %-3s | %-12s %-20s %-20s %-18s %-5s %-15s %-16s |\n", 
           "No", "Date", "Customer Name", "Product Type", "Product Name", 
           "Qty", "Price", "Total Price");
    printf("==========================================================================================================================\n");
        
    for (int i = 0; i < j; i++) {
        int index = foundAt[i];
        printf("| %-3d | %-2d/%-2d/%-6d %-20s %-20s %-18s %-5d Rp%-13.2lf Rp%-14.2lf |\n",
               i+1,
               data[index].tanggalTransaksiInfo.tanggalTransaksi,
               data[index].tanggalTransaksiInfo.bulanTransaksi,
               data[index].tanggalTransaksiInfo.tahunTransaksi,
               data[index].namaPelanggan,
               data[index].jenisProduk,
               data[index].namaProduk,
               data[index].jumlahProduk,
               data[index].hargaProduk,
               data[index].totalPembayaran);
    }

    printf("==========================================================================================================================\n\n");
}

// Fungsi search berdasarkan tanggal
void searchDate(struct DataPenjualan data[]) {
    int hari, bulan, tahun;
    int totalRow = totalRowCount();
    int foundAt[MAX_DATA];
    int j = 0;
    FILE *fl = fopen("sales.txt", "r");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }
    readData(data, &totalRow);

    do {
        printf("What data do you want to find? (DD MM YYYY): ");
        if (scanf("%d %d %d", &hari, &bulan, &tahun) != 3 ||
            hari < 1 || hari > 31 || bulan < 1 ||
            bulan > 12 || tahun < 1900 || tahun > 2100) {
            printf("Invalid date! Please enter a valid date.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);

    int matchFound = 0;

    for (int i = 0; i < totalRow; i++) {
        if (hari == data[i].tanggalTransaksiInfo.tanggalTransaksi &&
            bulan == data[i].tanggalTransaksiInfo.bulanTransaksi &&
            tahun == data[i].tanggalTransaksiInfo.tahunTransaksi) {
            foundAt[j] = i;
            j++;
            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("\nNo matching data found for the specified date.\n\n");
    } else {
        system("cls");
        printf("\nMatching data found for the specified date:\n");
        printSearch(data, foundAt, j);
    }

    system("pause");
}

// Fungsi search berdasarkan nama
void searchName(struct DataPenjualan data[]) {
    char nama[50];
    int totalRow = totalRowCount();
    int foundAt[MAX_DATA];
    int j = 0;
    FILE *fl = fopen("sales.txt", "r");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }
    readData(data, &totalRow);

    printf("What data do you want to find? : ");
    scanf(" %[^\n]", nama);
    
    int matchFound = 0;

    for (int i = 0; i < totalRow; i++) {
        char target[50];
        strcpy(target, data[i].namaPelanggan);
        toLowercase(target);
        toLowercase(nama);
        if (strcmp(nama, target) == 0) {
            foundAt[j] = i;
            j++;
            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("\nNo matching data found for the specified name.\n\n");
    } else {
        system("cls");
        printf("\nMatching data found for the specified name:\n");
        printSearch(data, foundAt, j);
    }

    system("pause");
}

// Fungsi search berdasarkan jenis produk
void searchPrType(struct DataPenjualan data[]) {
    char type[50];
    int totalRow = totalRowCount();
    int foundAt[MAX_DATA];
    int j = 0;
    FILE *fl = fopen("sales.txt", "r");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }
    readData(data, &totalRow);

    printf("What type of product do you want to find? : ");
    scanf(" %[^\n]", type);
    
    int matchFound = 0;

    for (int i = 0; i < totalRow; i++) {
        char target[50];
        strcpy(target, data[i].jenisProduk);
        toLowercase(target);
        toLowercase(type);
        if (strcmp(type, target) == 0) {
            foundAt[j] = i;
            j++;
            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("\nNo matching data found for the specified product type.\n\n");
    } else {
        system("cls");
        printf("\nMatching data found for the specified product type:\n");
        printSearch(data, foundAt, j);
    }

    system("pause");
}

// Fungsi search berdasarkan nama produk
void searchPrName(struct DataPenjualan data[]) {
    char nama[50];
    int totalRow = totalRowCount();
    int foundAt[MAX_DATA];
    int j = 0;
    FILE *fl = fopen("sales.txt", "r");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }
    readData(data, &totalRow);

    printf("What data do you want to find? : ");
    scanf(" %[^\n]", nama);
    
    int matchFound = 0;

    for (int i = 0; i < totalRow; i++) {
        char target[50];
        strcpy(target, data[i].namaProduk);
        toLowercase(target);
        toLowercase(nama);
        if (strcmp(nama, target) == 0) {
            foundAt[j] = i;
            j++;
            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("\nNo matching data found for the specified product name.\n\n");
    } else {
        system("cls");
        printf("\nMatching data found for the specified product name:\n");
        printSearch(data, foundAt, j);
    }

    system("pause");
}

// Fungsi search berdasarkan jumlah produk
void searchQty(struct DataPenjualan data[]) {
    int quantity;
    int totalRow = totalRowCount();
    int foundAt[MAX_DATA];
    int j = 0;
    FILE *fl = fopen("sales.txt", "r");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }
    readData(data, &totalRow);

    do {
        printf("Input quantity : ");
        if (scanf("%d", &quantity) != 1 || quantity < 0) {
            printf("Invalid input! Please enter a valid input.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);

    int matchFound = 0;

    for (int i = 0; i < totalRow; i++) {
        if (quantity == data[i].jumlahProduk) {
            foundAt[j] = i;
            j++;
            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("\nNo matching data found for the specified quantity.\n\n");
    } else {
        system("cls");
        printf("\nMatching data found for the specified quantity:\n");
        printSearch(data, foundAt, j);
    }

    system("pause");
}

// Fungsi search berdasarkan harga
void searchPrice(struct DataPenjualan data[]) {
    double price;
    int totalRow = totalRowCount();
    int foundAt[MAX_DATA];
    int j = 0;
    FILE *fl = fopen("sales.txt", "r");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }
    readData(data, &totalRow);

    do {
        printf("Input price : ");
        if (scanf("%lf", &price) != 1 || price < 0) {
            printf("Invalid input! Please enter a valid input.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);

    int matchFound = 0;

    for (int i = 0; i < totalRow; i++) {
        if (price == data[i].hargaProduk) {
            foundAt[j] = i;
            j++;
            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("\nNo matching data found for the specified price.\n\n");
    } else {
        system("cls");
        printf("\nMatching data found for the specified price:\n");
        printSearch(data, foundAt, j);
    }

    system("pause");
}

// Fungsi search berdasarkan total harga
void searchTotal(struct DataPenjualan data[]) {
    double total;
    int totalRow = totalRowCount();
    int foundAt[MAX_DATA];
    int j = 0;
    FILE *fl = fopen("sales.txt", "r");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }
    readData(data, &totalRow);

    do {
        printf("Input total price : ");
        if (scanf("%lf", &total) != 1 || total < 0) {
            printf("Invalid input! Please enter a valid input.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);

    int matchFound = 0;

    for (int i = 0; i < totalRow; i++) {
        if (total == data[i].totalPembayaran) {
            foundAt[j] = i;
            j++;
            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("\nNo matching data found for the specified total price.\n\n");
    } else {
        system("cls");
        printf("\nMatching data found for the specified total price:\n");
        printSearch(data, foundAt, j);
    }

    system("pause");
}

// Search Data
void searchData(struct DataPenjualan data[]) {
    int optionSearch;
    system("cls");
    printf("============================\n");
    printf("|     Search Data Menu     |\n");
    printf("============================\n");
    printf("| 1. Search date           |\n");
    printf("| 2. Search name           |\n");
    printf("| 3. Search product type   |\n");
    printf("| 4. Search product name   |\n");
    printf("| 5. Search quantity       |\n");
    printf("| 6. Search price          |\n");
    printf("| 7. Search total price    |\n");
    printf("| 8. Go back               |\n");
    printf("============================\n");
    printf("Select menu >> ");
    scanf("%d", &optionSearch);
    
    menuValidation(&optionSearch, 1, 8);
    
    if(optionSearch == 8) return;

    if (optionSearch == 1) {
        searchDate(data);
    } else if (optionSearch == 2) {
        searchName(data);
    } else if (optionSearch == 3) {
        searchPrType(data);
    } else if (optionSearch == 4) {
        searchPrName(data);
    } else if (optionSearch == 5) {
        searchQty(data);
    } else if (optionSearch == 6) {
        searchPrice(data);
    } else if (optionSearch == 7) {
        searchTotal(data);
    }
}

// Edit Data
void editData(struct DataPenjualan data[]) {
    int optionEdit;
    int totalRow = totalRowCount();
    FILE *fl = fopen("sales.txt", "r");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Menyimpan data ke struct
    readData(data, &totalRow);

    system("cls");
    printf("Choose a data to edit :\n");
    printf("==========================================================================================================================\n");
    printf("| %-3s | %-12s %-20s %-20s %-18s %-5s %-15s %-16s |\n", 
           "No", "Date", "Customer Name", "Product Type", "Product Name", 
           "Qty", "Price", "Total Price");
    printf("==========================================================================================================================\n");

    // Cetak data
    for (int i = 0; i < totalRow; i++) {
        printf("| %-3d | %-2d/%-2d/%-6d %-20s %-20s %-18s %-5d Rp%-13.2lf Rp%-14.2lf |\n",
               i+1,
               data[i].tanggalTransaksiInfo.tanggalTransaksi,
               data[i].tanggalTransaksiInfo.bulanTransaksi,
               data[i].tanggalTransaksiInfo.tahunTransaksi,
               data[i].namaPelanggan,
               data[i].jenisProduk,
               data[i].namaProduk,
               data[i].jumlahProduk,
               data[i].hargaProduk,
               data[i].totalPembayaran);
    }
        
    printf("==========================================================================================================================\n\n");

    fclose(fl);

    printf("Select data >> "); scanf("%d", &optionEdit);

    system("cls");
    do {
        printf("New Transaction Date (DD MM YYYY): ");
        if (scanf("%d %d %d", &data[optionEdit-1].tanggalTransaksiInfo.tanggalTransaksi,
                  &data[optionEdit-1].tanggalTransaksiInfo.bulanTransaksi,
                  &data[optionEdit-1].tanggalTransaksiInfo.tahunTransaksi) != 3 ||
            data[optionEdit-1].tanggalTransaksiInfo.tanggalTransaksi < 1 ||
            data[optionEdit-1].tanggalTransaksiInfo.tanggalTransaksi > 31 ||
            data[optionEdit-1].tanggalTransaksiInfo.bulanTransaksi < 1 ||
            data[optionEdit-1].tanggalTransaksiInfo.bulanTransaksi > 12 ||
            data[optionEdit-1].tanggalTransaksiInfo.tahunTransaksi < 1900 ||
            data[optionEdit-1].tanggalTransaksiInfo.tahunTransaksi > 2100) {
            
            printf("Invalid date! Please enter a valid date.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);
    printf("\n");

    printf("Customer Name: ");
    scanf(" %[^\n]", data[optionEdit-1].namaPelanggan);
    printf("\n");

    int optionType;
    productType(&optionType, &data[optionEdit-1]);

    if(optionType == 1) productName1(&data[optionEdit-1]);
    else if(optionType == 2) productName2(&data[optionEdit-1]);
    else if(optionType == 3) productName3(&data[optionEdit-1]);
    else if(optionType == 4) productName4(&data[optionEdit-1]);
    else if(optionType == 5) productName5(&data[optionEdit-1]);
    else if(optionType == 6) productName6(&data[optionEdit-1]);

    printf("Input new quantity: ");
    scanf(" %d", &data[optionEdit-1].jumlahProduk);
    printf("\n");

    data[optionEdit-1].totalPembayaran = data[optionEdit-1].jumlahProduk *
                                         data[optionEdit-1].hargaProduk;

    fl = fopen("sales.txt", "w");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for(int i = 0; i < totalRow; i++) {
        fprintf(fl, "%d,%d,%d,%s,%s,%s,%d,%.2lf,%.2lf\n",
            data[i].tanggalTransaksiInfo.tanggalTransaksi,
            data[i].tanggalTransaksiInfo.bulanTransaksi,
            data[i].tanggalTransaksiInfo.tahunTransaksi,
            data[i].namaPelanggan,
            data[i].jenisProduk,
            data[i].namaProduk,
            data[i].jumlahProduk,
            data[i].hargaProduk,
            data[i].totalPembayaran);
    }
    
    fclose(fl);

    printf("\nData successfully updated.\n\n");

    system("pause");
}

// Delete Data
void deleteData(struct DataPenjualan data[]) {
    int optionDelete;
    int totalRow = totalRowCount();
    FILE *fl = fopen("sales.txt", "r");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }
    readData(data, &totalRow);

    system("cls");
    printf("Choose a data to delete :\n");
    printf("======================================================================================================================\n");
    printf("| %-3s | %-12s %-16s %-20s %-18s %-5s %-15s %-16s |\n", 
           "No", "Date", "Customer Name", "Product Type", "Product Name", 
           "Qty", "Price", "Total Price");
    printf("======================================================================================================================\n");

    for (int i = 0; i < totalRow; i++) {
        printf("| %-3d | %-2d/%-2d/%-6d %-16s %-20s %-18s %-5d Rp%-13.2lf Rp%-14.2lf |\n",
               i+1,
               data[i].tanggalTransaksiInfo.tanggalTransaksi,
               data[i].tanggalTransaksiInfo.bulanTransaksi,
               data[i].tanggalTransaksiInfo.tahunTransaksi,
               data[i].namaPelanggan,
               data[i].jenisProduk,
               data[i].namaProduk,
               data[i].jumlahProduk,
               data[i].hargaProduk,
               data[i].totalPembayaran);
    }
        
    printf("======================================================================================================================\n\n");

    fclose(fl);

    printf("Select data >> "); scanf("%d", &optionDelete);

    for(int i = optionDelete-1; i < totalRow-1; i++) {
        data[i] = data[i+1];
    }

    fl = fopen("sales.txt", "w");
    if (fl == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for(int i = 0; i < totalRow-1; i++) {
        fprintf(fl, "%d,%d,%d,%s,%s,%s,%d,%.2lf,%.2lf\n",
            data[i].tanggalTransaksiInfo.tanggalTransaksi,
            data[i].tanggalTransaksiInfo.bulanTransaksi,
            data[i].tanggalTransaksiInfo.tahunTransaksi,
            data[i].namaPelanggan,
            data[i].jenisProduk,
            data[i].namaProduk,
            data[i].jumlahProduk,
            data[i].hargaProduk,
            data[i].totalPembayaran);
    }
    
    fclose(fl);

    printf("\nData successfully deleted.\n\n");

    system("pause");
}

// Fitur tambahan untuk edit data atau hapus data
void manageData(struct DataPenjualan data[]) {
    int optionManage;
    system("cls");
    printf("============================\n");
    printf("|     Manage Data Menu     |\n");
    printf("============================\n");
    printf("| 1. Edit data             |\n");
    printf("| 2. Delete data           |\n");
    printf("| 3. Go back               |\n");
    printf("============================\n");
    printf("Select menu >> "); 
    scanf("%d", &optionManage);
    
    menuValidation(&optionManage, 1, 3);

    if (optionManage == 1) {
        editData(data);
    } else if (optionManage == 2) {
        deleteData(data);
    }
}

// Opsi untuk menutup aplikasi
int exitProgram() {
    char decision;
    
    printf("Are you sure you want to quit the application? (y/n) ");
    scanf(" %c", &decision);

    decisionValidation(&decision);

    if (decision == 'y' || decision == 'Y') {
        system("cls");
        printf(BOLD "Exiting the app" RESET "\n");
        printf(BOLD "Thankyou for using this app :)" RESET "\n");
        Sleep(4000);
        return 0;
    } else {
        return 1;
    }
}

// Main function
int main() {
    int option;
    struct DataPenjualan data[MAX_DATA];
    int count = 0;

    intro();

    while (1) {
        display(&option);

        if (option == 1) {
            inputData(data, &count);
        } else if (option == 2) {
            displayData(data);            
        } else if (option == 3) {
            sortData(data);
        } else if (option == 4) {
            searchData(data);
        } else if (option == 5) {
            exportData(data);
        } else if (option == 6) {
            manageData(data);
        } else if (option == 7) {
            if (!exitProgram()) return 0;
        }
    }
    
    return 0;
}