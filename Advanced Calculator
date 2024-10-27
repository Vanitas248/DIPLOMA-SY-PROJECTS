#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

void decimalToBinary(int n, char binary[]) {
    int i = 0;
    while (n > 0) {
        binary[i++] = (n % 2) + '0';
        n /= 2;
    }
    binary[i] = '\0';
    strrev(binary);
}

int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int base = 1;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

void decimalToHex(int n, char hex[]) {
    int i = 0;
    char hexDigits[] = "0123456789ABCDEF";
    while (n > 0) {
        hex[i++] = hexDigits[n % 16];
        n /= 16;
    }
    hex[i] = '\0';
    strrev(hex);
}

int hexToDecimal(char hex[]) {
    int decimal = 0;
    for (int i = 0; i < strlen(hex); i++) {
        int value;
        if (hex[i] >= '0' && hex[i] <= '9') {
            value = hex[i] - '0';
        } else {
            value = hex[i] - 'A' + 10;
        }
        decimal = decimal * 16 + value;
    }
    return decimal;
}

void hexToBinary(char hex[], char binary[]) {
    int decimal = hexToDecimal(hex);
    decimalToBinary(decimal, binary);
}

void binaryToHex(char binary[], char hex[]) {
    int decimal = binaryToDecimal(binary);
    decimalToHex(decimal, hex);
}

int main() {
    int choice;
    char binary[32], hex[32];

    cout << "Advanced Calculator" << endl;
    cout << "1. Decimal to Binary" << endl;
    cout << "2. Binary to Decimal" << endl;
    cout << "3. Decimal to Hexadecimal" << endl;
    cout << "4. Hexadecimal to Decimal" << endl;
    cout << "5. Binary to Hexadecimal" << endl;
    cout << "6. Hexadecimal to Binary" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "Enter a decimal number: ";
        cin >> n;
        decimalToBinary(n, binary);
        cout << "Binary: " << binary << endl;
    } else if (choice == 2) {
        cout << "Enter a binary number: ";
        cin >> binary;
        cout << "Decimal: " << binaryToDecimal(binary) << endl;
    } else if (choice == 3) {
        int n;
        cout << "Enter a decimal number: ";
        cin >> n;
        decimalToHex(n, hex);
        cout << "Hexadecimal: " << hex << endl;
    } else if (choice == 4) {
        cout << "Enter a hexadecimal number: ";
        cin >> hex;
        cout << "Decimal: " << hexToDecimal(hex) << endl;
    } else if (choice == 5) {
        cout << "Enter a binary number: ";
        cin >> binary;
        binaryToHex(binary, hex);
        cout << "Hexadecimal: " << hex << endl;
    } else if (choice == 6) {
        cout << "Enter a hexadecimal number: ";
        cin >> hex;
        hexToBinary(hex, binary);
        cout << "Binary: " << binary << endl;
    }

    getch();
    return 0;
}
