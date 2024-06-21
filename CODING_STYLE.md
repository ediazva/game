# Coding Style Guidelines

Usamos **2-spaces**, no tab.

En los elementos de un `enum` usamos el estilo:
```c++
enum MyEnum {
  kValue1_MyEnum,
  kValue2_MyEnum,
  kValue3_MyEnum,
}
```

Las llaves tienen el siguiente estilo:
```c++
void foo() {
  // ...
}
```

Los `header`s se definen con .h, además se colocan `#pragma once` en vez de header guard

Los `source`s se definen con .cc

## Namespace
Colocar según el nombre de la carpeta.
```c++
namespace os {
  // ...
} // namespace os
```

Para hacer referencia a headers que están fuera del proyecto usar `#include <iostream>`. <br>
Para hacer referencia a headers que están dentro del proyecta usar el comillas y tiene que hacer referencia al directorio en cuestión, e.g: `#include "os/window.h"`