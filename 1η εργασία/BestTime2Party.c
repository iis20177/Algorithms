#include <stdio.h>
#include <stdlib.h>

int main(){
    int size, i, j, maxi1, maxi2;
    printf("Give the number of the bands: ");
    scanf("%d", &size);
    float arrival[size], departure[size], value;
    char name[size][500];
    int count[size], max1, max2;
    for (i=0; i<size; i++)
        {
            count[i] = 0;
        }
    for (i=0; i<size; i++)
        {
            printf("Give the name of band %d: ", i+1);
            scanf(" %[^\n]s", &name[i]);
            printf("Give the time of arrival of band %d: ", i+1);
            scanf("%f", &arrival[i]);
            printf("Give the time of departure of band %d: ", i+1);
            scanf("%f", &departure[i]);
        }
    for (j=0; j<size; j++)
        {
            value = arrival[j];
            for (i=0; i<size; i++)
                {
                    if (arrival[i] == value)
                        {
                            count[i]++;
                        }
                }
        }
    max1 = count[0];
    maxi1 = 0;
    for (i=1; i<(size+1)/2; i++)
        {
            if (max1 < count[i])
                {
                    max1 = count[i];
                    maxi1 = i;
                }
        }
    max2 = count[size/2];
    maxi2 = size/2;
    for (i=(size+1)/2; i<size; i++)
        {
            if (max2 < count[i])
                {
                    max2 = count[i];
                    maxi2 = i;
                }
        }
    if (count[maxi1]>=count[maxi2])
        {
            count[maxi1] = count[maxi2];
            max1 = count[0];
            maxi1 = 0;
            for (i=1; i<size/2; i++)
                {
                    if (max1 < count[i])
                        {
                            max1 = count[i];
                            maxi1 = i;
                        }
                }
        }
    else
        {
            count[maxi2] = count[maxi1];
            max2 = count[size/2];
            maxi2 = size/2;
                for (i=(size+1)/2; i<size; i++)
                    {
                        if (max2 <= count[i])
                            {
                                max2 = count[i];
                                maxi2 = i;
                            }
                    }
        }
    if (max1==max2)
        {
            printf("The best time to go to the xmas bazaar is: %.2f or %.2f", arrival[maxi2], arrival[maxi1]);
        }
    else
        {
            printf("The best time to go to the xmas bazaar is: %.2f ", arrival[maxi1]);
        }
    return 0;
}
