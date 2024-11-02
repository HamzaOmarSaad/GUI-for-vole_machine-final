#include "helperFunctions.h"
#include <QString>
#include <QDebug>
#include <QBitArray>

// Function to convert hex to binary
QString hexToBinary(const QString& hex) {
    QString binary;
    for (QChar hexChar : hex) {
        // Convert each hex character to an integer
        int value = (hexChar.isDigit()) ? hexChar.digitValue() : (hexChar.toUpper().unicode() - 'A' + 10);

        // Convert the integer to a binary string (4 bits)
        QString binarySegment = QString("%1").arg(value, 4, 2, QChar('0'));  // Pad to 4 bits
        binary += binarySegment;
    }
    return binary;
}

// Function to convert a binary string to an integer
int binaryStringToInt(const QString& binaryString) {
    return binaryString.toInt(nullptr, 2);  // Convert binary string to an int (base 2)
}

// Function to convert an integer to a binary string
QString intToBinaryString(int num) {
    return QString("%1").arg(num, 8, 2, QChar('0'));  // Convert integer to binary with 8-bit width
}

// Function to convert an integer to hex (with width)
QString toHex(int number, int width) {
    return QString("%1").arg(number, width, 16, QChar('0')).toUpper();  // Convert to hex with padding
}

// Function to convert a hexadecimal string to an integer
int hexToInt(const QString& hexStr) {
    bool ok;
    int decimalValue = hexStr.toInt(&ok, 16);
    if (!ok) {
        qDebug() << "Invalid hexadecimal input.";
        return -1;
    }
    return decimalValue;
}

// Function to add two binary numbers using two's complement
QString addTwoComplement(const QString &bin1, const QString &bin2) {
    // Convert the binary strings to integers
    int num1 = bin1.toInt(nullptr, 2);
    int num2 = bin2.toInt(nullptr, 2);
    int sum = num1 + num2;

    // Use 8 bits for the two's complement representation
    QString result = QString("%1").arg(sum & 0xFF, 8, 2, QChar('0'));  // Mask to get the last 8 bits
    return result;
}


double  binaryTodouble(QString B){

    QString sign=B[0]=='1'?"-":"+";
    QString Exspo=B.mid(1, 3);
    QString mantsea=B.mid(4, 7);
    int exspo=0;

    exspo=binaryStringToInt(Exspo)-4;


    if(exspo>0){
        mantsea.insert(exspo,".");
    } else{
        for(int i=exspo;i<0;i++){
            mantsea.insert(0,"0");

        };
        mantsea.insert(0,".");
        mantsea.insert(0,"0");

    }
    return sign=="-"? -binaryToDouble(mantsea):binaryToDouble(mantsea);
}


double binaryToDouble(const QString& binary) {
    size_t pointPos = binary.indexOf('.'); // Locate the decimal point
    double result = 0.0;


    for (int i = 0; i < pointPos; ++i) {
        if (binary[i] == '1') {
            result += pow(2, pointPos - i - 1);
        }
    }

    // Convert fractional part
    for (int i = pointPos + 1; i < binary.size(); ++i) {
        if (binary[i] == '1') {
            result += pow(2, -(int)(i - pointPos));
        }
    }

    return result;
}


QString intTo3BitBinary(int number) {
    QString binary = "";
    for (int i = 2; i >= 0; --i) {
        binary += (number & (1 << i)) ? "1" : "0";
    }
    return binary;
}
QString integerToBinary(int intPart) {
    QString intBinary = "";
    if (intPart == 0) return "0";
    while (intPart > 0) {
        intBinary = QString::number(intPart % 2) + intBinary;
        intPart /= 2;
    }
    return intBinary;
}

QString fractionalToBinary(double fracPart, int precision ) {

    QString fracBinary ;
    for (int i = 0; i < precision && fracPart > 0; ++i) {
        fracPart *= 2;
        if (fracPart >= 1) {
            fracBinary += "1";
            fracPart -= 1;
        } else {
            fracBinary += "0";
        }
    }

    return fracBinary;
}
QString doubleToBinary(double x) {

    QString sign = (x < 0) ? "1" : "0";
    x = abs(x);

    int intPart = static_cast<int>(x);
    double fracPart = x - intPart;

    QString intpart=integerToBinary(intPart);
    QString exsponant=intTo3BitBinary(intpart.length()+4);
    QString frac =fractionalToBinary(fracPart);

    QString mantesa =integerToBinary(intPart) +((fracPart == 0) ? "0" : fractionalToBinary(fracPart));
    if(exsponant.length()<3){

        for (int i = 0; i < 3-exsponant.length(); ++i) {
            exsponant="0"+exsponant;
        }
    }
    if(mantesa.length()<4){

        for (int i = 0; i < 4-mantesa.length(); ++i) {
            mantesa="0"+mantesa;
        }
    }

    return sign+ exsponant+mantesa.mid(mantesa.length()-4);
}

