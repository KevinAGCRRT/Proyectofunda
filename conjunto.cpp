#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
using namespace std;
//TRIVIA STUFF XD, NO SÉ COMO PONERLE.
//PARTE PABLO STRUCT
struct Usuario
{
    string name;
    int puntaje;
};
void crearUSUARIO()
{
    Usuario u;
    cout << "Nombre de usuario, sin espacios :( : ";
    cin >> u.name;

    ofstream archivo("usuario.txt", ios::app);
    if (archivo.is_open())
    {
        archivo << u.name << endl;
        archivo.close();
        cout << "Usuario creado con exito" << endl;
    }
    else
    {
        cout << "Error al crear usuario" << endl;
    }
}

void mostrarUSUARIO()
{
    ifstream archivo("usuario.txt");
    Usuario u;

    if (archivo.is_open())
    {
        cout << "--- Usuarios Disponibles ---" << endl;
        while (archivo >> u.name)
        {
            cout << "Nombre de Usuario: " << u.name << endl;
        }
        archivo.close();
    }
    else
    {
        cout << "Error al abrir el archivo.\n";
    }
}

void seleccionarUsuario()
{
    string buscarN;
    cout << "Ingrese el nombre del usuario que quiere seleccionar: ";
    cin >> buscarN;

    ifstream archivo("usuario.txt");
    Usuario u;

    if (archivo.is_open())
    {
        while (archivo >> u.name)
        {
            if (buscarN == u.name)
            {
                cout << "Usuario seleccionado: " << u.name << endl;
                archivo.close();
                return;
            }
        }
        archivo.close();
        cout << "Usuario no encontrado" << endl;
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
    }
}

void eliminarUsuario()
{
    int usuariosA = 0, usuariosD = 0;
    string eliminarN;
    cout << "Ingrese el nombre de ususario que quiere eliminar: ";
    cin >> eliminarN;

    ifstream archivo("usuario.txt");
    ofstream archivoElim("eliminar.txt");
    Usuario u;

    if (archivo.is_open() && archivoElim.is_open())
    {
        while (archivo >> u.name)
        {
            usuariosA++;
            if (eliminarN != u.name)
        {
            archivoElim << u.name << endl;
            usuariosD++;
        }
        }
        
    }
    archivo.close();
    archivoElim.close();

    remove("usuario.txt");
    rename("eliminar.txt", "usuario.txt");

    if (usuariosA == usuariosD)
    {
        cout << "Usuario no encontrado" << endl;
    }
    else
    {
        cout << "Usuario elimnado con exito" << endl;
    }
}
//PARTE KEVIN STRUCT
struct pregunta
{
    string texto;
    vector<string> opciones;
    char respuesta;
};
int main (){

 int opcion, puntaje = 0,puntajet =0, puntajen =0, juego, salir, us;
 string name;
    char answer;
    //inicio juego xd
    vector<pregunta> preguntah = {
        {"Quien fue el primer pais en atacar en la segunda guerra mundial?", {"A) espana", "B) UK", "C) Alemania"}, 'C'},
        {"Que imperio construyo Machu Picchu?", {"A) Mayas", "B) Incas", "C) Aztecas"}, 'B'},
        {"Que muro cayo en 1989?", {"A) La Gran Muralla China", "B) El Muro de Berlin", "C) La Muralla de Adriano"}, 'B'},
        {"Quien es considerado el padre de la independencia de El Salvador?", {"A) Jose Matias Delgado", "B) Manuel Jose Arce", "C) Francisco Morazan"}, 'A'},
        {"Que fecha celebra El Salvador como Independencia?", {"A) 5 de mayo de 1821", "B) 15 de septiembre de 1821", "C) 20 de noviembre de 1821"}, 'B'},
        {"Que pueblos indigenas vivieron en territorio salvadoreno antes de la llegada de los espanoles?", {"A) Mayas y Pipiles", "B) Incas y Chibchas", "C) Nahuas y Quechuas"}, 'A'},
        {"Quien fue el primer presidente de El Salvador?", {"A) Francisco Morazan", "B) Manuel Jose Arce", "C) Gerardo Barrios"}, 'B'},
        {"Que guerra vivio El Salvador en la decada de 1980?", {"A) La guerra de los 100 anos", "B) La guerra civil salvadorena", "C) La guerra de Centroamerica"}, 'B'},
        {"Que acuerdo de paz puso fin a la guerra civil en El Salvador?", {"A) Tratado de Versalles", "B) Acuerdo de Camp David", "C) Acuerdos de Chapultepec"}, 'C'},
        {"Que heroe nacional salvadoreño lidero la lucha en el levantamiento de 1932?", {"A) Feliciano Ama", "B) Anastasio Aquino", "C) José Simeon Cañas"}, 'A'},
        {"Que evento comenzo en 1914?", {"A) La Revolución Francesa", "B) La Primera Guerra Mundial", "C) La Guerra Fria"}, 'B'},
        {"Que pacto en 1949 creo la OTAN?", {"A) Pacto de Varsovia", "B) Tratado del Atlantico Norte", "C) Tratado de Versalles"}, 'B'},
        {"Que caida en 1989 simboliza el final de la Guerra Fria?", {"A) La caída del Muro de Berlín", "B) La caida de Saigon", "C) La caida de Kabul"}, 'A'},
        {"Que pais lanzo el primer satelite al espacio en 1957?", {"A) Estados Unidos", "B) Alemania", "C) La URSS"}, 'C'},
        {"Que evento en 2001 sacudio al mundo?", {"A) La caida de la bolsa de Wall Street", "B) El 11 de septiembre en USA", "C) La primavera arabe"}, 'B'}};
    vector<pregunta> preguntam = {
        {"Que cantante es conocido como the King of Pop?", {"A) Elvis Presley", "B) Michael Jackson", "C) Prince"}, 'B'},
        {"Que banda britanica estaba compuesta por John Lennon, Paul McCartney, George Harrison y Ringo Starr?", {"A) Queen", "B) The Beatles", "C) The Rolling Stones"}, 'B'},
        {"Quien canta WHITE FERRARY?", {"A) Kanye West", "B) Franl Ocean", "C) Bad Bunny"}, 'B'},
        {"Que genero musical nacio en el Bronx, Nueva York, en los anos 1970?", {"A) Jazz", "B) Rock and Roll", "C) Hip Hop"}, 'C'},
        {"Que ciudad de Estados Unidos es conocida como la cuna del Hip Hop?", {"A) Los Angeles", "B) Atlanta", "C) Nueva York (Bronx)"}, 'C'},
        {"Que artista latino tiene exitos como Vivir Mi Vida?", {"A) Marc Anthony", "B) Maluma", "C) Romeo Santos"}, 'A'},
        {"Que estilo musical popular nacio en Republica Dominicana?", {"A) Cumbia", "B) Merengue", "C) Tango"}, 'B'},
        {"Que artista latino es reconocido como pionero del trap en espanol?", {"A) Bad Bunny", "B) Anuel AA", "C) Arcángel"}, 'A'},
        {"Que banda de rock en espanol es de Argentina?", {"A) Soda Stereo", "B) Mana", "C) Cafe Tacvba"}, 'A'},
        {"Que cantante urbana canta Saoko?", {"A) Karol G", "B) Bad Bunny", "C) Rosalia"}, 'C'},
        {"Que grupo de Memphis es considerado pionero en el estilo Memphis Rap?", {"A) Three 6 Mafia", "B) Outkast", "C) Run-D.M.C"}, 'A'},
        {"Que artista canta Bichota?", {"A) Karol G", "B) Natti Natasha", "C) Anuel AA"}, 'A'},
        {"Que género mezcla el jazz, musica afroamericana y latina?", {"A) Soul", "B) Latin Jazz", "C) Reggae"}, 'B'},
        {"Que cantante es conocido como por sus comentarios polemicos en X?", {"A) Ye", "B) Kanye west", "C) Todas son correctas"}, 'C'},
        {"Que artista tiene el estilo de musica urbana en exitos como Felices los 4?", {"A) Maluma", "B) J Balvin", "C) Ozuna"}, 'A'}};
        vector<pregunta> preguntad ={
        {"Cuantos jugadores hay en el campo por equipo en un partido de futbol?", {"a) 9", "b) 10", "c) 11"}, 'C'},
        {"Cada cuantos anos se celebra la Copa Mundial de la FIFA?",{"a) Cada 2 anos", "b) Cada 4 anos", "c) Cada 5 anos"}, 'B'},
        {"Que pais ha ganado mas Copas del Mundo?",{"a) Alemania", "b) Italia", "c) Brasil"}, 'C'},
        {"Como se llama el torneo de clubes mas importante de Europa?", {"a) Europa League", "b) Champions League", "c) Conference League"}, 'B'},
        {"Cual de estos paises nunca ha ganado un Mundial?",{"a) Inglaterra", "b) Espana", "c) Paises Bajos"}, 'C'},
        {"Que significa 'hat-trick' en futbol?",{"a) Anotar tres goles en un partido", "b) Ganar tres titulos en un ano", "c) Defender tres penales"}, 'A'},
        {"Que pais fue sede del Mundial en 2022?", {"a) Rusia", "b) Qatar", "c) Japon"}, 'B'},
        {"Cual es la maxima autoridad en un partido de futbol?", {"a) El entrenador", "b) El capitan", "c) El arbitro"}, 'C'},
        {"Que superficie es la mas comun en el futbol profesional?",{"a) Arena", "b) Cesped", "c) Concreto"}, 'B'},
        {"Que pasa si un partido de eliminacion directa termina empatado tras los 90 minutos y el tiempo extra?",{"a) Se repite el partido", "b) Se define por penales", "c) Se da empate"}, 'B'},
        {"Cuantos anillos tiene el simbolo olimpico?", {"a) 4", "b) 5", "c) 6"}, 'B'},
        {"Que deporte se juega en un campo llamado 'diamond' en ingles?", {"a) Rugby", "b) Hockey", "c) Beisbol"}, 'C'},
        {"Cual es el principal torneo anual de tenis sobre cesped?", {"a) Roland Garros", "b) Wimbledon", "c) US Open"}, 'B'},
        {"Cuantos sets se necesitan ganar para triunfar en un partido de tenis masculino de Grand Slam?",{"a) 2", "b) 3", "c) 4"}, 'B'},
        {"Que deporte usa un disco llamado 'puck'?",{"a) Balonmano", "b) Hockey sobre hielo", "c) Waterpolo"}, 'B'}};
        vector<pregunta> preguntag ={
        {"Cual es el rio mas largo del mundo?", {"a) Amazonas", "b) Nilo", "c) Yangtse"}, 'A'},
        {"Cual es la capital de Suecia?", {"a) Copenhague", "b) Estocolmo", "c) Oslo"}, 'B'},
        {"En que continente se encuentra Vietnam?",{"a) Asia", "b) Europa", "c) Africa"}, 'A'},
        {"Cual es el pais con mas islas en el mundo?", {"a) Indonesia", "b) Suecia", "c) Filipinas"}, 'B'},
        {"Cual es el desierto mas grande del mundo?",{"a) Sahara", "b) Antartico", "c) Gobi"}, 'B'},
        {"Cual es la montana mas alta del mundo?", {"a) K2", "b) Everest", "c) Aconcagua"}, 'B'},
        {"En que pais esta el Taj Mahal?",{"a) India", "b) Pakistan", "c) Nepal"}, 'A'},
        {"Cual es el pais mas poblado del mundo?",{"a) India", "b) China", "c) Estados Unidos"}, 'B'},
        {"Que pais tiene forma de bota?", {"a) Francia", "b) Italia", "c) Grecia"}, 'B'},
        {"Cual es la capital de Corea del Sur?",{"a) Busan", "b) Seul", "c) Tokio"}, 'B'},
        {"Cual es el lago mas grande de Africa?",{"a) Lago Victoria", "b) Lago Tanganica", "c) Lago Malawi"}, 'A'},
        {"En que continente esta Surinam?", {"a) Europa", "b) Africa", "c) America"}, 'C'},
        {"Cual es el pais mas pequeno del mundo?",{"a) Monaco", "b) San Marino", "c) Ciudad del Vaticano"}, 'C'},
        {"Que oceano bana la costa este de Estados Unidos?",{"a) Atlantico", "b) Pacifico", "c) Indico"}, 'A'},
        {"Cual es la capital de Nueva Zelanda?", {"a) Auckland", "b) Wellington", "c) Christchurch"}, 'B'}};

cout<< "Bienvenido a Juegos Bichotas, selecciona uno de los dos juegos que deseas jugar este dia! \n1. Trivia Bichota \n2. Blackjack bichota"<<endl;
cin>> juego;
switch (juego)
{
case 1:
    cout << "Bienvenido a nuestra trivia! Espero estes preparado para pasarla bien y divertirte contestando nuestras preguntas" << endl;
    cout << "Ingresa: \n1. si quiere crear un usuario \n 2. si necesita cargar su usuario"<< endl;
    cout<< "estos son los usuarios ya creados:"<<endl;
    mostrarUSUARIO();
    cout<< "Ahora seleccione una opcion"<<endl;
    cin>> us;
    switch (us)
    {
    case 1:
        crearUSUARIO();
        break;
    case 2:
        seleccionarUsuario();
        break;
    default:
    cout<< "Seleccione una de las opciones para poder jugar"<<endl;
        break;
    }
    cout << "Bienvenido \n"
         << name << "\n selecciona la categoria que te gustaria jugar\n"
         << endl;
    do
    {
        cout << "categorias:\n 1. Historia\n 2. Musica\n 3. Deportes\n 4. Geografia\n 5. Opciones de Usuario \n 6. Salir del juego" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "usted a seleccionado historia, debes responder 7 preguntas, las cuales tendran un puntaje de 10 por cada pregunta correcta, si no es el caso se restaran 5 puntos. recuerde que sus respuestas deben ser en MAYUSCULAS" << endl;
            cout << "estas listo? Vamos!!!!" << endl;
            shuffle(preguntah.begin(), preguntah.end(), default_random_engine (time (0)));
            for (int i = 0; i <= 6; i++)
            {
                cout << "pregunta numero: " << i + 1 <<" "<< preguntah[i].texto << endl;

                for (int j = 0; j < preguntah[i].opciones.size(); j++)
                {
                    cout << preguntah[i].opciones[j] << endl;
                }
                cin >> answer;

                if (answer == preguntah[i].respuesta)
                {
                    cout << "usted ha seleccionado la opcion correcta ha ganado 10 puntos" << endl;
                   puntaje += 10;
                    
                }
                 else {
                    puntaje -= 5;
                cout<< "su respuesta es incorrecta "<< -5 << " puntos"<<endl;
                
            }
            }
            cout<< "su puntuacion es:" <<puntaje<<endl;
            cout << "si desea salir precione 0, si desea ir al menu de categorias precione 1:" << endl;
            cin >> salir;
            break;
            case 2:
            cout << "usted a seleccionado Musica, debes responder 7 preguntas, las cuales tendran un puntaje de 10 por cada pregunta correcta, si no es el caso se restaran 5 puntos. recuerde que sus respuestas deben ser en MAYUSCULAS " << endl;
            cout << "estas listo? Vamos!!!!" << endl;
            shuffle(preguntam.begin(), preguntam.end(), default_random_engine (time (0)));
            for (int i = 0; i <= 6; i++)
            {
                cout << "pregunta numero: " << i + 1 <<" "<< preguntam[i].texto << endl;

                for (int j = 0; j < preguntam[i].opciones.size(); j++)
                {
                    cout << preguntam[i].opciones[j] << endl;
                }
                cin >> answer;

                if (answer == preguntam[i].respuesta)
                {
                    cout << "usted ha seleccionado la opcion correcta ha ganado 10 puntos" << endl;
                   puntaje += 10;
                    
                }
                 else {
                    puntaje -= 5;
                cout<< "su respuesta es incorrecta "<< -5 << " puntos"<<endl;
                
            }
            }
            cout<< "su puntuacion es: " <<puntaje<<endl;
            cout << "si desea salir precione 0, si desea ir al menu de categorias precione 1:" << endl;
            cin >> salir;
            break;
            case 3:
            cout << "usted a seleccionado Deportes, debes responder 7 preguntas, las cuales tendran un puntaje de 10 por cada pregunta correcta, si no es el caso se restaran 5 puntos. recuerde que sus respuestas deben ser en MAYUSCULAS " << endl;
            cout << "estas listo? Vamos!!!!" << endl;
            shuffle(preguntad.begin(), preguntad.end(), default_random_engine (time (0)));
            for (int i = 0; i <= 6; i++)
            {
                cout << "pregunta numero:" << i + 1 <<" "<< preguntad[i].texto << endl;

                for (int j = 0; j < preguntad[i].opciones.size(); j++)
                {
                    cout << preguntad[i].opciones[j] << endl;
                }
                cin >> answer;

                if (answer == preguntad[i].respuesta)
                {
                    cout << "usted ha seleccionado la opcion correcta ha ganado 10 puntos" << endl;
                   puntaje += 10;
                    
                }
                 else {
                    puntaje -= 5;
                cout<< "su respuesta es incorrecta "<< -5 << " puntos"<<endl;
                
            }
            }
            cout<< "su puntuacion es: " <<puntaje<<endl;
            cout << "si desea salir precione 0, si desea ir al menu de categorias precione 1:" << endl;
            cin >> salir;
            break;
            case 4:
            cout << "usted a seleccionado Geografia, debes responder 7 preguntas, las cuales tendran un puntaje de 10 por cada pregunta correcta, si no es el caso se restaran 5 puntos. recuerde que sus respuestas deben ser en MAYUSCULAS " << endl;
            cout << "estas listo? Vamos!!!!" << endl;
            shuffle(preguntag.begin(), preguntag.end(), default_random_engine (time (0)));
            for (int i = 0; i <= 6; i++)
            {
                cout << "pregunta numero:" << i + 1 <<" "<< preguntag[i].texto << endl;

                for (int j = 0; j < preguntag[i].opciones.size(); j++)
                {
                    cout << preguntag[i].opciones[j] << endl;
                }
                cin >> answer;

                if (answer == preguntag[i].respuesta)
                {
                    cout << "usted ha seleccionado la opcion correcta ha ganado 10 puntos" << endl;
                   puntaje += 10;
                    
                }
                 else {
                    puntaje -= 5;
                cout<< "su respuesta es incorrecta "<< -5 << " puntos"<<endl;
                
            }
            }
            cout<< "su puntuacion es: " <<puntaje<<endl;
            cout << "si desea salir precione 0, si desea ir al menu de categorias precione 1:" << endl;
            cin >> salir;
            break;
            case 5:
            int opc;

    do
    {
        cout << "       --Bienvenido a la edicion de usuarios, seleccione una opcion-- " << endl;
        cout << "1. Mostrar usuarios" << endl;
        cout << "2. Seleccionar usuario" << endl;
        cout << "3. Eliminar usuario" << endl;
        cout << "4. Salir" << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            mostrarUSUARIO();
            break;
        case 2:
            eliminarUsuario();
            break;
        case 3:
            cout << "Adios, vuelva pronto";
            break;
        default:
            cout<<"Opcioj invalida";
            break;
        }

    } while (opc != 3);
            break;
            case 6:
            cout<< "saliendo del programa... te esperamos de nuevo para pasarlo bien!!!"<<endl;
        default:
        cout<< "esa opcion no existe, por favor selecciones una de las opciones anteriormentes mencionadas"<<endl;
            break;
        }

    } while (5 != opcion && 0 != salir);
    break;
 case 2:
 break;
default:
cout<< "esa opcion no existe"<<endl;
    break;
}

    return 0;
}