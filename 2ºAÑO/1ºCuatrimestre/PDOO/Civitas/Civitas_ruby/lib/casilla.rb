# encoding:utf-8

require_relative "tipo_casilla.rb"

module Civitas
  class Casilla
    
    #valores por defecto
    def initialize(nom="\0",imp=0,carc=0,tip=nil,titu=nil,sorpr=nil,maz=nil)
      @nombre = nom
      @importe = imp
      @@carcel = carc
      @tipo = tip
      @titulo_propiedad = titu
      @sorpresa = sorpr
      @mazo = maz
    end
    
    def self.new_casilla_descanso(nom)
      new(nom, 0, 0, Tipo_casilla::DESCANSO, nil, nil, nil)
    end
    
    def self.new_casilla_calle(titulo)
      new(titulo.nombre, 0, 0, Tipo_casilla::CALLE, titulo, nil, nil)
    end
    
    def self.new_casilla_impuesto(cantidad, nombre)
      new(nombre, cantidad, 0, Tipo_casilla::IMPUESTO, nil, nil, nil)
    end
    
    def self.new_casilla_juez(num_casilla_carcel, nombre)
      new(nombre, 0, num_casilla_carcel, Tipo_casilla::JUEZ, nil, nil, nil)
    end
    
    def self.new_casilla_sorpresa(mazo, nombre)
      #sor = mazo.siguiente
      new(nombre, 0, 0, Tipo_casilla::SORPRESA, nil,nil, mazo)
    end
    
    def informe(iactual, todos)
      Diario.instance.ocurre_evento("El jugador " + todos[iactual].nombre + "ha caido en la casilla")
      to_s
    end
    

    def jugador_correcto(iactual, todos)
      return iactual >= 0 && iactual < todos.size
    end
    
=begin
    def recibe_jugador(iactual,todos)
      
    end
    
    def recibe_jugador_calle(iactual, todos)
      
    end
=end
    
    def recibe_jugador_impuesto(iactual,todos)
      if jugador_correcto(iactual, todos)
        informe(iactual, todos)
        todos[iactual].paga_impuesto(@importe)
      end
    end
    
    def recibe_jugador_juez(iactual,todos)
      if jugador_correcto(iactual, todos)
        informe(iactual, todos)
        todos[iactual].encarcelar(@@carcel)
      end
    end

=begin
    def recibe_jugador_sorpresa(iactual, todos)
      
    end
=end
    
    def to_s
      "Casilla: \nNombre=   #{@nombre.to_s} , \n importe =  #{@importe.to_s}  , \n tipo =  #{@tipo.to_s}  , \n titulo =  #{@titulo.to_s}  \n sorpresa = #{@sorpresa.to_s} \n mazo = #{@mazo.to_s}"
    end
    
    private :informe, :recibe_jugador_impuesto
          
    attr_reader :nombre, :titulo_propiedad
              
    
  end
end