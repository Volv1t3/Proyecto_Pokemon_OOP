/**========================================================================
 * ?                                ABOUT
 * @author         :  Santiago Arellano
 * @email          :  sarellanoj(at)estud.usfq.edu.ec
 * @repo           :  Deber_3_Santiago_Arellano_00328370
 * @createdOn      :  22_10_23
 * @description    :  Archivo de Implementacion Clase Legendario
 *========================================================================**/
/**======================
 @DirectivasDePreprocesamiento
 *========================**/
#include <string>
#include "clase_legendario.h"

//! @Implementacion de Constantes Staticas de la Clase
const int Clase_Legendario::NORMAL = 0;
const int Clase_Legendario::ESPECIAL = 1;
const int Clase_Legendario::SUPREMO = 2;
const int Clase_Legendario::ATAQUE_PRIMARIO = 0;
const int Clase_Legendario::ATAQUE_SECUNDARIO = 1;
const double Clase_Legendario::RECUPERACION_ESPECIAL = 0.15;
const double Clase_Legendario::RECUPERACION_SUPREMA = 0.25;

//! @Implementacion de Constructores para la Clase

Clase_Legendario::Clase_Legendario(int tipoDePokemon, int tipoDeLegendario): Clase_Evolucion(tipoDePokemon)
{
    this->set_tipo_de_legendario(tipoDeLegendario);
}
Clase_Legendario::Clase_Legendario(std::string nombreDePokemon,
                                   int tipoDePokemon,
                                   int tipoDeLegendario): Clase_Evolucion(nombreDePokemon, tipoDePokemon)
{
    this->set_tipo_de_legendario(tipoDeLegendario);
}

//! @Implementacion de Meotods Set
void Clase_Legendario::set_ataque_extra_pokemon(int tipoDeAtaqueExtra)
{
    switch(tipoDeAtaqueExtra)
    {
        case Clase_Evolucion::LUCHA:
        {
            this->segundo_tipo_de_ataque = "Lucha";
            this->codigo_segundo_ataque_pokemon = Clase_Evolucion::LUCHA;
            break;
        }
        case Clase_Evolucion::TORMENTA:
        {
            this->segundo_tipo_de_ataque = "Tormenta";
            this->codigo_segundo_ataque_pokemon = Clase_Evolucion::TORMENTA;
            break;
        }
        case Clase_Evolucion::LLAMAS:
        {
            this->segundo_tipo_de_ataque = "Llamas";
            this->codigo_segundo_ataque_pokemon = Clase_Evolucion::LLAMAS;
            break;
        }
        case Clase_Evolucion::HIELO:
        {
            this->segundo_tipo_de_ataque = "Hielo";
            this->codigo_segundo_ataque_pokemon = Clase_Evolucion::HIELO;
            break;
        }
        default:
        {
            this->segundo_tipo_de_ataque = "Tierra";
            this->codigo_segundo_ataque_pokemon = Clase_Evolucion::TIERRA;
            break;
        }
    }
}
void Clase_Legendario::set_tipo_de_legendario(int tipoDeLegendario)
{
    switch(tipoDeLegendario)
    {
        case Clase_Legendario::NORMAL:
        {
            this->codigo_status_legendario = Clase_Legendario::NORMAL;
            break;
        }
        case Clase_Legendario::ESPECIAL:
        {
            this->codigo_status_legendario = Clase_Legendario::ESPECIAL;
            break;
        }
        case Clase_Legendario::SUPREMO:
        {
            this->codigo_status_legendario = Clase_Legendario::SUPREMO;
            break;
        }
        default:
        {
            this->codigo_status_legendario = Clase_Legendario::NORMAL;
            break;
        }
    }
}

//! @Implementacion de Metodos Get
std::string Clase_Legendario::get_segundo_tipo_de_ataque() const
{
    return this->segundo_tipo_de_ataque;
}
std::string Clase_Legendario::get_tipo_legendario() const
{
    std::string toString;
    switch (this->codigo_status_legendario) {
        case Clase_Legendario::NORMAL:
        {
            toString = "Normal";
            break;
        }
        case Clase_Legendario::ESPECIAL:
        {
            toString = "Especial";
            break;
        }
        case Clase_Legendario::SUPREMO:
        {
            toString = "Supremo";
            break;
        }
    }
    return toString;
}
//! @Implementacion de Metodos Auxiliares Impresion (Override)
std::string Clase_Legendario::mostrar_datos_pokemon() const
{
    std::string pokemon_en_datos;
    switch(this->codigo_status_legendario)
    {
        case Clase_Legendario::NORMAL:
        {
            pokemon_en_datos += "+ " + Clase_Evolucion::mostrar_datos_pokemon() + " +";
            break;
        }
        case Clase_Legendario::ESPECIAL:
        {
            pokemon_en_datos += "** " + Clase_Evolucion::mostrar_datos_pokemon() + " **";
            break;
        }
        case Clase_Legendario::SUPREMO:
        {
            pokemon_en_datos = "!!! " + Clase_Evolucion::mostrar_datos_pokemon() + " !!!";
            break;
        }
    }
    return pokemon_en_datos;
}

std::string Clase_Legendario::toString() const
{
    std::string pokemon_string = Clase_Evolucion::toString() +"\n" +
            "Segundo Tipo de Ataque: " + this->get_segundo_tipo_de_ataque() + "\n";
    return pokemon_string;
}

//! @Implementacion de Metodos de Combate Legendarios!
unsigned int Clase_Legendario::atacar_otro_pokemon(const unsigned int &numeroDeAtaque) const
{
    unsigned int  tipo_de_pokemon_atacando = 0;
    //? En esta funcion retornarmos el valor del tipo de pokemon, para revisar en la tabla de valores luego
    switch(numeroDeAtaque)
    {
        case Clase_Legendario::ATAQUE_PRIMARIO:
        {
            //? Si es ataque primario retornamos el codigo del tipo de pokemon base de la clase evolucion
            tipo_de_pokemon_atacando = Clase_Evolucion::get_codigo_tipo_pokemon();
            break;
        }
        case Clase_Legendario::ATAQUE_SECUNDARIO:
        {
            //? Si es ataque secundario, como estos son el mismo orden, retornamos el codigo del ataque secundario
            tipo_de_pokemon_atacando = this->codigo_segundo_ataque_pokemon;
            break;
        }
    }
    return tipo_de_pokemon_atacando;
}

void Clase_Legendario::atacado_por_otro_pokemon(const unsigned int &codigoDeTipoAtacante)
{
    int  valor_de_ataque = Clase_Evolucion::TABLA_VALORES_ATAQUES
            .at(this->get_codigo_tipo_pokemon()).at(codigoDeTipoAtacante);
    if ((this->get_nivel_de_energia_pokemon() - valor_de_ataque) > 1)
    {
        switch(this->codigo_status_legendario)
        {
            case Clase_Legendario::NORMAL:
            {
                Clase_Evolucion::set_nivel_de_energia(this->get_nivel_de_energia_pokemon() - valor_de_ataque);
                break;
            }
            case Clase_Legendario::ESPECIAL:
            {
                auto porcentaje_de_recuperacion = valor_de_ataque * Clase_Legendario::RECUPERACION_ESPECIAL;
                Clase_Evolucion::set_nivel_de_energia((this->get_nivel_de_energia_pokemon() - valor_de_ataque) + porcentaje_de_recuperacion);
                break;
            }
            case Clase_Legendario::SUPREMO:
            {
                auto porcentaje_de_recuperacion = valor_de_ataque * Clase_Legendario::RECUPERACION_SUPREMA;
                Clase_Evolucion::set_nivel_de_energia((this->get_nivel_de_energia_pokemon() - valor_de_ataque) + porcentaje_de_recuperacion);
                break;
            }
        }
    }
    else
    {Clase_Evolucion::set_nivel_de_energia(1);}
}