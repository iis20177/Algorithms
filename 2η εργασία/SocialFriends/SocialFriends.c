#include <stdio.h>
#include <stdlib.h>

void Function(int array[13][13], int start[]);

int main(){
    int i, j, sum[13], k, count = 0, max, pos;
    int Friends[13][13] =  {{0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
                            {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}};

    char Names[13][13] = {  "Nikos",
                            "Giannis",
                            "Akis",
                            "Zoi",
                            "Lydia",
                            "Manos",
                            "Eva",
                            "Alexandros",
                            "Maria",
                            "Eleni",
                            "Petros",
                            "Dhmhtris",
                            "Anna"  };
    Function(Friends, &sum);
    for (k=0; k<13; k++)
    {
        max = sum[0];
        for (j=1; j<13; j++)
            {
                if (max < sum[j])
                    {
                        max = sum[j];
                        pos = j;
                    }
            }
        for (i=0; i<13; i++)
            {
                for (j=0; j<13; j++)
                    {
                        if (Friends[pos][j] == 1)
                            {
                                Friends[pos][j] = 0;
                                Friends[j][pos] = 0;
                            }
                    }
            }
    }
    Function(Friends, &sum);
    for (j=0; j<13; j++)
        {
            if (sum[j] < 2)
                {
                    count++;
                }
        }
    printf("Plithos twn atomwn pou tha pane sto party: %d", count);
    for (i=0; i<13; i++)
        {
            if (sum[i] < 2)
            {
                printf("\n%s", Names[i]);
            }
        }
    return 0;
}

void Function(int array[13][13], int start[]){
    int a, b;
    for (a=0; a<13; a++)
        {
            start[a] = 0;
        }
    for (a=0; a<13; a++)
        {
            for (b=0; b<13; b++)
                {
                    if (array[a][b] == 1)
                        {
                            start[a]++;
                        }
                }
        }
}
