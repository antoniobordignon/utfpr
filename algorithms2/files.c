void gravaNoArquivo(FILE *fp, char *v){
    int i = 0;
    for(i=0;v[i]!='\0';i++){
        fputc(v[i], fp);
        fputc('\n', fp);
    }
    
    rewind(fp);      

}

int encontrouCaractereArquivo(FILE* arq, char ch){
    while(!feof(arq)){
        char chfile = fgetc(arq);
        if(chfile == ch){
            return ch = 1;   
        }
    }
    return ch = 0;

}