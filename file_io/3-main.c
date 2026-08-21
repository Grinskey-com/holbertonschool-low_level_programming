#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    ssize_t n;

    n = read_textfile("test.txt", 100);
    printf("\n(read %ld chars)\n", n);
    return (0);
}
