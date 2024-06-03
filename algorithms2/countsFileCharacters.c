int contaCaracteresArquivo(FILE* arq){
    int total = 0;
    while(!feof(arq)){
        char chfile = fgetc(arq);
        if(chfile != ' ' && chfile != '\0' && chfile != '\n'){
            total += 1;   
        }
    }
    return total - 1;
}