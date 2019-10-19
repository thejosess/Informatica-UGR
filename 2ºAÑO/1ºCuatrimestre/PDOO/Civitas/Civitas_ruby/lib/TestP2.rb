# encoding:utf-8

require_relative "dado.rb"
require_relative "tablero.rb"
require_relative "sorpresa.rb"
require_relative "estados_juego.rb"
require_relative "mazo_sorpresas.rb"
require_relative "diario.rb"
require_relative "titulo_propiedad.rb"
require_relative "civitas_juego.rb"

module Civitas
  class TestP2
    def self.main
      
      titulo = Titulo_propiedad.new("Eoo", 100, 2, 150, 200, 250)
      puts titulo.to_s
      
      jugador = Jugador.new("eo")
      aux = Jugador.new("hola")
      titulo.jugador=(jugador)
      puts titulo.get_precio_alquiler
      puts titulo.get_importe_cancelar_hipoteca
      puts titulo.tramitar_alquiler(aux)
      #puts titulo.propietario_encarcelado
      puts titulo.cantidad_casas_hoteles
      #puts titulo.precio_venta
      puts titulo.derruir_casas(0, jugador)
      puts titulo.vender(jugador)
      titulo.actualiza_propietario_por_conversion(jugador)
      puts titulo.hipotecar(jugador)
      
      todos = Array.new
      todos << jugador
      todos << aux

    @tablero = Tablero.new(5)
      
      mazo = Mazo_sorpresas.new()
      
        mazo.al_mazo(Sorpresa.new_generico(Tipo_sorpresa::PAGARCOBRAR, -100, "Te han multado por ir a 10km/h con el coche TORTUGA"))
        mazo.al_mazo(Sorpresa.new_generico(Tipo_sorpresa::PAGARCOBRAR,250,"Saludas a los autobuseros, por ser un buen ciudadano recibes 250 euros"))
        mazo.al_mazo(Sorpresa.new_ir_casilla(Tipo_sorpresa::IRCASILLA, @tablero, 4, "Te has caido en una alcantarilla y apareces en china, te mueves 4 casillas" ))
        mazo.al_mazo(Sorpresa.new_ir_casilla(Tipo_sorpresa::IRCASILLA,@tablero,2,"tropezar y no caerte es avanzar, te mueves dos casillas"))
        mazo.al_mazo(Sorpresa.new_carcel(Tipo_sorpresa::IRCARCEL,@tablero))
        mazo.al_mazo(Sorpresa.new_generico(Tipo_sorpresa::PORCASAHOTEL,25,"Recibes dinero por pasar por tu territorio, toma 25" ))
        mazo.al_mazo(Sorpresa.new_generico( Tipo_sorpresa::PORCASAHOTEL,-10,"No es tu territorio ahora pagas 10"))
        mazo.al_mazo(Sorpresa.new_generico(Tipo_sorpresa::PORJUGADOR, -12, "le pagas al resto de jugadores 12"))
        mazo.al_mazo(Sorpresa.new_generico(Tipo_sorpresa::PORJUGADOR, 12, "Hoy es el dia de la felicidad, todos los jugadores te dan 12"))
        mazo.al_mazo(Sorpresa.new_salir_carcel(Tipo_sorpresa::SALIRCARCEL, mazo ))
      
      casilla = Casilla.new_casilla_sorpresa(mazo,"hello premog eo")
      
       
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
      
      
      nombres = Array.new
      nombres << "Kike"
      nombres << "Juse"
      
      civitas = Civitas_juego.new(nombres)
      civitas.inicializar_mazo_sorpresas(@tablero)
      civitas.inicializar_tablero(mazo)
      
      puts "prueba del constructor sorpresa"
      s1 = Sorpresa.new_generico(Tipo_sorpresa::PAGARCOBRAR, -100, "Te han multado por ir a 10km/h con el coche TORTUGA")
      puts s1.to_s      
      
=begin
      puts "prueba david"
      puts civitas.tablero.casillas[4].to_s
      puts "eo division"
      puts civitas.tablero.casillas[4].sorpresa.to_s
      poner los get que te hacen falta
      
=end

   c1 = Sorpresa.new_ir_casilla(Tipo_sorpresa::IRCASILLA, @tablero, 10, "texto")
   c1.aplicar_a_jugador(0, todos)

   c2 = Sorpresa.new_carcel(Tipo_sorpresa::IRCARCEL, @tablero)
   c2.aplicar_a_jugador(0, todos)
      
  
  c3 = Sorpresa.new_generico(Tipo_sorpresa::PAGARCOBRAR, 12,"eo")
  c3.aplicar_a_jugador(0, todos)   
  
       c4 = Sorpresa.new_generico(Tipo_sorpresa::PORCASAHOTEL, 12,"e34o")
  c4.aplicar_a_jugador(0, todos) 
  
      puts "constructor copia"
      
      ju = Jugador.new("aux")
      puts ju.to_s
      #puts ju.debe_ser_encarcelado
      #ju.new_copia(aux)
      #ju.encarcelar(5)
      #puts ju.obtener_salvoconducto(c3)
      #puts ju.perder_salvoconducto
      puts ju.puede_comprar_casilla
      puts ju.paga(12)
      puts ju.paga_alquiler(3)
      puts ju.paga_impuesto(34)
      puts ju.recibe(200)
      puts ju.modificar_saldo(200)
      puts ju.mover_a_casilla(10)
      puts ju.vender(0)
      puts ju.tiene_algo_que_gestionar
      #puts ju.puede_salir_carcel_pagando
      puts ju.salir_carcel_pagando
      puts ju.salir_carcel_tirando
      puts ju.pasa_por_salida
      
  
      puts ju <=> aux
      
  
       c5 = Sorpresa.new_generico(Tipo_sorpresa::PORJUGADOR, 12,"asdf")
  c5.aplicar_a_jugador(0, todos)  
  
       c6 = Sorpresa.new_generico(Tipo_sorpresa::PORCASAHOTEL, 12,"asdf")
  c6.aplicar_a_jugador(0, todos) 
  
      c7 = Sorpresa.new_generico(Tipo_sorpresa::PORJUGADOR, 12,"asdf")
  c7.aplicar_a_jugador(0, todos)
  
       c8 = Sorpresa.new_salir_carcel(Tipo_sorpresa::SALIRCARCEL, mazo)
  c8.aplicar_a_jugador(0, todos)
      
      cas = Casilla.new_casilla_descanso("Parking")
      #cas.recibe_jugador_juez(0,todos)
      #cas.recibe_jugador_impuesto(0, todos)
      
      puts civitas.vender(2)
      puts civitas.final_del_juego
      puts civitas.siguiente_paso_completado(Operaciones_juego::COMPRAR)
      
      puts civitas.info_jugador_texto
      #puts civitas.pasar_turno
     # puts civitas.ranking
     # puts civitas.contabilizar_pasos_por_salida(ju)
      
      
      puts "ultima prueba real no fake"
      
      #civitas.mazo.siguiente
      #civitas.mazo.siguiente
      #puts civitas.mazo.siguiente.aplicar_a_jugador(civitas.indice_jugador_actual, civitas.jugadores)
      
    end
  end
  TestP2.main
end