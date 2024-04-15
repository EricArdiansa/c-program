#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// function declaration
void sayHello(char name[30]){
    printf("Selamat datang di program ini: %s\n!!!", name);
}
// main function

int main() {
    printf("Our basic program");
    return 0;
}