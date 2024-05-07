//Phoorin Chinphuad 66070501043
//Tower of Hanoi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void TowerOfHanoI(int N, char source, char dest, char aux);
// dest = destination & aux = auxiliary

int main(){
    int N;
    scanf(" %d", &N);
    int moves = pow(2, N)-1;

    TowerOfHanoI(N, 'A', 'C', 'B');
    printf("Total moves: %d\n" , moves);
    return 0;
}

void TowerOfHanoI(int N, char source, char dest, char aux){
    if( N==1 ){
        printf("Move disk %d from %c to %c\n", N, source, dest);
        return ;
    }

    TowerOfHanoI(N-1, source, aux, dest);
    printf("Move disk %d from %c to %c\n", N, source, dest);
    TowerOfHanoI(N-1, aux, dest, source);
}

