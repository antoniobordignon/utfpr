#include <string.h>

void * achar(void *point, char *v){
    int inicio = *(int *)point;
    int i;
    for(i = inicio; i < strlen(v); i++){
        if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u' || v[i]=='A' || v[i]=='E' || v[i]=='I' || v[i]=='O' || v[i]=='U'){
            point = &v[i];
            return point;
        }
    }
    point = &v[i - 1];
    return point;
}