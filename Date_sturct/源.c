#include"Data_Struct.h"

#include"math.h"

int main()
{
    int nunber = 0;

    int i = 1000;

    BinTree* T = NULL;
    while (i--) {
    
        T = BinTree_BanlaceInsert(T, rand());

       
    }

     BinTree_visualization(T);
    
}