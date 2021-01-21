#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1024
#define LIMITE 100
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

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

int main(void){
    char *lenstr;
    char inputBuffer[MAXLEN];
    int contentLength;
    int i;
    char x;
    char nuevoNombre[80];

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
    printf("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\">\n");
    printf("</head>\n");
	printf("<body style=\"background-color:#ccdbdc;\">");


    lenstr = getenv("CONTENT_LENGTH");
    //lenstr = (char *)getenv("CONTENT_LENGTH");
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


    separar(nuevoNombre, inputBuffer, '=');
    separar(nuevoNombre, inputBuffer, '&');
 //   char cadena1 [LIMITE];      char cadena2 [LIMITE];      char cadena3 [LIMITE]={};       char cadena4 [LIMITE];   

   	char name[23] = "\tworkgroup = ";
   	 strcat(name,nuevoNombre);
	 strcat(name,"\n");	
	

		FILE*fp,*fp2;
    fp=fopen("/etc/samba/smb.conf","r");
    if(fp==NULL){
        printf("no se pudo leer smb.conf");
    }
    fp2=fopen("/etc/samba/smb2.conf","a+");
    if(fp2==NULL){
        printf("no se pudo leer smb.conf copia"); 
    }
        
    char linea[LIMITE];
//   	fgets (cadena1, LIMITE, fichero);   fgets (cadena2, LIMITE, fichero);       fgets (cadena3, LIMITE, fichero);       fgets (cadena4, LIMITE, fichero);
    fgets(linea,LIMITE,fp);
    while(!feof(fp)){
        
	    if (linea[1] == 'w' && linea[2] == 'o' && linea[3] == 'r' && linea[4] == 'k' && linea[5] == 'g' && linea[6] == 'r' ){ 
            strcpy(linea, name);
            	printf("<br><div class=\"card text-center col-sm-7\" style=\"margin:auto;\">");
	            printf("<div class=\"card-body\"><h5 class=\"card-title\">Mensaje</h5> <p style=\"font-size:25px;\" class=\"card-text text-success\">");
	            printf("Se cambio el nombre del grupo de trabajo con exito a "); printf(nuevoNombre);
	            printf("</p><a href=\"/cgi-bin/config\" class=\"btn btn-primary\">Volver</a>");
	            printf("</div><div class=\"card-footer text-muted\">");
                printf("Que tenga un buen dia Sir.");
                printf("</div></div>");
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




























