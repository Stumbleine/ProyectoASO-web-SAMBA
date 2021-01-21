#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stddef.h>
#define MAXLEN 1024 
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void separar(char *cadena, char *linea, char separador){
    int x, y;
    x = 0; y = 0;
    while ((linea[x]) && (linea[x] != separador)){
        cadena[x] = linea[x];
        x = x + 1;
    }
    cadena[x] = '\0';
    if (linea[x]) ++x;
    y = 0;
    while (linea[y] = linea[x]) {
        linea[y] = linea[x];
        y++;
        x++;
    }
}
char *replace_str(char *str, char *orig, char *rep){
  static char buffer[4096];
  char *p;

  	if(!(p = strstr(str, orig)))  
      		return str;

  	strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  
	char aux[strlen(p+strlen(orig))+1]; 
	strcpy(aux, p+strlen(orig)); //Lo guardamos para que sprintf no lo machaque si rep es más largo que orig

	sprintf(buffer+(p-str), "%s%s", rep, aux);
  
 	return replace_str(buffer, orig, rep);
}
bool verificarNombre( char *cadena_a_Buscar){
	
    char temp[1024];

    FILE *f;
    f = fopen("/etc/samba/smb.conf", "r");
    if (f == NULL){
        printf("No se ha podido encontrar el archivo... \n");
        exit(1);
    }
    while (fgets(temp, 1024, (FILE *)f)){
        if(strstr(temp, cadena_a_Buscar)){
            return true;
        }
    }
    fclose(f);
}

bool verifPath(char *directorio)
{
    bool esCorrecto;
    char ruta[100];
    strcpy(ruta, directorio);
    strcat(ruta, "exp.txt");

	FILE *archivo;
	char caracter;
	
	archivo = fopen(ruta,"a");
	
	if (archivo == NULL){
            esCorrecto = false;
    }else{esCorrecto = true;
    fclose(archivo);
    
    char cmd[]="rm ";
    strcat(cmd,ruta);
    system(cmd);}
    return esCorrecto;
}

int main(){
	char *lenstr;
    char inputBuffer[MAXLEN];
    int contentLength;
    int i;
    char x;
    char nombre[80];
    char comentario[80];
    char lectura[80];
    char shell[80];
	char in[80];
    printf("Content-type:text/html\n\n");
    printf("<html>");
    printf("<head>");
    printf("<link rel=\"stylesheet\" href=\"htdocs/listar.css\">\n");
    printf("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\">\n");
    printf("</head>");
    printf("<body style=\"background-color: #ccdbdc ;\" >");
        int Uid, Gid, iUid, iGid; //var. para almacenar el ID de usuario y grupo
        Uid = getuid();
        Gid = getgid();

        if((setuid(0))<0) printf("\n<br>setuid: operacion no permitida\n");
        if((setgid(0))<0) printf("\n<br>setgid: operacion no permitida\n");
        iUid=getuid();
        iGid=getgid();

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

    separar(nombre, inputBuffer, '=');
    separar(nombre, inputBuffer, '&');
 
    separar(comentario, inputBuffer, '=');
    separar(comentario, inputBuffer, '&');

    separar(shell, inputBuffer, '=');
    separar(shell, inputBuffer, '&');
    separar(lectura, inputBuffer, '=');
    separar(lectura, inputBuffer, '&');
    separar(in, inputBuffer,'=');
	separar(in, inputBuffer,'&');
    char *aux = replace_str(shell, "%2F", "/");

	char name[100] = "\n[";
    	strcat(name,nombre);
    	strcat(name,"]\n");

         char coment[80] = "\tcomment = ";
         strcat(coment,comentario);
         strcat(coment,"\n");

         char path[80] = "\tpath = ";
         strcat(path,aux);
         strcat(path,"\n");
       	 char readOnly[80] = "\tread only = ";
        if(strcmp(lectura,"On")){
            strcat(readOnly,"Yes");
            strcat(readOnly,"\n");
        }else{ 
            strcat(readOnly,"No");
            strcat(readOnly,"\n");
        }

	    char acl[80] = "\tinherit acls = ";
        if(strcmp(in,"On")){
            strcat(acl,"Yes");
            strcat(acl,"\n");
        }else{
            strcat(acl,"No");
            strcat(acl,"\n");
        }







	FILE *fp;
    	fp = fopen ("/etc/samba/smb.conf", "a" );
bool res= verificarNombre(nombre);
    printf(aux);
	char p[80]="/home/astrut/";
	if(verificarNombre(nombre)==false){
	if(verifPath(aux)==true){
		fputs( name, fp );
    	fputs( coment, fp );
		fputs( acl, fp);
    	fputs( path, fp );
    	fputs( readOnly, fp );
		printf("<br><div class=\"card text-center col-sm-6\" style=\"margin:auto;\">");
        printf("<div class=\"card-body\"><h5 class=\"card-title\">La creacion del recurso compartido fue</h5> <p class=\"card-text\">");
            printf("EXITOSO");
        printf(" </p><a href=\"/cgi-bin/recursos\" class=\"btn btn-primary\">Volver</a>");
        printf("</div>");
 		printf(" </div>");
		}else{					printf("<br><div class=\"card text-center col-sm-6\" style=\"margin:auto;\">");
        printf("<div class=\"card-body\"><h5 class=\"card-title\">La creacion del recurso compartido fue</h5> <p class=\"card-text\">");
            printf("Fallido");
        printf(" </p><a href=\"/cgi-bin/recursos\" class=\"btn btn-primary\">Volver</a>");
        printf("</div><div class=\"card-footer text-muted\">");        printf("El path ingresado es invalido.");
 		printf(" </div> </div>");		}
   	}else{
        printf("<br><div class=\"card text-center\" col-sm-6\" style=\"margin:auto;\">");
        printf("<div class=\"card-body\"><h5 class=\"card-title\">La creacion del recurso compartido fue</h5> <p class=\"card-text\">");
        printf("FALLIDO");
        printf(" </p><a href=\"/cgi-bin/recursos\" class=\"btn btn-primary\">Volver</a>");
        printf("</div><div class=\"card-footer text-muted\">");
        printf("Ya existe un recurso con el mismo nombre");
        printf("</div></div>");
    }      
    fclose ( fp );

	printf("</body>");printf("</html>"); return 0;
}




