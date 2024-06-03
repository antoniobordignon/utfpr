int multiplicacao_recursiva(int v1, int v2){
    if(v1 == 0){
        return 0;   
    } else{
        return v2 + multiplicacao_recursiva(v1 - 1, v2);
    }
}