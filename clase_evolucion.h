/**========================================================================
 * ?                                ABOUT
 * @author         :  Santiago Arellano
 * @email          :  sarellanoj(at)estud.usfq.edu.ec
 * @repo           :  Deber_3_Santiago_Arellano_00328370
 * @createdOn      :  22_10_23
 * @description    :  Archivo de Definicion Clase Evolucion
 *========================================================================**/
/**======================
 @DirectivasDePreprocesamiento
 *========================**/
#include <iostream>
#include <string>
#include <array>
#include "./clase_pokemon.h"

#ifndef CMP_2102_PROGRAMACION_AVANZADA_EN_C_CLASE_EVOLUCION_H
#define CMP_2102_PROGRAMACION_AVANZADA_EN_C_CLASE_EVOLUCION_H


class [[maybe_unused]] Clase_Evolucion: public Clase_Pokemon
{
public:
    //! @Definition Constantes Staticas
    static const std::array<std::array<int, 4>, 4> TABLA_VALORES_ATAQUES;
    static const int LUCHA;
    static const int TORMENTA;
    static const int LLAMAS;
    static const int HIELO;
private:
    std::string primer_tipo_de_ataque_pokemon = " ";
    int nivel_de_energia_pokemon = 1;
    unsigned int codigo_primer_ataque_pokemon = 0;
public:
    //! Definicion de Constructores para la Clase
    //? Constructor base, toma simplemente el tipo de pokemon y arma el objeto con el constructor base de Clase_Pokemon

    /// @Definition Constructor Base de la Clase_Evolucion, constructor con un solo valor, acepta valores por defecto
    /// @param tipoDePokemon [in][unsigned int] [default= Clase_Pokemon::TIERRA] Variable Representativa de Constante Estatica Enumerada de Tipo de Pokemon
    explicit Clase_Evolucion(unsigned int tipoDePokemon = Clase_Pokemon::TIERRA);
    //? Constructor con todos los paraemtros, permite por defecto y crea con segundo constructor de Clase_Pokemon
    /// @Definition Constructor Completo de la Clase_Evolucion, constructor con todos los valores incluidos el nombre
    /// @param nombreDePokemon [in][std::string] Variable Representativa de String con el nombre del Pokemon
    /// @param tipoDePokemon [in][unsigned int] [default= Clase_Pokemon::TIERRA] Variable Representativa de Constante Estatica Enumerada de Tipo de Pokemon
    explicit Clase_Evolucion(const std::string& nombreDePokemon,
                    unsigned int tipoDePokemon = Clase_Pokemon::TIERRA);

    //! Definicion de Metodos get
    /// @Definicion Metodo de accesso, permite recuperar el primer tipo de ataque del Pokemon
    /// @returns primer_tipo_de_ataque_pokemon[out][std::string]
    [[nodiscard]] std::string get_primer_tipo_de_ataque_pokemon() const;
    /// @Definicion Metodo de accesso, permite recuperar el nivel de energia del Pokemon
    /// @returns nivel_de_energia_pokemon[out][int]
    [[nodiscard]] int get_nivel_de_energia_pokemon() const;
    /// @Definicion Metodo de accesso, permite recuperar el tipo de ataque basado en una Enumeracion Implicita del Tipo de Ataque en la Clase_Evolucion
    /// @param tipoDeAtaque [in][unsigned int] Variable Representativa de Enumeracion Implicita del Tipo de Ataque en la Clase_Evolucion
    /// @returns codigo_primer_ataque_pokemon[out][unsigned int]
    [[maybe_unused,nodiscard]] static std::string get_tipo_ataque_by_codigo(unsigned int tipoDeAtaque);

    //! Definicion de Metodos set
    /// @Definicion Metodo de acceso, permite definir el tipo del pokemon basado en una Enumeracion Implicita del Tipo de Pokemon de la Clase_Pokemon
    /// @param tipoDePokemon [in][unsigned int] Variable Representativa de Enumeracion Implicita del Tipo de Pokemon de la Clase_Pokemon
    [[maybe_unused]] virtual void set_tipo_pokemon(unsigned int tipoDePokemon) override;
    /// @Definicion Metodo de acceso, permite definir el nivel de energia de un Pokemon
    /// @param nivelDeEnergia [in][int] Variable Representativa de Entero con el nivel de energia del Pokemon
    [[maybe_unused]] void set_nivel_de_energia(int nivelDeEnergia);

    //! Definicion Metodos Auxililares Impresion (Override)
    /// @Definicion Metodo Auxiliar de Impresion, Formato Corto de Valores (Nombre,Tipo, Energia, Ataque)
    /// @returns pokemon_en_data [std::string]
    [[maybe_unused,nodiscard]] virtual std::string mostrar_datos_pokemon() const override;
    /// @Definicion Metodo Auxiliar de Impresion, Formato Largo de Valores (Nombre,Tipo, Energia, Ataque)
    /// @returns pokemon_en_data [std::string]
    [[maybe_unused,nodiscard]] virtual std::string toString() const override;
    /// @Definicion Metodo Auxiliar de Impresion, Tabla de Afectaciones
    [[maybe_unused]] static void print_tabla_afectaciones();

    //! Defincion Metodos de Batalla!
    /// @Definicion Metodo de Batalla, permite encontrar el tipo de ataque del pokemon que realiza el ataque para poder cuantificar su valor en el Pokemon que recibe
    /// @returns tipo_de_pokemon_atacando [out][unsigned int] Variable Representative del tipo del Pokemon atacando, con respecto al orden de la tabla de Afectaciones
    [[maybe_unused,nodiscard]] unsigned int  atacar_otro_pokemon() const;
    /// @Definicion Metodo de Batalla, permite recibir el ataque de un Pokemon sobre otro, basado en el tipo de Pokemon que ataca y su posicion en la tabla de Afectaciones
    /// @param codigoDeTipoAtacante [in][unsigned int] Variable Representative del tipo del Pokemon que ataca, variable obtenida y relativa al orden de la tabla de Afectaciones
    [[maybe_unused]] virtual void atacado_por_otro_pokemon(const unsigned int &codigoDeTipoAtacante);
    /// @Definicion Metodo de Batalla, permite curar a un Pokemon completamente
    [[maybe_unused]] void curar_a_pokemon();
protected:
    /// @Definicion Metodo de acceso, permite definir el tipo de ataque de un Pokemon, basado en el tipo de Pokemon registrado
    /// @param tipoDePokemon [in][unsigned int] Variable Representativa de Enumeracion Implicita del Tipo de Pokemon de la Clase_Pokemon
    [[maybe_unused]] void set_tipo_de_ataque(unsigned int tipoDePokemon);

};


#endif //CMP_2102_PROGRAMACION_AVANZADA_EN_C_CLASE_EVOLUCION_H
