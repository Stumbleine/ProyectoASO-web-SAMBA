#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stddef.h>
#define MAXLEN 1024 

#define LIMITE 100


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

    while (linea[y] = linea[x]){
        linea[y] = linea[x];
        y++;
        x++;
    }
}

int main(){

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
    printf("</head>");
    printf("<body style=\"background-color:#ccdbdc ;\" >");



	char *lenstr;
	char inputBuffer[MAXLEN];
	int contentLength;
	int i;
	char x;
	char estadoServidor[80];
	lenstr = getenv("CONTENT_LENGTH");
	//lenstr = (char *)getenv("CONTENT_LENGTH");

	if (lenstr!= NULL)
	{
		contentLength = atoi(lenstr);   
	}
	else contentLength = 0;

	if (contentLength > sizeof(inputBuffer)-1)
	contentLength = sizeof(inputBuffer)-1;

	i = 0;

	while (i < contentLength){

		x = fgetc(stdin);
		if (x==EOF) break;
		inputBuffer[i] = x;
		i++;
	}

	inputBuffer[i] = '\0';
	contentLength = i;

 //   printf("<br>Datos Estado: %s\n", inputBuffer);
	//printf("<br>Tama&ntildeo: %d\n",contentLength);
  

	separar(estadoServidor, inputBuffer, '=');
    separar(estadoServidor, inputBuffer, '&');

    //printf("<br>dato: %s\n",estadoServidor);

    	if (strcmp(estadoServidor,"iniciar")==0){
			system("systemctl start smb.service");
			    printf("<br><div class=\"card text-center col-sm-8\" style=\"margin:auto;>");
	            printf("<div class=\"card-body\"><h5 class=\"card-title\">Mensaje</h5> <p tyle=\"font-size:25px;\" class=\"card-text text-success\">");
	            printf("El servidor se inicio con exito.");
	            printf("</p><a href=\"/cgi-bin/config\" class=\"btn btn-primary\">Volver</a>");
	            printf("</div><div class=\"card-footer text-muted\">");
                    printf("Que tenga un buen dia Sir.");
                printf("</div></div>");
    	}else{
		    if(strcmp(estadoServidor,"apagar")==0){
			    system("systemctl stop smb.service");
			    printf("<br><div class=\"card text-center col-sm-8\" style=\"margin:auto;\">");
	            printf("<div class=\"card-body\"><h5 class=\"card-title\">Mensaje</h5> <p style=\"font-size:25px;\" class=\"card-text text-success\">");
	            printf("El servidor samba se detuvo con exito.");
	            printf("</p><a href=\"/cgi-bin/config\" class=\"btn btn-primary\">Volver</a>");
	            printf("</div><div class=\"card-footer text-muted\">");
                    printf("Que tenga un buen dia Sir.");
                printf("</div></div>");
		    
		    }else{
			    system("systemctl stop smb.service");
			    system("systemctl start smb.service");

			    printf("<br><div class=\"card text-center col-sm-8\"> style=\"margin:auto;");
	            printf("<div class=\"card-body\"><h5 class=\"card-title\">Mensaje</h5> <p style=\"font-size:25px;\" class=\"card-text text-success\">");
	            printf("Se reinicio el servidor samba con exito.");
	            printf("</p><a href=\"/cgi-bin/config\" class=\"btn btn-primary\">Volver</a>");
	            printf("</div><div class=\"card-footer text-muted\">");
                    printf("Que tenga un buen dia Sir.");
                printf("</div></div>");
		    }
    	}



      return 0;
}