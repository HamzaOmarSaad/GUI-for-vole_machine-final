// mainMemory.cpp
#include "mainMemorey.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>

// Default constructor
mainMemory::mainMemory() {
    maxSize = 0;  // Initialize maxSize to zero
}

// Constructor implementation
mainMemory::mainMemory(int m) {
    maxSize = m;
    memory.resize(m);  // Resize the QVector to the maximum size

    for (int i = 0; i < m; ++i) {
        memory[i].hex = "00";  // Initialize each memory unit
    }
    memoryUnit::count = -1;
}



void mainMemory::addData(QString input,int &currentInstructionPointer) {
    QVector<QString> hexValues;

    // hexValues.push_back(input.mid(0,2));
    // hexValues.push_back(input.mid(2,4));



        for (size_t i = 0; i < input.size(); i += 2) {
            QString hexByte = input.mid(i, 2);
            if (hexByte.size() == 2) {
                hexValues.push_back(hexByte);
            } else {
                return;
            }
        }


        for (size_t i = 0; i < hexValues.size(); i++) {
            memory[currentInstructionPointer+i].hex = hexValues[i];
            memory[currentInstructionPointer+i].binary = hexToBinary(hexValues[i]);
        }

        if (hexValues.size() % 2 != 0) {
           // QDebug << "The hex code does not form complete bytes. Please check your input." << std::endl;
        }

        currentInstructionPointer +=2;

}



void mainMemory::clearData() {
    memory.clear();  // Clear the QVector
    memory.resize(maxSize);  // Resize it back to the original size
    for (int i = 0; i < maxSize; ++i) {
        memory[i].hex = "00";  // Reinitialize each memory unit
    }
    memoryUnit::count = -1;
}

int mainMemory::getSize()
{
    return memory.size();

}
