# encoding:utf-8

require_relative "dado.rb"
require_relative "tablero.rb"
require_relative "sorpresa.rb"
require_relative "estados_juego.rb"
require_relative "mazo_sorpresas.rb"
require_relative "diario.rb"

module Civitas
  class TestP1
    def self.main
      
      @@TAMANIO=20
      
      puts " \n\n*****TAREA 1*****"
      
      uno = 0
      dos = 0
      tres = 0
      cuatro = 0
      
      for i in(1..100)
        
        empieza = Dado.instance.quien_empieza(4)+1
        
        if empieza == 1
          uno +=1
        end
        
        if empieza == 2
          dos +=1
        end
        
        if empieza == 3
          tres +=1
        end
        
        if empieza == 4
          cuatro +=1
        end
      end
      
      puts "El jugador 1 ha salido #{uno} veces"
      puts "El jugador 2 ha salido #{dos} veces"
      puts "El jugador 3 ha salido #{tres} veces"
      puts "El jugador 4 ha salido #{cuatro} veces"
      
      
      puts "\n\n*****TAREA 2*****"
      
      Dado.instance.debug=(true)
      puts Dado.instance.tirar
      
      Dado.instance.debug=(false)
      puts Dado.instance.tirar
      
      puts"\n\n*****TAREA 3*****"
      
      puts Dado.instance.tirar
      puts Dado.instance.get_ultimo_resultado
      puts Dado.instance.salgo_de_la_carcel
      
      puts "\n\n*****TAREA 4*****"
      
      puts "Casilla de tipo " + Tipo_casilla::CALLE.to_s
      puts "Sorpresa de tipo " + Tipo_sorpresa::SALIRCARCEL.to_s
      puts "Estado de juego " + Estados_juego::INICIO_TURNO.to_s
      
      puts "\n\n**TAREA 5**"
      prueba = ""
      @@mazo = Mazo_sorpresas.new
      @@s1 = Sorpresa.new_generico(Tipo_sorpresa::IRCARCEL,25,"hola2")
      @@s2 = Sorpresa.new_generico(Tipo_sorpresa::IRCARCEL,25,"hola2")
      @@mazo.al_mazo(@@s1)
      @@mazo.al_mazo(@@s2)
      @@mazo.siguiente
      @@mazo.inhabilitar_carta_especial(@@s2)
      @@mazo.habilitar_carta_especial(@@s2)
      puts Diario.instance.leer_evento
      puts Diario.instance.ocurre_evento("prueba")
      puts Diario.instance.leer_evento
      puts Diario.instance.eventos_pendientes()
            
      puts "\n\n **TAREA 7**"
      carcel = 0
      
      puts "Introduce el nuero de casilla de carcel: "
      carcel = gets.to_i 
      
      calle1 = "CALLE 1"
      calle2 = "CALLE 2"
      calle3 = "CALLE 3"
      calle4 = "CALLE 4"
      calle5 = "CALLE 5"
      calle6 = "CALLE 6"
      calle7 = "CALLE 7"
      calle8 = "CALLE 8"
      calle9 = "CALLE 9"
      
      @@tablero = Tablero.new(carcel)
      c1 = Casilla.new_casilla_descanso(calle1)
      c2 = Casilla.new_casilla_descanso(calle2)
      c3 = Casilla.new_casilla_descanso(calle3)
      c4 = Casilla.new_casilla_descanso(calle4)
      c5 = Casilla.new_casilla_descanso(calle5)
      c6 = Casilla.new_casilla_descanso(calle6)
      c7 = Casilla.new_casilla_descanso(calle7)
      c8 = Casilla.new_casilla_descanso(calle8)
      c9 = Casilla.new_casilla_descanso(calle9)
        
      @@tablero.añade_casilla(c1)
      @@tablero.añade_casilla(c2)
      @@tablero.añade_casilla(c3)
      @@tablero.añade_casilla(c4)
      @@tablero.añade_casilla(c5)
      @@tablero.añade_casilla(c6)
      @@tablero.añade_casilla(c7)
      @@tablero.añade_casilla(c8)
      @@tablero.añade_casilla(c9)
      
      if carcel > @@TAMANIO
        puts "ERROR, la posicion de carcel es mayor que el tamaño del tablero \n"
        @@tablero.añade_casilla(Casilla.new("Carcel"))
      else
        puts "Tablero creado correctamente"
      end
      
      @@tablero.añade_juez
      
      origen = 7
      
      puts "El jugador se encuentra en la casilla 7"
      valor_dado = Dado.instance.tirar
      puts "Tiramos el dado y sale #{valor_dado}"
      puts "Por lo tanto el jugador avanza hasta la casilla " + @@tablero.nueva_posicion(origen, valor_dado).to_s
      
      #hay 9 casillas + juez y mas carcel
      
    end
  end
  TestP1.main
end