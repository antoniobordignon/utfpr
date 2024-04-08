void ordenar(int *a, int *b, int *c) {
    int *aux;

    if(*a > *b){
        aux = a;
        a = b;
        b = aux;
    }if(*a > *c){
        aux = a;
        a = c;
        c = aux;
    }if(*b > *c){
        aux = b;
        b = c;
        c = aux;
    }
    printf("%d %d %d", *a, *b, *c);
}