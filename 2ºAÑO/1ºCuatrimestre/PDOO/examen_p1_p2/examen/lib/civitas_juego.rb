# encoding:utf-8

require_relative "jugador.rb"
require_relative "dado.rb"
require_relative "mazo_sorpresas.rb"
require_relative "gestor_estados.rb"
require_relative "tablero.rb"

module Civitas
  class Civitas_juego
    
    def initialize(nombres)
      @tablero
      @estado
      
      @jugadores = Array.new
      
      for i in nombres do
        @jugadores << Jugador.new(i)
      end
      
      @gestor_estados = Gestor_estados.new
      @estado = @gestor_estados.estado_inicial
      @indice_jugador_actual = Dado.instance.quien_empieza(@jugadores.size)
      @mazo = Mazo_sorpresas.new
      inicializar_tablero(@mazo)
      inicializar_mazo_sorpresas(@tablero)
    end
    
    
    
=begin
def construir_casa(ip)
      
    end
    
    def construir_hotel(ip)
      
    end

 def cancelar_hipoteca(ip)
      return self.jugador_actual.hipotecar(ip)
    end

=end
    
    def contabilizar_pasos_por_salida(jugador_actual)
      
      seguir = true
      
      while seguir do
        if @tablero.por_salida == 0
          seguir = false
        else
          jugador_actual.pasa_por_salida
        end
      end
      
    end
    
    def final_del_juego
      final = false
      
      for i in @jugadores do
        if i.en_bancarrota
          final = true
        end
      end
      final
    end
    
    def jugador_actual
      return @jugadores[@indice_jugador_actual]
    end
    
    def casilla_actual
      casilla = @jugadores.indice_jugador_actual.num_casilla_actual
      return @tablero.get_casilla(casilla)
    end
    
=begin
def hipotecar(ip)
      return self.jugador_actual.hipotecar(ip)
    end
=end
    
    
    def info_jugador_texto
      @jugadores[@indice_jugador_actual].to_s
    end
    
    def inicializar_mazo_sorpresas(tablero)
        @mazo.al_mazo(Sorpresa.new_generico(Tipo_sorpresa::PAGARCOBRAR, -100, "Te han multado por ir a 10km/h con el coche TORTUGA"))
        @mazo.al_mazo(Sorpresa.new_generico(Tipo_sorpresa::PAGARCOBRAR,250,"Saludas a los autobuseros, por ser un buen ciudadano recibes 250 euros"))
        @mazo.al_mazo(Sorpresa.new_ir_casilla(Tipo_sorpresa::IRCASILLA, tablero, 4, "Te has caido en una alcantarilla y apareces en china, te mueves 4 casillas" ))
        @mazo.al_mazo(Sorpresa.new_ir_casilla(Tipo_sorpresa::IRCASILLA,tablero,2,"tropezar y no caerte es avanzar, te mueves dos casillas"))
        @mazo.al_mazo(Sorpresa.new_carcel(Tipo_sorpresa::IRCARCEL,tablero))
        @mazo.al_mazo(Sorpresa.new_generico(Tipo_sorpresa::PORCASAHOTEL,25,"Recibes dinero por pasar por tu territorio, toma 25" ))
        @mazo.al_mazo(Sorpresa.new_generico( Tipo_sorpresa::PORCASAHOTEL,-10,"No es tu territorio ahora pagas 10"))
        @mazo.al_mazo(Sorpresa.new_generico(Tipo_sorpresa::PORJUGADOR, -12, "le pagas al resto de jugadores 12"))
        @mazo.al_mazo(Sorpresa.new_generico(Tipo_sorpresa::PORJUGADOR, 12, "Hoy es el dia de la felicidad, todos los jugadores te dan 12"))
        @mazo.al_mazo(Sorpresa.new_salir_carcel(Tipo_sorpresa::SALIRCARCEL, @mazo ))
    end
    
    def inicializar_tablero(mazo)
      @tablero = Tablero.new(5)
      @tablero.añade_casilla(Casilla.new_casilla_descanso("Parking"))
      @tablero.añade_casilla(Casilla.new_casilla_juez(5, "Juez"))
      @tablero.añade_casilla(Casilla.new_casilla_impuesto(100, "Impuesto"))
      @tablero.añade_casilla(Casilla.new_casilla_sorpresa(mazo, "Sorpresa 1"))
      @tablero.añade_casilla(Casilla.new_casilla_sorpresa(mazo, "Sorpresa 2"))
      @tablero.añade_casilla(Casilla.new_casilla_sorpresa(mazo, "Sorpresa 3"))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C1", 150, 200, 80, 45, 140)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C2", 170, 250, 90, 55, 150)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C3", 190, 300, 100, 65, 160)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C4", 210, 350, 110, 75, 170)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C5", 230, 400, 120, 85, 180)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C6", 250, 450, 130, 95, 190)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C7", 270, 500, 140, 105, 200)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C8", 290, 550, 150, 115, 210)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C9", 310, 600, 160, 125, 220)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C10", 330, 650, 170, 135, 230)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C11", 350, 700, 180, 145, 240)))
      @tablero.añade_casilla(Casilla.new_casilla_calle(Titulo_propiedad.new("C12", 370, 750, 190, 155, 250)))
      
    end
    
    def pasar_turno
      @indice_jugador_actual = (@indice_jugador_actual + 1) % @jugadores.size
    end
    
    def ranking
      @jugadores.sort
    end
    
    def salir_carcel_pagando
      return @jugador_actual.salir_carcel_pagando
    end
    
    def salir_carcel_tirando
      return @jugador_actual.salir_carcel_tirando
    end
    
=begin
def siguiente_paso
      
    end
def avanza_jugador()
      
    end
    
    
    
   
    
    def comprar
      
    end

=end
    
    
    
    
    def siguiente_paso_completado(operacion)
      @estado = @gestor_estados.siguiente_estado(@jugador_actual, @estado, operacion)
    end
    
    def vender(ip)
      return @jugador_actual.vender(ip)
    end
                
    private  :contabilizar_pasos_por_salida, :inicializar_tablero,
            :pasar_turno, :ranking, :inicializar_mazo_sorpresas
    
  end
end
