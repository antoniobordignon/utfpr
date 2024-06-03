char string[100];

void inverter(int i) {
    if(string[i] == '\0'){
        return;
    } else {
        inverter(i+1);
        printf("%c", string[i]);
    }
}