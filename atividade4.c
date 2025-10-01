#include <stdio.h>
#include <string.h>
int main(){
    int n = 5;
    char senha[6];
    printf("Digite a senha: ");
    scanf("%5s", senha);
    char chute[11];
    for(int x=0;x<10^n;x++){
        sprintf(chute,"%05d",x); //guarda na memoria as possiveis senhas
        printf("%s\n",chute);
        if(strcmp(chute,senha)==0){
            printf("Senha encontrada: %s\n",chute);
            return 0;
        }
    }
    return 0;
}
