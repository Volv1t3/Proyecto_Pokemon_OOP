/**========================================================================
 * ?                                ABOUT
 * @author         :  Santiago Arellano
 * @email          :  sarellanoj(at)estud.usfq.edu.ec
 * @repo           :  Deber_3_Santiago_Arellano_00328370
 * @createdOn      :  22_10_23
 * @description    :  Archivo de Implementacion Clase Evolucion
 *========================================================================**/
/**======================
 @DirectivasDePreprocesamiento
 *========================**/
#include <iostream>

#include <string>
#include <array>
#include <iomanip>
#include "clase_evolucion.h"

//! @Implementacion Constantes Staticas
const std::array<std::array<int,4>,4> Clase_Evolucion::TABLA_VALORES_ATAQUES
{{{10, 40, 50, 30},
{40, 10, 20, 30},
{50, 20, 10, 40},
{30, 30, 40, 10}}};
const int Clase_Evolucion::LUCHA =0;
const int Clase_Evolucion::TORMENTA =1;
const int Clase_Evolucion::LLAMAS =2;
const int Clase_Evolucion::HIELO =3;

//! @Implementacion Constructores de la Clase
Clase_Evolucion::Clase_Evolucion(unsigned int tipoDePokemon): Clase_Pokemon(tipoDePokemon)
{
    this->nivel_de_energia_pokemon = 100;
    this->set_tipo_de_ataque(tipoDePokemon);
}
Clase_Evolucion::Clase_Evolucion(const std::string& nombreDePokemon,
                                 unsigned int tipoDePokemon):
                                 Clase_Pokemon(nombreDePokemon, tipoDePokemon)
{
    this->set_tipo_de_ataque(tipoDePokemon);
    this->nivel_de_energia_pokemon = 100;
}
//! @Implementacion Metodos set
void Clase_Evolucion::set_tipo_pokemon(unsigned int tipoDePokemon)
{
    this->Clase_Pokemon::set_tipo_pokemon(tipoDePokemon);
    this->set_tipo_de_ataque(tipoDePokemon);
}
void Clase_Evolucion::set_nivel_de_energia( int nivelDeEnergia)
{
    if(nivelDeEnergia >= 1)
    {
        this->nivel_de_energia_pokemon = nivelDeEnergia;
    }
    else {this->nivel_de_energia_pokemon = 1;}
}
void Clase_Evolucion::set_tipo_de_ataque(unsigned int tipoDePokemon)
{
        std::string tipoString;
        switch(tipoDePokemon)
        {
            case Clase_Pokemon::TIERRA:
            {
                tipoString = "Lucha";
                this->primer_tipo_de_ataque_pokemon = tipoString;
                this->codigo_primer_ataque_pokemon = 0;
                break;
            }
            case Clase_Pokemon::AIRE:
            {
                tipoString = "Tormenta";
                this->primer_tipo_de_ataque_pokemon = tipoString;
                this->codigo_primer_ataque_pokemon = 1;
                break;
            }
            case Clase_Pokemon::FUEGO:
            {
                tipoString = "Llamas";
                this->primer_tipo_de_ataque_pokemon = tipoString;
                this->codigo_primer_ataque_pokemon = 2;
                break;
            }
            case Clase_Pokemon::AGUA:
            {
                tipoString = "Hielo";
                this->primer_tipo_de_ataque_pokemon = tipoString;
                this->codigo_primer_ataque_pokemon = 3;
                break;
            }
            default:
            {
                tipoString = "Lucha";
                this->primer_tipo_de_ataque_pokemon = tipoString;
                this->codigo_primer_ataque_pokemon = 0;
                break;
            }
        }
}

//! @Implementacion Metodos get

std::string Clase_Evolucion::get_primer_tipo_de_ataque_pokemon() const
{
    return this->primer_tipo_de_ataque_pokemon;
}

int Clase_Evolucion::get_nivel_de_energia_pokemon() const
{
    return this->nivel_de_energia_pokemon;
}

std::string Clase_Evolucion::get_tipo_ataque_by_codigo(unsigned int tipoDeAtaque)
{
    std::string tipoString;
    switch (tipoDeAtaque) {
        case Clase_Evolucion::LUCHA:
        {
            tipoString = "Lucha";
            break;
        }
        case Clase_Evolucion::TORMENTA:
        {
            tipoString = "Tormenta";
            break;
        }
        case Clase_Evolucion::LLAMAS:
        {
            tipoString = "Llamas";
            break;
        }
        case Clase_Evolucion::HIELO:
        {
            tipoString = "Hielo";
            break;
        }
        default:
        {
            tipoString = "Tipo de Ataque no Encontrado";
            break;
        }
    }
    return tipoString;
}

//! @Implementacion Metodos Auxiliares Impresion (Override)
std::string Clase_Evolucion::mostrar_datos_pokemon() const
{
    std::string pokemon_en_datos = this->get_nombre_pokemon() + "[" +
            this->get_tipo_pokemon() + ":" +
            std::to_string(this->get_nivel_de_energia_pokemon()) + "]" +
            "{" + this->get_primer_tipo_de_ataque_pokemon() + "}";
    return pokemon_en_datos;
}

std::string Clase_Evolucion::toString() const
{
    std::string pokemon_string = Clase_Pokemon::toString() + "\n" +
            "Nivel de Energia: " + std::to_string(this->nivel_de_energia_pokemon) + "\n" +
            "Primer Tipo de Ataque: " + this->primer_tipo_de_ataque_pokemon;
    return pokemon_string;
}

void Clase_Evolucion::print_tabla_afectaciones()
{
    std::cout << "Tabla de Afectaciones:\n";
    std::cout << "\t" << std::setw(10) << std::right << "Lucha" << "\t" <<
    std::setw(10) << std::right << "Tormenta" << "\t" <<
    std::setw(10) << std::right << "Llamas" << "\t" <<
    std::setw(10) << std::right << "Hielo" << "\n";
    for(size_t index = 0; index < TABLA_VALORES_ATAQUES.size(); index++)
    {
        std::cout << Clase_Pokemon::get_tipo_by_codigo(index) << "\t" ;
        for(size_t jindex = 0; jindex < TABLA_VALORES_ATAQUES.size(); jindex++)
        {
            std::cout << std::setw(10) << std::right << TABLA_VALORES_ATAQUES.at(index).at(jindex) << "\t";
        }
        std::cout << "\n";
    }
}

//! @Implementacion Metodos de Batalla!

unsigned int Clase_Evolucion::atacar_otro_pokemon() const
{
     auto tipo_de_pokemon_atacando = this->get_codigo_tipo_pokemon();
     return tipo_de_pokemon_atacando;
}

void Clase_Evolucion::atacado_por_otro_pokemon(const unsigned int &codigoDeTipoAtacante)
{
    int  valor_de_ataque = Clase_Evolucion::TABLA_VALORES_ATAQUES
            .at(this->get_codigo_tipo_pokemon()).at(codigoDeTipoAtacante);
    if (nivel_de_energia_pokemon- valor_de_ataque > 1)
    {
        this->nivel_de_energia_pokemon -= valor_de_ataque;
    }
    else
    {
        this->nivel_de_energia_pokemon = 1;
    }
}

void Clase_Evolucion::curar_a_pokemon()
{
    this->nivel_de_energia_pokemon = 100;
}

