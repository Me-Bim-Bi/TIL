//
// Created by Chu Ha Thanh on 2024-11-17.
//
#include "Functions.hpp"
#include <iostream>
#include <string>

using namespace std;

/**
*originalFilePath - detta är namnet på filen som ska läsas
*shortWordsFilePath - detta är namnet på filen på vilken de korta orden ska skrivas. Om filen inte finns ska den skapas
*longWordsFilePath -  detta är namnet på filen på vilken de långa orden ska skrivas. Om filen inte finns ska den skapas
*splitFromLength - gränsen mellan vad som anses vara ett kort ord  och ett långt ord. Ett långt ord har längden från och med detta värde.*/

int wordSorter(std::string originalFilePath, std::string shortWordsFilePath, std::string longWordsFilePath, int slitFromLength)
{

    return 0;
}

/*ska ta in arrayen med ord som ska läsas och arrayens längd,
 *samt två redan allokerade arrayer att skriva korta respektive långa ord till.
 *Dessa arrayer förväntas vara allokerade med exakt storlek att fylla de ord som behövs*/
void partition( const std::string original[], int originalSize, std::string shortWords[], std::string longWords[], int splitFromLength) {

}


/*ska ta in en existerande array,
 *arrayens storlek samt gränsen på längden mellan korta och långa ord.
 *Funktion ska ta reda på antalet långa och korta ord som finns i arrayen,
 *och leverera dessa två värden med hjälp av utparametrar*/
void getWordPartitionSize( const std::string original[], int nrOfWords, int splitFromLength, int& numberOfShortWords, int& numberOfLongWords)
{

}

/*ska ta in en array med ord och arrayens storlek.
 *Funktionen sorterar arrayen växande*/
void sort(std::string words[], int size);
{

}

