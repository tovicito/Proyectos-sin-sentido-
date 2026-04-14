#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 256

char* detectar_backend() {
    if (system("which apt > /dev/null 2>&1") == 0) return "apt";
    if (system("which dnf > /dev/null 2>&1") == 0) return "dnf";
    if (system("which pacman > /dev/null 2>&1") == 0) return "pacman";
    if (system("which snap > /dev/null 2>&1") == 0) return "snap";
    if (system("which flatpak > /dev/null 2>&1") == 0) return "flatpak";
    return "apt"; // default
}

void ejecutar_comando(const char *comando) {
    int resultado = system(comando);
    if (resultado == -1) {
        printf("Error al ejecutar el comando.\n");
    } else if (WEXITSTATUS(resultado) != 0) {
        printf("El comando terminó con código %d (puede ser warning).\n", WEXITSTATUS(resultado));
    } else {
        printf("Comando ejecutado exitosamente.\n");
    }
}

void instalar_paquete(char* backend) {
    char paquete[MAX_INPUT];
    printf("Ingrese el nombre del paquete a instalar: ");
    if (fgets(paquete, sizeof(paquete), stdin) != NULL) {
        paquete[strcspn(paquete, "\n")] = 0;
        if (strlen(paquete) > 0) {
            char comando[512];
            if (strcmp(backend, "apt") == 0) {
                snprintf(comando, sizeof(comando), "sudo apt install -y %s", paquete);
            } else if (strcmp(backend, "dnf") == 0) {
                snprintf(comando, sizeof(comando), "sudo dnf install -y %s", paquete);
            } else if (strcmp(backend, "pacman") == 0) {
                snprintf(comando, sizeof(comando), "sudo pacman -S --noconfirm %s", paquete);
            } else if (strcmp(backend, "snap") == 0) {
                snprintf(comando, sizeof(comando), "sudo snap install %s", paquete);
            } else if (strcmp(backend, "flatpak") == 0) {
                snprintf(comando, sizeof(comando), "flatpak install %s", paquete);
            } else {
                printf("Backend no soportado para instalación.\n");
                return;
            }
            printf("Instalando %s con %s...\n", paquete, backend);
            ejecutar_comando(comando);
        } else {
            printf("Nombre de paquete inválido.\n");
        }
    }
}

void desinstalar_paquete(char* backend) {
    char paquete[MAX_INPUT];
    printf("Ingrese el nombre del paquete a desinstalar: ");
    if (fgets(paquete, sizeof(paquete), stdin) != NULL) {
        paquete[strcspn(paquete, "\n")] = 0;
        if (strlen(paquete) > 0) {
            char comando[512];
            if (strcmp(backend, "apt") == 0) {
                snprintf(comando, sizeof(comando), "sudo apt remove -y %s", paquete);
            } else if (strcmp(backend, "dnf") == 0) {
                snprintf(comando, sizeof(comando), "sudo dnf remove -y %s", paquete);
            } else if (strcmp(backend, "pacman") == 0) {
                snprintf(comando, sizeof(comando), "sudo pacman -R --noconfirm %s", paquete);
            } else if (strcmp(backend, "snap") == 0) {
                snprintf(comando, sizeof(comando), "sudo snap remove %s", paquete);
            } else if (strcmp(backend, "flatpak") == 0) {
                snprintf(comando, sizeof(comando), "flatpak uninstall %s", paquete);
            } else {
                printf("Backend no soportado para desinstalación.\n");
                return;
            }
            printf("Desinstalando %s con %s...\n", paquete, backend);
            ejecutar_comando(comando);
        } else {
            printf("Nombre de paquete inválido.\n");
        }
    }
}

void actualizar_lista(char* backend) {
    char comando[512];
    if (strcmp(backend, "apt") == 0) {
        strcpy(comando, "sudo apt update");
    } else if (strcmp(backend, "dnf") == 0) {
        strcpy(comando, "sudo dnf check-update");
    } else if (strcmp(backend, "pacman") == 0) {
        strcpy(comando, "sudo pacman -Sy");
    } else if (strcmp(backend, "snap") == 0) {
        strcpy(comando, "sudo snap refresh");
    } else if (strcmp(backend, "flatpak") == 0) {
        strcpy(comando, "flatpak update");
    } else {
        printf("Backend no soportado para actualizar lista.\n");
        return;
    }
    printf("Actualizando lista de paquetes con %s...\n", backend);
    ejecutar_comando(comando);
}

void actualizar_sistema(char* backend) {
    char comando[512];
    if (strcmp(backend, "apt") == 0) {
        strcpy(comando, "sudo apt upgrade -y");
    } else if (strcmp(backend, "dnf") == 0) {
        strcpy(comando, "sudo dnf upgrade -y");
    } else if (strcmp(backend, "pacman") == 0) {
        strcpy(comando, "sudo pacman -Syu --noconfirm");
    } else if (strcmp(backend, "snap") == 0) {
        strcpy(comando, "sudo snap refresh");
    } else if (strcmp(backend, "flatpak") == 0) {
        strcpy(comando, "flatpak update");
    } else {
        printf("Backend no soportado para actualizar sistema.\n");
        return;
    }
    printf("Actualizando el sistema con %s...\n", backend);
    ejecutar_comando(comando);
}

void buscar_paquete(char* backend) {
    char paquete[MAX_INPUT];
    printf("Ingrese el nombre del paquete a buscar: ");
    if (fgets(paquete, sizeof(paquete), stdin) != NULL) {
        paquete[strcspn(paquete, "\n")] = 0;
        if (strlen(paquete) > 0) {
            char comando[512];
            if (strcmp(backend, "apt") == 0) {
                snprintf(comando, sizeof(comando), "apt search %s", paquete);
            } else if (strcmp(backend, "dnf") == 0) {
                snprintf(comando, sizeof(comando), "dnf search %s", paquete);
            } else if (strcmp(backend, "pacman") == 0) {
                snprintf(comando, sizeof(comando), "pacman -Ss %s", paquete);
            } else if (strcmp(backend, "snap") == 0) {
                snprintf(comando, sizeof(comando), "snap find %s", paquete);
            } else if (strcmp(backend, "flatpak") == 0) {
                snprintf(comando, sizeof(comando), "flatpak search %s", paquete);
            } else {
                printf("Backend no soportado para búsqueda.\n");
                return;
            }
            printf("Buscando %s con %s...\n", paquete, backend);
            ejecutar_comando(comando);
        } else {
            printf("Nombre de paquete inválido.\n");
        }
    }
}

void instalar_aur() {
    if (system("which yay > /dev/null 2>&1") != 0) {
        printf("yay no está instalado. Instálalo primero.\n");
        return;
    }
    char paquete[MAX_INPUT];
    printf("Ingrese el nombre del paquete AUR a instalar: ");
    if (fgets(paquete, sizeof(paquete), stdin) != NULL) {
        paquete[strcspn(paquete, "\n")] = 0;
        if (strlen(paquete) > 0) {
            char comando[512];
            snprintf(comando, sizeof(comando), "yay -S --noconfirm %s", paquete);
            printf("Instalando %s desde AUR...\n", paquete);
            ejecutar_comando(comando);
        } else {
            printf("Nombre de paquete inválido.\n");
        }
    }
}

void mostrar_menu(char* backend) {
    printf("\n=== Gestor de Paquetes (%s) ===\n", backend);
    printf("1. Instalar paquete\n");
    printf("2. Desinstalar paquete\n");
    printf("3. Actualizar lista de paquetes\n");
    printf("4. Actualizar sistema\n");
    printf("5. Buscar paquete\n");
    if (strcmp(backend, "pacman") == 0) {
        printf("6. Instalar desde AUR\n");
        printf("7. Salir\n");
    } else {
        printf("6. Salir\n");
    }
    printf("================================\n");
}

int main() {
    char* backend = detectar_backend();
    printf("Backend detectado: %s\n", backend);
    int opcion;
    while (1) {
        mostrar_menu(backend);
        printf("Seleccione una opción: ");
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("Opción inválida. Ingrese un número.\n");
            continue;
        }
        while (getchar() != '\n');

        if (strcmp(backend, "pacman") == 0) {
            switch (opcion) {
                case 1:
                    instalar_paquete(backend);
                    break;
                case 2:
                    desinstalar_paquete(backend);
                    break;
                case 3:
                    actualizar_lista(backend);
                    break;
                case 4:
                    actualizar_sistema(backend);
                    break;
                case 5:
                    buscar_paquete(backend);
                    break;
                case 6:
                    instalar_aur();
                    break;
                case 7:
                    printf("Saliendo del gestor de paquetes. ¡Hasta luego!\n");
                    return 0;
                default:
                    printf("Opción inválida.\n");
            }
        } else {
            switch (opcion) {
                case 1:
                    instalar_paquete(backend);
                    break;
                case 2:
                    desinstalar_paquete(backend);
                    break;
                case 3:
                    actualizar_lista(backend);
                    break;
                case 4:
                    actualizar_sistema(backend);
                    break;
                case 5:
                    buscar_paquete(backend);
                    break;
                case 6:
                    printf("Saliendo del gestor de paquetes. ¡Hasta luego!\n");
                    return 0;
                default:
                    printf("Opción inválida.\n");
            }
        }
    }
    return 0;
}