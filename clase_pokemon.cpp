/**========================================================================
 * ?                                ABOUT
 * @author         :  Santiago Arellano
 * @email          :  sarellanoj(at)estud.usfq.edu.ec
 * @repo           :  Deber_3_Santiago_Arellano_00328370
 * @createdOn      :  22_10_23
 * @description    :  Archivo de Implementacion Clase Pokemon
========================================================================**/
/**======================
 @DirectivasDePreprocesamiento
 *========================**/
#include <string>
#include "clase_pokemon.h"

//! @Implementacion Constantes Staticas para la Clase
const int Clase_Pokemon::TIERRA = 0;
const int Clase_Pokemon::AIRE = 1;
const int Clase_Pokemon::FUEGO = 2;
const int Clase_Pokemon::AGUA = 3;

//! @Implementacion Constructores
Clase_Pokemon::Clase_Pokemon(const std::string &nombrePokemon, unsigned int tipoDePokemon)
{
    if (nombrePokemon.length() > 0 && (tipoDePokemon >= 0 && tipoDePokemon <= 3))
    {
        this->set_nombre_pokemon(nombrePokemon);
        this->set_tipo_pokemon(tipoDePokemon);
        this->set_codigo_by_tipo(tipoDePokemon);

    }
    else
    {
        this->set_nombre_pokemon("Pokemon");
        this->set_tipo_pokemon(tipoDePokemon);
        this->set_codigo_by_tipo(tipoDePokemon);
    }
}

Clase_Pokemon::Clase_Pokemon(const unsigned int tipoDePokemon)
{
    this->set_nombre_pokemon("Pokemon");
    this->set_tipo_pokemon(tipoDePokemon);
    this->set_codigo_by_tipo(tipoDePokemon);
}

//! @Implementacion Metodos set

void Clase_Pokemon::set_nombre_pokemon(const std::string& nombrePokemon)
{
    this->nombre_pokemon = nombrePokemon;
}

void Clase_Pokemon::set_tipo_pokemon(unsigned int tipoDePokemon)
{
    this->tipo_de_pokemon= get_tipo_by_codigo(tipoDePokemon);
}

//! @Implementacion Metodos Get

std::string Clase_Pokemon::get_nombre_pokemon() const
{
    return this->nombre_pokemon;
}

std::string Clase_Pokemon::get_tipo_pokemon() const
{
    return this->tipo_de_pokemon;
}

unsigned int Clase_Pokemon::get_codigo_tipo_pokemon() const
{
    return this->codigo_de_tipo_pokemon;
}

// ! @Implementacion Metodos Auxiliares Impresion

std::string Clase_Pokemon::get_tipo_by_codigo(unsigned int tipoDePokemon)
{
    std::string tipoString;
    switch(tipoDePokemon)
    {
        case Clase_Pokemon::TIERRA:
        {
            tipoString = "Tierra";
            break;
        }
        case Clase_Pokemon::AIRE:
        {
            tipoString = "Aire";
            break;
        }
        case Clase_Pokemon::FUEGO:
        {
            tipoString = "Fuego";
            break;
        }
        case Clase_Pokemon::AGUA:
        {
            tipoString = "Agua";
            break;
        }
        default:
        {
            tipoString = "Tipo no encontrado";
            break;
        }
    }
    return tipoString;
}
void Clase_Pokemon::set_codigo_by_tipo(unsigned int tipoDePokemon)
{
    switch (tipoDePokemon) {
        case Clase_Pokemon::TIERRA:
        {
            this->codigo_de_tipo_pokemon = Clase_Pokemon::TIERRA;
            break;
        }
        case Clase_Pokemon::AIRE:
        {
            this->codigo_de_tipo_pokemon = Clase_Pokemon::AIRE;
            break;
        }
        case Clase_Pokemon::FUEGO:
        {
            this->codigo_de_tipo_pokemon = Clase_Pokemon::FUEGO;
            break;
        }
        case Clase_Pokemon::AGUA:
        {
            this->codigo_de_tipo_pokemon = Clase_Pokemon::AGUA;
            break;
        }
        default:
        {
            this->codigo_de_tipo_pokemon = Clase_Pokemon::TIERRA;
            break;
        }
    }
}

std::string Clase_Pokemon::mostrar_datos_pokemon() const
{
    std::string pokemon_en_datos = this->get_nombre_pokemon() + "[" + this->get_tipo_pokemon() + "]";
    return pokemon_en_datos;
}

std::string Clase_Pokemon::toString() const
{
    std::string pokemon_string = "Nombre: " + this->get_nombre_pokemon() + "\n" +
            "Tipo: " + this->get_tipo_pokemon();
    return pokemon_string;
}


