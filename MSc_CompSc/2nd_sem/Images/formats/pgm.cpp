void func(){
    FILE *pArq;
    pArq = fopen("j.pgm", "ab");

    char line1[2], line2[100], line3[10];

    int cont = 1;
    while(1){
        if(cont ==1){ //version
            fscanf(pArq, "%s", &line1);
            if(feof(pArq)) break;

            printf("%s", line1);
        }

        if(cont ==2){ //comment
            fscanf(pArq, "%s", &line2);
            if(feof(pArq)) break;

            printf("%s", line2);
        }

        if(cont ==3){ //width, height
            fscanf(pArq, "%s", &line3);
            if(feof(pArq)) break;

            printf("%s", line3);
        }

        cont++;
    }
    fclose(pArq);
}
