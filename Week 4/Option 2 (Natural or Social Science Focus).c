#include <stdio.h>
#include <stdlib.h>

struct rational {
    int n;  // numerator
    int d;  // denominator
}data[10];

typedef struct rational RATIONAL;

void generate_pairs(FILE *ifp);
void test_pairs(RATIONAL a, RATIONAL b);

RATIONAL add_rationals(RATIONAL a, RATIONAL b);
RATIONAL subtract_rationals(RATIONAL a, RATIONAL b);
RATIONAL multiply_rationals(RATIONAL a, RATIONAL b);
RATIONAL divide_rationals(RATIONAL a, RATIONAL b);

int main (int argc, char **argv) {
    FILE *ifp;
    char c;

    if(argc != 2){
        printf("Usage: numbers file.txt\n");
        exit(1);
    }
    // File exists?
    ifp = fopen(argv[1], "r");
    if (ifp == NULL) {
        printf("File not found\n");
        exit(1);
    }
    // Generate pairs from input text
    generate_pairs(ifp);
    // Test pair for operations
    test_pairs(data[0], data[1]);
    //
    fclose(ifp);
    return(0);
}
/*
 * According to the value of first element (n) of the file,
 * generate 'n' pairs.
 */
void generate_pairs(FILE *ifp) {
    int a[10], *ptr_a, i=0, j=0;

    ptr_a = &a[0];
    // Read input file
    while(fscanf(ifp, "%d", ptr_a++) == 1) { }

    printf("Number of pairs: %d\n",a[0]);
    // Store pairs in data struct
    while(++i <= a[0]) {
        data[j].n = a[(i*2)-1];
        data[j].d = a[i*2];
        printf("Pair %d: %d/%d\n", j, data[j].n, data[j].d);
        j++;
    }
}

void test_pairs(RATIONAL a, RATIONAL b) {
    RATIONAL res; // result from pair operation
    // '+' operation
    res = add_rationals(a,b);
    printf("Add: %d/%d + %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);
    // '-' operation
    res = subtract_rationals(a,b);
    printf("Subtract: %d/%d - %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);
    // '*' operation
    res = multiply_rationals(a,b);
    printf("Multiply: %d/%d * %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);
    // '/' operation
    res = divide_rationals(a,b);
    printf("Divide: %d/%d / %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);
}
/*
 * Add operation for input pair
 */
RATIONAL add_rationals(RATIONAL a, RATIONAL b) {
    RATIONAL r;

    r.d = a.d*b.d;
    r.n = a.n*b.d + b.n*a.d;
    return(r);
}
/*
 * Subtract operation for input pair
 */
struct rational subtract_rationals(RATIONAL a, RATIONAL b) {
    RATIONAL r;

    r.d = a.d*b.d;
    r.n = a.n*b.d - b.n*a.d;
    return(r);
}
/*
 * Multiplication operation for input pair
 */
RATIONAL multiply_rationals(RATIONAL a, RATIONAL b) {
    RATIONAL r;

    r.d = a.d*b.d;
    r.n = a.n*b.n;
    return(r);
}
/*
 * Divide operation for input pair
 */
RATIONAL divide_rationals(RATIONAL a, RATIONAL b) {
    RATIONAL r;

    r.d = a.d*b.n;
    r.n = a.n*b.d;
    return(r);
}
