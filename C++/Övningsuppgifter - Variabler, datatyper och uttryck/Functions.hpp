//
// Created by Chu Ha Thanh on 2024-11-17.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int wordSorter(std::string originalFilePath, std::string shortWordsFilePath, std::string longWordsFilePath, int slitFromLength);
void partition( const std::string original[], int originalSize, std::string shortWords[], std::string longWords[], int splitFromLength);
void getWordPartitionSize( const std::string original[], int nrOfWords, int splitFromLength, int& numberOfShortWords, int& numberOfLongWords);
void sort(std::string words[], int size);

#endif //FUNCTIONS_H
