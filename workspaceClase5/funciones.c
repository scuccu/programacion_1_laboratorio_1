/**ejemplo carga secuecial que retorne void*

 int edad;
    float precio;
    int listadoEdades[5]={22,33,44,11,55};
    float listadoPrecios[5];
    int i;

    for(i=0; i<5;i++)
    {
        printf("\nIngrese el numero:");
        scanf("\n %d",&listadoEdades[i]);
    }

    for(i=0;i<5;i++)
    {
        printf("\n %d: %d",i,listadoEdades[i]);

    }



    /**< edad=66;
    printf("\n Edad: ",edad);
    printf("\n &edad: %d" ,&edad);

    printf("\n&listadoEdades:%d",&listadoEdades);
    printf("\nlistadoEdades:%d",listadoEdades);
    printf("\nlistadoEdades[0]:%d",listadoEdades[0]);
    printf("\n&listadoEdades[0]:%d",&listadoEdades[0]);
    printf("\nlistadoEdades[4]:%d",listadoEdades[4]);
    printf("\nlistadoEdades[5]:%d",listadoEdades[5]);

    printf("\n&listadoPrecios:%f",&listadoPrecios);

     for(i=0; i<5;i++)
    {
        printf("\n %d: %d",i,listadoEdades[i]);
    }

    */
