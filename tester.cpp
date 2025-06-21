#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;
struct pregunta
{
    string texto;
    vector<string> opciones;
    char respuesta;
};
int main()
{
    int opcion, puntaje = 0,puntajet =0, puntajen =0,n=7;
    char answer;
    // float puntaje;
    vector<pregunta> preguntah = {
        {"Quien fue el primer pais en atacar en la segunda guerra mundial?", {"A) espana", "B) UK", "C) Alemania"}, 'C'},
        {"Que imperio construyo Machu Picchu?", {"A) Mayas", "B) Incas", "C) Aztecas"}, 'B'},
        {"Que muro cayo en 1989?", {"A) La Gran Muralla China", "B) El Muro de Berlin", "C) La Muralla de Adriano"}, 'B'},
        {"Quien es considerado el padre de la independencia de El Salvador?", {"A) Jose Matias Delgado", "B) Manuel Jose Arce", "C) Francisco Morazan"}, 'A'},
        {"Que fecha celebra El Salvador como Independencia?", {"A) 5 de mayo de 1821", "B) 15 de septiembre de 1821", "C) 20 de noviembre de 1821"}, 'B'},
        {"Que pueblos indigenas vivieron en territorio salvadoreno antes de la llegada de los espanoles?", {"A) Mayas y Pipiles", "B) Incas y Chibchas", "C) Nahuas y Quechuas"}, 'A'},
        {"Quien fue el primer presidente de El Salvador?", {"A) Francisco Morazan", "B) Manuel Jose Arce", "C) Gerardo Barrios"}, 'B'},
        {"Que guerra vivio El Salvador en la decada de 1980?", {"A) La guerra de los 100 años", "B) La guerra civil salvadoreña", "C) La guerra de Centroamerica"}, 'B'},
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
        {"Que ciudad de Estados Unidos es conocida como la cuna del Hip Hop?", {"A) Los Ángeles", "B) Atlanta", "C) Nueva York (Bronx)"}, 'C'},
        {"Que artista latino tiene exitos como Vivir Mi Vida?", {"A) Marc Anthony", "B) Maluma", "C) Romeo Santos"}, 'A'},
        {"Que estilo musical popular nacio en Republica Dominicana?", {"A) Cumbia", "B) Merengue", "C) Tango"}, 'B'},
        {"Que artista latino es reconocido como pionero del trap en espanol?", {"A) Bad Bunny", "B) Anuel AA", "C) Arcángel"}, 'A'},
        {"Que banda de rock en espanol es de Argentina?", {"A) Soda Stereo", "B) Maná", "C) Café Tacvba"}, 'A'},
        {"Que cantante urbana canta Saoko?", {"A) Karol G", "B) Bad Bunny", "C) Rosalía"}, 'C'},
        {"Que grupo de Memphis es considerado pionero en el estilo Memphis Rap?", {"A) Three 6 Mafia", "B) Outkast", "C) Run-D.M.C"}, 'A'},
        {"Que artista canta Bichota?", {"A) Karol G", "B) Natti Natasha", "C) Anuel AA"}, 'A'},
        {"Que género mezcla el jazz, musica afroamericana y latina?", {"A) Soul", "B) Latin Jazz", "C) Reggae"}, 'B'},
        {"Que cantante es conocido como por sus comentarios polemicos en X?", {"A) Ye", "B) Kanye west", "C) Todas son correctas"}, 'C'},
        {"Que artista tiene el estilo de musica urbana en exitos como Felices los 4?", {"A) Maluma", "B) J Balvin", "C) Ozuna"}, 'A'}};
    string name;
    int salir;
    cout << "Bienvenido a nuestra trivia! Espero estes preparado para pasarla bien y divertirte contestando nuestras preguntas" << endl;
    cout << "Ingresa tu nombre para guardar tu jugador y score" << endl;
    cin >> name;
    cout << "Bienvenido \n"
         << name << "\n selecciona la categoria que te gustaria jugar\n"
         << endl;
    do
    {
        cout << "categorias: 1. Historia 2. Musica 3. Geografia 4. Deportes 5. Finalizar el juego" << endl;
        cin >> opcion;
        srand(time(0));
        int numero = rand() % 7 + 1;
        switch (opcion)
        {
        case 1:
            cout << "usted a seleccionado historia, debes responder 7 preguntas, las cuales tendran un puntaje de 10 por cada pregunta correcta, si no es el caso se restaran 5 puntos. recuerde que sus respuestas deben ser en MAYUSCULAS" << endl;
            cout << "estas listo? Vamos!!!!" << endl;
            shuffle(preguntah.begin(), preguntah.end(), default_random_engine (time (0)));
            for (int i = 0; i <= 7; i++)
            {
                cout << "pregunta numero:" << i + 1 << preguntah[i].texto << endl;

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
                cout<< "su respuesta es incorrecta"<< -5 << "puntos"<<endl;
                
            }
            }
            cout<< "su puntuacion es:" <<puntaje<<endl;
            cout << "desea salir precione 0, si desea seguir la siguiente categoria precione 1:" << endl;
            cin >> salir;
            break;
            case 2:
            cout << "usted a seleccionado Musica, debes responder 7 preguntas, las cuales tendran un puntaje de 10 por cada pregunta correcta, si no es el caso se restaran 5 puntos. recuerde que sus respuestas deben ser en MAYUSCULAS " << endl;
            cout << "estas listo? Vamos!!!!" << endl;
            shuffle(preguntam.begin(), preguntam.end(), default_random_engine (time (0)));
            for (int i = 0; i <= 7; i++)
            {
                cout << "pregunta numero:" << i + 1 << preguntam[i].texto << endl;

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
                cout<< "su respuesta es incorrecta"<< -5 << "puntos"<<endl;
                
            }
            }
            cout<< "su puntuacion es:" <<puntaje<<endl;
            cout << "desea salir precione 0, si desea seguir la siguiente categoria precione 1:" << endl;
            cin >> salir;
            break;
        default:
            break;
        }

    } while (5 != opcion && 0 != salir);

    return 0;
}