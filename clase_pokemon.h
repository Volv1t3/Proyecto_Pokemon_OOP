/**========================================================================
 * ?                                ABOUT
 * @author         :  Santiago Arellano
 * @email          :  sarellanoj(at)estud.usfq.edu.ec
 * @repo           :  Deber_3_Santiago_Arellano_00328370
 * @createdOn      :  22_10_23
 * @description    :  Archivo de Definicion Clase Pokemon
 *========================================================================**/
/**======================
 @DirectivasDePreprocesamiento
 *========================**/
#include <string>



#ifndef CMP_2102_PROGRAMACION_AVANZADA_EN_C_CLASE_POKEMON_H
#define CMP_2102_PROGRAMACION_AVANZADA_EN_C_CLASE_POKEMON_H



class [[maybe_unused]] Clase_Pokemon {
public:
    //! @Constantes Staticas para la Clase
    static const int TIERRA;
    static const int AIRE;
    static const int FUEGO;
    static const int AGUA;
private:
    std::string nombre_pokemon =" ";
    std::string tipo_de_pokemon =" ";
    unsigned int codigo_de_tipo_pokemon =0;
public:
    //! Definicion Constructores
    //? Constructor secundario, Requiere el tipo, pero puede ser default
    /// @Definition Construtor inicial para Clase_Pokemon, ingreso de un solo valor o ninguno aceptado.
    /// @param tipoDePokemon [in][unsigned int]
    /// [default=Clase_Pokemon::TIERRA] \n Variable Representativa de
    /// Constante Estatica Enumerada de Tipo de Pokemon
    explicit Clase_Pokemon(unsigned int tipoDePokemon =Clase_Pokemon::TIERRA);
    //? Constructor General, Requiere un nombre y el tipo puede ser default

    /// @Definition Construtor inicial para Clase_Pokemon, ingreso de todos los valores, incluido nombres
    /// @param nombrePokemon [in][std::string][no default] \n Variable represnetativa del nombre del Pokemon.
    /// @param tipoDePokemon [in][unsigned int] [default=Clase_Pokemon::TIERRA] \n Variable Representativa de Constante Estatica Enumerada de Tipo de Pokemon
    explicit Clase_Pokemon(const std::string &nombrePokemon, unsigned int tipoDePokemon = Clase_Pokemon::TIERRA);


    //! Definicion Metodos Set
    /// @Definition Metodo de accesso para definir el tipo de Pokemon basado en una Enumeracion Representativa del Tipo
    /// @param tipoDePokemon [in][unsigned int] [default=Clase_Pokemon::TIERRA] \n Variable Representativa de Constante Estatica Enumerada de Tipo de Pokemon
    [[maybe_unused]] virtual void set_tipo_pokemon(unsigned int tipoDePokemon);

    //! Definicion Metodos Get

    /// @Definition Metodo de accesso para solicitar el nombre del Pokemon
    /// @returns nombre_pokemon [std::string]
    [[nodiscard]] std::string get_nombre_pokemon() const;
    /// @Definition Metodo de accesso para solicitar el tipo de Pokemon
    /// @returns tipo_de_pokemon [std::string]
    [[nodiscard]] std::string get_tipo_pokemon() const;
    /// @Definition Metodo de accesso para solicitar el codigo del tipo de Pokemon
    /// @returns codigo_de_tipo_pokemon [unsigned int]
    [[nodiscard]] unsigned int get_codigo_tipo_pokemon() const;


    //! Definicion Metodos Auxililares Impresion

    /// @Definition Metodo Auxiliar Estatico para encontrar el Tipo de Pokemon Basado en un Codigo Enumerad de Tipo
    /// @param tipoDePokemon [in] [unsigned int] [default=Clase_Pokemon::TIERRA] \n Variable Representativa de Constante Estatica Enumerada de Tipo de Pokemon
    /// @returns tipo_de_pokemon [std::string]
    [[maybe_unused,nodiscard]] static std::string get_tipo_by_codigo(unsigned int tipoDePokemon);
    /// @Definition Metodo Auxiliar de Impresion, Formato Corto de Valores (Nombre y Tipo)
    /// @returns pokemon_en_data [std::string]
    [[maybe_unused,nodiscard]] virtual std::string mostrar_datos_pokemon() const;
    /// @Definition Metodo Auxiliar de Impresion, Formato Largo de Valores (Nombre, Tipo y Codigo)
    /// @returns pokemon_en_data [std::string]
    [[maybe_unused,nodiscard]] virtual std::string toString() const;
protected:
    //! @Definicion de Metodos set auxiliares
    /// @Definition Metodo de acceso para definir el nombre del Pokemon
    /// @param nombrePokemon [in][std::string] \n Variable Representativa del Nombre del Pokemon
    [[maybe_unused]] void set_nombre_pokemon(const std::string& nombrePokemon);
    /// @Definition Metodo de acceso para definir el codigo del tipo de Pokemon basado en una Enumeracion Representativa del Tipo de Pokemon
    /// @param tipoDePokemon [in][unsigned int] \n Variable Representativa de Constante Estatica Enumerada de Tipo de Pokemon
    [[maybe_unused]]  void set_codigo_by_tipo(unsigned int tipoDePokemon);
};


#endif //CMP_2102_PROGRAMACION_AVANZADA_EN_C_CLASE_POKEMON_H
