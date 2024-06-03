char *findAlphabeticFile(FILE *f){ 
    int size = 0;
    
    while(!feof(f)){
        char chfile = fgetc(f);
        if((chfile >= 'a' && chfile <= 'z') || (chfile >= 'A' && chfile <= 'Z')){
            size += 8;
        }
    }
    
    if(size == 0){
        return NULL;
    }
    
    rewind(f); 
    
    char *s = (char*) malloc(size);    
    int i = 0;
    while(!feof(f)){
        char chfile = fgetc(f);
        if((chfile >= 'a' && chfile <= 'z') || (chfile >= 'A' && chfile <= 'Z')){
            s[i] += chfile;
            i ++;
        }
    }
    
    return s;
  
}