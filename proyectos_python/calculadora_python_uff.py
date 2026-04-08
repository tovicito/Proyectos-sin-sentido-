import time
import os
import sys
import random

# Colores para máxima distracción
R = "\033[0;31m" # Rojo
G = "\033[0;32m" # Verde
B = "\033[0;34m" # Azul
C = "\033[0;36m" # Cian
Y = "\033[1;33m" # Amarillo brillante
M = "\033[0;35m" # Magenta
RESET = "\033[0m"
BLINK = "\033[5m"

def carga_odiosa(texto, duracion=3):
    print(f"{C}{texto}{RESET}")
    bar_size = 20
    for i in range(bar_size + 1):
        # Simulamos que se queda trabado al 99%
        if i == bar_size:
            time.sleep(1.5)
        percent = (i * 100) // bar_size
        bar = "█" * i + "-" * (bar_size - i)
        sys.stdout.write(f"\r{Y}[{bar}] {percent}%")
        sys.stdout.flush()
        time.sleep(duracion / bar_size)
    print(f"\n{G}¡HECHO (o eso creo)!{RESET}\n")

def limpiar():
    os.system("cls" if os.name == "nt" else "clear")

def saludar():
    limpiar()
    print(f"{M}{BLINK}¡¡¡BIENVENIDO A LA SUPER CALCULADORA 3000!!!{RESET}")
    print(f"{B}Preparando motores cuánticos...{RESET}")
    time.sleep(2)
    pedir()

def pedir():
    try:
        n1 = input(f"{C}Introduce el primer número (con cuidado): {RESET}")
        time.sleep(0.5)
        n2 = input(f"{C}Introduce el segundo número (sin prisa): {RESET}")
        
        limpiar()
        carga_odiosa("Inyectando algoritmos de la NASA...", 2)
        
        limpiar()
        print(f"{R}ERROR: Se detectó una mosca en el servidor.{RESET}")
        time.sleep(1)
        carga_odiosa("Desinfectando sistema...", 4)
        
        limpiar()
        print(f"{M}Analizando tu personalidad según tus números...{RESET}")
        time.sleep(2)
        
        limpiar()
        carga_odiosa("Sumando el resultado con las veces que has parpadeado hoy...", 5)
        
        limpiar()
        print(f"{Y}--- PROCESO COMPLETADO ---{RESET}")
        time.sleep(1)
        
        # El gran final innecesariamente ruidoso
        resultado = int(n1) + int(n2)
        
        print(f"{G}Después de 47 simulaciones, el resultado es:{RESET}")
        for _ in range(3):
            print(f"{R} loading... {RESET}")
            time.sleep(0.7)
            
        print(f"\n{B}EL RESULTADO FINAL (redondeado al infinito) ES:{RESET}")
        print(f"{Y}{BLINK}>>>> {resultado} <<<<{RESET}")
        
        print(f"\n{M}Gracias por perder 20 segundos de tu vida.{RESET}")
        
    except ValueError:
        print(f"{R}¡NOOO! ¡Eso no es un número! Reinicia todo el PC ahora.{RESET}")

if __name__ == "__main__":
    saludar()
