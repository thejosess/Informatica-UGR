# encoding:utf-8

require_relative "casilla.rb"

module Civitas
  class Tablero
    
    #al tener este constructor en el initialize es publico no??
    def initialize(num_casilla_carcel)
      if num_casilla_carcel >=1
        @num_casilla_carcel = num_casilla_carcel
      else
        @num_casilla_carcel = 1
      end
      
      @casillas = Array.new
      @casillas << Casilla.new_casilla_descanso("Salida")
      @por_salida = 0
      @tiene_juez = false
    end
    
    def correcto
      if @casillas.size > @num_casilla_carcel && @tiene_juez
        return true
      else
        return false
      end
    end
    #duda sobre este metodo
    
    def correcto_p(num_casilla)
      return correcto == true && (num_casilla > 0 && num_casilla <= @casillas.size)
    end
    
    def por_salida
      if @por_salida <= 0
        valor = @por_salida
      else
        valor = @por_salida
        @por_salida = @por_salida - 1
      end
      return valor
    end
    
    def añade_casilla(casilla)      #VA A DAR PROBLEMAS CREO
      if @casillas.size == @num_casilla_carcel
        @casillas << Casilla.new_casilla_descanso("Carcel")    #es descanso la del juez??
      end
     
      @casillas << casilla
      
      if @casillas.size == @num_casilla_carcel
        @casillas << Casilla.new_casilla_descanso("Carcel")
      end
      
    end
    
    def añade_juez()
      if !@tiene_juez
        @casillas << Casilla.new_casilla_juez(@num_casilla_carcel,"Juez")
        @tiene_juez = true
      end
    end
    
    def get_casilla(numCasilla)
      if correcto_p(numCasilla)
        @casillas.at(numCasilla)
      else
        return nil
      end
    end
    
    def nueva_posicion(actual, tirada)
      if correcto == false
        return -1
      else
        pos_final = (actual + tirada) % @casillas.size
        
        if pos_final != actual + tirada
          @por_salida = @por_salida + 1
        end
      end
      return pos_final
    end
    
    def calcular_tirada(origen, destino)
      if (destino - origen) < 0
        tirada = destino - origen + @casilla.size
        return tirada
      else
        tirada = destino - origen
        return tirada
      end
    end
    
    def to_s
      "\nTablero: \nnum_casilla_carcel = #{@num_casilla_carcel.to_s} \n casillas : #{@casillas.to_s} \n por_salida = #{@por_salida.to_s} \n tiene_juez = #{@tiene_juez.to_s}"
    end
    
    attr_reader :num_casilla_carcel
    #attr_writter :por_salida
    #no me funciona el accessor del set
    
  end
end

