void gravaNoArquivo(FILE *fp, int v[], int n){

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", v[i]);
    }
    
    rewind(fp);

}

int somaArquivo(FILE *fp){
    int sum = 0;
    int value;
    
    rewind(fp);
    
    while (fscanf(fp, "%d", &value) != EOF) {
        sum += value;
    }
    
    return sum;

}