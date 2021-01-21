#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1024
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
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
    char name[LIMITE];
    char re[LIMITE];
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
    printf ("Content-type:text/html\n\n");	   
	printf("<html>");
    printf("<head>");
    printf("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\">\n");
    printf("</head>\n");
	printf("<body>");

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
//seaparando para cada variable
    separar(name, inputBuffer, '=');
    separar(name, inputBuffer, '&');
    printf("<p> nombreActual: %s", name);

    separar(re, inputBuffer, '=');
    separar(re, inputBuffer, '&');
    printf("<p>  nuevoNombre: %s", re);

//abriendo archivos
    fp=fopen("/etc/samba/smb.conf","r");
    if(fp==NULL){
        printf("no se pudo leer smb.conf");
    }
    fp2=fopen("/etc/samba/smb2.conf","a+");
    if(fp2==NULL){
        printf("no se pudo leer smb.conf copia"); 
    }
    //concatenando
    char actual_name[80]="[";
    strcat(actual_name, name);
    strcat(actual_name,"]");
    strcat(actual_name,"\n");

    char rename[80]="[";
    strcat(rename, re);
    strcat(rename,"]");
    strcat(rename,"\n");

    fgets(linea,LIMITE,fp);
    while(!feof(fp)){
	    if (linea[0] == '['){
            if(strcmp(linea,actual_name)==0){
                strcpy(linea, rename);
                printf("<br><div class=\"card text-center col-sm-7\" style=\"margin:auto;\">");
	            printf("<div class=\"card-body\"><h5 class=\"card-title\">Mensaje</h5> <p style=\"font-size:25px;\" class=\"card-text text-success\">");
	            printf("Se cambio el nombre del recurso compartido a "); printf(re);
	            printf("</p><a href=\"/cgi-bin/recursos\" class=\"btn btn-primary\">Volver</a>");
	            printf("</div><div class=\"card-footer text-muted\">");
                printf("Que tenga un buen dia Sir.");
                printf("</div></div>");
            }
        }
        fputs(linea,fp2);
        fgets(linea,LIMITE,fp);
    }
    fclose(fp);
    fclose(fp2);
    system("rm /etc/samba/smb.conf");
    system("mv /etc/samba/smb2.conf /etc/samba/smb.conf");
    printf("</body>");
	printf("</html>");
    return 0;
}