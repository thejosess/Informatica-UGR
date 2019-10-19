# encoding:utf-8

module Civitas
  class Mazo_sorpresas
    
    def initialize (debug = false)  #asi le estas diciendo que si no le pasa nada es a false
      init
      @debug = debug
      @ultima_sorpresa
    end
    
    def init
      @sorpresas = Array.new
      @cartas_especiales = Array.new
      @vacio = false
      @barajada = false
      @usadas = 0
    end
    
    #en ruby no se puede tener dos metodos con el mismo nombre
    
    def Mazo_sorpresas(d)   #dudas con este tambien
      @debug = d
      init
      if @debug == true
        Diario.instance.ocurre_evento("debug ya activado")
      end
    end
    
    def al_mazo(s)
      if @barajada == false
        @sorpresas << s
      end
    end
    
    def ultima_sorpresa
      return @ultima_sorpresa
    end
    
    def siguiente
      if @barajada == false || @usadas == @sorpresas.size
        if !@debug
          @sorpresas.shuffle 
          @usadas = 0
          @barajada = true
        end
      end
      
      @usadas = @usadas + 1
      aux = @sorpresas.at(0)
      @sorpresas.delete_at(0)
      @sorpresas << aux
      @ultima_sorpresa = aux
      return @ultima_sorpresa
    end
    
    def inhabilitar_carta_especial(sorpresa)
      if @sorpresas.include?(sorpresa)
        @sorpresas.delete(sorpresa)
        @cartas_especiales << sorpresa
      end
    end
    
    def habilitar_carta_especial(sorpresa)
      if @cartas_especiales.include?(sorpresa)
        @cartas_especiales.delete(sorpresa)
        @sorpresas << sorpresa
      end
    end
    
    private :init
    
  end
end