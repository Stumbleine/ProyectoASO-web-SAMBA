#include <stdio.h>
#include<stdlib.h>
#include <string.h>
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
	char contenido [LIMITE];
    char cadena1 [LIMITE];      char cadena2 [LIMITE];  char cadena3 [LIMITE]={};       char cadena4 [LIMITE];
    char cadena5 [LIMITE];      char cadena6 [LIMITE];  char cadena7 [LIMITE];          char cadena8 [LIMITE];
    char cadena9 [LIMITE]={};   char cadena10[LIMITE];  char cadena11[LIMITE];          char cadena12[LIMITE];
    char cadena13 [LIMITE];     char cadena14 [LIMITE]; char cadena15 [LIMITE]={};      char cadena16[LIMITE];

    char captura [LIMITE];      char nombre [20];       char lectura [20];              char pat [20];		    	char coment [20];
    char vacio [20]={'Y','e','s','\0'};	//	char ccpy [20];             	char lecpy [20];        	char pcpy [20];
        
	FILE* fichero;
        fichero=fopen("/etc/samba/smb.conf","r");
    fgets (cadena1, LIMITE, fichero);	fgets (cadena2, LIMITE, fichero);   	fgets (cadena3, LIMITE, fichero);       fgets (cadena4, LIMITE, fichero);
    fgets (cadena5, LIMITE, fichero);   fgets (cadena6, LIMITE, fichero);       fgets (cadena7, LIMITE, fichero);	fgets (cadena8, LIMITE, fichero);
    fgets (cadena9, LIMITE, fichero);  	fgets (cadena10, LIMITE, fichero);	fgets (cadena11, LIMITE, fichero);  	fgets (cadena12, LIMITE, fichero);
    fgets (cadena13, LIMITE, fichero);	fgets (cadena14, LIMITE, fichero);	fgets (cadena15, LIMITE, fichero);      fgets (cadena16, LIMITE, fichero);
    
    printf("Content-type:text/html\n\n");
    printf("<html>");
    printf("<head>");
    printf("<link rel=\"stylesheet\" href=\"htdocs/listar.css\">\n");
    printf("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\">\n");
    printf("</head>");


    printf("<body style=\"background-color:#ccdbdc ;\" >");
    printf("<br><h2>Lista de archivos compartidos</h2>\n");
   //inicia tabl
    printf("<div style=\" padding:2em;\"> \n");
    printf("<table class=\"table table-hover table-light table-bordered border-dark \" style=\"\">\n");
    printf(" <thead class=\"thead-dark mr-1 \">\n");
    printf("<tr><th scope=\"col\">Name</th><th scope=\"col\">Read Only</th><th scope=\"col\">Path</th><th scope=\"col\">Comment</th></tr>\n");
    printf("</thead>\n");
    printf("<tbody class=\"mr-1 \">\n");

	fgets (captura, LIMITE, fichero);
while(!feof(fichero)){
	if (captura[0] == '['){
          separar(nombre,captura,'[');
          separar(nombre,captura,']');
	}else{
		if ((captura[1] == 'c') && (captura[2] == 'o') && (captura[3] == 'm') && (captura[4] == 'm')){
                	separar(coment,captura,'=');
                	separar(coment,captura,'\n');
		}else{ 
			if (captura[1] == 'p' && captura[2] == 'a' && captura[3] == 't' && captura[4] == 'h'){
             		   	separar(pat,captura,'=');
                		separar(pat,captura,'\n');
            		}else{
				if (captura[1] == 'r' && captura[2] == 'e' && captura[3] == 'a' && captura[4] == 'd'){
                		separar(lectura,captura,'=');
                		separar(lectura,captura,'\n');
				}
			}
		}
	}
	fgets (captura, LIMITE, fichero);

	if(captura[0] == '[' || feof(fichero) ){
		
	        printf("<tr ><td>");
       		printf(nombre);
        	printf("</td><td>");
        	printf(lectura);
       		printf("</td> <td>");
        	printf(pat);
        	printf("</td><td>");
        	printf(coment);
        	printf("</td></tr>\n");
		strcpy(lectura,vacio);
	}
}
        printf("</tbody>\n");
        printf("</table>\n");
        printf("</div>");
    //termina tabla empiza botones
        printf("<div class=\"ml-5\">");
        printf("<a class=\"btn btn-primary\" href=\"/cgi-bin/agregar\" >Agregar</a>\n");
        printf("<button type=\"button\"  class=\"btn btn-warning\" data-bs-toggle=\"modal\" data-bs-target=\"#mdEditar\">Editar</button>\n");
        printf("<button type=\"button\"  class=\"btn btn-danger\" data-bs-toggle=\"modal\" data-bs-target=\"#mdBorrar\">Eliminar</button>\n");
        printf(" <button type=\"button\"  class=\"btn btn-secondary\" data-bs-toggle=\"modal\" data-bs-target=\"#staticBackdrop\">Renombrar</button>\n");
        printf("</div><br>");

        fclose(fichero);
//editar

        printf("<div class=\"modal fade mt-2\" id=\"mdeditar\" data-bs-backdrop=\"static\" data-bs-keyboard=\"false\" tabindex=\"-1\" aria-labelledby=\"staticBackdropLabel\" aria-hidden=\"true\">\n");
        printf("<div class=\"modal-dialog modal-dialog-centered\"> <div class=\"modal-content pl-3 \" style=\"font-size:20px;\">");
                printf("<form ACTION=\"/cgi-bin/editar\" METHOD=\"POST\" \">\n");
                printf("<div class=\"form-group \" >");
                printf("<label for=\"n_actual\" class=\"form-label text-primary\">id nombre recurso para editar</label><input name=\"id_name\" class=\"form-control col-sm-8 border-primary\" id=\"n_actual\">\n");
                printf("<label for=\"n_new\" class=\"form-label\">nombre </label><input name=\"new_name\" class=\"form-control col-sm-10 \" id=\"n_new\">\n");
                printf("<label for=\"coment\" class=\"form-label\">comentario </label><input name=\"coment\" class=\"form-control col-sm-10 \" id=\"coment\">\n");
                printf("<label for=\"path\" class=\"form-label\">path </label><input name=\"path\" class=\"form-control col-sm-10 \" id=\"path\">\n");
                printf("<label for=\"ronly\" class=\"form-label\">read only?</label><input name=\"readonly\" class=\"form-control col-sm-10 \" id=\"ronly\">\n");
                printf("<label for=\"in\" class=\"form-label\">inherit acls? </label><input name=\"inherit\" class=\"form-control col-sm-10 \" id=\"in\">\n");
                printf("</div>");

                printf("<div class=\"form-group mx-3 \" style=\"text-align: end;\"><button class=\"btn btn-secondary\" data-bs-dismiss=\"modal\">Close</button><button type=\"submit\" class=\"btn btn-primary ml-3\">Guardar</button></div>\n");
                printf("</form>");

        printf("</div></div></div>");
//eliminar
        printf("<div class=\"modal fade\" id=\"mdBorrar\" data-bs-backdrop=\"static\" data-bs-keyboard=\"false\" tabindex=\"-1\" aria-labelledby=\"staticBackdropLabel\" aria-hidden=\"true\">\n");
        printf("<div class=\"modal-dialog modal-dialog-centered\"> <div class=\"modal-content pl-3 pt-3 \">");
        printf("<form ACTION=\"/cgi-bin/eliminar\" METHOD=\"POST\"  style=\"font-size:20px; \">\n");
        printf("<div class=\"form-group \">");
        printf("<label for=\"nBorrar\" class=\"form-label text-primary\">Nombre del recurso que desea borrar:</label><input name=\"borrar\" class=\"form-control col-10 border-primary\" id=\"nBorrar\">\n");
        printf("</div>");

        printf("<div class=\"form-group mx-3 \" style=\"text-align: center;\"><button class=\"btn btn-secondary\" data-bs-dismiss=\"modal\">Close</button><button type=\"submit\" class=\"btn btn-primary ml-3\">Guardar</button></div>\n");
        printf("</form>");

        printf("</div></div></div>");
//renombrar
        printf("<div class=\"modal fade m-auto\" id=\"staticBackdrop\" data-bs-backdrop=\"static\" data-bs-keyboard=\"false\" tabindex=\"-1\" aria-labelledby=\"staticBackdropLabel\" aria-hidden=\"true\">\n");
        printf("<div class=\"modal-dialog modal-dialog-centered\"> <div class=\"modal-content p-3 align-items-center\">");
                printf("<form ACTION=\"/cgi-bin/renombrar\" METHOD=\"POST\"  style=\"font-size:20px; \">\n");
                printf("<div class=\"form-group \">");
                printf("<label for=\"n_actual\" class=\"form-label text-primary\">Nombre del recurso que desea renombrar:</label><input name=\"name\" class=\"form-control col-10 border-primary\" id=\"n_actual\">\n");
                printf("<label for=\"n_new\" class=\"form-label\">Nuevo nombre: </label><input name=\"re\" class=\"form-control col-10 \" id=\"n_new\">\n");
                printf("</div>");

                printf("<div class=\"form-group mt-3 \" style=\"text-align: end;\"><button class=\"btn btn-secondary\" data-bs-dismiss=\"modal\">Close</button><button type=\"submit\" class=\"btn btn-primary ml-3\">Guardar</button></div>\n");
                printf("</form>");

        printf("</div></div></div>");




        printf("<script src=\"https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/js/bootstrap.bundle.min.js\" integrity=\"sha384-ygbV9kiqUc6oa4msXn9868pTtWMgiQaeYH7/t7LECLbyPA2x65Kgf80OJFdroafW\" crossorigin=\"anonymous\"></script>");
        printf("<body>");
        printf("</html>");
        return 0;
}













