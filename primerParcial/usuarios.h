#ifndef ESTRUCTURAUsuario_H_INCLUDED
#define ESTRUCTURAUsuario_H_INCLUDED

typedef struct
{
    char nombre[50];
    int idUsuario;
    int estado;
}eUsuario;
#endif

int eUsuario_init(eUsuario[],int limite);
int eUsuario_buscarPorId(eUsuario[] ,int limite, int id);
int eUsuario_siguienteId(eUsuario[] ,int limite);
int eUsuario_buscarLugarLibre(eUsuario listado[],int limite);

int eUsuario_alta(eUsuario[] ,int limite);
int eUsuaio_baja(eUsuario[] ,int limite, int id);
int eUsuaio_modificacion(eUsuario[] ,int limite, int id);
