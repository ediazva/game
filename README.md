# Django: Sin palomas

## Esquema
![](schema.svg)

## Compilación
Para compilar Django, se necesita la carpeta de binarios del proyecto [raylib](https://github.com/raysan5/raylib/releases/tag/5.0) adecuado para tu compilador.
Supongamos que `/raylib-win` es el directorio de _raylib_:
```
raylib-win/
├─ include/
│  ├─ raylib.h
│  ├─ raymath.h
│  ├─ rlgl.h
├─ lib/
│  ├─ raylib.dll
│  ├─ raylib.lib
│  ├─ raylibdll.lib
├─ README.md
├─ CHANGELOG
├─ LICENSE
```
Se deberá agregar ese directorio al proyecto estableciendo la variable `RAYLIB_DIR` ya sea por `cmake-gui` o mediante el argumento `-DRAYLIB_DIR=<dir>`.
```sh
cmake -G Ninja \
  -DRAYLIB_DIR=/raylib-win
  ..
ninja
```

## Testing
Para crear ejecutables que prueben alguna parte del proyecto se deben agregar archivos `.cc` en la carpeta [tests](/tests/) con el formato `test_<lib>*_<name>.cc`. e.g:
```
test_engine_1.cc    →   Agregar un ejecutable que importa la librería engine

test_1.cc → Agregar un ejecutable sin incluir alguna librería.

test_engine_base_os_1.cc    →    Agregar un ejecutable que importa las librerías engine,base,os
```

## Cosas por agregar
- [ ] Sprites
- [ ] Hitbox <- Activador
- [ ] Eventos
- [ ] Timers
- [ ] Fisicas?
- [ ] Entidades (GameObject?)
- [ ] Observador

Sprites:
 - JSON contiene datos del sprite
 - sprite.png
 - Animaciones
 - Mediante Aseprite o algún programa
HitBox (colisiones):
 - Se crea un rectangulo (forma) que indique la colisión (colisión entre rectangulos)
 
 GameObject:
  - Components (Componentes):
    - HitBox
    - Sprite
    
Crear Tile generico para Sprites????
Crer un TextureRect que nos permite dividir una Textura en rectangulos y poder hacer referencia a uno de ellos


Entity -> Contiene Componentes
Pool -> Contiene la lista de todas las Entidades y podemos obtener todos las entidades que contienen un Componente
SystemManager -> Manejar las entidades