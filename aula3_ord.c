#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input(char * str, int size) {    
	int i = 0;    
	char c = getchar();    
	while (c != '\n') {        
		if (size > 0) {            
			str[i] = c;            
			i++;            
			size--;        
		}        
		c = getchar();   
	}    
	str[i] = '\0';    
	return i;
}


int main (){
    
    char first[30], last[30], address[30], city[20], state[15], zip[9];
    char filename[15];
    FILE* fd;
	int size;
	char buffer[256];

    printf("Digite o nome do arquivo a ser criado: ");
    input(filename, 15);

    if ((fd = fopen(filename,"w")) == NULL) {
        printf("Erro no acesso do arquivo\n");
        exit(1);
    }

    printf("\n\nDigite o Sobrenome, ou <ENTER> para sair\n>>>");
    size = input(last, 30);
    
    while ( size > 0 ) {
        buffer[0]='\0';
        printf("\nPrimeiro nome\n>>>");
        input(first, 30);
        strcat(buffer, first);
        strcat(buffer, "|");
        
        strcat(buffer, last);
        strcat(buffer, "|");
        
        printf("\nEndereco\n>>>");
        input(address, 30);
        strcat(buffer, address);
        strcat(buffer, "|");
        
        printf("\nCidade\n>>>");
        input(city, 20);
        strcat(buffer, city);
        strcat(buffer, "|");
        
        printf("\nEstado\n>>>");
        input(state, 15);
        strcat(buffer, state);
        strcat(buffer, "|");
        
        printf("\nCEP\n>>>");
        input(zip, 9);
        strcat(buffer, zip);
        strcat(buffer, "|");
        
        int tam_string = strlen(buffer);
        
        fwrite(&tam_string, sizeof(int),1, filename);

        fwrite(buffer, sizeof(char), tam_string, filename);
        
        printf("\n\nDigite o Sobrenome, ou <ENTER> para sair\n>>>");
        size = input(last, 30);
    }
}
