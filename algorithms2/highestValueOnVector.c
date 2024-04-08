double* max(double *v, int tam) {
    double *aux = &v[0];
    for(int i = 1; i < tam; i++) {
        if(*aux < v[i]) {
            aux = &v[i];
        }
    }
    return aux;
}