**Funcionamiento general**

Este manual tiene la función de explicar el funcionamiento del programa
prototipo elaborado con la finalidad de apoyar al personal que deba utilizarlo para las
tareas de inventariado.
El programa tiene como objetivo el ayudar al personal a realizar tareas de
inventariado y organización, siendo entre sus capacidades las de añadir y/o retirar
productos, cambiar sus características, hacer un reporte y aumentar o disminuir las
cantidades para una mayor facilidad de alteración al momento de realizar movimientos
como comprar o vender productos.

**Instrucciones**

Al iniciar el programa, se lanzará un menú pidiendo al usuario que ingrese un
número, el cual servirá para señalar el tipo de proceso que se desea realizar.
El programa cuenta como se dijo anteriormente con ciertas capacidades, siendo
estas enlistadas por el menú de la siguiente manera:

  - Para añadir productos se debe presionar y enviar el número 1 para comenzar
  con el proceso.
  - Para retirar productos se debe presionar y enviar el número 2 para comenzar
  con el proceso.
  - Para cambiar los detalles de los productos se debe presionar y enviar el número
  3 para comenzar con el proceso.
  - Para imprimir el reporte de los productos se debe presionar y enviar el número 4
  para comenzar con el proceso.
  - Para poder aumentar o decrementar la cantidad de alguno de los productos se
  debe presionar y enviar el número 5 para comenzar con el proceso.
  Para salir del programa y así dar por terminada la sesión se debe presionar y
  enviar el número 6

**Altas**

Mediante una función de tipo void el programa le solicita al usuario todas las
características del mismo desde el nombre, precio. Hasta un identificador único para
cada uno de los productos ingresados. Estos mismos teniendo en cuenta parámetros
de máximos y mínimos. Como por ejemplo no se puede dar el caso de ingresar más de
100 productos debido a la estructura del programa solicitada y tampoco el hecho de
poner cantidades por debajo de cero, de lo contrario se le solicitará al usuario que
ingrese datos válidos para continuar con el programa.

Aquí pueden verse 2 de las interacciones posibles con el programa al momento de
registrar un producto, cuando uno trata de registrar un producto pero hace que 
el precio o la cantidad sea inferior de cero (0), el programa imprimirá un mensaje 
indicando que se introdujeron valores incorrectos. Por otro lado, se ve el proceso
de registro funcionar de manera exitosa.

![gif1](https://github.com/user-attachments/assets/feed8343-0d25-4a0e-bc2a-c29ae18c58f1)

**Bajas**

Mediante un proceso similar al utilizado al momento de registrar productos, en
este caso mediante un ciclo, esto lo hace mediante la solicitud del código del producto,
se iteran las posiciones del arreglo para encontrar el producto que se desea eliminar, Si
el producto no es encontrado el programa se lo hará saber

![gif2](https://github.com/user-attachments/assets/9a1ddb6b-ad5b-48c5-afa6-719a72b0f65c)

**Cambios**

El programa pedirá el número del artículo que se desea alterar, de existir, el
programa imprimirá en pantalla la información de este, se podrá alterar su nombre, la
descripción, el precio (siempre y cuando este último sea mayor de cero (0)) y la
cantidad de productos, al finalizar el programa volverá al menú.

![gif3](https://github.com/user-attachments/assets/af035837-786f-49cb-91a1-93bb0b900e59)

**Reportes**

El programa preguntará al usuario de qué manera se desea ver el contenido del
inventario, ya sea ordenado por número o por nombre y pedirá que se introduzca un
número, 1 para verlo ordenado por número (o identificador) y 2 para verlo ordenado 
por nombre del producto, al terminar la impresión el programa pedirá que se ingrese 
un caracter cualquiera para ir de regreso al menu.

Aquí se imprimió la información de los productos de manera ascendente basado en su nombre
y posteriormente basado en su código de producto:

![gif4](https://github.com/user-attachments/assets/b6b451d8-b5dd-4ed9-8757-2b357a1f2eb8)

**Entradas y Salidas**

Esta función permite alterar la cantidad de productos en existencia, esto para poder
reflejar de manera más simple los movimientos que se realizan al vender un producto 
a los clientes y/o al comprar a proveedores, al finalizar se volverá al menú para 
continuar.

Aquí se tiene un producto al cual se le agrega producto en cuestión de cantidades:

![gif5](https://github.com/user-attachments/assets/262bf012-3b39-4975-a7bf-9229cecb5620)

Aquí se tiene un producto al cual se le subtrae producto en cuestión de cantidades:

![gif6](https://github.com/user-attachments/assets/a8d2c374-17f6-4e63-afe9-296ea6809c81)

**Salir (finalizar el proceso)**

Cuando el programa se encuentre en el menú, la opción de salir hará que el
proceso que se estuviese ejecutando se detenga y que se termine el programa.

Aquí es que la sesión se dio por terminada, cerrando el programa:

![gif7](https://github.com/user-attachments/assets/3516ff08-e780-4d70-b85b-0900c82b2b66)

**Conclusion**

Entonces para resumir, este prototipo es capaz de ayudar en el proceso de
inventariado de la empresa, siendo capaz de añadir objetos, quitar dichos objetos,
cambiar los detalles de estos, hacer un reporte de los objetos en el inventario contando
además con la capacidad de ordenarlos ya sea por su nombre o por su número(o
identificador) de producto de manera ascendente, además de mencionar la cantidad de
productos registrados en el inventario. Por no mencionar la capacidad de registrar
fácilmente los movimientos que se hacen de productos, siendo capaz de aumentar y
disminuir la cantidad de productos sin alterar las demás cualidades de cada uno de
estos para representar las ventas y adquisiciones que se hacen a lo largo del tiempo.
Muchas de las soluciones implementadas no son más que la combinación de
procesos o funciones que vimos en clase (o en las tareas), demostrando al final el uso
de lo aprendido a lo largo del semestre, en especial en términos de ciclos, módulos y
arreglos (aunque claro, hay gente que utiliza sus conocimientos previos para mejorar la
calidad del programa).
Y si bien es cierto que este tipo de labores administrativas pueden ser realizados
por una persona o por un pequeño grupo de estas, al final el propósito de este
programa es el de acelerar el proceso de inventariado para hacer el proceso más
llevadero para el (o los) empleados encargados de realizar esta tarea, en especial para
aquellos que no tengan mucha experiencia con estas tareas.
El programa es bastante simple, lo que si bien no permite una gran variedad de
acciones o de flexibilidad como otras, es fácil de usar, lo que resulta de ayuda para la
gente que no esta tan capacitada en temas informáticos.

**Referencias**

Blandino, E. B. (2021). Empaques eficientes RRP (M. B. Barrios, Ed.). Walmart México y Centroamérica
https://www.walmartcentroamerica.com/content/dam/walmart-centro-america/documents/proveedores/actualizacion/manual-rrp-2022.pdf

Taboada A. [Programación ATS]. (2018, 2 de abril). Aprende Programación en C++
[Video]. Youtube
https://www.youtube.com/playlist?list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh

**Anexos**

1. Ángel Benitez: 
Este trabajo sin duda fue complicado, aunque no mucho la verdad, lo
digo más bien por el hecho de estarlo haciendo de manera remota,lo que sí es algo
más complicado en términos de comunicación y de tiempos debido a que no todos
estamos disponibles al mismo tiempo.
Mi contribución es en su mayoría la de hacer la documentación que está leyendo
en este momento, esto debido a que muchas de las funciones requeridas son algo
nuevas para mi y me sigue costando un poco el implementarlas de la mejor manera
(por no mencionar eventos personales), aun así (y aunque mi contribución resultó
menor en el programa) pienso que mi parte (cambios) es lo suficientemente buena
como para cumplir con su propósito de manera eficiente lo que a su vez me demuestra
que en efecto, aprendí algo a lo largo del semestre en su clase.
Y aunque ciertamente mi parte del código podría funcionar mejor o estar más
refinada, practicar y aprender me ayudará con el tiempo a que esta situación se corrija
por completo, por lo que tampoco es algo por lo que deba martirizarme.

2. Angel Torres:
A lo largo de este proyecto aprendí que programar con un propósito no
implica solamente tener el conocimiento de las particularidades del lenguaje de
programación, la lógica de los algoritmos y el funcionamiento de los bloques de código
existentes, sino de comprender las necesidades específicas del problema que debe
atacarse, así como el contexto en el que este mismo se presenta. Para poder
programar una solución, es imperativo pasar por una fase de lluvia de ideas en la que
se ponga en marcha nuestra creatividad, de modo que imaginemos una gama de
posibles caminos que podrían tomarse.
Una vez que se haya llegado a un conjunto de opciones viables, es momento de
analizar cuál de ellas sería la más óptima para los intereses del consumidor o de la
funcionalidad del producto a realizar. Siempre hay que tomar en cuenta que el usuario
no tiene los mismos conocimientos que quienes codifican y que el programa debe ser
lo más claro posible, de manera que sea intuitivo para el público en general. Lo que
hace que un producto informático sea realmente bueno es que logre ser entendido de
manera natural mientras se utiliza y que ofrezca las técnicas más efectivas.
Además, el trabajo en equipo y la química entre los programadores es de vital
importancia, ya que a través de él las diferentes partes del código pueden
complementarse y tomar sentido. Mientras más se entiendan los colaboradores entre
sí, mayor será el éxito del proyecto.
Cesar Rivera: Me gustó mucho este proyecto. Fue muy divertido porque realmente sí
pasamos por problemáticas que se tuvieron que resolver, así como el hecho de que
aplicamos cosas que personalmente yo no tenía conocimiento al respecto, como el uso
de la librería <cstdlib>. Un problema importante fue el manejo de los arreglos y el uso
de Bubble sort, que, aunque son cosas que vimos en clase y personalmente ya tenía
algo de conocimiento al respecto, en la práctica fue un reto hacerlo. También el uso del
comando para eliminar los caracteres de la terminal es algo que desconocía que se
podía hacer antes de investigar. En general, se me hizo muy interesante este proyecto
y espero que este sea uno de muchos proyectos interesantes que hagamos durante la
carrera.

3. César Rivera:
Me gustó mucho este proyecto. Fue muy divertido porque realmente sí
pasamos por problemáticas que se tuvieron que resolver, así como el hecho de que
aplicamos cosas que personalmente yo no tenía conocimiento al respecto, como el uso
de la librería <cstdlib>. Un problema importante fue el manejo de los arreglos y el uso
de Bubble sort, que, aunque son cosas que vimos en clase y personalmente ya tenía
algo de conocimiento al respecto, en la práctica fue un reto hacerlo. También el uso del
comando para eliminar los caracteres de la terminal es algo que desconocía que se
podía hacer antes de investigar. En general, se me hizo muy interesante este proyecto
y espero que este sea uno de muchos proyectos interesantes que hagamos durante la
carrera.


5. Sergio Stratta:
El desarrollo del proyecto me ha permitido poner en práctica las habilidades adquiridas
a lo largo del semestre en la materia de Métodos de Programación. Considero que
logré desempeñarme de manera exitosa durante el proceso, aplicando los
conocimientos teóricos y prácticos aprendidos así como los ya existentes. Además,
esta experiencia me ha brindado la oportunidad de consolidar mi comprensión de los
conceptos y sobre todo a mejorar mi capacidad para resolver problemas en un
contexto real.
