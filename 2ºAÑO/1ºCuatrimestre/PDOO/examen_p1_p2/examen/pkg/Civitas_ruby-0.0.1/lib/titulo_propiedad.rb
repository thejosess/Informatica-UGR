# encoding:utf-8

require_relative "jugador.rb"

module Civitas
  class Titulo_propiedad
    
    @@factor_intereses_hipoteca = 1.1
    
    def initialize(nom, ab, fr, hb, pc, pe)
      @alquiler_base = ab
      @factor_revalorizacion = fr
      @hipoteca_base = hb
      @hipotecado = false
      @nombre = nom
      @num_casas = 0
      @num_hoteles = 0
      @precio_compra = pc
      @precio_edificar = pe
      @propietario = nil
    end
    
    #quitar
    def jugador=(otro)
      @propietario = otro
    end
    
    def actualiza_propietario_por_conversion(jugador)
      @propietario = jugador
    end
    
    def cancelar_hipoteca(jugador)
      if hipotecado && es_este_el_propietario(jugador)
        jugador.paga(get_importe_cancelar_hipoteca)
        @hipotecado=false
        return true
      else
        return false
      end
    end
    
    def cantidad_casas_hoteles
      return @num_casas + @num_hoteles
    end
    
    def comprar(jugador)
        if tiene_propietario
            return false
        else
            @propietario = jugador
            @propietario.paga(@precio_compra)
            return true
        end
    end
    
    def construir_casa(jugador)
      aux = false
      if @propeitario == jugador 
        @propietario.paga(@precio_edificar)
        @num_casas++
        aux = true
      end
        return aux
    end
    
    def construir_hotel(jugador)
      aux = false
      if @propeitario == jugador 
        @propietario.paga(@precio_edificar)
        @num_hoteles++
        aux = true
      end
        return aux
    end
    
    def derruir_casas(n, jugador)
      if @propietario == jugador && @num_casas > n
        @num_casas -= n
        return true
      else
        return false
      end
    end
    
    def es_este_el_propietario(jugador)
      if jugador == @propietario
        return true
      else
        return false
      end
    end
    
    def get_importe_cancelar_hipoteca
      return @hipoteca_base*@@factor_intereses_hipoteca
    end
    
    def get_precio_alquiler
      if @hipotecado || propietario_encarcelado
        return 0
      else
        return @alquiler_base*(1.0+(@num_casas*0.5) + (@num_hoteles*2.5))
      end
    end
    
    def precio_venta
      return @precio_compra + (@precio_edificar*@factor_revalorizacion)
    end
    
  def hipotecar(jugador) 
      if !@hipotecado && es_este_el_propietario(jugador)
        jugador.recibe(@hipoteca_base)
        @hipotecado = true
        return true
      else
        return false
      end
    end
    
    def propietario_encarcelado
      aux = true
      
      if !@propietario.is_encarcelado || @propietario == nil
        aux = false
      elsif @propietario.is_encarcelado
        aux = true
      end
      
      return aux
    end
    
    def tiene_propietario
      return @propietario != nil
    end
    
     def to_s
      "Nombre = #{@nombre.to_s} \n PrecioCompra = #{@precio_compra.to_s} \n AlquilerBase = #{@alquiler_base.to_s} \n FactorRevalorizacion = #{@factor_revalorizacion.to_s} 
              \n HipotecaBase = #{@hipoteca_base.to_s} \n PrecioEdificar = #{@precio_edificar.to_s} \n NumCasas = #{@num_casas.to_s} \n NumHoteles = #{@num_hoteles.to_s} \n Propietario = #{@propietario.to_s} \n Hipotecado = #{@hipotecado.to_s}"
    end
     
    def tramitar_alquiler(jugador)
      if @propietario != nil && !es_este_el_propietario(jugador)
        jugador.paga_alquiler(get_precio_alquiler)
        @propietario.recibe(get_precio_alquiler)
      end
    end
    
    def vender(jugador)
        if es_este_el_propietario(jugador)
        
            precio_venta = @precio_compra+(@num_casas+5*@num_hoteles)*@precio_edificar*@factor_revalorizacion
            @propietario.recibe(precio_venta)
            @propietario = nil
            return true
        else
            return false
        end
    end
    
    attr_reader :hipotecado, :hipoteca_base, :nombre, :num_casas, :num_hoteles, :precio_compra, :precio_edificar, :propietario
    private :es_este_el_propietario, :precio_venta, :propietario_encarcelado
  end
end
