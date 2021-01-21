#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#define MAXLEN 1024 
#define LIMITE 100
void separar(char *cadena, char *linea, char separador)
{
    int x, y;

    x = 0;
    y = 0;

    while ((linea[x]) && (linea[x] != separador))
    {
        cadena[x] = linea[x];
        x = x + 1;
    }
    cadena[x] = '\0';
    if (linea[x])
        ++x;

    y = 0;

    while (linea[y] = linea[x])
    {
        linea[y] = linea[x];
        y++;
        x++;
    }
}

int main(){
    char linea[LIMITE]={};
    char id_name[LIMITE];
    char nombre[LIMITE];        char name[LIMITE];
    char comentario[LIMITE];    char coment[LIMITE];
    char shell[LIMITE];         char path[LIMITE];
    char lectura[LIMITE];       char read[LIMITE];
    char inherit[LIMITE];       char in[LIMITE];

    FILE*fp,*fp2;
    char *lenstr;
    char inputBuffer[MAXLEN];
    int contentLength;
    int i;
    char x;
        int Uid, Gid, iUid, iGid; //var. para almacenar el ID de usuario y grupo
        Uid = getuid();
        Gid = getgid();

        if((setuid(0))<0) printf("\n<br>setuid: operacion no permitida\n");
        if((setgid(0))<0) printf("\n<br>setgid: operacion no permitida\n");
        iUid=getuid();
        iGid=getgid();

    printf("Content-type:text/html\n\n");
    printf("<html>");

    printf("<head>");
    printf("<link rel=\"stylesheet\" href=\"htdocs/listar.css\">\n");
    printf("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\">\n");
    printf("</head>");
    printf("<body>");
 printf("<br><h2>seccion para editar\n");


    lenstr = getenv("CONTENT_LENGTH");
    if (lenstr != NULL){
        contentLength = atoi(lenstr);
    }else
        contentLength = 0;

    if (contentLength > sizeof(inputBuffer) - 1)
        contentLength = sizeof(inputBuffer) - 1;
    i = 0;
    while (i < contentLength){
        x = fgetc(stdin);
        if (x == EOF)
            break;
        inputBuffer[i] = x;
        i++;
    }
    inputBuffer[i] = '\0';
    contentLength = i;
    printf("<br>Datos Formulario: %s\n", inputBuffer);
    printf("<br>Tama&ntildeo: %d\n", contentLength);
//obteniendo del form editar, separar y asignar
    separar(id_name, inputBuffer, '=');
    separar(id_name, inputBuffer, '&');
    printf("<p> id_recurso: %s", id_name);

    separar(nombre, inputBuffer, '=');
    separar(nombre, inputBuffer, '&');
    printf("<p> nombre nuevo: %s", nombre);

    separar(comentario, inputBuffer, '=');
    separar(comentario, inputBuffer, '&');
    printf("<p> comentario nuevo: %s", comentario);
    
    separar(shell, inputBuffer, '=');
    separar(shell, inputBuffer, '&');
    printf("<p> lectura: %s", shell);

    separar(lectura, inputBuffer, '=');
    separar(lectura, inputBuffer, '&');
    printf("<p> lectura: %s", lectura);

    separar(inherit, inputBuffer, '=');
    separar(inherit, inputBuffer, '&');
    printf("<p> inherit: %s", inherit);

    
	printf("</body></html>");
}





