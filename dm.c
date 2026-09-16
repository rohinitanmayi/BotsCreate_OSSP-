#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *p;

    printf("enter the size of dynamic memory\n");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("%d element\n", (i + 1));
        scanf("%d", p + i);
    }

    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d element is: %d\n", (i + 1), *(p + i));
    }

    p = (int *)realloc(p, (n + 2) * sizeof(int));

    p[n] = 5;
    p[n + 1] = 10;

    int j;
    for (j = 0; j < n + 2; j++)
    {
        printf("%d element is: %d\n", (j + 1), *(p + j));
    }

    free(p);

    return 0;
}
