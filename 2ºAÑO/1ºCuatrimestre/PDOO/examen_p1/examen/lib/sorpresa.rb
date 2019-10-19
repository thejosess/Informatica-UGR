# encoding:utf-8

require_relative "tipo_sorpresa.rb"

module Civitas
  class Sorpresa
    
    def initialize(tipo,tablero=nil,valor=-1,texto="\0",mazo=nil)
      @tipo_sorpresa = tipo
      @texto = texto
      @valor = valor
      @mazo = mazo
      @tablero = tablero
    end
    
    def self.new_carcel(tipo, tablero)
      if tipo == Tipo_sorpresa::IRCARCEL
        new(tipo,tablero,tablero.num_casilla_carcel,"\0",nil)
      end
    end
    
    def self.new_ir_casilla(tipo, tablero, valor, texto)
      if tipo == Tipo_sorpresa::IRCASILLA
        new(tipo,tablero,valor,texto,nil)
      end
    end
    
    def self.new_generico(tipo,valor, texto)
      new(tipo,nil,valor,texto,nil)
    end
    
    def self.new_salir_carcel(tipo, mazo)
      if tipo == Tipo_sorpresa::SALIRCARCEL
        new(tipo,nil,0,"\0",mazo)
      end
    end
    
        def self.init
      @valor = -1
      @mazo = nil
      @tablero = nil
    end
    
    
    def aplicar_a_jugador(actual,todos)
      
      if @tipo_sorpresa == Tipo_sorpresa::IRCASILLA
        aplicar_a_jugador_ir_a_casilla(actual,todos)
        
        else if @tipo_sorpresa == Tipo_sorpresa::IRCARCEL
          aplicar_a_jugador_ir_carcel(actual,todos)
          
          else if @tipo_sorpresa == Tipo_sorpresa::PAGARCOBRAR
            aplicar_a_jugador_pagar_cobrar(actual,todos)
            
            else if @tipo_sorpresa == Tipo_sorpresa::PORCASAHOTEL
              aplicar_a_jugador_por_casa_hotel(actual,todos)
              
              else if @tipo_sorpresa == Tipo_sorpresa::PORJUGADOR
                aplicar_a_jugador_por_jugador(actual,todos)
                
                else if @tipo_sorpresa == Tipo_sorpresa::SALIRCARCEL
                  aplicar_a_jugador_salir_carcel(actual,todos)
                end
              end
            end
          end
        end
      end
      
    end
    
    def aplicar_a_jugador_ir_a_casilla(actual,todos)
      
      if jugador_correcto(actual,todos)
        
        informe(actual,todos)
        casilla_actual = todos[actual].num_casilla_actual
        tirada = @tablero.calcular_tirada(casilla_actual, @valor)
        posicion = @tablero.nueva_posicion(casilla_actual, tirada)
        todos[actual].mover_a_casilla(posicion)
        #@tablero.casilla.recibe_jugador(actual, todos)
        
      end
    end
    
    def aplicar_a_jugador_ir_carcel(actual,todos)
      if jugador_correcto(actual,todos)
        informe(actual,todos)
        todos[actual].encarcelar(@tablero.num_casilla_carcel)
      end
    end
    
    def aplicar_a_jugador_pagar_cobrar(actual,todos)
      if jugador_correcto(actual,todos)
        informe(actual,todos)
        todos[actual].modificar_saldo(@valor)
      end
    end
    
    def aplicar_a_jugador_por_casa_hotel(actual,todos)
      if jugador_correcto(actual,todos)
        informe(actual,todos)
        todos[actual].modificar_saldo(@valor*todos[actual].cantidad_casas_hoteles)
      end
    end
    
    def aplicar_a_jugador_por_jugador(actual,todos)
      if jugador_correcto(actual,todos)
        informe(actual,todos)
        
        s1 = Sorpresa.new_generico(Tipo_sorpresa::PAGARCOBRAR,@valor*(-1),"pagarCobrar")
        
        for i in 1..todos.size-1 do
          if i != actual 
            s1.aplicar_a_jugador_pagar_cobrar(i,todos)
          end
        end
        
        s2 = Sorpresa.new_generico(Tipo_sorpresa::PAGARCOBRAR,@valor*todos.size-1,"pagarCobrar")
        s2.aplicar_a_jugador_pagar_cobrar(actual,todos)
        
      end
    end
    
    def aplicar_a_jugador_salir_carcel(actual,todos)
      if jugador_correcto(actual,todos)
        informe(actual,todos)
        
        for i in 0..todos.size-1 do   
          if todos[i].tiene_salvoconducto
            sigue = false
          end
        end
        if sigue
          todos[actual].obtener_salvoconducto
        end
        salir_del_mazo
      end
    end
    
    def informe(actual,todos)
      Diario.instance.ocurre_evento("Se está aplicando una sorpresa al jugador " + todos[actual].nombre)
    end
    

    
    def jugador_correcto(actual,todos)
      return actual >= 0 && actual < todos.size
    end
    
    def salir_del_mazo
      if @tipo == Tipo_sorpresa::SALIRCARCEL
        @mazo.inhabilitar_carta_especial(self)  #duda de esto
      end
    end
    
    def to_s
      "Tipo sorpresa = #{@tipo_sorpresa.to_s} \n valor = #{@valor.to_s} \n texto = #{@texto.to_s}
            \n mazo = #{@mazo.to_s}  \n tablero = #{@tablero.to_s}"
    end

    def usada
      if @tipo == Tipo_sorpresa::SALIRCARCEL
        @mazo.habilitar_carta_especial(self)  #duda de esto
      end
    end
    
    protected :aplicar_a_jugador_pagar_cobrar
    
    private :informe, :aplicar_a_jugador_ir_a_casilla,
            :aplicar_a_jugador_ir_carcel,
            :aplicar_a_jugador_por_casa_hotel, :aplicar_a_jugador_por_jugador
            :aplicar_a_jugador_salir_carcel
   #publicos por defecto    
  end
end