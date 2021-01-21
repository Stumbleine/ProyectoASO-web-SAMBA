#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stddef.h>
#define MAXLEN 1024

int main(){
    printf("Content-type:text/html\n\n");
    printf("<html>");
    printf("<head>");
    printf("<link rel=\"stylesheet\" href=\"htdocs/listar.css\">\n");
    printf("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\">\n");
    printf("</head>");
    printf("<body style=\"background-color: #ccdbdc ;\" >");
    printf("<br><h2 style=\"text-align: center;\" >Agregar archivos compartidos <h2>\n");



//fo
	printf("<br><form action=\"/cgi-bin/leerAgregar\" method=\"POST\" class=\"d-block align-content-center \"  style=\"padding: 1em; margin: 1em; font-size:20px; \">\n");
        printf("<div class=\"form-group row\">\n");
      	printf("<label class=\"col-form-label col-sm-2\">Share Name</label><div class=\"col-sm-5\"><input name=\"name\" class=\"form-control\"></div>\n");
        printf("</div>\n");
        printf("<div class=\"form-group row\">\n");
        printf("<label class=\"col-form-label col-sm-2\">Commentary</label><div class=\"col-sm-5\"><input name=\"coment\" class=\"form-control\"></div>\n");
      	printf(" </div>\n");
        //radio btns
/*	printf("<fieldset class=\"form-group\">\n");
            printf("<div class=\"row\"><legend class=\"col-form-label col-sm-2 pt-0\">Share type</legend>\n");
               printf(" <div class=\"col-sm-5\">\n");
                  printf("  <div class=\"form-check\">\n");
                   printf("<input class=\"form-check-input\" type=\"radio\" name=\"gridRadios\" value=\"option1\"><label class=\"form-check-label\">Printer</label>\n");
                   printf(" </div>\n");
                   printf(" <div class=\"form-check\">\n");
                       printf(" <input class=\"form-check-input\" type=\"radio\" name=\"gridRadios\" value=\"option2\"><label class=\"form-check-label\">Directory</label>\n");
                    printf("</div>\n");
               printf(" </div>\n");
            printf("</div>\n");
       printf("</fieldset>\n");*/
	//path
       printf(" <div class=\"form-group row\">\n");
       printf("<label class=\"col-sm-2 col-form-label\">Path share</label><div class=\"col-sm-5\"><input name=\"path\"  class=\"form-control\"></div>\n");
       printf("</div>\n");
//checks
       printf(" <div class=\"form-group d-flex\">\n");
            printf("<div class=\"col-sm-4\">\n");
            printf(" <div class=\"form-check\"><input name=\"readOnly\" class=\"form-check-input\" type=\"checkbox\"><label class=\"form-check-label\" >Read-Only</label></div>\n");
            printf("</div>\n");
            printf("<div class=\"col-sm-4\">\n");
            printf("<div class=\"form-check\"><input name=\"inherit\" class=\"form-check-input\" type=\"checkbox\"><label class=\"form-check-label\">InheritACLs</label></div>\n");
           printf(" </div>\n");
       printf(" </div>\n");

//bbot
       printf("<div class=\"form-group\">\n");
       printf("<button type=\"submit\" class=\"btn btn-primary\">Guardar</button>\n");
       printf("<a href=\"/cgi-bin/recursos\" class=\"btn btn-secondary\">Cancelar</a>\n");
       printf(" </div>\n");
	printf("</form>");


printf("<body>");
}





