#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stddef.h>
#define MAXLEN 1024 
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
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
	char cadena1 [LIMITE];      char cadena2 [LIMITE];  char cadena3 [LIMITE]={};       char cadena4 [LIMITE];
	char work [LIMITE];
	char nameWG [LIMITE];// char estado[LIMITE]="defecto";

    char status [80];
    char disable [80] = "El servidor esta inactivo.";
    char enable [80] = "El servidor esta activo.";

        int Uid, Gid, iUid, iGid; //var. para almacenar el ID de usuario y grupo
        Uid = getuid();
        Gid = getgid();
        if((setuid(0))<0) printf("\n<br>setuid: operacion no permitida\n");
        if((setgid(0))<0) printf("\n<br>setgid: operacion no permitida\n");
        iUid=getuid();
        iGid=getgid();

        FILE* fichero;
        fichero=fopen("/etc/samba/smb.conf","r");
    fgets (cadena1, LIMITE, fichero);   fgets (cadena2, LIMITE, fichero);       fgets (cadena3, LIMITE, fichero);       fgets (cadena4, LIMITE, fichero);
	fgets (work, LIMITE, fichero);
		
	separar(nameWG,work,'=');
    separar(nameWG,work,'\n');
    printf("Content-type:text/html\n\n");
    printf("<html>");

    printf("<head>");
    printf("<link rel=\"stylesheet\" href=\"htdocs/listar.css\">\n");
    printf("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\">\n");
    printf("</head>");
    printf("<body style=\"background-color:#ccdbdc ;\" >");
    printf("<br><h2 style=\"text-align:center;\">Configuracion\n</h2><br>");
	printf("<div class=\"inline-block \">\n");
    fclose(fichero);
//ESTADO DELSERVIDOR 
	printf("<div class=\"cont container bg-light\" style=\"padding: 20px; border-radius:10px; margin:auto; \" >\n");
    printf("<form ACTION=\"./leerServe\" METHOD=\"POST\"  style=\"font-size:20px; text-align: center; \">\n");
	printf("<h3>Estado del servidor</h3>\n");
    printf("<p style=\" text-align: center; font-size:20px; color:#3a0ca3\" >                ");
 //metodo para verifficar estado   
    system("systemctl status smb.service | grep \"Active: active (running)\" > estadoServidor.txt");
    FILE*estado=fopen("estadoServidor.txt","r");
    if (estado == NULL){
        perror("Error en la apertura del archivo");
		printf("<br><p><b>Error en la verificacion del estado</b></p>");
       	return 1;
    }
    fseek(estado,0,SEEK_END);
    if(ftell(estado)==0){
        strcpy(status,disable);
        printf(status);
    }else{
        strcpy(status,enable);
        printf(status);
    }
    fclose(estado);
	system("rm estadoServidor.txt");
	printf(" </p>");
	
	printf("<div class=\"form-group\">\n");
        printf("<button name=\"start\" type=\"submit\" value=\"iniciar\" class=\"btn btn-primary\">Iniciar Servidor</button>\n");
        printf("<button name=\"restart\" type=\"submit\"  value=\"reiniciar\" class=\"btn btn-warning\">Reiniciar Servidor</button>\n");
        printf("<button name=\"stop\"type=\" submit\" value=\"apagar\" class=\"btn btn-danger\">Apagar Servidor</button>\n");
	printf(" </div>\n");
    printf("</form>");
	printf(" </div><br>\n");



//Workgroup seccion
	printf("<div class=\"container bg-light rounded-3 \" style=\"padding: 20px; border-radius:10px; margin:auto;\" >\n");

	//form input
	printf("<form ACTION=\"/cgi-bin/leerConfig\" METHOD=\"POST\"  style=\"font-size:20px; text-align:center; \">\n");
    	printf("<h3>Nombre del grupo de trabajo</h3>\n");
        printf("<div class=\"form-group \">El nombre actual es:  \n");
        printf("<label class=\"col-form-label d-inline-flex col-sm-4\" style=\"font-size:16px; color:blue;\"  >"); 
        printf(nameWG); 
        printf("</label><div class=\"col-sm-8 d-inline-flex\"><input class=\"form-control \" name=\"workgroup\"></div>\n");

            printf("<div class=\"form-group \"  style=\"margin-top:10px;\">\n");
            printf("<button type=\"submit\"  href=\"#\" class=\"btn btn-primary\">Guardar</button>\n");
//            printf("<button type=\"submit\" class=\"btn btn-secondary\">Cancelar</button>\n");
            printf(" </div>\n");
        printf("</form>");
	    printf("</div>\n"); 
	    printf("</div>\n");

        printf("<body>");
        return 0;
}











































