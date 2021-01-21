#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdlib.h>
#include <stddef.h>
#define MAXLEN 1024

int main(void){
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
    printf("<body style=\"background-color:#ccdbdc ;\" >");

    	system("rpm -qa | grep samba > instalado.txt");
    FILE * instalado = fopen("instalado.txt","r");
    if (instalado == NULL){
        perror("Error en la apertura del archivo");
    	printf("<br><p>Error en la verificacion de instlacion</p>");
            return 1;
    }
	fseek(instalado,0,SEEK_END);
    if(ftell(instalado)==0){
				printf("<br><div class=\"card text-center col-sm-5\" style=\"margin:auto;>");
	            printf("<div class=\"card-body\"><h5 class=\"card-title\">Mensaje</h5> <p tyle=\"font-size:25px;\" class=\"card-text text-success\">");
	            printf("El paquete samba no esta instalado.");
	            printf("</p><a href=\"/htdocs/index.htmal\" class=\"btn btn-primary\">Volver</a>");

	   }else{
				printf("<br><div class=\"card text-center col-sm-5\" style=\"margin:auto;>");
	            printf("<div class=\"card-body\"><h5 class=\"card-title\">Mensaje</h5> <p tyle=\"font-size:25px;\" class=\"card-text text-success\">");
	            printf("El paquete samba esta instalado");
	            printf("</p><a href=\"/htdocs/index.html\" class=\"btn btn-primary\">Volver</a>");

	   }
       	fclose(instalado);
	    system("rm instalado.txt");
        	printf("</body>");

	printf("</html>");
    return 0;
}