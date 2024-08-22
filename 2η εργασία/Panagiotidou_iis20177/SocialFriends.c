#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, sum[13], k, count = 0, max, pos, temp;
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
    for (i=0; i<13; i++)
        {
            sum[i] = 0;
        }
    for (i=0; i<13; i++)
        {
            for (j=0; j<13; j++)
                {
                    if (Friends[i][j] == 1)
                        {
                            sum[i]++;
                        }

                }
        }
     for (k=0; k<13; k++)
        {
            for (i=0; i<13; ++i)
                {
                    for (j=i+1; j<13; ++j)
                    {
                        if (sum[i] < sum[j] && sum[i] > 2)
                        {
                            temp = sum[i];
                            sum[i] = sum[j];
                            sum[j] = temp;
                        }
                    }
                }
            for (i=0; i<13; i++)
                {
                    sum[i] = pos;
                    for (j=0; j<13; j++)
                        {
                            if (Friends[pos][j] == 1)
                                {
                                    Friends[pos][j] = -1;
                                    Friends[j][pos] = -1;
                                }
                        }
                }
            for (i=0; i<13; i++)
                {
                    sum[i] = 0;
                }
            for (i=0; i<13; i++)
                {
                    for (j=0; j<13; j++)
                        {
                            if (Friends[i][j] == 1)
                                {
                                    sum[i]++;
                                }

                        }
                }
        }
        for (j=0; j<13; j++)
            {
                if (sum[j] == 0)
                    {
                        count++;
                    }
            }
        printf("Plithos twn atomwn pou tha pane sto party: %d", count);
        for (i=0; i<13; i++)
            {
                if (sum[i] == 0)
                    {
                        printf("\n%s", Names[i]);
                    }
            }
    return 0;
}
