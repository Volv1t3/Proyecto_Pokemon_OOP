/**========================================================================
 * ?                                ABOUT
 * @author         :  Santiago Arellano
 * @email          :  sarellanoj(at)estud.usfq.edu.ec
 * @repo           :  Deber_3_Santiago_Arellano_00328370
 * @createdOn      :  22_10_23
 * @description    :  Archivo de Definicion Clase Legendario
 *========================================================================**/
/**======================
 @DirectivasDePreprocesamiento
 *========================**/
#include <string>
#include "./clase_evolucion.h"

#ifndef CMP_2102_PROGRAMACION_AVANZADA_EN_C_CLASE_LEGENDARIO_H
#define CMP_2102_PROGRAMACION_AVANZADA_EN_C_CLASE_LEGENDARIO_H


class Clase_Legendario: public Clase_Evolucion
{
public:
    //! @Definicion Constantes Staticas de la Clase
    static const int NORMAL;
    static const int ESPECIAL;
    static const int SUPREMO;
    static const int ATAQUE_PRIMARIO;
    static const int ATAQUE_SECUNDARIO;
    static const double RECUPERACION_ESPECIAL;
    static const double RECUPERACION_SUPREMA;
private:
    //! @Definicion de Atributos de la Clase
    std::string segundo_tipo_de_ataque = " ";
    unsigned int codigo_segundo_ataque_pokemon = 0;
    unsigned int codigo_status_legendario = 0;
public:
    //! Definicion de Construtores para la Clase
    //? Primer constructor, sencillo con dos argumentos, tipo de pokemon y tipo de legendario
    /// @Definicion Constructor primario de la Clase_Legendario, presenta dos datos con valores por defecto, por lo que dobla como constructor base y con datos
    /// @param tipoDePokemon [in][int][default = Clase_Pokemon::TIERRA] Variable Representativa de Constante Estatica Enumerada de Tipo de Pokemon
    /// @param tipoDeLegendario [in][int] [default = Clase_Legendario::NORMAL] Variable Representativa de Constante Estatica Enumerada de Tipo de Legendario
    explicit Clase_Legendario(int tipoDePokemon = Clase_Pokemon::TIERRA,int tipoDeLegendario = Clase_Legendario::NORMAL);
    //? Segundo constructor, con todos los argumentos
    /// @Definicion Constructor secundario de la Clase_Legendario, presenta todos los datos de la Clase_Legendario, incluye valores por defecto, pero al incluir el nombre este no tiene valor por defecto
    /// @param nombreDePokemon [in][std::string] Variable Representativa de String con el nombre del Pokemon
    /// @param tipoDePokemon [in][int][default = Clase_Pokemon::TIERRA] Variable Representativa de Constante Estatica Enumerada de Tipo de Pokemon
    /// @param tipoDeLegendario [in][int] [default = Clase_Legendario::NORMAL] Variable Representativa de Constante Estatica Enumerada de Tipo de Legendario
    explicit Clase_Legendario(std::string nombreDePokemon,
                     int tipoDePokemon = Clase_Pokemon::TIERRA ,
                     int tipoDeLegendario = Clase_Legendario::NORMAL);

    //! Definicion de Metodos Set
    /// @Definicion Metodo de acceso, permite definir el segundo ataque extra de un legendario basado en una Variable Representativa de una Enumeracion de Tipo de Pokemon
    /// @param tipoDeAtaqueExtra [in][int] Variable Representativa de Constante Estatica Enumerada de Tipo de Ataque de un Pokemon, proveniente de Clase_Evolucion
    [[maybe_unused]] void set_ataque_extra_pokemon(int tipoDeAtaqueExtra);
    //! Defincion de Metodos Get
    /// @Definicion Metodo de acceso, permite recoger el segundo tipo de ataque del legendario
    /// @return [out][std::string] Variable Representativa de String con el segundo ataque del legendario
    [[maybe_unused, nodiscard]] std::string get_segundo_tipo_de_ataque() const;
    /// @Definicion Metodo de acceso, permite recoger el tipo de legendario
    /// @return [out][std::string] Variable Representativa de String con el tipo de legendario
    [[maybe_unused, nodiscard]] std::string get_tipo_legendario() const;
    //! Definicion Metodos Auxililares Impresion (Override)
    /// @Definicion Metodo Auxiliar de Impresion, Formato Corto de Valores (Nombre,Tipo, Energia, Ataque, formato adecuado segun legendario)
    /// @returns pokemon_en_data [std::string]
    [[maybe_unused]] [[nodiscard]] virtual std::string mostrar_datos_pokemon() const override;
    /// @Definicion Metodo Auxiliar de Impresion, Formato Largo de Valores (Nombre,Tipo, Energia, Ataque, formato adecuado segun legendario)
    /// @returns pokemon_en_data [std::string]
    [[maybe_unused]] [[nodiscard]] virtual std::string toString() const override;

    //! Definicion Metodos de Combate Legendarios!
    /// @Definicion Metodo de Batalla, permite encontrar el tipo de ataque del pokemon que realiza el ataque, basado en el numero de ataque del legendario, para poder cuantificar su valor en el Pokemon que recibe
    /// @returns tipo_de_pokemon_atacando [out][unsigned int] Variable Representative del tipo del Pokemon atacando, con respecto al orden de la tabla de Afectaciones
    [[maybe_unused]] [[nodiscard]] unsigned int  atacar_otro_pokemon(const unsigned int& numeroDeAtaque) const;
    /// @Definicion Metodo de Batalla, permite recibir el ataque de un Pokemon sobre otro, basado en el tipo de Pokemon que ataca y su posicion en la tabla de Afectaciones
    /// @param codigoDeTipoAtacante [in][unsigned int] Variable Representative del tipo del Pokemon que ataca, variable obtenida y relativa al orden de la tabla de Afectaciones
    [[maybe_unused]] virtual void atacado_por_otro_pokemon(const unsigned int &codigoDeTipoAtacante);
protected:
    /// @Definicion Metodo de acceso, permite definir el tipo de legendario basado en una Variable Representativa de una Enumeracion definida en la Clase_Legendario
    /// @param tipoDeLegendario [in][int] Variable Representativa de Constante Estatica Enumerada de Tipo de Legendario
    [[maybe_unused]] void set_tipo_de_legendario(int tipoDeLegendario);
};


#endif //CMP_2102_PROGRAMACION_AVANZADA_EN_C_CLASE_LEGENDARIO_H
