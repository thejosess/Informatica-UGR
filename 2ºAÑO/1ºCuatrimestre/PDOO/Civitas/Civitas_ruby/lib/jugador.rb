# encoding:utf-8

module Civitas
  class Jugador
    
      @@saldo_inicial = 7500
      @@paso_por_salida = 1000
      @@precio_libertad = 200
      @@casas_max = 4
      @@casas_por_hotel = 4
      @@hoteles_max = 4

    
     def initialize(nombre)
      @encarcelado = false
      @nombre = nombre
      @num_casilla_actual = 0
      @puede_comprar = false
      @saldo = 0
      @propiedades = Array.new
      @salvoconducto = nil
    end
    
     #creo que está mal
    def new_copia(otro)
      @nombre = otro.nombre
      @encarcelado = otro.is_encarcelado
      @num_casilla_actual = otro.num_casilla_actual
      @puede_comprar = otro.puede_comprar
      @saldo = otro.saldo
      @propiedades = otro.propiedades
      @salvoconducto = otro.salvoconducto
    end
    
    def <=>(otro) # #1 if self>other; 0 if self==other; -1 if self<other
      @saldo <=> otro.saldo
    end
    
=begin   
    def cancelar_hipoteca(ip)
      
    end
=end   
    def cantidad_casas_hoteles
      aux = 0
      
      @propiedades.each do |i|
        aux += i.cantidad_casas_hoteles
      end
      
      return aux
    end
=begin    
    def comprar(titulo)
      
    end
    
    def construir_casa(ip)
      
    end
    
    def construir_hotel(ip)
    
    end
=end
    
    def debe_ser_encarcelado
      if is_encarcelado
        return false
      else
        if !tiene_salvoconducto
          return true
        else
          perder_salvoconducto
          Diario.instance.ocurre_evento("El jugador se libra de la cárcel")
          return false
        end
      end
    end
    
    def en_bancarrota
      return @saldo < 0      
    end
    
    def encarcelar(num_casilla_carcel)
      if debe_ser_encarcelado
        mover_a_casilla(num_casilla_carcel)
        @encarcelado = true
        Diario.instance.ocurre_evento("Jugador encarcelado")
      end
      return @encarcelado
    end
    
    def existe_la_propiedad(ip)
      return @propiedades.at(ip)
    end
=begin   
    def hipotecar(ip)
      
    end
=end   
    def is_encarcelado
      return @encarcelado
    end
    
    def modificar_saldo(cantidad)
      @saldo +=cantidad
      true
    end
    
    def mover_a_casilla(num_casilla)
      if is_encarcelado
        return false
      else
        @num_casilla_actual = num_casilla
        @puede_comprar = false
        Diario.instance.ocurre_evento("Jugador movido de casilla")
        return true
      end
    end
    
    def obtener_salvoconducto(sorpresa)
      if is_encarcelado
        return false
      else
        @salvoconducto = sorpresa
        return true
      end
    end
    
    def paga(cantidad)
      return modificar_saldo(cantidad*(-1))
    end
    
    def paga_alquiler(cantidad)
      if is_encarcelado
        return false
      else
        return paga(cantidad)
      end
    end
    
    def paga_impuesto(cantidad)
      if is_encarcelado
        return false
      else
        return paga(cantidad)
      end
    end
    
    def pasa_por_salida
      modificar_saldo(@@paso_por_salida)
      Diario.instance.ocurre_evento("El jugador pasa por la salida y cobra")
      return true
    end
    
    def perder_salvoconducto
      @salvoconducto.usada
      @salvoconducto = nil
    end
    
    def puede_comprar_casilla
      if is_encarcelado
        @puede_comprar = false
      else
        @puede_comprar = true
      end
      return @puede_comprar
    end
    
    def puede_salir_carcel_pagando
      return @saldo >= @@precio_libertad
    end
    
    
=begin
def puede_edificar_casa(titulo)
        return titulo.construir_casa(self)  #¿self?
      end
    
  
      def puede_edificar_hotel(titulo)
        return titulo.construir_hotel(self)
      end
=end
    
    
    
    def puedo_gastar(precio)
      if is_encarcelado
        return false
      else
        return @saldo >= precio
      end
    end
    
    def recibe(cantidad)
      if is_encarcelado
        return false
      else
        return modificar_saldo(cantidad)
      end
    end
    
    def salir_carcel_pagando
      if is_encarcelado && puede_salir_carcel_pagando
        paga(@@precio_libertad)
        @encarcelado = false
        Diario.instance.ocurre_evento("El jugador paga y sale de la cárcel")
        return true
      else
        return false
      end
    end
    
    def salir_carcel_tirando
      if Dado.instance.salgo_de_la_carcel
        @encarcelado = false
        Diario.instance.ocurre_evento("El jugador sale de la cárcel")
        return true
      else
        return false
      end
    end
    
    def tiene_algo_que_gestionar
      return @propiedades.any? #duda
    end
    
    def tiene_salvoconducto
      return @salvoconducto != nil
    end
    
    def to_s
      "Jugador:\n" + "\nencarcelado =" + @encarcelado.to_s + "\nnombre =" << @nombre.to_s + "\nnum_casilla actual =" + @num_casilla_actual.to_s + 
        "\npuede_comprar =" + @puede_comprar.to_s + "\nsaldo =" + @saldo.to_s + "\npropiedades:\n" + @propiedades.to_s
    end
    
    def vender(ip)
      if is_encarcelado
        return false
      else
        @titulo = nil
        if existe_la_propiedad(ip) && @titulo.vender(self)
          @propiedades.remove(ip)
          Diario.instance.ocurre_evento("Propiedad vendida con éxito")
          return true
        else
          return false
        end
      end
    end
    
     attr_reader :casas_max, :casas_por_hotel, :hoteles_max, 
      :nombre, :num_casilla_actual, :precio_libertad,
      :paso_por_salida, :propiedades, :puede_comprar, :saldo, :salvoconducto
    
    protected :debe_ser_encarcelado, :new_copia
    private :existe_la_propiedad, :perder_salvoconducto,
      :puede_salir_carcel_pagando, :puedo_gastar
    
  end
end