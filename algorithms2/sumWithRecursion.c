int somatorio(int n) {
    if(n == 0){
        return 0;
    } else {
        return n + somatorio(n - 1);
    }   
}